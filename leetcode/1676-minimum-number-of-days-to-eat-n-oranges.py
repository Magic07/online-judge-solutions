class Solution:
    def minDays(self, n: int) -> int:
        @lru_cache(None)
        def md(n):
            if n==0:
                return 0
            answer=sys.maxsize
            if n%3==0:
                answer=min(answer, md(n//3)+1)
            if n%2==0:
                answer=min(answer, md(n//2)+1)
            r=n-(n//2)*2+1
            answer=min(answer, md(n//2)+r)
            r=n-(n//3)*3+1
            answer=min(answer, md(n//3)+r)
            return answer
        return md(n)-1