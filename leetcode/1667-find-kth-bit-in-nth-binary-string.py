class Solution:
    def findKthBit(self, n: int, k: int) -> str:
        s='0'
        def invert(s):
            copys=list(copy.deepcopy(s))
            for i in range(len(s)):
                if s[i]=='1':
                    copys[i]='0'
                else:
                    copys[i]='1'
            return ''.join(copys)
        for i in range(n):
            s=s+'1'+''.join(reversed(invert(s)))
        return s[k-1]
            