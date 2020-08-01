class Solution:
    def maxNumOfSubstrings(self, s: str) -> List[str]:
        char_range={}
        for i in range(len(s)):
            if s[i] in char_range:
                char_range[s[i]][1]=i
            else:
                char_range[s[i]]=[i,i]

        answer=[]
        lastEnd=-1
        for i in range(len(s)):
            begin, end=char_range[s[i]]
            if begin<i:
                continue
            j=i
            valid=True
            while j<=end:
                beginOfJ, endOfJ=char_range[s[j]]
                if beginOfJ<begin:
                    valid=False
                    break
                end=max(end, endOfJ)
                j+=1
            if valid:
                if end<lastEnd:
                    answer[-1]=s[begin:end+1]
                else:
                    answer.append(s[begin:end+1])
                lastEnd=end
        return answer