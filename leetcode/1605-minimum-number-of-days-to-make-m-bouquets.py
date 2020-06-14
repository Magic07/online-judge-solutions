class Solution:
    def minDays(self, bloomDay: List[int], m: int, k: int) -> int:
        if m*k>len(bloomDay):
            return -1
        used=[False]*len(bloomDay)
        sortedIndex=[x[0] for x in sorted(enumerate(bloomDay), key=lambda y:y[1])]
        print(sortedIndex)
        def bouquet(index):
            flower=1
            i=index-1
            lower=index
            higher=index
            while i>=0 and bloomDay[i]<=bloomDay[index] and flower<k:
                if used[i]==True:
                    pass
                else:
                    flower+=1
                    lower=i
                i-=1
            i=index+1            
            while i<len(bloomDay) and bloomDay[i]<=bloomDay[index] and flower<k:
                if used[i]==True:
                    pass
                else:
                    flower+=1
                    higher=i
                i+=1
            if flower>k:
                print('wrong')
            if flower==k:
                used[lower:higher+1]=[True]*(higher-lower+1)
                return True
            else:
                return False
        for x in sortedIndex:
            if used[x]==False and bouquet(x):
                m-=1
                if m==0:
                    return bloomDay[x]
        return 0
            