import queue

class Solution:
    def maxProbability(self, n: int, edges: List[List[int]], succProb: List[float], start: int, end: int) -> float:
        graph={}
        for i in range(len(edges)):
            a,b =edges[i]
            if a not in graph:
                graph[a]=[]
            if b not in graph:
                graph[b]=[]
            graph[a].append((b, succProb[i]))
            graph[b].append((a,succProb[i]))
        prob=[0]*n
        prob[start]=1
        pq=[]
        if start not in graph:
            return 0
        for e in graph[start]:
            heappush(pq, (e[1], (start, e[0])))
        while pq:
            p,vs=heappop(pq)
            if prob[vs[0]]*p>prob[vs[1]]:
                prob[vs[1]]=prob[vs[0]]*p
                for e in graph[vs[1]]:
                    pq.append((e[1], (vs[1], e[0])))
                    #heappush(pq, (e[1], (vs[1], e[0])))
            if prob[vs[1]]*p>prob[vs[0]]:
                prob[vs[0]]=prob[vs[1]]*p
                for e in graph[vs[0]]:
                    pq.append((e[1], (vs[0], e[0])))
                    #heappush(pq, (e[1], (vs[0], e[0])))
        return prob[end]
            
            