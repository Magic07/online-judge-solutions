class Solution:
    def maxProfit(self, inventory: List[int], orders: int) -> int:
        inventory=sorted(inventory, reverse=True)
        inventory.append(0)
        answer=0
        for i in range(1, len(inventory)):
            if orders==0 or inventory[i-1]==0:
                return answer%1000000007
            diff=inventory[i-1]-inventory[i]
            if diff==0:
                continue
            if orders>=(diff*i):
                answer+=((inventory[i]+1+inventory[i-1])*diff//2)*i
                orders-=(diff*i)
            else:
                pick=orders//i
                answer+=(2*inventory[i-1]-pick+1)*(pick)*i//2
                answer+=(orders-pick*i)*(inventory[i-1]-pick)
                orders=0
        return answer%1000000007