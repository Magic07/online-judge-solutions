class Solution:
    def kthSmallestPath(self, destination: List[int], k: int) -> str:
        r,c=destination
        answer=[]
        while r>0 or c>0:
            if r==0:
                answer.append('H')
                c-=1
            elif c==0:
                answer.append('V')
                r-=1
            else:
                if math.comb(r+c-1,r)<k:
                    answer.append('V')
                    k-=math.comb(r+c-1,r)
                    r-=1
                else:
                    answer.append('H')
                    c-=1
        return ''.join(answer)