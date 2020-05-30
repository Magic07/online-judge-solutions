class Solution:
    def hasAllCodes(self, s: str, k: int) -> bool:
        for i in range(1<<(k+1)-1):
            if ('{0:0'+str(k)+'b}').format(i) not in s:
                return False
        return True