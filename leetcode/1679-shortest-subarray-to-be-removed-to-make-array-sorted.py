class Solution:
    def findLengthOfShortestSubarray(self, arr: List[int]) -> int:
        start=-1
        end=len(arr)-1
        for i in range(1, len(arr)):
            if arr[i]<arr[i-1]:
                start=i-1
                break
        if start==-1:
            return 0
        j=len(arr)-1
        while j>=0:
            if arr[j-1]>arr[j]:
                end=j
                break
            j-=1
        s=start
        answer=sys.maxsize
        while s>=0 and arr[s]>arr[end]:
            s-=1
        answer=min(answer, end-s-1)
        e=end
        while e<len(arr) and arr[e]<arr[start]:
            e+=1
        answer=min(answer, e-start-1)
        return answer
            