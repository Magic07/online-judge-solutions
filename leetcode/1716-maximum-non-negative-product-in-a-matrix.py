class Solution:
    def maxProductPath(self, grid: List[List[int]]) -> int:
        @lru_cache(None)
        def productPath(product, row, col):
            if row==(len(grid)-1) and col==(len(grid[0])-1):
                return product*grid[row][col]
            answer=-1
            if row>=len(grid) or col>=len(grid[0]):
                return answer
            answer=product*grid[row][col]
            if answer==0:
                return 0
            return max(productPath(answer, row+1,col), productPath(answer, row, col+1))
        answer=productPath(1, 0,0)
        if answer==-1:
            return -1
        return answer%1000000007