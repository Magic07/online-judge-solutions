class Solution:
    def getMaximumGenerated(self, n: int) -> int:
        nums=[0]*105
        nums[1]=1
        for i in range(1, 51):
            nums[i*2]=nums[i]
            nums[i*2+1]=nums[i]+nums[i+1]
        return max(nums[:n+1])
            
        