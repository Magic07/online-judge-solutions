class Solution:
    def getLastMoment(self, n: int, left: List[int], right: List[int]) -> int:
        left=sorted(left)
        right=sorted(right)
        answer=0
        if len(right)>0:
            answer=max(answer, n-right[0])
        if len(left)>0:
            answer=max(answer, left[-1])
        return answer