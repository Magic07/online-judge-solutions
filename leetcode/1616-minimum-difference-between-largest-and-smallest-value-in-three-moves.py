class Solution:
    def minDifference(self, nums: List[int]) -> int:
        if len(nums)<=4:
            return 0
        nums=sorted(nums)
        answer=sys.maxsize
        for i in range(4):
            answer=min(answer, nums[i-4]-nums[i])
        return answer