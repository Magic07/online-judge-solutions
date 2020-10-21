class Solution:
    def areConnected(self, n: int, threshold: int, queries: List[List[int]]) -> List[bool]:
        cities=[0]*(n+1)
        group={}
        nextGroupId=1
        
        def union(source, to):
            if source==to:
                return
            for c in group[source]:
                cities[c]=to
            group[to].extend(group[source])
            del group[source]
        
        for base in range(threshold+1, n):
            currentGroupId=nextGroupId
            nextGroupId+=1
            group[currentGroupId]=[]
            for member in range(base, n+1, base):
                if cities[member]==0:
                    cities[member]=currentGroupId
                    group[currentGroupId].append(member)
                else:
                    union(cities[member], currentGroupId)
        
        answer=[False]*len(queries)
        for i in range(len(queries)):
            u,v=queries[i]
            if cities[u]==cities[v] and cities[u]!=0:
                answer[i]=True
        return answer
                