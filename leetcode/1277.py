class Solution:
	def countSquares(self, A) -> int:
		for i in range(1, len(A)):
			for j in range(1, len(A[0])):
				A[i][j] *= min(A[i-1][j-1], A[i-1][j], A[i][j-1]) + 1

		return sum(map(sum, A))


sol = Solution()
A = [
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
a = sol.countSquares(A)
print(a)