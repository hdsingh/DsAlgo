/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 *
 * https://leetcode.com/problems/word-search/description/
 *
 * algorithms
 * Medium (33.64%)
 * Likes:    2805
 * Dislikes: 143
 * Total Accepted:    393.7K
 * Total Submissions: 1.2M
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * Given a 2D board and a word, find if the word exists in the grid.
 * 
 * The word can be constructed from letters of sequentially adjacent cell,
 * where "adjacent" cells are those horizontally or vertically neighboring. The
 * same letter cell may not be used more than once.
 * 
 * Example:
 * 
 * 
 * board =
 * [
 * ⁠ ['A','B','C','E'],
 * ⁠ ['S','F','C','S'],
 * ⁠ ['A','D','E','E']
 * ]
 * 
 * Given word = "ABCCED", return true.
 * Given word = "SEE", return true.
 * Given word = "ABCB", return false.
 * 
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

class Solution {
    vector<vector<char>> board;
    int n, m, sz;
    string word;
    vvi dirs =  {{0,1},{0,-1},{1,0},{-1,0}};
public:
    bool exist(vector<vector<char>>& board, string word) {
        this->board = board;
        this->word = word;
        n = board.size(); m = board[0].size();
        sz = word.size();
        
        forn(i, n){
            forn(j, m){
                if(board[i][j]==word[0]){
                    this->board[i][j] = '*';
                    if(canForm(i,j, 1)){
                        this->board[i][j] = word[0];
                        return true;
                    } 
                    this->board[i][j] = word[0];
               }
           }
       }
       return false;
    }

    bool canForm(int i, int j, int pos){
        if(pos==sz) return true;

        for(auto dir: dirs){
            int ni = i+dir[0]; int nj = j+dir[1];
            if(0<=ni && ni<n && 0<=nj && nj<m && board[ni][nj]==word[pos]){
                board[ni][nj] = '*';
                if(canForm(ni,nj,pos+1)){
                    board[ni][nj] = word[pos];
                    return true;
                }
                board[ni][nj] = word[pos];
            }
        }
        return false;
    }
};
// @lc code=end

int main(){
    vector<vector<char>> board =
            {
            {'A','B','C','E'},
            {'S','F','C','S'},
            {'A','D','E','E'}
            };
    Solution sol;  bool out;
    vs words;
    words = {"ABCCED","SEE","SFCF"};
    // words = {"SEE"};
    board = {{'a','a'}};
    words = {"aaa"};
    for(auto &word: words){
        out = sol.exist(board, word); deb(out);
    }

    return 0;
}
