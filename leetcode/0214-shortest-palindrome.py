class Solution:
    def shortestPalindrome(self, s: str) -> str:
        longString=s+'.'+s[::-1]
        def getNext(s):
            current=1
            lenOfPrefix=0
            nextList=[0]*len(longString)
            while current<len(s):
                if s[lenOfPrefix]==s[current]:
                    lenOfPrefix+=1
                    nextList[current]=lenOfPrefix
                    current+=1
                elif lenOfPrefix==0:
                    nextList[current]=0
                    lenOfPrefix=0
                    current+=1
                else:
                    lenOfPrefix=nextList[lenOfPrefix-1]
            return nextList
        nextList=getNext(longString)
        palindromeIndex=nextList[-1]
        return s[:palindromeIndex-1:-1]+s
    
# Ref: https://leetcode.com/problems/shortest-palindrome/discuss/60113/Clean-KMP-solution-with-super-detailed-explanation