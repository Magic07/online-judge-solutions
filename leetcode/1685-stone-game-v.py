class Solution:
    def stoneGameV(self, stoneValue: List[int]) -> int:
        @lru_cache(None)
        def stone(start, end):
            if start == end:
                #print('start='+str(start)+',end='+str(end)+', answer=0')
                return 0
            if end == start+1:
                #print('start='+str(start)+',end='+str(end)+', answer='+str(min(stoneValue[start], stoneValue[end])))
                return min(stoneValue[start], stoneValue[end])
            sumOfRight = sum(stoneValue[start:end+1])
            sumOfLeft = 0
            diff = abs(sumOfRight-sumOfLeft)
            answer = 0
            for i in range(start, end):
                sumOfLeft += stoneValue[i]
                sumOfRight -= stoneValue[i]
                if sumOfLeft < sumOfRight:
                    answer = max(answer, sumOfLeft+stone(start, i))
                elif sumOfLeft > sumOfRight:
                    answer = max(answer, sumOfRight+stone(i+1, end))
                else:
                    answer = max(answer, max(
                        sumOfLeft+stone(i+1, end), sumOfRight+stone(start, i)))
            #print('start='+str(start)+',end='+str(end)+', answer='+str(answer))
            return answer
        return stone(0, len(stoneValue)-1)
