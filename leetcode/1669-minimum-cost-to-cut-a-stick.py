class Solution:
    def minCost(self, n: int, cuts: List[int]) -> int:
        cuts.append(0)
        cuts.append(n)
        cuts=sorted(cuts)
        dp=[[0 for i in range(len(cuts))] for j in range(len(cuts))]
        for distance in range(2, len(cuts)):
            for start in range(len(cuts)-distance):
                min_cost=sys.maxsize
                for c in range(start+1, start+distance):
                    min_cost=min(min_cost, dp[start][c]+dp[c][start+distance]+cuts[start+distance]-cuts[start])
                dp[start][start+distance]=min_cost                
        return dp[0][len(cuts)-1]