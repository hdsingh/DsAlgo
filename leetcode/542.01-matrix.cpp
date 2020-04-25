/*
 * @lc app=leetcode id=542 lang=cpp
 *
 * [542] 01 Matrix
 *
 * https://leetcode.com/problems/01-matrix/description/
 *
 * algorithms
 * Medium (38.42%)
 * Likes:    1074
 * Dislikes: 97
 * Total Accepted:    69.7K
 * Total Submissions: 181.4K
 * Testcase Example:  '[[0,0,0],[0,1,0],[0,0,0]]'
 *
 * Given a matrix consists of 0 and 1, find the distance of the nearest 0 for
 * each cell.
 * 
 * The distance between two adjacent cells is 1.
 * 
 * 
 * 
 * Example 1: 
 * 
 * 
 * Input:
 * [[0,0,0],
 * ⁠[0,1,0],
 * ⁠[0,0,0]]
 * 
 * Output:
 * [[0,0,0],
 * [0,1,0],
 * [0,0,0]]
 * 
 * 
 * Example 2: 
 * 
 * 
 * Input:
 * [[0,0,0],
 * ⁠[0,1,0],
 * ⁠[1,1,1]]
 * 
 * Output:
 * [[0,0,0],
 * ⁠[0,1,0],
 * ⁠[1,2,1]]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The number of elements of the given matrix will not exceed 10,000.
 * There are at least one 0 in the given matrix.
 * The cells are adjacent in only four directions: up, down, left and right.
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

// Besides DFS and BFS, simple dp solution
// For each cell that is 1, we need to know its distance to nearest 0
// that would be min(all adj cells) + 1
// we can find this min distance in 2 passes, 
// pass 1 using top and left
// pass 2 using bottom and  right
class Solution {
    const int inf = 1e6;
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& M) {
        int n = M.size(); int m = M[0].size();
        vvi dist(n, vi(m)); 

        for(int i=0;  i<n; ++i){
            for(int j=0; j<m; ++j){
                if(M[i][j]) {
                    dist[i][j] = 1 + min({ i ? dist[i-1][j] : inf, j ? dist[i][j-1] : inf});
                }
            }
        } 

        for(int i=n-1; i>=0; --i){
            for(int j=m-1; j>=0; --j){
                if(M[i][j]){
                    dist[i][j] = min({dist[i][j], 1 + min( i+1<n ?  dist[i+1][j] : inf, j+1<m ? dist[i][j+1] : inf) });
                }
            }
        }

        return dist;
    }
};
// @lc code=end

int main(){
    Solution sol;
    vvi M = {{0,0,0},
            {0,1,0},
            {0,0,0}};
    M  = sol.updateMatrix(M); print_vv(M);

    M = {{0,0,0},
         {0,1,0},
         {1,1,1}};
    M  = sol.updateMatrix(M); print_vv(M);

    return 0;
}
