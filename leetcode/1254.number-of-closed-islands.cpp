/*
 * @lc app=leetcode id=1254 lang=cpp
 *
 * [1254] Number of Closed Islands
 *
 * https://leetcode.com/problems/number-of-closed-islands/description/
 *
 * algorithms
 * Medium (59.22%)
 * Likes:    55
 * Dislikes: 2
 * Total Accepted:    3.6K
 * Total Submissions: 6K
 * Testcase Example:  '[[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]'
 *
 * Given a 2D grid consists of 0s (land) and 1s (water).  An island is a
 * maximal 4-directionally connected group of 0s and a closed island is an
 * island totally (all left, top, right, bottom) surrounded by 1s.
 * 
 * Return the number of closed islands.
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: grid =
 * [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
 * Output: 2
 * Explanation: 
 * Islands in gray are closed because they are completely surrounded by water
 * (group of 1s).
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input: grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
 * Output: 1
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: grid = [[1,1,1,1,1,1,1],
 * [1,0,0,0,0,0,1],
 * [1,0,1,1,1,0,1],
 * [1,0,1,0,1,0,1],
 * [1,0,1,1,1,0,1],
 * [1,0,0,0,0,0,1],
 * ⁠              [1,1,1,1,1,1,1]]
 * Output: 2
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= grid.length, grid[0].length <= 100
 * 0 <= grid[i][j] <=1
 * 
 */
#include "cpp.h"
using namespace std;

typedef std::vector<int> vi;
typedef std::vector<vector<int>> vvi;

// @lc code=start
// Optimisation: instead of visted, use grid by marking visited land as water
class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        if(grid.size()<=2 || grid[0].size() <=2) return 0;
        
        int closed_islands = 0;
        for(int i=1; i<grid.size()-1; i++){
            for(int j=1; j<grid[0].size()-1; j++){
                if(grid[i][j]==0)
                    if(dfs(i,j,grid))
                        closed_islands++;
            }
        }

        return closed_islands;
    }

    bool dfs(int i, int j, vvi &grid){
        // if reached border return false
        if(i==0 || j==0 || i==grid.size()-1 || j==grid[0].size()-1){
            return false;
            
            // The only time we reach the border is when land is present here, 
            // due to checks below i.e if(grid[i-1][j]== 0)
            // if(grid[i][j]==1) return true;
            // else return false;
        }

        // if is water
        if(grid[i][j]==1) return true;

        grid[i][j]=1;

        bool left(true), right(true), up(true), down(true);
        
        // left
        if(grid[i-1][j]== 0)
            left = dfs(i-1, j, grid);

        // right
        if(grid[i+1][j]== 0)
            right = dfs(i+1, j, grid);

        // up
        if(grid[i][j-1]== 0)
            up = dfs(i, j-1, grid);

        // down
        if(grid[i][j+1]== 0)
            down = dfs(i, j+1, grid);

        return left && right && up && down;

    }
};
// @lc code=end
int main(){
    Solution sol;
    vvi grid = {{1,1,1,1,1,1,1,0},
                {1,0,0,0,0,1,1,0},
                {1,0,1,0,1,1,1,0},
                {1,0,0,0,0,1,0,1},
                {1,1,1,1,1,1,1,0}};
    cout<<sol.closedIsland(grid)<<endl;

    grid = {{0,0,1,0,0},
            {0,1,0,1,0},
            {0,1,1,1,0}};
    cout<<sol.closedIsland(grid)<<endl;

    grid = {   {1,1,1,1,1,1,1},
               {1,0,0,0,0,0,1},
               {1,0,1,1,1,0,1},
               {1,0,1,0,1,0,1},
               {1,0,1,1,1,0,1},
               {1,0,0,0,0,0,1},
               {1,1,1,1,1,1,1}};
    cout<<sol.closedIsland(grid)<<endl;

    grid = {{0,0,1,1,0,1,0,0,1,0},
            {1,1,0,1,1,0,1,1,1,0},
            {1,0,1,1,1,0,0,1,1,0},
            {0,1,1,0,0,0,0,1,0,1},
            {0,0,0,0,0,0,1,1,1,0},
            {0,1,0,1,0,1,0,1,1,1},
            {1,0,1,0,1,1,0,0,0,1},
            {1,1,1,1,1,1,0,0,0,0},
            {1,1,1,0,0,1,0,1,0,1},
            {1,1,1,0,1,1,0,1,1,0}};
    cout<<sol.closedIsland(grid)<<endl;
    
    return 0;
}
