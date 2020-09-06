class Solution:
    def maxNumEdgesToRemove(self, n: int, edges: List[List[int]]) -> int:
        answer=0
        aliceVisited=[0]*(n+1)
        bobVisited=[0]*(n+1)
        aliceSet={}
        aliceSetNum=1
        bobSet={}
        bobSetNum=1

        # Return False if this edge can be deleted. Applies to all addEdge* methods.
        def addEdge(edge) -> bool:
            [t, v1, v2]=edge
            if t==3:
                use1=addEdgeFor('alice', edge)
                use2=addEdgeFor('bob', edge)
                return use1 or use2
            elif t==1:
                return addEdgeFor('alice', edge)
            else:
                return addEdgeFor('bob', edge)

        def addEdgeFor(name, edge):
            nonlocal aliceSetNum
            nonlocal bobSetNum
            [t, v1, v2]=edge
            visited=aliceVisited
            vSet=aliceSet
            setNum=aliceSetNum
            if name=='bob':
                visited=bobVisited
                vSet=bobSet
                setNum=bobSetNum
            
            if visited[v1]==visited[v2]:
                if visited[v1]!=0:
                    return False
                visited[v1]=setNum
                visited[v2]=setNum
                vSet[setNum]=[v1, v2]
                if name=='alice':
                    aliceSetNum+=1
                else:
                    bobSetNum+=1
            elif visited[v1]==0:
                visited[v1]=visited[v2]
                vSet[visited[v1]].append(v1)
            elif visited[v2]==0:
                visited[v2]=visited[v1]
                vSet[visited[v2]].append(v2)
            else:
                set1=visited[v1]
                set2=visited[v2]
                for x in vSet[set2]:
                    visited[x]=set1
                vSet[set1].extend(vSet[set2])
                del vSet[set2]
            return True
        
        for edge in edges:
            if edge[0]==3:
                if not addEdge(edge):
                    answer+=1
        for edge in edges:
            if edge[0]!=3:
                if not addEdge(edge):
                    answer+=1

        if len([x for x in aliceVisited[1:] if x==0])!=0 or len([x for x in bobVisited[1:] if x==0])!=0:
            return -1
        return answer