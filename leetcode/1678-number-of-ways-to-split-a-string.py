class Solution:
    def numWays(self, s: str) -> int:
        numOf1s=0
        for x in s:
            if x=='1':
                numOf1s+=1
        if numOf1s==0:
            return comb(len(s)-1,2)%1000000007
        if numOf1s%3!=0:
            return 0
        zero1=0
        zero2=0
        index1=0
        for x in s:
            if x=='1':
                index1+=1
                continue
            if index1==numOf1s/3:
                zero1+=1
                continue
            if index1==2*numOf1s/3:
                zero2+=1
        return (zero1+1)*(zero2+1)%1000000007