class Solution:
    def getLengthOfOptimalCompression(self, s: str, k: int) -> int:
        @lru_cache(maxsize=None)
        def compress(index, last, lastCount, left):
            if left<0:
                return sys.maxsize
            if index>=len(s):
                return 0
            if s[index]==last:
                if lastCount==1 or lastCount==9 or lastCount==99:
                    return 1+compress(index+1, last, lastCount+1, left)
                return compress(index+1, last, lastCount+1, left)
            return min(1+compress(index+1, s[index], 1, left), compress(index+1, last, lastCount, left-1))
        return compress(0, '', 0, k)
            
# Ref: https://leetcode.com/problems/string-compression-ii/discuss/755970/Python-dynamic-programming