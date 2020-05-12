class Solution:
    def fallingSquares(self, positions: List[List[int]]) -> List[int]:
        answer=[]
        heights={0:0}
        max_height=0
        for p in positions:
            last_height=heights[max(k for k in heights if k<p[0]+p[1])]
            old_heights=list(heights[k] for k in heights if k>p[0] and k<p[0]+p[1])
            if p[0] not in heights:
                old_heights.append(heights[max(k for k in heights if k<p[0])])
            else:
                old_heights.append(heights[p[0]])
            if len(old_heights)==0:
                old_heights.append(0)
            new_height=max(old_heights)+p[1]
            heights[p[0]]=new_height
            for item in list(k for k in heights if k>p[0] and k<p[0]+p[1]):
                del heights[item]
            heights[p[0]+p[1]]=last_height
            max_height=max(max_height, new_height)
            answer.append(max_height)
        return answer
            
        