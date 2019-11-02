/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 *
 * https://leetcode.com/problems/triangle/description/
 *
 * algorithms
 * Medium (40.70%)
 * Likes:    1388
 * Dislikes: 161
 * Total Accepted:    206.5K
 * Total Submissions: 500.9K
 * Testcase Example:  '[[2],[3,4],[6,5,7],[4,1,8,3]]'
 *
 * Given a triangle, find the minimum path sum from top to bottom. Each step
 * you may move to adjacent numbers on the row below.
 * 
 * For example, given the following triangle
 * 
 * 
 * [
 * ⁠    [2],
 * ⁠   [3,4],
 * ⁠  [6,5,7],
 * ⁠ [4,1,8,3]
 * ]
 * 
 * 
 * The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
 * 
 * Note:
 * 
 * Bonus point if you are able to do this using only O(n) extra space, where n
 * is the total number of rows in the triangle.
 * 
 */
#include "cpp.h"
using namespace std;

typedef std::vector<int> vi;
typedef std::vector<vector<int>> vvi;

// @lc code=start
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int size = triangle.size();
        if(!size) return 0;
        vi dp = triangle[size-1];

        for(int i=size-2; i>=0; i--)
            for(int j=0; j<=i; j++)
                dp[j] = triangle[i][j] + min(dp[j], dp[j+1]);

        return dp[0];
    }

    // Recursive
    int minimumTotal1(vector<vector<int>>& triangle) {
        int size = triangle.size();
        return traverse(0, 0, triangle, size);
    }

    int traverse(int r, int c, vvi &triangle, int size){
        cout<<r<<","<<c<<endl;
        if(r>=size) return 0;
        int a = traverse(r+1, c, triangle, size);
        int b = traverse(r+1, c+1, triangle, size);
        return triangle[r][c] + min(a , b);
    }
};
// @lc code=end

int main(){
    Solution s;
    vvi triangle;
    triangle = {
     {2},
    {3,4},
   {6,5,7},
  {4,1,8,3}
};
    triangle = {{-1}, {2,3}, {1,-1,-3}};
    cout<<s.minimumTotal(triangle)<<endl;

    return 0;
}

