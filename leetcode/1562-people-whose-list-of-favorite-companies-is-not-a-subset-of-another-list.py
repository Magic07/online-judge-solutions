class Solution:
    def isSubset(self, la, lb)->bool:
        i=0
        j=0
        while i<len(la) and j<len(lb):
            if la[i]==lb[j]:
                i+=1
                j+=1
            elif la[i]<lb[j]:
                return False
            elif la[i]>lb[j]:
                j+=1
        if i==len(la):
            return True
        return False
    def peopleIndexes(self, favoriteCompanies: List[List[str]]) -> List[int]:
        for i in range(len(favoriteCompanies)):
            favoriteCompanies[i]=sorted(favoriteCompanies[i])
        answer=[]
        for i in range(len(favoriteCompanies)):
            isSubset=False
            for j in range(len(favoriteCompanies)):
                if i!=j and self.isSubset(favoriteCompanies[i], favoriteCompanies[j]):
                    isSubset=True
                    break
            if isSubset==False:
                answer.append(i)
        return answer
                    