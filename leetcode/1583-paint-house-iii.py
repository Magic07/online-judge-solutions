class Solution:    
    @lru_cache(maxsize=None)
    def minCostAfter(self, index, lastColor, target):
        if target<0 or len(self.houses)-index+1<target:
            return -1
        if index==self.m-1:
            if self.houses[index]!=0:
                if (target==0 and lastColor==self.houses[index]) or (target==1 and lastColor!=self.houses[index]):
                    return 0
                else:
                    return -1
            elif target==0:
                return self.cost[index][lastColor-1]
            elif target==1:
                answer=sys.maxsize
                return min(self.cost[index][i] for i in range(self.n) if i!=lastColor-1)
            else:
                return -1
        if self.houses[index]!=0:
            if index==0 or self.houses[index]!=lastColor:
                target-=1
            return self.minCostAfter(index+1, self.houses[index], target)
        answer=sys.maxsize
        for c in range(1, self.n+1):
            if index==0 or lastColor!=c:
                ca=self.minCostAfter(index+1, c, target-1)
                if ca!=-1:
                    answer=min(answer,ca+self.cost[index][c-1])
            else:
                ca=self.minCostAfter(index+1,c,target)
                if ca!=-1:
                    answer=min(answer,ca+self.cost[index][c-1])
        if answer==sys.maxsize:
            return -1
        return answer

    def minCost(self, houses: List[int], cost: List[List[int]], m: int, n: int, target: int) -> int:
        self.cost=cost
        self.houses=houses
        self.m=m
        self.n=n
        return self.minCostAfter(0, 0, target)
            
                