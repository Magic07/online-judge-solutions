class Fancy:

    def __init__(self):
        self.data=[]
        self.add=[]
        self.mult=[]

    def append(self, val: int) -> None:
        self.data.append(val)
        if len(self.mult)==0:
            self.mult.append(1)
            self.add.append(0)
        self.mult.append(self.mult[-1])
        self.add.append(self.add[-1])

    def addAll(self, inc: int) -> None:
        if len(self.data)==0:
            return
        self.add[-1]+=inc

    def multAll(self, m: int) -> None:
        if len(self.data)==0:
            return
        self.mult[-1]*=m
        self.add[-1]*=m

    def getIndex(self, idx: int) -> int:
        if idx>=len(self.data):
            return -1
        m=self.mult[-1]//self.mult[idx]
        inc=self.add[-1]-self.add[idx]*m
        return (self.data[idx]*m+inc)%1000000007


# Your Fancy object will be instantiated and called as such:
# obj = Fancy()
# obj.append(val)
# obj.addAll(inc)
# obj.multAll(m)
# param_4 = obj.getIndex(idx)

# Ref: https://leetcode.com/problems/fancy-sequence/discuss/898753/Python-Time-O(1)-for-each