class Solution:
    def containsPattern(self, arr: List[int], m: int, k: int) -> bool:
        if m*k>len(arr):
            return False
        for i in range(len(arr)-k*m+1):
            for j in range(m):
                found=True
                for kk in range(1, k):
                    #print('i='+str(i)+',j='+str(j)+',kk='+str(kk))
                    if arr[i+j]==arr[i+j+m*kk]:
                        continue
                    else:
                        found=False
                        break
                if not found:
                    break
                if j==m-1 and found:
                    return True
        return False
            