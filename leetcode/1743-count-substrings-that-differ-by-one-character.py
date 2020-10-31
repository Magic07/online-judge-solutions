class Solution:
    def countSubstrings(self, s: str, t: str) -> int:
        answer=0
        if len(s)>len(t):
            s,t=t,s
        def isOneCharDiff(s,si,t,ti,length):
            diff=0
            for i in range(length):
                if s[si+i]!=t[ti+i]:
                    diff+=1
                    if diff>1:
                        return False
            if diff==1:
                return True
            return False
        for length in range(1, len(s)+1):
            for s_start in range(len(s)-length+1):
                for t_start in range(len(t)-length+1):
                    if isOneCharDiff(s,s_start,t,t_start,length):
                        answer+=1
        return answer