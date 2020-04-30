class Solution:
    def maxScore(self, cardPoints: List[int], k: int) -> int:
        current=sum(cardPoints[:k])
        answer=current
        for i in range(k):
            current=current-cardPoints[k-1-i]+cardPoints[-i-1]
            answer=max(answer,current)
        return answer
        