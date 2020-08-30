class Solution:
    def getMaxLen(self, nums: List[int]) -> int:
        def maxLen(nums):
            positive=0
            negative=0
            firstNegative=len(nums)
            lastNegative=0
            for i in range(len(nums)):
                x=nums[i]
                if x>0:
                    positive+=1
                else:
                    negative+=1
                    firstNegative=min(firstNegative, i)
                    lastNegative=max(lastNegative, i)
            if negative%2==0:
                return len(nums)
            else:
                offset=min(firstNegative+1, len(nums)-lastNegative)
                return len(nums)-offset
        answer=0
        lastZero=-1
        for i in range(len(nums)):
            if nums[i]!=0:
                continue
            if i>lastZero+1:
                answer=max(answer, maxLen(nums[lastZero+1:i]))
            lastZero=i
        if lastZero!=len(nums)-1:
            answer=max(answer, maxLen(nums[lastZero+1:]))
        return answer
            
                