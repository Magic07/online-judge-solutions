class Solution:
    def waysToMakeFair(self, nums: List[int]) -> int:
        odd=[0]*len(nums)
        even=[0]*len(nums)
        for i in range(len(nums)):
            odd[i]=odd[i-1]
            even[i]=even[i-1]
            if i%2:
                odd[i]+=nums[i]
            else:
                even[i]+=nums[i]
        answer=0
        oddSum=odd[-1]
        evenSum=even[-1]
        if oddSum==evenSum-nums[0]:
            answer+=1
        for i in range(1,len(nums)):
            if oddSum-odd[i]+even[i-1]==evenSum-even[i]+odd[i-1]:
                answer+=1
        return answer