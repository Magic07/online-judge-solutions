class Solution:
    def minDistance(self, houses: List[int], k: int) -> int:
        houses=sorted(houses)
        def totalDis(start, end):
            middle=start+(end-start)//2
            dis=0
            for i in range(start, end+1):
                dis+=abs(houses[i]-houses[middle])
            return dis
        @lru_cache(maxsize=None)
        def minDis(startIndex, k):
            if len(houses)-startIndex==k:
                return 0
            if k==1:
                return totalDis(startIndex, len(houses)-1)
            answer=sys.maxsize
            for i in range(startIndex, len(houses)-k+1):
                answer=min(answer, totalDis(startIndex,i)+minDis(i+1, k-1))
            return answer
        return minDis(0,k)
        