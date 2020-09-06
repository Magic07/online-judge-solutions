class Solution:
    def minCost(self, s: str, cost: List[int]) -> int:
        answer=0
        lastCost=cost[0]
        for i in range(1, len(cost)):
            if s[i]==s[i-1]:
                answer+=min(lastCost, cost[i])
                lastCost=max(lastCost, cost[i])
            else:
                lastCost=cost[i]
        return answer