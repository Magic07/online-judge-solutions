class Solution:
    def getCircleCenter(self, p1, p2, r)->List[List[int]]:
        (x1, y1)=p1
        (x2, y2)=p2
        d=sqrt((x1-x2)**2+(y1-y2)**2)/2.0
        xm=(x1+x2)/2.0
        ym=(y1+y2)/2.0
        h2=r**2-(x1-xm)**2-(y1-ym)**2
        if(h2<0):
            return []
        h=sqrt(h2)
        dy=(x1-xm)*h/d
        dx=(y1-ym)*h/d
        return [[xm+dx,ym-dy],[xm-dx, ym+dy]]
    
    def countPoints(self, points, c, r)->int:
        answer=0
        for p in points:
            (x,y)=p
            (xc,yc)=c
            if (xc-x)**2+(yc-y)**2<=r**2:
                answer+=1
        return answer
        
    def numPoints(self, points: List[List[int]], r: int) -> int:
        answer=1
        for (x1, y1), (x2, y2) in itertools.combinations(points, 2):
            centers=self.getCircleCenter((x1,y1),(x2,y2),r)
            for c in centers:
                ps=self.countPoints(points, c, r)
                answer=max(answer, ps)
        return answer