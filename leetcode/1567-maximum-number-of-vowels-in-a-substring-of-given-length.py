class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        current=0
        for i in range(k):
            if s[i] in ['a','e','i','o','u']:
                current+=1
        i=k
        answer=current
        while i<len(s):
            if s[i-k] in ['a','e','i','o','u']:
                current-=1
            if s[i] in ['a','e','i','o','u']:
                current+=1
            answer=max(answer,current)
            i+=1
        return answer
        