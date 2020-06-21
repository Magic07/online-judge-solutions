class Solution:
    def xorOperation(self, n: int, start: int) -> int:
        answer=start
        for i in range(1,n):
            answer=answer^(start+2*i)
        return answer
        
        