class Solution:
    def kLengthApart(self, nums: List[int], k: int) -> bool:
        lastOne=-1
        for i in range(len(nums)):
            if nums[i]==1:
                if lastOne>=0 and i-lastOne-1<k:
                    return False
                else:
                    lastOne=i
        return True
        