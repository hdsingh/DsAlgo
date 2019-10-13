#include "cpp.h"
#include "extra.h"
using namespace std;


class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>> out;
        vector<vector<int>> board(8, vector<int>(8, 0));
        
        // place queens on board
        for(auto q: queens){
            board[q[0]][q[1]] = 1;
        }
        

        int row = king[0]; int col = king[1];
        // go top and add first
        for(int i=row; i>=0; i--){
            if(board[i][col]){
                out.push_back({i,col});
                break;
            }
        }

        // go down and add first
        for(int i=row; i<8; i++){
            if(board[i][col]){
                out.push_back({i,col});
                break;
            }
        }

        // go left and add first
        for(int i=col; i>=0; i--){
            if(board[row][i]){
                out.push_back({row, i});
                break;
            }
        }

        // go right and add first
        for(int i=col; i<8; i++){
            if(board[row][i]){
                out.push_back({row, i});
                break;
            }
        }

        // top left
        int i = row-1; int j = col-1;
        while(i>=0 && j>=0){
            if(board[i][j]){
                out.push_back({i,j});
                break;
            }
            i--; j--;
        }

        // top right
        i = row-1; j = col+1;
        while(i>=0 && j<8){
            if(board[i][j]){
                out.push_back({i,j});
                break;
            }
            i--; j++;
        }

        // bottom left
        i = row+1; j = col-1;
        while(i<8 && j>=0){
            if(board[i][j]){
                out.push_back({i,j});
                break;
            }
            i++; j--;
        }

        // bottom right
        i = row+1; j = col+1;
        while(i<8 && j<8){
            if(board[i][j]){
                out.push_back({i,j});
                break;
            }
            i++; j++;
        }


        return out;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> queens = {{5,6},{7,7},{2,1},{0,7},{1,6},{5,1},{3,7},{0,3},{4,0},{1,2},{6,3},{5,0},{0,4},{2,2},{1,1},{6,4},{5,4},{0,0},{2,6},{4,5},{5,2},{1,4},{7,5},{2,3},{0,5},{4,2},{1,0},{2,7},{0,1},{4,6},{6,1},{0,6},{4,3},{1,7}};
    vi king = {3,4};
    auto out = sol.queensAttacktheKing(queens, king);
    print_vv(out);
}