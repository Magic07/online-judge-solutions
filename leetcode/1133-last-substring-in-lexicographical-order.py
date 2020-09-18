class Solution:
    def lastSubstring(self, s: str) -> str:
        currentMax=0
        start=1
        length=0
        while start+length<len(s):
            if s[currentMax+length]==s[start+length]:
                length+=1
                continue
            if s[currentMax+length]>s[start+length]:
                start=start+length+1
            else:
                currentMax=start
                start+=1
            length=0
        return s[currentMax:]
    
# Ref: https://leetcode.com/problems/last-substring-in-lexicographical-order/discuss/363662/Short-python-code-O(n)-time-and-O(1)-space-with-proof-and-visualization