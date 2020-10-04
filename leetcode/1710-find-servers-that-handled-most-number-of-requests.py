import sortedcontainers

class Solution:
    def busiestServers(self, k: int, arrival: List[int], load: List[int]) -> List[int]:
        taskFinished=[0]*k
        busyServers=[]
        availableServers=sortedcontainers.SortedList([x for x in range(k)])
        # Return -1 if no server available.
        def getServer(index, arrival):
            nonlocal availableServers
            while len(busyServers)>0 and busyServers[0][0]<=arrival:
                server=heapq.heappop(busyServers)
                availableServers.add(server[1])
            if len(availableServers)==0:
                return -1
            current=bisect_left(availableServers, index%k)
            return availableServers[current%len(availableServers)]
        for i in range(len(arrival)):
            server=getServer(i, arrival[i])
            if server==-1:
                continue
            heapq.heappush(busyServers, (arrival[i]+load[i], server))
            taskFinished[server]+=1
            availableServers.remove(server)
        maxTaskFinished=max(taskFinished)
        return [i for i,v in enumerate(taskFinished) if v==maxTaskFinished]