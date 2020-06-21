class Solution:
    def getFolderNames(self, names: List[str]) -> List[str]:
        dirs={}
        answer=[]
        for n in names:
            if n not in dirs and n not in answer:
                answer.append(n)
                dirs[n]=0
            else:
                if n not in dirs:
                    renameN=1
                else:
                    renameN=dirs[n]+1
                newName=n+'('+str(renameN)+')'
                while newName in dirs:
                    renameN+=1
                    newName=n+'('+str(renameN)+')'
                answer.append(newName)
                dirs[n]=renameN
        return answer
                