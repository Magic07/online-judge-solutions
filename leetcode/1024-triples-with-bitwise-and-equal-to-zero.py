class Solution:
    def fwt(self, A, inverse: bool):
        length=1
        i=0
        while length <= len(A)/2:
            while i<len(A):
                for j in range(length):
                    x=A[i+j]
                    y=A[i+j+length]
                    if not inverse:
                        A[i+j]=x+y
                        A[i+j+length]=y
                    else:
                        A[i+j]=x-y
                        A[i+j+length]=y
                i+=(2*length)
            i=0
            length*=2
        
    def countTriplets(self, A: List[int]) -> int:
        n=0
        maxOfA=max(A)
        while n<=16:
            if 2**n>maxOfA:
                break
            else:
                n+=1
        T=[0]*(1<<n)
        for x in A:
            T[x]+=1
        self.fwt(T, False)
        for i in range(len(T)):
            T[i]=T[i]**3
        self.fwt(T, True)
        return T[0]