class Solution:
    def minFlips(self, target: str) -> int:
        answer=0
        last='0'
        for x in target:
            if x!=last:
                answer+=1
                last=x
        return answer
            