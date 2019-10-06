/*
 * @lc app=leetcode id=52 lang=cpp
 *
 * [52] N-Queens II
 *
 * https://leetcode.com/problems/n-queens-ii/description/
 *
 * algorithms
 * Hard (53.64%)
 * Likes:    334
 * Dislikes: 128
 * Total Accepted:    110.4K
 * Total Submissions: 204.6K
 * Testcase Example:  '4'
 *
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard
 * such that no two queens attack each other.
 * 
 * 
 * 
 * Given an integer n, return the number of distinct solutions to the n-queens
 * puzzle.
 * 
 * Example:
 * 
 * 
 * Input: 4
 * Output: 2
 * Explanation: There are two distinct solutions to the 4-queens puzzle as
 * shown below.
 * [
 * [".Q..",  // Solution 1
 * "...Q",
 * "Q...",
 * "..Q."],
 * 
 * ["..Q.",  // Solution 2
 * "Q...",
 * "...Q",
 * ".Q.."]
 * ]
 * 
 * 
 */
#include "cpp.h"
// #include "extra.h"
using namespace std;


// @lc code=start
class Solution {

private:
    void solveNQueens(int &res, vector<string> &nqueens, int row, int &n){
        
        if(row==n) res+=1;

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
    
public:
    int totalNQueens(int n) {
        int res=0;
        vector<string> nqueens(n, string(n, '.'));
        solveNQueens(res, nqueens, 0, n);
        return res;
    }
};


// @lc code=end

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        
        int ret = Solution().totalNQueens(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}