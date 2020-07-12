class Solution:
    def getMinDistSum(self, positions: List[List[int]]) -> float:
        if len(positions)==1:
            return 0
        def dis(a, b):
            return sqrt((a[0]-b[0])**2+(a[1]-b[1])**2)
        sumX=0
        sumY=0
        sumN=0
        for px,py in positions:
            sumX+=px
            sumY+=py
        cx=sumX/len(positions)
        cy=sumY/len(positions)
        while True:
            snx=0
            sny=0
            sd=0
            for x,y in positions:
                d=dis([x,y], [cx,cy])
                if d==0:
                    continue
                snx+=x/d
                sny+=y/d
                sd+=1/d
            if sd==0:
                break
            ncx=snx/sd
            ncy=sny/sd
            if abs(ncx-cx)<0.0000001 and abs(ncy-cy)<0.0000001:
                break
            cx=ncx
            cy=ncy
        answer=0
        for p in positions:
            answer+=dis(p, [cx,cy])
        return answer
    
# Ref: Weiszfeld's algorithm.
