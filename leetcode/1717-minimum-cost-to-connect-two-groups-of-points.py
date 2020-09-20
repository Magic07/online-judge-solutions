class Solution:
    def connectTwoGroups(self, cost: List[List[int]]) -> int:
        cost2=[[] for i in range(len(cost[0]))]
        for c in cost:
            for i in range(len(c)):
                cost2[i].append(c[i])
        @lru_cache(None)
        def connect(i, mask):
        # i is the index of elements in first group. mask is connected points of group 2.
            answer=0
            if i>=len(cost):
                for j in range(len(cost[0])):
                    if 1<<j & mask==0:
                        answer+=min(cost2[j])
                return answer
            answer=sys.maxsize
            for j in range(len(cost[0])):
                answer=min(answer,cost[i][j]+connect(i+1, mask|1<<j))
            return answer
        return connect(0,0)