class Solution:
    def minSwaps(self, grid: List[List[int]]) -> int:
        lastOne=[0]*len(grid)
        for i in range(len(grid)):
            for j in range(len(grid[0])-1,-1,-1):
                if grid[i][j]==1:
                    lastOne[i]=j
                    break
        print(lastOne)
        def swapRow(r1, r2)->int:
            s=0
            for i in range(r2, r1, -1):
                grid[i], grid[i-1]=grid[i-1], grid[i]
                lastOne[i], lastOne[i-1]=lastOne[i-1], lastOne[i]
                s+=1
            return s
        answer=0
        for i in range(len(grid)):
            if lastOne[i]<=i:
                continue
            j=i+1
            while j<len(grid):
                if lastOne[j]<=i:
                    break
                j+=1
            if j>=len(grid):
                return -1
            answer+=swapRow(i,j)
        return answer
            
                    