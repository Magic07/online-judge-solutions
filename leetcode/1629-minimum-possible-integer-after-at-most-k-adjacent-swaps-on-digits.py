class Solution:
    def minInteger(self, num: str, k: int) -> str:
        sortedNum=sorted(num)
        if k>=len(num)**2//2:
            return ''.join(sortedNum)
        indexOfPos=[0]*10
        intPos= [[] for i in range(10)]
        used=[False]*len(num)
        answer=['']*len(num)
        sortedIndex=0
        for i in range(len(num)):
            intPos[int(num[i])].append(i)
        i=0
        outOfOrder=False
        while i<len(num):
            if k==0:
                break
            if not outOfOrder:
                x=int(sortedNum[i])
                swapPos=intPos[x][indexOfPos[x]]
                indexOfPos[x]+=1
                kNeeded=sum(x==False for x in used[:swapPos+1])-1
                if kNeeded<=k:
                    used[swapPos]=True
                    k-=kNeeded
                    answer[i]=num[swapPos]
                else:
                    outOfOrder=True
                    continue
            else:
                swapMin=sys.maxsize
                minIndex=i
                currentIndex=0
                tempK=k
                while tempK+1>0:
                    if used[currentIndex]==False:
                        tempK-=1
                    else:
                        currentIndex+=1
                        continue
                    if int(num[currentIndex])<swapMin:
                        swapMin=int(num[currentIndex])
                        minIndex=currentIndex
                        k=tempK+1
                    currentIndex+=1
                used[minIndex]=True
                indexOfPos[swapMin]+=1
                answer[i]=str(swapMin)
            i+=1
        return ''.join(answer[:i+1])+''.join([num[j] for j in range(len(num)) if used[j]==False])