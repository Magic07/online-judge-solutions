class Solution:
    def maxCoins(self, piles: List[int]) -> int:
      piles=sorted(piles)
      n=len(piles)
      answer=0
      for i in range(int(n/3),n, 2):
        answer+=piles[i]
      return answer
        