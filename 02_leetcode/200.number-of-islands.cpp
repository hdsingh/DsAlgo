/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 *
 * https://leetcode.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (43.45%)
 * Likes:    3468
 * Dislikes: 128
 * Total Accepted:    468.7K
 * Total Submissions: 1.1M
 * Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * Given a 2d grid map of '1's (land) and '0's (water), count the number of
 * islands. An island is surrounded by water and is formed by connecting
 * adjacent lands horizontally or vertically. You may assume all four edges of
 * the grid are all surrounded by water.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * 11110
 * 11010
 * 11000
 * 00000
 * 
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * 11000
 * 11000
 * 00100
 * 00011
 * 
 * Output: 3
 * 
 */
#include "cpp.h"
using namespace std;

typedef std::vector<int> vi;
typedef std::vector<vector<int>> vvi;

// @lc code=start
// Optimization: instead of using visited for dfs, grid itself can be used
class Solution {
public:
    int numIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        if(!n) return 0;
        int m = grid[0].size();
        if(!m) return 0;

        int islands = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]){
                    dfs(i,j,grid);
                    islands++;

                }
            }
        }

        return islands;
    }

    void dfs(int x, int y, vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        grid[x][y]=0;

        if(x-1>=0 && grid[x-1][y]==1)
            dfs(x-1,y,grid);
        if(x+1<n && grid[x+1][y]==1)
            dfs(x+1,y,grid);
        if(y-1>=0 && grid[x][y-1]==1)
            dfs(x,y-1,grid);
        if(y+1<m && grid[x][y+1]==1)
            dfs(x,y+1,grid);

        
                
        return;
    }
};
// @lc code=end
int main(){
    Solution sol;
    vector<vector<int>> grid;
    grid = {
        {1,1,1,1,0},
        {1,1,0,1,0},
        {1,1,0,0,0},
        {0,0,0,0,0},
    };

    cout<<sol.numIslands(grid)<<endl;

    grid = {
        {1,1,0,0,0},
        {1,1,0,0,0},
        {0,0,1,0,0},
        {0,0,0,1,1}
        };
    cout<<sol.numIslands(grid)<<endl;

    grid = {};
    cout<<sol.numIslands(grid)<<endl;



}