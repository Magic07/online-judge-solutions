import queue

class Solution:
    def fixOrder(self, root, parent):
        answer=0
        if root in self.rr:
            for x in self.rr[root]:
                if x!=parent:
                    answer+=self.fixOrder(x, root)
        if root in self.roads:
            for x in self.roads[root]:
                if x!=parent:
                    answer+=1
                    answer+=self.fixOrder(x, root)
        return answer
    def minReorder(self, n: int, connections: List[List[int]]) -> int:
        checked=[False]*n
        roads={}
        rr={}
        for c in connections:
            if c[0] not in roads:
                roads[c[0]]=[c[1]]
            else:
                roads[c[0]].append(c[1])
            if c[1] not in rr:
                rr[c[1]]=[c[0]]
            else:
                rr[c[1]].append(c[0])
        self.roads=roads
        self.rr=rr
        return self.fixOrder(0,-1)