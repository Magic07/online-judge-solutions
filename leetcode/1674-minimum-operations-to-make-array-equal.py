class Solution:
    def minOperations(self, n: int) -> int:
        length=0
        start=0
        if n%2==1:
            length=(n-1)/2
            start=2
            end=length*2
        else:
            length=n/2
            start=1
            end=length*2-1
        return (int)((start+end)*length/2)
        