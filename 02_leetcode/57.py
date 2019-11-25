from typing import List

class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        s, e = newInterval[0], newInterval[1]
        left = [i for i in intervals if i[1] < s]
        right = [i for i in intervals if i[0] > e]
        if left + right != intervals:
            s = min(s, intervals[len(left)][0])
            e = max(e, intervals[-len(right)-1][1])
        return left + [[s,e]] + right

sol = Solution()
ins = [[1,3],[6,9]]
ni = [2,5]
out = sol.insert(ins, ni)
print(out)

left = [1,2]
right = [3,4]
print(left+right != [3,4])

parts = a,b,c = [1],[],[]
print(parts[0])
a = ~1
print(a)