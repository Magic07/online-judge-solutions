class Solution:
    def minDeletions(self, s: str) -> int:
        nums=[0]*26
        for i in range(len(s)):
            nums[ord(s[i])-ord('a')]+=1
        nums=sorted(nums, reverse=True)
        answer=0
        for i in range(1,26):
            if nums[i]==0:
                return answer
            while nums[i]>=nums[i-1] and nums[i]!=0:
                nums[i]-=1
                answer+=1
        return answer