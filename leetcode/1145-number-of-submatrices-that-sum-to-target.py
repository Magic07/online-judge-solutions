class Solution:
    def numSubmatrixSumTarget(self, matrix: List[List[int]], target: int) -> int:
        for m in matrix:
            for i in range(1, len(matrix[0])):
                m[i]+=m[i-1]
        answer=0
        for i in range(len(matrix[0])):
            for j in range(i, len(matrix[0])):
                sumAbove=0
                counter={0:1}
                for k in range(len(matrix)):
                    sumAbove+=matrix[k][j]
                    if i>0:
                        sumAbove-=matrix[k][i-1]
                    if sumAbove-target in counter:
                        answer+=counter[sumAbove-target]
                    if sumAbove not in counter:
                        counter[sumAbove]=0
                    counter[sumAbove]+=1
        return answer
                

# Ref: https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/discuss/303750/JavaC%2B%2BPython-Find-the-Subarray-with-Target-Sum