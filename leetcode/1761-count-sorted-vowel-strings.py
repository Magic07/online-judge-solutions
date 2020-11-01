class Solution:
    def countVowelStrings(self, n: int) -> int:
        @lru_cache(None)
        def count(n, start):
            if n<=0 or start>4:
                return 0
            if n==1:
                return 5-start
            answer=0
            for i in range(start, 5):
                answer+=count(n-1, i)
            return answer
        return count(n, 0)
            