class Solution:
    def longestSubarray(self, nums: List[int], limit: int) -> int:
        answer=1
        for i in range(len(nums)):
            if(len(nums)-i<=answer):
                return answer
            low=nums[i]
            high=nums[i]
            for j in range(i+1, len(nums)):
                low=min(low, nums[j])
                high=max(high,nums[j])
                if high-low>limit:
                    answer=max(answer, j-i)
                    break
                else:
                    answer=max(answer, j-i+1)
        return answer