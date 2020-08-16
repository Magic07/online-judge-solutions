class Solution:
    def threeConsecutiveOdds(self, arr: List[int]) -> bool:
        odds=0
        for x in arr:
            if x%2==1:
                odds+=1
                if odds==3:
                    return True
            else:
                odds=0
        return False
        