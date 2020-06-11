class Solution:
    @lru_cache(maxsize=None)
    def minInsertionsInternal(self, start, end):
        middle=(end-start+1)//2
        current=0
        while current<=middle and self.s[current+start]==self.s[end-current]:
            current+=1
        if current==middle+1:
            return 0
        return min(self.minInsertionsInternal(start+current+1,end-current), self.minInsertionsInternal(start+current, end-current-1))+1
            
    
    def minInsertions(self, s: str) -> int:
        self.s=s
        return self.minInsertionsInternal(0, len(s)-1)