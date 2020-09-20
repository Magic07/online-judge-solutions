class Solution:
    def maxUniqueSplit(self, s: str) -> int:
        def maxSplit(subStrings: list, s: str):
            answer=-1
            if len(s)==0:
                return answer
            if s not in subStrings:
                answer=1
            for i in range(1, len(s)):
                if s[:i] not in subStrings:
                    ss=copy.deepcopy(subStrings)
                    ss.append(s[:i])
                    answer=max(answer, maxSplit(ss, s[i:])+1)
            return answer
        return maxSplit([], s)
            