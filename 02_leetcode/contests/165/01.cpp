#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x <<  " " << x << endl;
#define fo(i,n) for(int i=0;i<n;i++)
#define rep(i, a, b) for (int i = int(a); i <=int(b); i++)
#define all(x) x.begin(), x.end()
typedef std::vector<int> vi;
typedef std::vector<vector<int>> vvi;
typedef std::vector<string> vs;
typedef std::vector<bool> vb;
typedef std::pair<int, int> pii;
const int inf = 1e9;

template <typename T>
void print(T v){
    for(auto i= v.begin(); i!=v.end(); i++)
        cout<<*i<<" ";
    cout<<endl; 
}

template <typename T>
void print_vv(T v, bool same_line=true){
    for(auto i= 0; i<v.size(); i++){
        cout<<"{";
        for(auto j = 0; j!=v[i].size(); j++){
            cout<<setw(3)<<v[i][j]<<",";
        }
        cout<<"},";
        if(same_line) cout<<endl;
    }
    cout<<endl;
}

class Solution {
    vector<vector<char>> board;
public:
    string tictactoe(vector<vector<int>>& moves) {
        board.resize(3, vector<char>(3,' '));
        int tot_moves = moves.size();

        bool aturn = true;
        for(auto m: moves){
            if(aturn)
                board[m[0]][m[1]] = 'X';
            else
                board[m[0]][m[1]] = 'O';
            aturn = !aturn;

        }
        string winner = validate(board);

        if(winner==" "){
            if(tot_moves==9)
                return "Draw";
            else
                return "Pending";
        }

        return winner;

    }

    string validate(vector<vector<char>> &board){
        bool found = false;
        bool winner;
        for(int i=0; i<3; i++){
            char req = board[i][0];
            if(req==' ') break;
            if(board[i][1]==req && board[i][2]==req)
                return req =='X' ? "A" : "B";
        }

        for(int j=0; j<3; j++){
            char req = board[0][j];
            if(req==' ') break;
            if(board[1][j]==req && board[2][j]==req)
                return req=='X' ? "A" : "B";
        }


        char req;
        req = board[0][0];
        
        if(req!=' ' && req==board[1][1] && req==board[2][2])
            return req=='X' ? "A" : "B";
        

        req = board[0][2];
        if(req!=' ' && req==board[1][1] && req==board[2][0])
            return req=='X' ? "A" : "B";

        return " ";
    }
};
 
int main(){
    vvi moves;
    Solution sol;
    string out;

    moves = {{0,0},{2,0},{1,1},{2,1},{2,2}};
    out = sol.tictactoe(moves);
    deb(out);


    moves = {{0,0},{1,1},{0,1},{0,2},{1,0},{2,0}};
    out = sol.tictactoe(moves);
    deb(out);

    moves = {{0,0},{1,1},{2,0},{1,0},{1,2},{2,1},{0,1},{0,2},{2,2}};
    out = sol.tictactoe(moves);
    deb(out);

    moves = {{0,0},{1,1}};
    out = sol.tictactoe(moves);
    deb(out);

    return 0;
}