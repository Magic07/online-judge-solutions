class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        @lru_cache(maxsize=None)
        def distinct(si: int, ti: int)->int:
            if ti==len(t):
                return 1
            if len(s)-si<len(t)-ti:
                return 0
            answer=0
            if s[si]==t[ti]:
                answer+=distinct(si+1, ti+1)
                answer+=distinct(si+1, ti)
            else:
                answer+=distinct(si+1,ti)
            return answer

        return distinct(0,0)