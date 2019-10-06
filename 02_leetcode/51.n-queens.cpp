/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 *
 * https://leetcode.com/problems/n-queens/description/
 *
 * algorithms
 * Hard (41.31%)
 * Likes:    1195
 * Dislikes: 54
 * Total Accepted:    160.9K
 * Total Submissions: 386.2K
 * Testcase Example:  '4'
 *
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard
 * such that no two queens attack each other.
 * 
 * 
 * 
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 * 
 * Each solution contains a distinct board configuration of the n-queens'
 * placement, where 'Q' and '.' both indicate a queen and an empty space
 * respectively.
 * 
 * Example:
 * 
 * 
 * Input: 4
 * Output: [
 * ⁠[".Q..",  // Solution 1
 * ⁠ "...Q",
 * ⁠ "Q...",
 * ⁠ "..Q."],
 * 
 * ⁠["..Q.",  // Solution 2
 * ⁠ "Q...",
 * ⁠ "...Q",
 * ⁠ ".Q.."]
 * ]
 * Explanation: There exist two distinct solutions to the 4-queens puzzle as
 * shown above.
 * 
 * 
 */

// @lc code=start
#include "cpp.h"
#include "extra.h"
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> nqueens(n, string(n, '.'));
        solveNQueens(res, nqueens, 0, n);
        return res;
    }

private:
    void solveNQueens(vector<vector<string>> &res, vector<string> &nqueens, int row, int &n){
        
        if(row==n) res.push_back(nqueens);

        for(int col = 0; col<n; col++){
            if(isValid(nqueens, row, col, n)){
                nqueens[row][col] = 'Q';
                solveNQueens(res, nqueens, row+1, n);
                nqueens[row][col] = '.';
            }
        }
    }

    bool isValid(vector<string> &nqueens,  int row, int col, int &n){
        // check if this col has a queen before
        for(int i=0; i<row; i++)
            if(nqueens[i][col]=='Q') return false;
        
        // Check the 45 deg diagonal
        for(int i=row-1, j= col+1; i>=0 && j<n; i--, j++)
            if(nqueens[i][j]=='Q') return false;

        // Check the 135 deg diagonal
        for(int i=row-1, j= col-1; i>=0 && j>=0; i--, j--)
            if(nqueens[i][j]=='Q') return false;   
        
        return true;
    }
};


// @lc code=end

int main(int argc, char const *argv[])
{
	cout<<"HEllo";
	return 0;
}