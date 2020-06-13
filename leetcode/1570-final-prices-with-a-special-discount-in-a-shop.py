class Solution:
    def finalPrices(self, prices: List[int]) -> List[int]:
        answer=[-1]*len(prices)
        for i in range(len(prices)):
            price=prices[i]
            for x in prices[i+1:]:
                if x <= price:
                    answer[i]=price-x
                    break
            if answer[i]<0:
                answer[i]=price
        return answer
                    