class Solution:
    def numSub(self, s: str) -> int:
        def numOf1(n):
            return int((1+n)*n/2)
        answer=0
        one=0
        for i in range(len(s)):
            if s[i]=='1':
                one+=1
            elif one!=0:
                answer+=numOf1(one)
                one=0
        if one!=0:
            answer+=numOf1(one)
        return answer%1000000007
            