class Solution:
    def findMaxValueOfEquation(self, points: List[List[int]], k: int) -> int:
        # Elements of q are [y-x, x], increasing order.
        q=collections.deque()
        answer=-sys.maxsize
        for point in points:
            while q and point[0]-q[0][1]>k:
                q.popleft()
            if q:
                answer=max(answer, q[0][0]+point[1]+point[0])
            while q and q[-1][0]<point[1]-point[0]:
                q.pop()
            q.append([point[1]-point[0], point[0]])
        return answer

# Ref: https://leetcode.com/problems/max-value-of-equation/discuss/709231/Python-Stack-O(N)