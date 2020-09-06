class Solution:
    def modifyString(self, s: str) -> str:
        sl=list(s)
        for i in range(len(sl)):
            if sl[i]=='?':
                if i==0 or sl[i-1]!='a':
                    sl[i]='a'
                else:
                    sl[i]='b'
                if i!=len(sl)-1 and sl[i+1]==sl[i]:
                    sl[i]='c'
        return ''.join(sl)