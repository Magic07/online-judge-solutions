class Solution:
    def countSubgraphsForEachDiameter(self, n: int, edges: List[List[int]]) -> List[int]:
        distance=[[sys.maxsize for _ in range(n)] for _ in range(n)]
        for i in range(n):
            distance[i][i]=0
        for u,v in edges:
            distance[u-1][v-1]=1
            distance[v-1][u-1]=1
        for i in range(n):
            for j in range(n):
                for k in range(n):
                    distance[j][k]=min(distance[j][k],distance[j][i]+distance[i][k])
        print(distance)
        answer=[0]*(n-1)
        
        def checkDistance(bitmask):
            cities=0
            edges=0
            maxDistance=0
            for i in range(n):
                if bitmask>>i&1==0:
                    continue
                cities+=1
                for j in range(i+1, n):
                    if (bitmask>>j)&1==0:
                        continue
                    if distance[i][j]==1:
                        edges+=1
                    if distance[i][j]>maxDistance:
                        maxDistance=distance[i][j]
            if cities!=edges+1:
                return 0
            return maxDistance

        for i in range(2**n):
            d=checkDistance(i)
            if d>0:
                answer[d-1]+=1
        return answer

# Ref: https://leetcode.com/problems/count-subtrees-with-max-distance-between-cities/discuss/889070/C%2B%2BPython-Bitmask-try-all-subset-of-cities-Clean-and-Concise-O(2n-*-n)