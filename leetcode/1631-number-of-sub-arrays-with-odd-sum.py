class Solution:
    def numOfSubarrays(self, arr: List[int]) -> int:
        answer=0
        numOdd=0
        numEven=0
        for x in arr:
            if x%2:
                numOdd, numEven=numEven+1, numOdd
            else:
                numEven+=1
            answer+=numOdd
        return answer%1000000007
                