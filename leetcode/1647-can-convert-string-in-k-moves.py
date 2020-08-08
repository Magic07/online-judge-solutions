class Solution:
    def canConvertString(self, s: str, t: str, k: int) -> bool:
        if len(s)!=len(t):
            return False
        steps=[0]*26
        for i in range(26):
            steps[i]=i
        for i in range(len(s)):
            if t[i]==s[i]:
                continue
            diff=ord(t[i])-ord(s[i])
            if diff<0:
                diff+=26
            if steps[diff]>k:
                return False
            steps[diff]+=26
        return True