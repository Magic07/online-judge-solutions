class Solution:
    def minOperations(self, nums: List[int], x: int) -> int:
        N=len(nums)
        sumLeft=[0]*(N+1)
        sumLeftMap={0:0}
        sumRight=[0]*(N+1)
        sumRightMap={0:0}
        for i in range(1, N+1):
            sumLeft[i]=sumLeft[i-1]+nums[i-1]
            sumLeftMap[sumLeft[i]]=i
        for i in range(N-1,-1,-1):
            sumRight[i]=sumRight[i+1]+nums[i]
            sumRightMap[sumRight[i]]=N-i
        answer=sys.maxsize
        for i in range(N+1):
            if sumLeft[i]<=x and x-sumLeft[i] in sumRightMap:
                answer=min(answer, i+sumRightMap[x-sumLeft[i]])
            elif sumLeft[i]>x:
                break
        for i in range(N, i):
            if sumRight[i]<=x and x-sumRight[i] in sumLeftMap:
                answer=min(answer, N-i+sumLeftMap[x-sumRight[i]])
            elif sumRight[i]>x:
                break
        if answer==sys.maxsize or answer>len(nums):
            return -1
        return answer