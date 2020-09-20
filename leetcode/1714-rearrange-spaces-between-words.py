class Solution:
    def reorderSpaces(self, text: str) -> str:
        spaces=0
        for x in text:
            if x == ' ':
                spaces+=1
        textList=text.split()
        answer=textList[0]
        if len(textList)==1:
            for i in range(spaces):
                answer+=' '
            return answer
        wordSpaces=''
        for i in range(spaces//(len(textList)-1)):
            wordSpaces+=' '
        for i in range(1,len(textList)):
            answer+=wordSpaces
            answer+=textList[i]
        for i in range(spaces%(len(textList)-1)):
            answer+=' '
        return answer