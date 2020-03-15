/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 *
 * https://leetcode.com/problems/surrounded-regions/description/
 *
 * algorithms
 * Medium (25.48%)
 * Likes:    1205
 * Dislikes: 550
 * Total Accepted:    188.9K
 * Total Submissions: 740.3K
 * Testcase Example:  '[["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]'
 *
 * Given a 2D board containing 'X' and 'O' (the letter O), capture all regions
 * surrounded by 'X'.
 * 
 * A region is captured by flipping all 'O's into 'X's in that surrounded
 * region.
 * 
 * Example:
 * 
 * 
 * X X X X
 * X O O X
 * X X O X
 * X O X X
 * 
 * 
 * After running your function, the board should be:
 * 
 * 
 * X X X X
 * X X X X
 * X X X X
 * X O X X
 * 
 * 
 * Explanation:
 * 
 * Surrounded regions shouldn’t be on the border, which means that any 'O' on
 * the border of the board are not flipped to 'X'. Any 'O' that is not on the
 * border and it is not connected to an 'O' on the border will be flipped to
 * 'X'. Two cells are connected if they are adjacent cells connected
 * horizontally or vertically.
 * 
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define pb push_back
#define deb(x) cout<<#x<<" "<<x<<endl;
#define deb2(x, y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define deb3(x, y, z) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int, int> pii;
const int mod = 1e9 + 7;
template<class T, class U> inline void add_self(T &a, U b){a += b;if (a >= mod) a -= mod;if (a < 0) a += mod;}
template<class T, class U> inline void min_self(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void max_self(T &x, U y) { if (y > x) x = y; }

template <typename T>void print(T v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<v.size(); i++)cout<<setw(w)<<i<<" ";cout<<endl;}for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(w)<<*i<<" ";cout<<endl;}
template <typename T>void print_vv(T v){if(v.size()==0) {cout<<"Empty"<<endl; return;} int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}
template <class T, class U> void print_m(map<T,U> m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}


// X X X X
// X O O X
// X X X X
// X O O X

// Mark all 0s as 1s by dfs on boundary, not marked will be sourrounded
// X X X X
// X O O X
// X X X X
// X 1 1 X

// Fill all Os as ones
// X X X X
// X X X X
// X X X X
// X 1 1 X

// Restore 1 to Os
// X X X X
// X X X X
// X X X X
// X O O X


class Solution {
    int n, m;
public:
    void solve(vector<vector<char>>& board) {
        n = board.size(); m = board[0].size();

    
        for(int row: {0, n-1})
            for(int col=0; col<m; ++col)
                if(board[row][col]=='O')
                    dfs(row, col, board);

        for(int col: {0,m-1})
            for(int row=0; row<n; ++row)
                if(board[row][col]=='O')    
                    dfs(row,col,board);

        // restore: by setting 1 to O and O to X
        for(int row=0; row<n; ++row){
            for(int col=0; col<m; ++col){
                if(board[row][col]=='1')
                    board[row][col] = 'O';
                else if(board[row][col]=='O')
                    board[row][col] = 'X';
            }
        }        
    }

    void dfs(int row, int col, vector<vector<char>> &board){
        if(row<0 || row>=n || col<0 || col>=m || board[row][col]!='O') return;
        board[row][col] = '1';
        dfs(row-1,col,board);
        dfs(row+1,col,board);
        dfs(row,col-1,board);
        dfs(row,col+1,board);
    }
};
// @lc code=end

int main(){
    Solution sol;  
    vvi board;  
    return 0;
}
