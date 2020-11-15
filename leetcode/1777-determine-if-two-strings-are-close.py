class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        if len(word1)!=len(word2):
            return False
        show1=[0]*26
        show2=[0]*26
        for i in range(len(word1)):
            show1[ord(word1[i])-ord('a')]+=1
            show2[ord(word2[i])-ord('a')]+=1
        show1Char={}
        show2Char={}
        for i in range(len(show1)):
            if (show1[i]==0 and show2[i]!=0) or (show1[i]!=0 and show2[i]==0):
                return False
            if show1[i] not in show1Char:
                show1Char[show1[i]]=0
            show1Char[show1[i]]+=1
            if show2[i] not in show2Char:
                show2Char[show2[i]]=0
            show2Char[show2[i]]+=1
        for k,v in show1Char.items():
            if k not in show2Char:
                return False
            if show2Char[k]!=v:
                return False
        return True