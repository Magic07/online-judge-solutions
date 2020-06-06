class Solution:
    def nthMagicalNumber(self, N: int, A: int, B: int) -> int:
        lcm=A*B/gcd(A,B)
        oneRound=lcm/A
        oneRound+=lcm/B
        oneRound-=1
        rounds=N//oneRound
        answer=int(lcm*rounds)%1000000007
        nextA=answer+A
        nextB=answer+B
        N-=oneRound*rounds
        while N>0:
            if nextA<nextB:
                answer=nextA
                nextA+=A
            else:
                answer=nextB
                nextB+=B
            N-=1
        return answer%1000000007
            
        