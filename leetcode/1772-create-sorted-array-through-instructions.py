class Solution:
    def createSortedArray(self, instructions: List[int]) -> int:
        bit=[0]*(max(instructions)+1)
        
        def query(x):
            answer=0
            while x>0:
                answer+=bit[x]
                x-=x&-x
            return answer
        
        def add(x):
            while x<len(bit):
                bit[x]+=1
                x+=x&-x
        
        cost=0
        added=0
        for x in instructions:
            cost+=min(query(x-1), added-query(x))
            add(x)
            added+=1
        return cost%1000000007