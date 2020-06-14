class Solution:
    def runningSum(self, nums: List[int]) -> List[int]:
        s=0
        answer=[0]*len(nums)
        for i in range(len(nums)):
            s+=nums[i]
            answer[i]=s
        return answer