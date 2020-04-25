class Solution:
    def markSkippedPeople(self, people: List[List[str]]):
        skipped=[]
        for i,p in enumerate(people):
            if(len(p)==0 or people.index(p)!=i):
                skipped+=[i]
        return skipped

    def smallestSufficientTeam(self, req_skills: List[str], people: List[List[str]]) -> List[int]:
        skipped=self.markSkippedPeople(people)
        skills={v:k for k,v in enumerate(req_skills)}
        answer={0:[]}
        for i,p in enumerate(people):
            if i in skipped:
                continue
            people_skill=0
            for s in p:
                if s in skills:
                    people_skill |= (1<<skills[s])
            for aik, aiv in list(answer.items()):
                new_a=aik|people_skill
                if new_a not in answer or len(aiv)+1<len(answer[new_a]):
                    answer[new_a]=answer[aik]+[i]
        return answer[(1<<len(req_skills))-1]


# Ref: https://leetcode.com/problems/smallest-sufficient-team/discuss/334832/c%2B%2B-dp-bitmask-solution-with-algorithm