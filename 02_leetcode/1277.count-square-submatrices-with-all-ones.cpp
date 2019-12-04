/*
 * @lc app=leetcode id=1277 lang=cpp
 *
 * [1277] Count Square Submatrices with All Ones
 *
 * https://leetcode.com/problems/count-square-submatrices-with-all-ones/description/
 *
 * algorithms
 * Medium (65.82%)
 * Likes:    85
 * Dislikes: 1
 * Total Accepted:    3.8K
 * Total Submissions: 5.7K
 * Testcase Example:  '[[0,1,1,1],[1,1,1,1],[0,1,1,1]]'
 *
 * Given a m * n matrix of ones and zeros, return how many square submatrices
 * have all ones.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: matrix =
 * [
 * [0,1,1,1],
 * [1,1,1,1],
 * [0,1,1,1]
 * ]
 * Output: 15
 * Explanation: 
 * There are 10 squares of side 1.
 * There are 4 squares of side 2.
 * There is  1 square of side 3.
 * Total number of squares = 10 + 4 + 1 = 15.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: matrix = 
 * [
 * ⁠ [1,0,1],
 * ⁠ [1,1,0],
 * ⁠ [1,1,0]
 * ]
 * Output: 7
 * Explanation: 
 * There are 6 squares of side 1.  
 * There is 1 square of side 2. 
 * Total number of squares = 6 + 1 = 7.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= arr.length <= 300
 * 1 <= arr[0].length <= 300
 * 0 <= arr[i][j] <= 1
 * 
 * 
 */
#include "cpp.h"
using namespace std;

typedef std::vector<int> vi;
typedef std::vector<vector<int>> vvi;

// Lets count what is the maximum size of square that could be formed at 
// each point, then add all the sizes(i.e sum of matrix);
// dp[i][j] means the biggest square with A[i][j] as bottom-right corner.

// If A[i][j] == 0, no square.

// If A[i][j] == 1,
// we compare the size of square dp[i-1][j-1], dp[i-1][j] and dp[i][j-1].
// min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) + 1 is the maximum size of square that we can find.

// // @lc code=start
class Solution1 {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int count = 0;
        
        for(int i=1; i<matrix.size(); i++){
            for(int j=1; j<matrix[0].size(); j++){
                matrix[i][j] = matrix[i][j] ?  min(min(matrix[i-1][j], matrix[i][j-1]), matrix[i-1][j-1])+1 :0;
            }
        }

        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                count+=matrix[i][j];
            }
        }

        return count;
    }
};

class Solution2 {
public:
    int countSquares(vector<vector<int>>& A) {
        int count = 0;
        
        for(int i=0; i<A.size(); i++){
            for(int j=0; j<A[0].size(); j++){
                if(A[i][j] && i && j){
                    A[i][j] = min( min(A[i-1][j], A[i][j-1]), A[i-1][j-1]) + 1;
                }
                count+=A[i][j];
            }
        }

        return count;
    }
};

class Solution {
public:
    int countSquares(vector<vector<int>>& A) {
        int count = 0;
        
        for(int i=0; i<A.size(); i++){
            for(int j=0; j<A[0].size(); j++){
                if(A[i][j] && i && j){
                    // A[i][j] = min( min(A[i-1][j], A[i][j-1]), A[i-1][j-1]) + 1;
                    A[i][j] = min({A[i-1][j], A[i][j-1], A[i-1][j-1]}) + 1;
                }
                count+=A[i][j];
            }
        }

        return count;
    }
};
// @lc code=end
int main(){
    Solution sol;
    vvi matrix;
    matrix =  { 
        { 0,1,1,1 },
        { 1,1,1,1 },
        { 0,1,1,1 }
        };
    cout<<sol.countSquares(matrix)<<endl;

    matrix = { 
        { 1,0,1 },
        { 1,1,0 },
        { 1,1,0 }
        };

    cout<<sol.countSquares(matrix)<<endl;

    matrix = { 
        { 1,},
        { 1,},
        { 1,}
        };

    cout<<sol.countSquares(matrix)<<endl;
    matrix = { 
        { 1,1,0,}
        };

    cout<<sol.countSquares(matrix)<<endl;
    vi a = {1,2,4,2};
    

}
