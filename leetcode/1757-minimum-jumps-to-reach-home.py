class Solution:
    def minimumJumps(self, forbidden: List[int], a: int, b: int, x: int) -> int:
        steps=[[1000000,False,False] for _ in range(8001)]
        steps[0]=[0,False,False]
        for y in forbidden:
            steps[y][0]=-1
        q=deque()
        q.append((0,True))
        max_current=0
        while len(q)>0:
            current, back=q.popleft()
            val, forward, backward=steps[current]
            if current==x:
                return val
            if current+a<=8000 and steps[current+a][0]!=-1 and val+1<=steps[current+a][0] and not forward:
                steps[current+a][0]=val+1
                steps[current][1]=True
                q.append((current+a, True))
            if back and current-b>=0 and steps[current-b][0]!=-1 and val+1<=steps[current-b][0] and not backward:
                steps[current-b][0]=val+1
                q.append((current-b, False))
        return -1
        
        