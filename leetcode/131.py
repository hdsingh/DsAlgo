class Solution:
	def partition(self, s: str):
		res = []
		self.dfs(s,[], res)
		return res
		
	def dfs(self, s, sub, res):
		if not s:
			res.append(sub)
			return

		for i in range(1, len(s)+1):
			if self.isPal(s[:i]):
				self.dfs(s[i:], sub+[s[:i]], res)

	def isPal(self, s):
		return s == s[::-1]

s = "0123"
print(s[:2])