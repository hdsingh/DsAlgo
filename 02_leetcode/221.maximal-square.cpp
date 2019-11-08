/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 *
 * https://leetcode.com/problems/maximal-square/description/
 *
 * algorithms
 * Medium (34.02%)
 * Likes:    1658
 * Dislikes: 41
 * Total Accepted:    154.5K
 * Total Submissions: 450.9K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * Given a 2D binary matrix filled with 0's and 1's, find the largest square
 * containing only 1's and return its area.
 * 
 * Example:
 * 
 * 
 * Input: 
 * 
 * 1 0 1 0 0
 * 1 0 1 1 1
 * 1 1 1 1 1
 * 1 0 0 1 0
 * 
 * Output: 4
 * 
 */
#include "cpp.h"
using namespace std;

typedef std::vector<int> vi;
typedef std::vector<vector<int>> vvi;

// @lc code=start

// here dp[i][j] represents the maximum length of a size at that point
// if matrix[i][j] exist then max length at that point will be 
// 1 + min of matrix{ (i-1,j), (i, j-1), (i-1,j-1) }
//  __  __
// |    x
// else 0
// in the end we compute are from lenght of max side
// everything else is just to initialize dp and handle corner cases

int min3(int a, int b, int c){
    return min(min(a,b),c);
}

class Solution {
public:
    int maximalSquare(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(!n) return 0;
        int m = matrix[0].size();
        if(!m) return 0;


        vvi dp(n, vi(m, 0));
        int max_side = 0;

        // base cases
        
        for(int j=0; j<m; j++){
            dp[0][j] = matrix[0][j];
            max_side = max(max_side, dp[0][j]);
            if(matrix[0][j] && n==1) return 1;
        }
        if(n==1) return 0;
        

        for(int i=0; i<n; i++){
            dp[i][0] = matrix[i][0];
            max_side = max(max_side, dp[i][0]);
            if(matrix[i][0] && m==1) return 1;
        }
        if(m==1) return 0;
    
        // // initalize the first row and first col with same num
        // for(int i=0; i<n; i++) dp[i][0] = matrix[i][0];
        // for(int j=0; j<m; j++) dp[0][j] = matrix[0][j];

        for(int i=1; i<n; i++)
            for(int j=1; j<m; j++){
                if(matrix[i][j]){
                    dp[i][j] = 1 + min3(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]);
                    max_side = max(max_side, dp[i][j]);
                }
            }

        // print_vv(dp);

        return max_side * max_side;
    }
};
// @lc code=end
int main(){
    Solution sol;
    vvi matrix;
    matrix = {{1,0,1,0,0},
              {1,0,1,1,1},
              {1,1,1,1,1},
              {1,0,0,1,0}};

    cout<<sol.maximalSquare(matrix)<<endl;

    matrix = {{1},{0}};
    cout<<sol.maximalSquare(matrix)<<endl;

    matrix = {{0},{0},{0}};
    cout<<sol.maximalSquare(matrix)<<endl;

    matrix = {{0,1},{1,0}};
    cout<<sol.maximalSquare(matrix)<<endl;

    matrix = {{0}};
    cout<<sol.maximalSquare(matrix)<<endl;
    


}
