/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 *
 * https://leetcode.com/problems/minimum-path-sum/description/
 *
 * algorithms
 * Medium (49.28%)
 * Likes:    1750
 * Dislikes: 45
 * Total Accepted:    275.6K
 * Total Submissions: 558.7K
 * Testcase Example:  '[[1,3,1],[1,5,1],[4,2,1]]'
 *
 * Given a m x n grid filled with non-negative numbers, find a path from top
 * left to bottom right which minimizes the sum of all numbers along its path.
 * 
 * Note: You can only move either down or right at any point in time.
 * 
 * Example:
 * 
 * 
 * Input:
 * [
 * [1,3,1],
 * ⁠ [1,5,1],
 * ⁠ [4,2,1]
 * ]
 * Output: 7
 * Explanation: Because the path 1→3→1→1→1 minimizes the sum.
 * 
 * 
 */
#include "cpp.h"
using namespace std;

typedef std::vector<int> vi;
typedef std::vector<vector<int>> vvi;

// @lc code=start

// DP 1d
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vi dp(m+1, INT_MAX);
        dp[0] = 0;

        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
                dp[j] = grid[i-1][j-1] + min(dp[j-1], dp[j]);

        return dp[m];
    }
};

// DP 2d
class Solution3 {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vvi dp(n+1, vi(m+1, INT_MAX));
        dp[0][1] = 0; dp[1][0] = 0;

        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
                dp[i][j] = grid[i-1][j-1] + min(dp[i-1][j], dp[i][j-1]);

        return dp[n][m];
    }
};


// Memo
class Solution2 {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vvi cache(n, vi(m, -1));
        return findPath(0,0, grid, cache);
    }

    int findPath(int x, int y, vvi &grid, vvi &cache){
        int n = grid.size();
        int m = grid[0].size();
        
        if(x == n-1 && y==m) return 0;
        if(y == m-1 && x==n) return 0;

        if(x>=n || y>=m) return INT_MAX;

        if(cache[x][y]!=-1) return cache[x][y];

        int right = findPath(x, y+1, grid, cache);
        int down = findPath(x+1, y, grid, cache);
        int cell = grid[x][y];

        return cache[x][y] = cell + min(down, right);
    }
};

// Recursive
class Solution1 {
public:
    int minPathSum(vector<vector<int>>& grid) {
        return findPath(0,0, grid);
    }

    int findPath(int x, int y, vvi &grid){
        int n = grid.size();
        int m = grid[0].size();
        
        if(x == n-1 && y==m) return 0;
        if(y == m-1 && x==n) return 0;

        if(x>=n || y>=m) return INT_MAX;

        int right = findPath(x, y+1, grid);
        int down = findPath(x+1, y, grid);
        int cell = grid[x][y];

        return cell + min(down, right);
    }
};
// @lc code=end
int main(){
    Solution sol;
    vvi grid = {
                {1,3,1},
                {1,5,1},
                {4,2,1}
               };

    cout<<sol.minPathSum(grid)<<endl;

    grid = {{1,2,5},
            {3,2,1}};

    cout<<sol.minPathSum(grid)<<endl;
    
}