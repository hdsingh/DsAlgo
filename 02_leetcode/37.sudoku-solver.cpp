/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 *
 * https://leetcode.com/problems/sudoku-solver/description/
 *
 * algorithms
 * Hard (38.68%)
 * Likes:    1114
 * Dislikes: 73
 * Total Accepted:    147.1K
 * Total Submissions: 377K
 * Testcase Example:  '[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]'
 *
 * Write a program to solve a Sudoku puzzle by filling the empty cells.
 * 
 * A sudoku solution must satisfy all of the following rules:
 * 
 * 
 * Each of the digits 1-9 must occur exactly once in each row.
 * Each of the digits 1-9 must occur exactly once in each column.
 * Each of the the digits 1-9 must occur exactly once in each of the 9 3x3
 * sub-boxes of the grid.
 * 
 * 
 * Empty cells are indicated by the character '.'.
 * 
 * 
 * A sudoku puzzle...
 * 
 * 
 * ...and its solution numbers marked in red.
 * 
 * Note:
 * 
 * 
 * The given board contain only digits 1-9 and the character '.'.
 * You may assume that the given Sudoku puzzle will have a single unique
 * solution.
 * The given board size is always 9x9.
 * 
 * 
 */
#include "cpp.h"
#include "extra.h"
using namespace std;
#include <unistd.h>

// @lc code=start
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        int n = 9;
        int m = 3;
        int row(0), col(0);
        bool done = false;
        Solver(board, row, col, done);
    }
    
    void Solver(vector<vector<char>>& board, int row, int col, bool &done){
        
        // To visualze the process
        // usleep(10000);
        // std::system("clear");
        // print_vv(board);
        // usleep(10000);
               
        if(col==9){
            // if reaches end finish
            if(row==8){
                done = true;
                return;
            };
            // if reaches end of col, then switch to new row
            row++; col=0;
        }

        if(board[row][col]=='.'){
            for(int i = 1; i<=9; i++){
                if(isValid(board, row, col, i + '0')){
                    board[row][col] = i + '0';
                    Solver(board, row, col+1, done);
                }
            }
            if(!done) board[row][col] = '.';
        }else
            Solver(board, row, col+1, done);

    }

    bool isValid(vector<vector<char>>&board, int row, int col, char p){

        // iterate over all the elements in row to check duplicate
        for(int i = 0; i<9; i++)
            if(board[row][i]== p) return false;
        
        // iterate over all the elements in col to check duplicate
        for(int i = 0 ; i<9; i++){
            if(board[i][col]== p) return false; 
        }

        // iterate and sum sub box
        int r_start = (row/3)*3;
        int c_start = (col/3)*3;
        
        for(int i = 0; i<3; i++){
            for(int j = 0; j<3; j++){
                if(board[r_start + i][c_start + j] == p) return false; 
            }
        }

        return true;
    }
};
// @lc code=end


int main(){
    vector<vector<char>> board = {  {'5','3','.','.','7','.','.','.','.'},
                                    {'6','.','.','1','9','5','.','.','.'},
                                    {'.','9','8','.','.','.','.','6','.'},
                                    {'8','.','.','.','6','.','.','.','3'},
                                    {'4','.','.','8','.','3','.','.','1'},
                                    {'7','.','.','.','2','.','.','.','6'},
                                    {'.','6','.','.','.','.','2','8','.'},
                                    {'.','.','.','4','1','9','.','.','5'},
                                    {'.','.','.','.','8','.','.','7','9'}};
    print_vv(board);

    Solution s;
    s.solveSudoku(board);
    print_vv(board);

}
