#
# @lc app=leetcode id=51 lang=python3
#
# [51] N-Queens
#
# https://leetcode.com/problems/n-queens/description/
#
# algorithms
# Hard (41.31%)
# Likes:    1195
# Dislikes: 54
# Total Accepted:    160.9K
# Total Submissions: 386.2K
# Testcase Example:  '4'
#
# The n-queens puzzle is the problem of placing n queens on an n×n chessboard
# such that no two queens attack each other.
# 
# 
# 
# Given an integer n, return all distinct solutions to the n-queens puzzle.
# 
# Each solution contains a distinct board configuration of the n-queens'
# placement, where 'Q' and '.' both indicate a queen and an empty space
# respectively.
# 
# Example:
# 
# 
# Input: 4
# Output: [
# ⁠[".Q..",  // Solution 1
# ⁠ "...Q",
# ⁠ "Q...",
# ⁠ "..Q."],
# 
# ⁠["..Q.",  // Solution 2
# ⁠ "Q...",
# ⁠ "...Q",
# ⁠ ".Q.."]
# ]
# Explanation: There exist two distinct solutions to the 4-queens puzzle as
# shown above.
# 
# 
#

# @lc code=start
class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        nqueen = [['.']*n for i in range(n)]
        res = []

        def dfs(row):
            if row==n:
                res.append([''.join(row) for row in nqueen])
                return 
            
            for col in range(n):
                if(isvalid(row, col)):
                    nqueen[row][col] = 'Q'
                    dfs(row+1)
                    nqueen[row][col] = '.'
        
        def isvalid(row, col):
            for i in range(row):
                if nqueen[i][col] == 'Q': return False
            
            # 45 deg
            i, j = row-1, col+1
            while(i>=0 and j<n):
                if nqueen[i][j]=='Q':
                    return False
                i-=1; j+=1
            
            #135 deg
            i, j = row-1, col-1
            while(i>=0 and j>=0):
                if nqueen[i][j]=='Q':
                    return False
                i-=1; j-=1
            
            return True
        
        dfs(0)
        return res
# @lc code=end

