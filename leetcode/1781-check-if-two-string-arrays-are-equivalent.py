class Solution:
    def arrayStringsAreEqual(self, word1: List[str], word2: List[str]) -> bool:
        sa=''
        for x in word1:
            sa+=x
        sb=''
        for x in word2:
            sb+=x
        if sa==sb:
            return True
        else:
            return False