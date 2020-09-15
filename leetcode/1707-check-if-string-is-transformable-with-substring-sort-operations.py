class Solution:
    def isTransformable(self, s: str, t: str) -> bool:
        currentIndex=[0]*10
        indices=[[] for x in range(10)]
        for i in range(len(s)):
            indices[int(s[i])].append(i)
        for i in range(len(s)):
            if s[i]==t[i]:
                currentIndex[int(s[i])]+=1
                continue
            targetDigit=int(t[i])
            if currentIndex[targetDigit]>=len(indices[targetDigit]):
                return False
            for j in range(targetDigit):
                if currentIndex[j]<len(indices[j]) and indices[j][currentIndex[j]]<=indices[targetDigit][currentIndex[targetDigit]]:
                    return False
            currentIndex[targetDigit]+=1
        return True
    
# Ref1: https://leetcode.com/problems/check-if-string-is-transformable-with-substring-sort-operations/discuss/843917/C%2B%2BJavaPython-O(n)
# Ref2: bubble sort.