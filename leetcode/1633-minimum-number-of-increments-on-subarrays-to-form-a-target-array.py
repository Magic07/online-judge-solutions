class Solution:
    def minNumberOperations(self, target: List[int]) -> int:
        answer=0
        last=0
        for x in target:
            answer+=max(x-last,0)
            last=x
        return answer