class Solution:
    def profitableSchemes(self, G: int, P: int, group: List[int], profit: List[int]) -> int:
        
        @lru_cache(maxsize=None)
        def schemes(G, P, start):
            if G<0:
                return 0
            if start==len(group):
                if P<=0:
                    return 1
                else:
                    return 0
            return schemes(G,P,start+1)+schemes(G-group[start], max(0,P-profit[start]), start+1)
        return schemes(G,P,0)%1000000007