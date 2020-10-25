class Solution:
    def checkArithmeticSubarrays(self, nums: List[int], l: List[int], r: List[int]) -> List[bool]:
        answer=[False]*len(l)
        
        def isArithmeticSubarrays(i):
            subArray=sorted(nums[l[i]:r[i]+1])
            if len(subArray)<=2:
                return True
            for i in range(2,len(subArray)):
                if subArray[i]-subArray[i-1]!=subArray[i-1]-subArray[i-2]:
                    return False
            return True
        
        for i in range(len(answer)):
            answer[i]=isArithmeticSubarrays(i)
        return answer