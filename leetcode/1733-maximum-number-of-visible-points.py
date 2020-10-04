class Solution:
    def visiblePoints(self, points: List[List[int]], angle: int, location: List[int]) -> int:
        directions=[0]*len(points)
        (x,y)=location
        for i in range(len(points)):
            xp,yp=points[i]
            if xp==x and yp==y:
                directions[i]=-100
                continue
            directions[i]=math.atan2(yp-y, xp-x)
        directions=sorted(directions)
        angle=math.radians(angle)
        directions+=[x+2*math.pi for x in directions if x!=-100]
        alwaysSee=0
        lastSee=0
        maxSee=0
        for i in range(len(directions)):
            if directions[i]==-100:
                alwaysSee+=1
                lastSee+=1
                continue
            while directions[i]-directions[lastSee]>angle:
                lastSee+=1
            maxSee=max(maxSee, i-lastSee+1)
        return alwaysSee+maxSee
                
            