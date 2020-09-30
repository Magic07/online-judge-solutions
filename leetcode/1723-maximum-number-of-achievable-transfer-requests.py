class Solution:
    def maximumRequests(self, n: int, requests: List[List[int]]) -> int:
        def checkStatus(status):
            io=[0]*n
            index=0
            while status>0:
                if status&1:
                    io[requests[index][0]]-=1
                    io[requests[index][1]]+=1
                index+=1
                status>>=1
            return len([x for x in io if x!=0])==0
            
        @lru_cache(None)
        def tryRequests(start, status):
            if start>=len(requests):
                if checkStatus(status):
                    return bin(status).count("1")
                else:
                    return -1
            return max(tryRequests(start+1, status), tryRequests(start+1, status+(1<<start)))
        
        return tryRequests(0,0)