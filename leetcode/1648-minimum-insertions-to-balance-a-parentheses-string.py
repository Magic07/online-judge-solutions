class Solution:
    def minInsertions(self, s: str) -> int:
        left=0
        right=0
        answer=0
        for x in s:
            if x=='(':
                if right==1:
                    left-=1
                    right-=1
                    answer+=1
                left+=1
            else:
                right+=1
            if left==0 and right>0:
                left+=1
                answer+=1
            if right==2:
                left-=1
                right-=2
        if right==1:
            left-=1
            right-=1
            answer+=1
        answer+=(2*left)
        return answer
                