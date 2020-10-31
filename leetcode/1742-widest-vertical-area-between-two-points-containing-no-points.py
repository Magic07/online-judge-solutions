class Solution:
    def maxWidthOfVerticalArea(self, points: List[List[int]]) -> int:
        xs=sorted([x for (x,y) in points])
        answer=0
        for i in range(1,len(xs)):
            answer=max(answer, xs[i]-xs[i-1])
        return answer
        