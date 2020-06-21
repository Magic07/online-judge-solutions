import queue

class Solution:
    def mst(self, n, edges, skip, use):
        w=0
        cluster={}
        visited=[0]*n
        for x in range(n):
            cluster[x]=[x]
            visited[x]=x
        pq=queue.PriorityQueue(len(edges))
        criticalPaths=[]
        for i in range(len(edges)):
            if i!=skip and i!=use:
                e=edges[i]
                pq.put((e[2],e))
        def merge(e):
            global weight
            if visited[e[0]]!=visited[e[1]]:
                oldE1=visited[e[1]]
                for v in cluster[visited[e[1]]]:
                    visited[v]=visited[e[0]]
                    cluster[visited[e[0]]].append(v)
                del cluster[oldE1]
                return e[2]
            return 0
        if use>=0:
            merge(edges[use])
            w+=edges[use][2]
        while pq.qsize()>0:
            e=pq.get()[1]
            w+=merge(e)
        return w
                
        
    def findCriticalAndPseudoCriticalEdges(self, n: int, edges: List[List[int]]) -> List[List[int]]:
        wOfMst=self.mst(n, edges,-1, -1)
        criticalEdges=[]
        nonCriticalEdges=[]
        for i in range(len(edges)):
            currentW=self.mst(n, edges, i,-1)
            if currentW!=wOfMst:
                criticalEdges.append(i)
            elif self.mst(n, edges, -1, i)==wOfMst: 
                nonCriticalEdges.append(i)
        return [criticalEdges,nonCriticalEdges]