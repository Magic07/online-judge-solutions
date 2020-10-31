class Solution:
    def numWays(self, words: List[str], target: str) -> int:
        char_show=[[0 for _ in range(26)] for _ in range(len(words[0]))]
        for word in words:
            for i in range(len(word)):
                char_show[i][ord(word[i])-ord('a')]+=1

        @lru_cache(None)
        def ways(words_index, target_index):
            if target_index==len(target):
                return 1
            if words_index>len(words[0])-len(target)+target_index:
                return 0
            answer=0
            for i in range(words_index, len(word)-len(target)+target_index+1):
                if char_show[i][ord(target[target_index])-ord('a')]>0:
                    answer+=(ways(i+1, target_index+1)*char_show[i][ord(target[target_index])-ord('a')])
            return answer%1000000007
                    
        return ways(0,0)%1000000007