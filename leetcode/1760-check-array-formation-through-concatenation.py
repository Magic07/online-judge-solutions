class Solution:
    def canFormArray(self, arr: List[int], pieces: List[List[int]]) -> bool:
        i=0
        while i<len(arr):
            found=False
            for j in range(len(pieces)):
                if pieces[j][0]==arr[i]:
                    found=True
                    for k in range(1,len(pieces[j])):
                        if pieces[j][k]!=arr[i+1]:
                            return False
                        else:
                            i+=1
            if found==False:
                return False
            i+=1
        return True