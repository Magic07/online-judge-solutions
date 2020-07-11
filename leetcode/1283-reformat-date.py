class Solution:
    def reformatDate(self, date: str) -> str:
        pattern = re.compile(r'[0-9]+')
        dateList=date.split(' ')
        day=pattern.findall(dateList[0])[0]
        monthList=["Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"]
        month=monthList.index(dateList[1])+1
        year=dateList[2]
        return year+'-'+str(month).zfill(2)+'-'+str(day).zfill(2)