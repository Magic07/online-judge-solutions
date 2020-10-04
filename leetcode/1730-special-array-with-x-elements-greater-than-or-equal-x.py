class Solution:
    def specialArray(self, nums: List[int]) -> int:
        nums=sorted(nums)
        last=-1
        for i in range(len(nums)):
            if nums[i]==last:
                continue
            if len(nums)-i<=nums[i] and len(nums)-i>last:
                return len(nums)-i
            last=nums[i]
        return -1