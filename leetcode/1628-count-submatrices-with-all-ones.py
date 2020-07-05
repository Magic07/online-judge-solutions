class Solution:
    def numSubmat(self, mat: List[List[int]]) -> int:
        answer=0
        for r in range(len(mat)):
            for c in range(len(mat[0])):
                maxW=len(mat[0])-c
                for h in range(len(mat)-r):
                    if mat[r+h][c]==0:
                        break
                    for w in range(maxW):
                        if mat[r+h][w+c]==1:
                            answer+=1
                        else:
                            maxW=w
                            break
        return answer