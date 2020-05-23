class Solution:
    def candy(self, ratings: List[int]) -> int:
        answer=1
        lastCheckpoint=[0]*len(ratings)
        lessThanLast=[0]*len(ratings)
        last=1
        for i in range(1, len(ratings)):
            if ratings[i]>ratings[i-1]:
                last+=1
                answer+=last
                lastCheckpoint[i]=i
            elif ratings[i]==ratings[i-1]:
                lessThanLast[i]=last-1
                answer+=1
                last=1
                lastCheckpoint[i]=i
            elif last>1:
                # TODO.
                lessThanLast[i]=last-1
                last=1
                answer+=1
                if lessThanLast[i]==1:
                    lastCheckpoint[i]=lastCheckpoint[i-1]
                else:
                    lastCheckpoint[i]=i
            else:
                lessThanLast[i]=1
                last=1
                answer+=(i-lastCheckpoint[i-1]+1)
                lessThanLast[lastCheckpoint[i-1]]-=1
                if lessThanLast[lastCheckpoint[i-1]]==1 and ratings[lastCheckpoint[i-1]]<ratings[lastCheckpoint[i-1]-1]:
                    lastCheckpoint[i]=lastCheckpoint[lastCheckpoint[i-1]-1]
                else:
                    lastCheckpoint[i]=lastCheckpoint[i-1]
        return answer
