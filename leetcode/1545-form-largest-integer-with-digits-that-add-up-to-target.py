class Solution:
    @lru_cache(maxsize=None)
    def largestNumberInternal(self, target: int) -> str:
        if(target==0):
            return ''
        if(target<min(self.cost)):
            return '0'
        answer='0'
        for i in range(9):
            suffix=self.largestNumberInternal(target-self.cost[i])
            if suffix!='0' and len(suffix)+1>=len(answer):
                answer=str(i+1)+suffix
        return answer
    def largestNumber(self, cost: List[int], target: int) -> str:
        self.cost=cost
        return self.largestNumberInternal(target)
        