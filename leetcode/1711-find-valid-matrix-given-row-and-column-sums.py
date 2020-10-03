class Solution:
    def restoreMatrix(self, rowSum: List[int], colSum: List[int]) -> List[List[int]]:
        answer=[[0]*len(colSum) for x in range(len(rowSum))]
        for r in range(len(rowSum)):
            for c in range(len(colSum)):
                answer[r][c]=min(rowSum[r], colSum[c])
                rowSum[r]-=answer[r][c]
                colSum[c]-=answer[r][c]
                if rowSum[r]==0:
                    break
        return answer