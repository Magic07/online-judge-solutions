class Solution:
    def minimumEffortPath(self, heights: List[List[int]]) -> int:
        effort=[[sys.maxsize for i in range(len(heights[0]))] for i in range(len(heights))]
        q=deque()
        q.appendleft((0,0,0))
        effort[0][0]=0
        while len(q)>0:
            row, col, last=q.pop()
            thisEffort=effort[row][col]
            if row>0 and last!=1:
                diff=max(abs(heights[row][col]-heights[row-1][col]), thisEffort)
                if effort[row-1][col]>diff:
                    effort[row-1][col]=diff
                    q.appendleft((row-1,col, 2))
            if row<len(heights)-1 and last!=2:
                diff=max(abs(heights[row][col]-heights[row+1][col]), thisEffort)
                if effort[row+1][col]>diff:
                    effort[row+1][col]=diff
                    q.appendleft((row+1,col,1))
            if col>0 and last!=3:
                diff=max(abs(heights[row][col]-heights[row][col-1]), thisEffort)
                if effort[row][col-1]>diff:
                    effort[row][col-1]=diff
                    q.appendleft((row,col-1,4))
            if col<len(heights[0])-1 and last!=4:
                diff=max(abs(heights[row][col]-heights[row][col+1]), thisEffort)
                if effort[row][col+1]>diff:
                    effort[row][col+1]=diff
                    q.appendleft((row,col+1,3))
        return effort[len(heights)-1][len(heights[0])-1]