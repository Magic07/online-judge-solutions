class Solution:
    def minSubarray(self, nums: List[int], p: int) -> int:
        s=sum(nums)
        if s%p==0:
            return 0
        s%=p
        lastRemainder={0: -1}
        currentSum=0
        answer=sys.maxsize
        for i in range(len(nums)):
            currentSum+=nums[i]
            need=(currentSum-s)%p
            if need in lastRemainder: 
                answer= min(answer, i-lastRemainder[need])
            lastRemainder[currentSum%p]=i
        return -1 if answer>=len(nums) else answer