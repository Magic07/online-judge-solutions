class Solution:
    def closestToTarget(self, arr: List[int], target: int) -> int:
        answer=sys.maxsize
        for i in range(len(arr)):
            func=1048575
            for j in range(i, len(arr)):
                func&=arr[j]
                answer=min(answer, abs(func-target))
                if func<target:
                    break
            if func>target:
                break
        return answer