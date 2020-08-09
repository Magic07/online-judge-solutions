class Solution:
    def longestAwesome(self, s: str) -> int:
        bitmask=0
        first_seen=[sys.maxsize]*1024
        first_seen[0]=-1
        bm=[0]*len(s)
        answer=1
        for i in range(len(s)):
            bitmask^=1<<(ord(s[i])-48)
            first_seen[bitmask]=min(first_seen[bitmask],i)
            bm[i]=bitmask
        print(bm)
        for i in range(len(s)-1,0,-1):
            if i<answer:
                return answer
            current=bm[i]
            answer=max(answer, i-first_seen[bm[i]])
            for j in range(10):
                current^=1<<j
                answer=max(answer, i-first_seen[current])
                current^=1<<j;
        return answer
