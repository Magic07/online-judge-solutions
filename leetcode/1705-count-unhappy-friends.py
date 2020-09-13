class Solution:
    def unhappyFriends(self, n: int, preferences: List[List[int]], pairs: List[List[int]]) -> int:
        p=[-1]*n
        for [x,y] in pairs:
            p[x]=y
            p[y]=x
        answer=0
        for i in range(len(preferences)):
            iIsHappy=True
            for j in preferences[i]:
                if j==p[i]:
                    break
                for k in preferences[j]:
                    if k==p[j]:
                        break
                    if k==i:
                        iIsHappy=False
                        break
                if not iIsHappy:
                    break
            if not iIsHappy:
                answer+=1
        return answer