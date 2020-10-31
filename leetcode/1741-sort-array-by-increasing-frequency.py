class Solution:
    def frequencySort(self, nums: List[int]) -> List[int]:
        frequency={}
        for x in nums:
            if x not in frequency:
                frequency[x]=0
            frequency[x]+=1
        frequency={k: v for k, v in sorted(frequency.items(), key=lambda item:(item[1], -item[0]))}
        answer=[]
        for k,v in frequency.items():
            for i in range(v):
                answer.append(k)
        return answer