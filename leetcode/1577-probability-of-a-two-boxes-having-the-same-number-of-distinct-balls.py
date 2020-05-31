class Solution:
    def validShuffles(self, balls: List[int], box1, box2, index) -> int:
        answer=0
        if index==len(balls)-1:
            for x in range(balls[index]+1):
                box1[index]=x
                box2[index]=balls[index]-x
                if len([x for x in box1 if x>0])==len([x for x in box2 if x>0]) and sum(box1)==sum(box2):
                    answer+=((factorial(sum(box1))/prod([factorial(x) for x in box1]))*(factorial(sum(box2))/prod([factorial(x) for x in box2])))
            return answer
        for x in range(balls[index]+1):
            box1[index]=x
            box2[index]=balls[index]-x
            answer+=self.validShuffles(balls, box1, box2, index+1)
        return answer
        
    def getProbability(self, balls: List[int]) -> float:
        total=factorial(sum(balls))/prod([factorial(x) for x in balls])
        valid=self.validShuffles(balls, [0]*len(balls), [0]*len(balls),0)
        return valid/total
