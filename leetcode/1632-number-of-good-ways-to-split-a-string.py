class Solution:
    def numSplits(self, s: str) -> int:
        answer=0
        left=[0]*26
        right=[0]*26
        for x in s:
            right[ord(x)-ord('a')]+=1
        leftNum=0
        rightNum=sum(x > 0 for x in right)
        for x in s:
            index=ord(x)-ord('a')
            if left[index]==0:
                leftNum+=1
            left[index]+=1
            right[index]-=1
            if right[index]==0:
                rightNum-=1
            if leftNum==rightNum:
                answer+=1
        return answer
            
                