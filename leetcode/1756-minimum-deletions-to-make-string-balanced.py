class Solution:
    def minimumDeletions(self, s: str) -> int:
        answer=sys.maxsize
        hasa=0
        hasb=0
        numa=[0]*len(s)
        numb=[0]*len(s)
        for i in range(len(s)):
            numb[i]=hasb
            if s[i]=='b':
                hasb+=1
        for i in range(len(s)-1,-1,-1):
            numa[i]=hasa
            if s[i]=='a':
                hasa+=1
        for i in range(len(s)):
            answer=min(answer,numa[i]+numb[i])
        return answer