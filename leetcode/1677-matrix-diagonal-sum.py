class Solution:
    def diagonalSum(self, mat: List[List[int]]) -> int:
        answer=0
        for i in range(len(mat)):
            answer+=mat[i][i]
            j=len(mat)-i-1
            if j!=i:
                answer+=mat[i][j]
        return answer