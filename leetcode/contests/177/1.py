from datetime import date

# d0 = date(2008, 8, 18)
# d1 = date(2008, 9, 26)
# delta = d1 - d0
# print(delta.days)

class Solution:
    def daysBetweenDates(self, date1: str, date2: str) -> int:
        y1 = int(date1[:4]) 
        y2 = int(date2[:4])
        m1 = int(date1[5:7])
        m2 = int(date2[5:7])
        d1 = int(date1[8:])
        d2 = int(date2[8:])
        # print(d1,d2,m1,m2,y1,y2)
        delta = date(y1,m1,d1) - date(y2,m2,d2)
        # print(delta.days)
        return abs(delta.days)
        

date2 = "2020-01-15"
date1 = "2019-12-31"

ol = Solution()
out = ol.daysBetweenDates(date1,date2)
print(out)
