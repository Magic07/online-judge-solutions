class Solution:
    def getMaxGridHappiness(self, m: int, n: int, introvertsCount: int, extrovertsCount: int) -> int:
        mask=0b11
        for i in range(1,n):
            mask<<=2
            mask+=0b11
        #print('{0:b}'.format(mask))
        @lru_cache(None)
        def dp(index, last, ic, ec):
            #print('index=%d,last=%s,ic=%d,ec=%d.'%(index,last,ic,ec))
            if index>=m*n:
                return 0
            answer=0
            diff=0
            if ic>0:
                diff+=120
                if index%n>0 and last&0b01:
                    diff-=60
                elif index%n>0 and last&0b10:
                    diff-=10
                if last&(0b01<<2*(n-1)):
                    diff-=60
                elif last&(0b10<<2*(n-1)):
                    diff-=10
                diff+=dp(index+1, ((last<<2)+0b01)&mask,ic-1,ec)
                answer=max(answer,diff)
            diff=0
            if ec>0:
                diff+=40
                if index%n>0 and last&0b01:
                    diff-=10
                elif index%n>0 and last&0b10:
                    diff+=40
                if last&(0b01<<2*(n-1)):
                    diff-=10
                elif last&(0b10<<2*(n-1)):
                    diff+=40
                diff+=dp(index+1, ((last<<2)+0b10)&mask,ic,ec-1)
                answer=max(answer,diff)
            diff=0
            diff+=dp(index+1, (last<<2)&mask,ic,ec)
            answer=max(answer,diff)
            return answer
        return dp(0,0,introvertsCount,extrovertsCount)