/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 *
 * https://leetcode.com/problems/unique-paths-ii/description/
 *
 * algorithms
 * Medium (33.68%)
 * Likes:    1085
 * Dislikes: 181
 * Total Accepted:    234.6K
 * Total Submissions: 695.3K
 * Testcase Example:  '[[0,0,0],[0,1,0],[0,0,0]]'
 *
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in
 * the diagram below).
 * 
 * The robot can only move either down or right at any point in time. The robot
 * is trying to reach the bottom-right corner of the grid (marked 'Finish' in
 * the diagram below).
 * 
 * Now consider if some obstacles are added to the grids. How many unique paths
 * would there be?
 * 
 * 
 * 
 * An obstacle and empty space is marked as 1 and 0 respectively in the grid.
 * 
 * Note: m and n will be at most 100.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * [
 * [0,0,0],
 * [0,1,0],
 * [0,0,0]
 * ]
 * Output: 2
 * Explanation:
 * There is one obstacle in the middle of the 3x3 grid above.
 * There are two ways to reach the bottom-right corner:
 * 1. Right -> Right -> Down -> Down
 * 2. Down -> Down -> Right -> Right
 * 
 * 
 */
#include "cpp.h"
using namespace std;

typedef std::vector<int> vi;
typedef std::vector<vector<int>> vvi;

// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& og) {
        int r = og.size();
        int c = og[0].size();
        // vvi dp(r+1, vi(c+1, 1));
        vector<vector<unsigned long long>> dp(r+1, vector<unsigned long long>(c+1, 1));

        
        // Put the mask on dp
        for(int i=1; i<=r; i++)
            for(int j=1; j<=c; j++)
                if(og[i-1][j-1])
                    dp[i][j] = 0;
        
        // print_vv(dp);
        
        // if obstacle in 1st first row or col, the remaining positions can't be reached 
        for(int i=2; i<=r; i++)
            if(dp[i-1][1]==0)
                dp[i][1] = 0;

        for(int j=2; j<=c; j++)
            if(dp[1][j-1]==0)
                dp[1][j] = 0;
        

        // // if dp at i,j is initially 0 i.e obstacle is there,
        // // so skip it
        for(int i=2; i<=r; i++){
            for(int j=2; j<=c; j++){
                if(dp[i][j])
                    dp[i][j] = dp[i][j-1] + dp[i-1][j];
            }
        }

        print_vv(dp);
        return dp[r][c];
    }
};


// @lc code=end
int main(){
    Solution s;
    vvi og = {
                {0,0,0},
                {1,0,0},
                {0,0,0}
            };
    // og = {{0,1}};
    og = {  {0,1,0},
            {0,0,0},
            {0,0,0}
         };
    // og = {{0},{1}};
    // og = {{0,0,1}};
    cout<<s.uniquePathsWithObstacles(og)<<endl;

}