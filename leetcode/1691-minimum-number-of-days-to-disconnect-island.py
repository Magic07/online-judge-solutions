class Solution:
    def minDays(self, grid: List[List[int]]) -> int:
        ones=0
        for x in grid:
            for y in x:
                if y==1:
                    ones+=1
        if ones==0:
            return 0
        if ones==1:
            return 1
        def visitOne(startPoint):
            visited=[[False for i in range(len(grid[0]))] for j in range(len(grid))]
            answer=0
            q=deque()
            q.appendleft(startPoint)
            while len(q)!=0:
                [row, col]=q.pop()
                if visited[row][col]:
                    continue
                visited[row][col]=True
                answer+=1
                if row!=0 and grid[row-1][col]==1 and visited[row-1][col]==False:
                    q.appendleft([row-1,col])
                if row!=len(grid)-1 and grid[row+1][col]==1 and visited[row+1][col]==False:
                    q.appendleft([row+1,col])
                if col!=0 and grid[row][col-1]==1 and visited[row][col-1]==False:
                    q.appendleft([row,col-1])
                if col!=len(grid[0])-1 and grid[row][col+1]==1 and visited[row][col+1]==False:
                    q.appendleft([row,col+1])
            return answer
        def firstOne():
            for r in range(len(grid)):
                for c in range(len(grid[0])):
                    if grid[r][c]==1:
                        return [r,c]
            return None
        fo=firstOne()
        if fo==None:
            return 0
        if visitOne(fo)!=ones:
            return 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j]==1:
                    grid[i][j]=0
                    fo=firstOne()
                    if visitOne(fo)!=ones-1:
                        return 1
                    grid[i][j]=1
        return 2
