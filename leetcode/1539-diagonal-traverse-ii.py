class Solution:
    def findDiagonalOrder(self, nums: List[List[int]]) -> List[int]:
        d=[deque()]
        for i in range(len(nums)):
            for j in range(len(nums[i])):
                if i+j>=len(d):
                    d.append(deque())
                d[i+j].append(nums[i][j])
        answer=[]
        for dq in d:
            while len(dq)!=0:
                answer.append(dq.pop())
        return answer