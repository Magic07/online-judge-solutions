class Solution:
    def alertNames(self, keyName: List[str], keyTime: List[str]) -> List[str]:
        visitTime={}
        for i in range(len(keyName)):
            name=keyName[i]
            time=keyTime[i]
            if name not in visitTime:
                visitTime[name]=[]
            visitTime[name].append(datetime.datetime.combine(date.today(),datetime.datetime.strptime(time, '%H:%M').time()))
        answer=[]
        for k,v in visitTime.items():
            if len(v)<=2:
                continue
            v=sorted(v)
            for i in range(2, len(v)):
                if v[i]-v[i-2]<=timedelta(hours=1):
                    answer.append(k)
                    break
        return sorted(answer)
                