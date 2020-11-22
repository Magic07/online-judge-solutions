class Solution:
    def minimumEffort(self, tasks: List[List[int]]) -> int:
        tasks.sort(key=lambda x: x[1]-x[0])
        answer=0
        for actual, req in tasks:
            answer=max(answer+actual,req)
        return answer