class Solution:
    def numSpecial(self, mat: List[List[int]]) -> int:
        answer=0
        for i in range(len(mat)):
            for j in range(len(mat[0])):
                if mat[i][j]==1:
                    if len([x for x in mat[i] if x==1])>1:
                        continue
                    isAnswer=True
                    for k in range(len(mat)):
                        if k!=i and mat[k][j]==1:
                            isAnswer=False
                            continue
                    if isAnswer:
                        answer+=1
        return answer
                    