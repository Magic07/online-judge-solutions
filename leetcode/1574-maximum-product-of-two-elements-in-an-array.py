class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        nums=sorted(nums)
        n=len(nums)
        return (nums[n-2]-1)*(nums[n-1]-1)