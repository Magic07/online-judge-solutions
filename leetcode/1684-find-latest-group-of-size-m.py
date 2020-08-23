class Solution:
    def findLatestStep(self, arr: List[int], m: int) -> int:
        n=len(arr)
        length=[0]*n
        previous=[-1]*n
        answer=-1
        groups={}
        for i in range(len(arr)):
          x=arr[i]-1
          previous_index=x
          length_index=x
          length[x]=1
          previous[x]=x
          if x!=n-1 and length[x+1]!=0:
            length[x]=length[x+1]+1
            previous_index=x+length[x]-1
            previous[previous_index]=x
            groups[length[x+1]]-=1
          if x!=0 and previous[x-1]!=-1:
            length_index=previous[x-1]
            groups[length[length_index]]-=1
            length[length_index]+=length[x]
            previous[previous_index]=length_index
            previous[x-1]=-1
            length[x]=0
          if length[length_index] not in groups:
            groups[length[length_index]]=1
          else:
            groups[length[length_index]]+=1
          #print('i='+str(i)+', length='+str(length)+', previous='+str(previous)+', groups='+str(groups))
          if m in groups and groups[m]!=0:
            answer=i+1
        return answer
          