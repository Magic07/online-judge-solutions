class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        answer=0
        u=[0]*len(points)
        unionMap={}
        if len(points)==1:
            return 0
        edges=[]
        for i in range(len(points)):
            u[i]=i
            unionMap[i]=[i]
            for j in range(i+1, len(points)):
                edges.append((abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]), i,j))
        heapq.heapify(edges)
        while len(edges)>0 and len(unionMap)>1:
            (dis, x,y)=heapq.heappop(edges)
            if u[x]==u[y]:
                continue
            toBeMerged=u[y]
            for e in unionMap[u[y]]:
                u[e]=u[x]
                unionMap[u[x]].append(e)
            del unionMap[toBeMerged]
            answer+=dis
        return answer