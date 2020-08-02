class Solution:
    def getWinner(self, arr: List[int], k: int) -> int:
        if k>=len(arr):
            return sorted(arr)[-1]
        answer=0
        win_count=0
        q=collections.deque(arr)
        while win_count<k:
            first=q.popleft()
            second=q.popleft()
            if first>second:
                q.appendleft(first)
                q.append(second)
                win_count+=1
            else:
                q.appendleft(second)
                q.append(first)
                win_count=1
        return q[0]
        