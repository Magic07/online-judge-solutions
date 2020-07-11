class Solution:
    def minNumberOfSemesters(self, n: int, dependencies: List[List[int]], k: int) -> int:
        deps=[0]*(n)
        for x,y in dependencies:
            deps[y-1]+=1<<(x-1)
        finished=[sys.maxsize]*(1<<(n))  # finished[i] is the semester when i is took.
        finished[0]=0
        
        for i in range(1<<n):
            canTake=0
            for j in range(n):
                if deps[j]&i==deps[j]:
                    canTake+=1<<j
            canTake&= ~i
            t=canTake
            while t>0:
                if finished[i|t]>finished[i]+1 and bin(t).count('1') <= k:
                    finished[i|t]=min(finished[i|t], finished[i]+1)
                t=(t-1)&canTake
        return finished[-1]

# Ref: https://leetcode.com/problems/parallel-courses-ii/discuss/708263/Can-anyone-explain-the-bit-mask-method