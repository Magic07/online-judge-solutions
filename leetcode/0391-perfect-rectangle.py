class Solution:
    def isRectangleCover(self, rectangles: List[List[int]]) -> bool:
        points={}
        for r in rectangles:
            vs=[tuple(r[:2]), (r[2],r[1]), tuple(r[2:]), (r[0],r[3])]
            for i in range(len(vs)):
                v=vs[i]
                if v not in points:
                    points[v]=[False]*4
                if points[v][i]:
                    return False
                points[v][i]=True
        singleDirection=0
        for k,v in points.items():
            quadrant=sum(x for x in v if x==True)
            if quadrant==1:
                singleDirection+=1
            elif quadrant==2 and v[0]==v[2]:
                return False
            elif quadrant==3:
                return False
        if singleDirection==4:
            return True
        return False