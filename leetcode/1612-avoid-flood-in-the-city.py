class Solution:
    def minDay(self, dryDays, day):
        for x in dryDays:
            if x>day:
                return x
        return 0

    def avoidFlood(self, rains: List[int]) -> List[int]:
        n=len(rains)
        answer=[-1]*n
        fullLakes={}
        dryDays=[]
        for i in range(n):
            r=rains[i]
            if r!=0:
                if r not in fullLakes:
                    fullLakes[r]=i
                elif len(dryDays)==0:
                    return []
                else:
                    dd=self.minDay(dryDays, fullLakes[r])
                    if dd==0:
                        return []
                    answer[dd]=r
                    dryDays.remove(dd)
                    fullLakes[r]=i
            else:
                dryDays.append(i)
                answer[i]=1
        return answer
    
# Ref: https://leetcode.com/problems/avoid-flood-in-the-city/discuss/697687/A-Set-and-A-Map-Lucid-code-with-documented-comments.