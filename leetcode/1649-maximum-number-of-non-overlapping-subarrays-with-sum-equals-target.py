class Solution:
    def maxNonOverlapping(self, nums: List[int], target: int) -> int:
        pre=0
        preSumMax=0
        answer=0
        for i in range(len(nums)):
            s=0
            if preSumMax+nums[i]<target:
                pre+=1
                preSumMax+=nums[i]
                preSumMax=max(0, preSumMax)
                continue
            found=False
            for j in range(pre+1):
                s+=nums[i-j]
                if s==target:
                    pre=0
                    found=True
                    break
            if found:
                pre=0
                answer+=1
                preSumMax=0
            else:
                pre+=1
                preSumMax+=nums[i]
                preSumMax=max(0, preSumMax)
        return answer