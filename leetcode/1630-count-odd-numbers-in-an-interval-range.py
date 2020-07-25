class Solution:
    def countOdds(self, low: int, high: int) -> int:
        interval=high-low+1
        if interval%2==0:
            return interval//2
        elif low%2:
            return interval//2+1
        else:
            return interval//2