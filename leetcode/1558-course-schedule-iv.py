import queue

class Solution:
    @lru_cache(maxsize=None)
    def prerequisiteList(self, i):
        if i not in self.pre:
            return []
        answer=[]
        preQueue=queue.Queue()
        for x in self.pre[i]:
            preQueue.put(x)
            answer.append(x)
        while not preQueue.empty():
            current=preQueue.get()
            newPre=self.prerequisiteList(current)
            for y in newPre:
                if y not in answer:
                    answer.append(y)
                    preQueue.put(y)
        return answer
            
    def checkIfPrerequisite(self, n: int, prerequisites: List[List[int]], queries: List[List[int]]) -> List[bool]:
        self.pre={}
        for p in prerequisites:
            if p[1] not in self.pre:
                self.pre[p[1]]=[p[0]]
            else:
                self.pre[p[1]].append(p[0])
        print(self.pre)
        completePre=[None]*n
        for i in range(n):
            completePre[i]=self.prerequisiteList(i)
        print(completePre)
        answer=[]
        for q in queries:
            preOfQ=completePre[q[1]]
            answer.append(q[0] in preOfQ)
        return answer
                
                