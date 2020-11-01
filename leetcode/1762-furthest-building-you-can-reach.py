class Solution:
    def furthestBuilding(self, heights: List[int], bricks: int, ladders: int) -> int:
        diff=[0]*len(heights)
        for i in range(1,len(heights)):
            diff[i]=max(0, heights[i]-heights[i-1])
        answer=0
        reached=-1
        queue=[]
        while ladders>=0 or bricks>=0:
            while reached<len(heights)-1 and diff[reached+1]<=bricks:
                heapq.heappush(queue, -diff[reached+1])
                bricks-=diff[reached+1]
                reached+=1
            if reached==len(heights)-1:
                return reached
            if ladders==0:
                return reached
            highest=(-heapq.heappop(queue))
            if highest>diff[reached]:
                bricks+=bricks
            ladders-=1
            reached+=1
        return max(0,reached)
        