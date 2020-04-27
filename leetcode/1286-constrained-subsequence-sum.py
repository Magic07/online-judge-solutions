class Solution:
    def constrainedSubsetSum(self, nums: List[int], k: int) -> int:
        answer=max(nums)
        if(answer<=0):
            return answer
        maxSum=[0]*len(nums)
        maxQueue = collections.deque()
        maxSum[0]=nums[0]
        maxQueue.append(maxSum[0])
        for i in range(1, len(nums)):
            maxSum[i]=max(0,maxQueue[0])+nums[i]
            while len(maxQueue) and maxQueue[-1]<maxSum[i]:
                maxQueue.pop()
            maxQueue.append(maxSum[i])
            if i>=k and len(maxQueue)>0 and maxQueue[0]==maxSum[i-k]:
                maxQueue.popleft()
        return max(maxSum)