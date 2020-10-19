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
#include "cpp.h"
#include "extra.h"
using namespace std;

        // To visualze the process
        // usleep(10000);
        // std::system("clear");
        // print_vv(board);
        // usleep(10000);

// @lc code=start
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> nqueen(n, string(n, '.'));
        nq_helper(res, nqueen, n , 0);
        return res;
    }

    void nq_helper(vector<vector<string>> &res, vector<string> &nqueen, int &n, int row){
        // terminating condition
        if(row==n) res.push_back(nqueen);
        if(row>=n) return;

        // exploration
        for(int col = 0; col<n; col++){
            if(is_valid(nqueen, row, col, n)){
                nqueen[row][col] = 'Q';
                nq_helper(res, nqueen, n, row+1);
                nqueen[row][col] = '.';
            }
        }
    }

    bool is_valid(vector<string> &board, int row, int col, int n){
        // All the prev row of const col cell
        for(int i= row; i>=0; i--) if(board[i][col]=='Q') return false;

        // check 45 deg diagonally
        int i(row-1), j(col-1);
        while(i>=0 && j>=0){
            if(board[i--][j--]=='Q') return false;
        }

        // check 135 deg diagonally
        i= row-1; j=col+1;
        while(i>=0 && j<n){
            if(board[i--][j++]=='Q') return false;
        }

        return true;
    }
};

class Solution {
    int n;
    vector<vector<string>> ans;
    vector<string> board;
    vector<bool> used_col, used_dia1, used_dia2;
public:
    vector<vector<string>> solveNQueens(int _n) {
        n = _n;
        board.assign(n,string(n,'.'));
        used_col.assign(n,false); 
        used_dia1.assign(2*n-1,false);
        used_dia2.assign(2*n-1,false);
        
        solve(0);
        return ans;
    }
    
    void solve(int row){
        if(row==n){
            ans.push_back(board);
            return;
        }
        for(int col=0; col<n; ++col){
            int d1 = row + col, d2 = row + (n-1-col);
            if(!used_col[col] && !used_dia1[d1] && !used_dia2[d2]){
                used_col[col] = used_dia1[d1] = used_dia2[d2] = 1;
                board[row][col] = 'Q';
                
                solve(row+1);
                
                board[row][col] = '.';
                used_col[col] = used_dia1[d1] = used_dia2[d2] = 0;
            }
        }
    }
};
// @lc code=end

int main(){
    int n = 4;
    Solution s;
    vector<vector<string>> out = s.solveNQueens(n);
    print_vv(out);
}