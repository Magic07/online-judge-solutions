class Solution:
    def findKthPositive(self, arr: List[int], k: int) -> int:
        arr.append(10000)
        current=1
        i=0
        while k>0:
            if arr[i]!=current:
                k-=1
            else:
                i+=1
            current+=1
        return current-1
            