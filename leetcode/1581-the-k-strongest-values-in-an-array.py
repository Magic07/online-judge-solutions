class Solution:
    def getStrongest(self, arr: List[int], k: int) -> List[int]:
        if k>=len(arr):
            return arr
        median=sorted(arr)[(len(arr)-1)//2]
        strong=[0]*len(arr)
        for i in range(len(arr)):
            strong[i]=abs(arr[i]-median)
        minStrong=sorted(strong, reverse=True)[k]
        minArray=[]
        answer=[]
        for i in range(len(arr)):
            if strong[i]>minStrong:
                answer.append(arr[i])
            elif strong[i]==minStrong:
                minArray.append(arr[i])
        minArray=sorted(minArray, reverse=True)
        if len(answer)==k:
            return answer
        for i in range(k-len(answer)):
            answer.append(minArray[i])
        return answer
            
        