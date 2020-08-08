class RangeModule:

    def __init__(self):
        self.ranges=[]

    def addRange(self, left: int, right: int) -> None:
        #print('add range '+str(left)+', '+str(right))
        index=bisect_left(self.ranges, [left, right])
        end=index
        while end<len(self.ranges):
            if self.ranges[end][0]>right:
                break
            right=max(right, self.ranges[end][1])
            end+=1
        if index>0 and self.ranges[index-1][1]>=left:
            if self.ranges[index-1][1]>=right:
                return
            index-=1
            left=self.ranges[index][0]
        del self.ranges[index:end]
        self.ranges.insert(index, [left, right])
        #print(self.ranges)

    def queryRange(self, left: int, right: int) -> bool:
        #print('query range '+str(left)+', '+str(right))
        #print(self.ranges)
        index=bisect_right(self.ranges, [left, 1000000000])
        if index>0 and self.ranges[index-1][0]<=left and self.ranges[index-1][1]>=right:
            return True
        return False

    def removeRange(self, left: int, right: int) -> None:
        #print('remove range '+str(left)+', '+str(right))
        index=bisect_left(self.ranges, [left, left])
        #print('index='+str(index))
        if index>0 and self.ranges[index-1][1]>left:
            if self.ranges[index-1][1]>right:
                self.ranges.insert(index,[right, self.ranges[index-1][1]])
            self.ranges[index-1][1]=left
        if index==len(self.ranges) or self.ranges[index][0]>=right:
            return
        end=index
        while end<len(self.ranges):
            if self.ranges[end][1]>=right:
                self.ranges[end][0]=max(right, self.ranges[end][0])
                break
            end+=1
        #print('del '+str(end))
        del self.ranges[index:end]
        #print(self.ranges)

# Your RangeModule object will be instantiated and called as such:
# obj = RangeModule()
# obj.addRange(left,right)
# param_2 = obj.queryRange(left,right)
# obj.removeRange(left,right)