class Solution:
    def findLeastNumOfUniqueInts(self, arr: List[int], k: int) -> int:
        count={}
        for x in arr:
            if x in count:
                count[x]+=1
            else:
                count[x]=1
        countList=list({k: v for k, v in sorted(count.items(), key=lambda item: item[1])}.items())
        start=0
        while start<len(countList) and k>=countList[start][1]:
            k-=countList[start][1]
            start+=1
        return len(countList)-start