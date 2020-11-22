class Solution:
    def getSmallestString(self, n: int, k: int) -> str:
        sa=[1]*n
        for i in range(n-1, -1,-1):
            sa[i]=min(k-i,26)
            k-=sa[i]
        print(sa)
        answer=''
        for x in sa:
            answer+=chr(ord('a')+x-1)
        return answer
        