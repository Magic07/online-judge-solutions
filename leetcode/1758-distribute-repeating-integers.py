class Solution:
    def canDistribute(self, nums: List[int], quantity: List[int]) -> bool:
        numbersMap={}
        for x in nums:
            if x not in numbersMap:
                numbersMap[x]=0
            numbersMap[x]+=1
        index=0
        numbers=[0]*len(numbersMap)
        for k,v in numbersMap.items():
            numbers[index]=v
            index+=1
        numbers=sorted(numbers, reverse=True)
        quantity=sorted(quantity, reverse=True)
        valid_numbers=0
        while valid_numbers<len(numbers) and numbers[valid_numbers]!=0:
            valid_numbers+=1
        def distribute(start):
            if start>=len(quantity):
                return True
            for j in range(valid_numbers):
                if numbers[j]>=quantity[start]:
                    numbers[j]-=quantity[start]
                    if distribute(start+1):
                        return True
                    numbers[j]+=quantity[start]
            return False
        return distribute(0)
        