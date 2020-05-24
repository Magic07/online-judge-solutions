class Solution:
    def maxDotProduct(self, nums1: List[int], nums2: List[int]) -> int:
        self.nums1=nums1
        self.nums2=nums2
        maxNums1=max(nums1)
        minNums1=min(nums1)
        maxNums2=max(nums2)
        minNums2=min(nums2)
        if maxNums1<0 and minNums2>0:
            return maxNums1*minNums2
        if maxNums2<0 and minNums1>0:
            return maxNums2*minNums1
        dp=[x[:] for x in [[0] * (len(nums1)+1)] * (len(nums2)+1)]
        for i in range(len(nums1)):
            for j in range(len(nums2)):
                dp[j+1][i+1]=max(dp[j][i], dp[j+1][i], dp[j][i+1], dp[j][i]+nums1[i]*nums2[j])
        return dp[len(nums2)][len(nums1)]