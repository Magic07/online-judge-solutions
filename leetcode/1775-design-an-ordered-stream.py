class OrderedStream:

    def __init__(self, n: int):
        self.data=[None]*n
        self.ptr=0

    def insert(self, id: int, value: str) -> List[str]:
        self.data[id-1]=value
        self.old_ptr=self.ptr
        while self.ptr<len(self.data) and self.data[self.ptr]:
            self.ptr+=1
        return self.data[self.old_ptr:self.ptr]


# Your OrderedStream object will be instantiated and called as such:
# obj = OrderedStream(n)
# param_1 = obj.insert(id,value)