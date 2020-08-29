class Solution:
    def sortItems(self, n: int, m: int, group: List[int], beforeItems: List[List[int]]) -> List[int]:
        indegreeOutOfGroup=[0]*n
        indegreeInGroup=[0]*n
        adj=[[] for i in range(n)]
        groupItems=[[] for i in range(m)]
        groupHead=[-1]*n
        for i in range(n):
            groupHead[i]=i
            if group[i]!=-1:
                groupItems[group[i]].append(i)
                indegreeInGroup[i]=len([x for x in beforeItems[i] if group[x]==group[i]])
                indegreeOutOfGroup[i]=len(beforeItems[i])-indegreeInGroup[i]
            else:
                indegreeOutOfGroup[i]=len(beforeItems[i])
            for x in beforeItems[i]:
                adj[x].append(i)
        def tsort(items, indegree, adj, sameGroup):
            #print('items: '+str(items)+', indegree: '+str(indegree)+', adj: '+str(adj))
            sortedItems=[]
            dq=collections.deque()
            for x in items:
                if indegree[x]==0:
                    dq.appendleft(x)
            while len(dq)!=0:
                item=dq.pop()
                sortedItems.append(item)
                for x in adj[item]:
                    if sameGroup and x not in items:
                        continue
                    if not sameGroup:
                        x=groupHead[x]
                    indegree[x]-=1
                    if indegree[x]==0:
                        dq.appendleft(x)
            if len(sortedItems)!=len(items):
                print('Assertion failed for '+str(items))
            return sortedItems
        for i in range(len(groupItems)):
            groupItems[i]=tsort(groupItems[i], indegreeInGroup, adj, True)
        #print('groupitems: '+str(groupItems))
        for x in groupItems:
            for i in range(1, len(x)):
                groupHead[x[i]]=x[0]
                adj[x[0]].extend(adj[x[i]])
                adj[x[i]]=[]
                indegreeOutOfGroup[x[0]]+=indegreeOutOfGroup[x[i]]
                indegreeOutOfGroup[x[i]]=0
        items=[x for x in range(n) if group[x]==-1]
        for x in groupItems:
            if len(x)>0:
                items.append(x[0])
        groupOrder=tsort(items, indegreeOutOfGroup, adj, False)
        answer=[]
        for x in groupOrder:
            if group[x]==-1:
                answer.append(x)
            else:
                answer.extend(groupItems[group[x]])
        #print(answer)
        if len(answer)!=n:
            return []
        added=set()
        for x in answer:
            added.add(x)
            for y in beforeItems[x]:
                if y not in added:
                    print(str(y)+' is not added')
                    return []
        return answer
        