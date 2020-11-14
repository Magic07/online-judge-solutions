class Solution:
    def decrypt(self, code: List[int], k: int) -> List[int]:
        answer=[0]*len(code)
        if k==0:
            return answer
        for i in range(len(code)):
            if k>0:
                for j in range(1,k+1):
                    answer[i]+=code[(j+i)%len(code)]
            else:
                for j in range(-1, k-1, -1):
                    answer[i]+=code[(j+i)%len(code)]
        return answer