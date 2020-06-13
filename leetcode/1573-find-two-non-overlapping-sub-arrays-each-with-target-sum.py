class Solution:
    def minSumOfLengths(self, arr: List[int], target: int) -> int:
        start=0
        current=0
        currentSum=0
        subArrays=[]
        for i in range(len(arr)):
            currentSum+=arr[i]
            while currentSum>target:
                currentSum-=arr[start]
                start+=1
            if currentSum==target:
                subArrays.append((i-start+1,start))
        if len(subArrays)<2:
            return -1
        subArrays=sorted(subArrays)
        answer=subArrays[0][0]
        for x in subArrays[1:]:
            if x[1]+x[0]-1<subArrays[0][1] or x[1]>subArrays[0][0]+subArrays[0][1]-1:
                answer+=x[0]
                return answer
        return -1