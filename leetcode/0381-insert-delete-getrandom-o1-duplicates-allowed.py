class RandomizedCollection:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        # Key is value of data, value is its index in data.
        self.indexes={}
        self.data=[]

    def insert(self, val: int) -> bool:
        """
        Inserts a value to the collection. Returns true if the collection did not already contain the specified element.
        """
        answer=False
        if val not in self.indexes:
            answer=True
            self.indexes[val]=[]
        self.indexes[val].append(len(self.data))
        self.data.append((val,len(self.indexes[val])-1))
        return answer

    def remove(self, val: int) -> bool:
        """
        Removes a value from the collection. Returns true if the collection contained the specified element.
        """
        if val not in self.indexes:
            return False
        index=self.indexes[val][-1]
        if index!=len(self.data)-1:
            self.data[index]=self.data[-1]
            self.indexes[self.data[index][0]][self.data[index][1]]=index
        self.data.pop()
        self.indexes[val].pop()
        if len(self.indexes[val])==0:
            del self.indexes[val]
        return True

    def getRandom(self) -> int:
        """
        Get a random element from the collection.
        """
        return random.choice(self.data)[0]


# Your RandomizedCollection object will be instantiated and called as such:
# obj = RandomizedCollection()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()