class Solution:
    def maxDistance(self, position: List[int], m: int) -> int:
        position=sorted(position)
        dis=position[-1]-position[0]
        if m==2:
            return position[-1]-position[0]
        low=1
        high=dis
        
        def validInterval(interval):
            n=m-1
            i=0
            while n>0:
                j=i
                while j<len(position)-1 and position[j]-position[i]<interval:
                    j+=1
                if position[j]-position[i]<interval:
                    return False
                i=j
                n-=1
            return True
        
        while low!=high:
            mid=(high+low)//2
            if mid==low:
                mid+=1
            if validInterval(mid):
                low=mid
            else:
                high=mid-1
        return high