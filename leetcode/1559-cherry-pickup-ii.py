class Solution:
    @lru_cache(maxsize=None)
    def cherryPickupFromLine(self, line, r1, r2):
        answer=self.grid[line][r1]
        if r1!=r2:
            answer+=self.grid[line][r2]
        if len(self.grid)==line+1:
            return answer
        picked=0
        for i in range(max(0, r1-1), min(r1+1, len(self.grid[0])-1)+1):
            for j in range(max(0, r2-1), min(r2+1, len(self.grid[0])-1)+1):
                picked=max(picked, self.cherryPickupFromLine(line+1,i,j))
        return answer+picked
        
        
    def cherryPickup(self, grid: List[List[int]]) -> int:
        self.grid=grid
        return self.cherryPickupFromLine(0, 0, len(grid[0])-1)