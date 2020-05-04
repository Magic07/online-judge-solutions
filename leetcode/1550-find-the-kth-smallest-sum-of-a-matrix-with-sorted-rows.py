class Solution:
    def smallerSum(self, mat:List[List[int]], k: int, row: int, num: int, s: int)->int:
        if row==len(mat):
            return 1
        answer=0
        for i in range(len(mat[0])):
            if s+mat[row][i]<=num:
                answer+=self.smallerSum(mat, k, row+1, num, s+mat[row][i])
                if answer==0:
                    return answer
                if answer>k:
                    return answer
        return answer
        
    def kthSmallest(self, mat: List[List[int]], k: int) -> int:
        low=len(mat)
        high=len(mat)*5000
        mid=low+(high-low)/2
        while low<=high:
            smallerCount=self.smallerSum(mat,k,0,mid,0)
            if smallerCount>=k:
                high=floor(mid)-1
            else:
                low=floor(mid)+1
            mid=low+(high-low)/2
        return high+1