class Solution:
    @lru_cache(maxsize=None)
    def isListInterleave(self, i1, i2, i3)->bool:
        if i3==len(self.l3):
            if i1==len(self.l1) and i2==len(self.l2):
                return True
            else:
                return False
        if i1<len(self.l1) and self.l1[i1]==self.l3[i3]:
            if self.isListInterleave(i1+1,i2,i3+1):
                return True
        if i2<len(self.l2) and self.l2[i2]==self.l3[i3]:
            if self.isListInterleave(i1, i2+1, i3+1):
                return True
        return False
        
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        self.l1=list(s1)
        self.l2=list(s2)
        self.l3=list(s3)
        return self.isListInterleave(0,0,0)
        