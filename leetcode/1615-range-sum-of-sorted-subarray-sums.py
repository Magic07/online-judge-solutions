class Solution:
    def rangeSum(self, nums: List[int], n: int, left: int, right: int) -> int:
        sumList=[[] for i in range(n)]
        for i in range(n):
            sumList[i].append(nums[i])
            for j in range(i):
                sumList[j].append(sumList[j][-1]+nums[i])
        for i in range(1,n):
            sumList[0].extend(sumList[i])
        sums=sumList[0]
        sums=sorted(sums)
        return sum(sums[left-1: right])%1000000007
        