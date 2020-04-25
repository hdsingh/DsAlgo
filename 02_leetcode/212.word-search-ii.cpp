/*
 * @lc app=leetcode id=212 lang=cpp
 *
 * [212] Word Search II
 *
 * https://leetcode.com/problems/word-search-ii/description/
 *
 * algorithms
 * Hard (32.53%)
 * Likes:    1974
 * Dislikes: 94
 * Total Accepted:    176.9K
 * Total Submissions: 541.3K
 * Testcase Example:  '[["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]]\n["oath","pea","eat","rain"]'
 *
 * Given a 2D board and a list of words from the dictionary, find all words in
 * the board.
 * 
 * Each word must be constructed from letters of sequentially adjacent cell,
 * where "adjacent" cells are those horizontally or vertically neighboring. The
 * same letter cell may not be used more than once in a word.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: 
 * board = [
 * ⁠ ['o','a','a','n'],
 * ⁠ ['e','t','a','e'],
 * ⁠ ['i','h','k','r'],
 * ⁠ ['i','f','l','v']
 * ]
 * words = ["oath","pea","eat","rain"]
 * 
 * Output: ["eat","oath"]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * All inputs are consist of lowercase letters a-z.
 * The values of words are distinct.
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
#define sz(a) int((a).size())
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

struct trie{
    bool eow = false;
    trie* ch[26] = {};
};

class Solution {
    int n,m;
    trie* root;
    set<string> out;
    int dirs[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new trie();
        out.clear();

        for(auto w: words)
            insert(w);    

        n = board.size();
        m = board[0].size();
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                string word;
                dfs(i,j,root,word,board);
            }
        }

        vector<string> res;
        for(auto word: out)
            res.push_back(word);
        return res;
    }

    void insert(string &word){
        auto cur = root;
        for(auto x: word){
            if(!cur->ch[x-'a'])
                cur->ch[x-'a'] = new trie();
            cur = cur->ch[x-'a'];
        }
        cur->eow = true;
    }

    void dfs(int i, int j, trie* cur, string &word, vector<vector<char>>& board){
        if(board[i][j]=='.') return;
        cur = cur->ch[board[i][j] -'a'];
        if(!cur) return;

        word.push_back(board[i][j]);
        char here = board[i][j];
        board[i][j] = '.'; // mark as visited

        if(cur->eow) out.insert(word);

        for(auto dir: dirs){
            int nx = i + dir[0];
            int ny = j + dir[1];
            if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
            dfs(nx,ny,cur,word,board);
        }
        
        word.pop_back();
        board[i][j] = here;
    }
};
// @lc code=end

int main(){
    vector<vector<char>> board = {
                    {'o','a','a','n'},
                    {'e','t','a','e'},
                    {'i','h','k','r'},
                    {'i','f','l','v'}
                    };

    vs words = {"oath","pea","eat","rain"};
    Solution sol; vs out;
    out =  sol.findWords(board,words); print(out);

    return 0;
}
