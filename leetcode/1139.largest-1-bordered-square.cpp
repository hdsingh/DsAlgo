/*
 * @lc app=leetcode id=1139 lang=cpp
 *
 * [1139] Largest 1-Bordered Square
 *
 * https://leetcode.com/problems/largest-1-bordered-square/description/
 *
 * algorithms
 * Medium (45.69%)
 * Likes:    110
 * Dislikes: 31
 * Total Accepted:    6.8K
 * Total Submissions: 14.8K
 * Testcase Example:  '[[1,1,1],[1,0,1],[1,1,1]]'
 *
 * Given a 2D grid of 0s and 1s, return the number of elements in the largest
 * square subgrid that has all 1s on its border, or 0 if such a subgrid doesn't
 * exist in the grid.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: grid = [[1,1,1],[1,0,1],[1,1,1]]
 * Output: 9
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: grid = [[1,1,0,0]]
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= grid.length <= 100
 * 1 <= grid[0].length <= 100
 * grid[i][j] is 0 or 1
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
template <typename T>void print_vv(T v){int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}
template <class T, class U> void print_m(map<T,U> m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}

class Solution {
public:
    int largest1BorderedSquare(vvi& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int mp = min(n, m); //max possible

        vvi lt(n, vi(m)), up(n, vi(m));
        
        forn(i, n){
            forn(j,m){
                if(grid[i][j]){
                    lt[i][j] = (j ? lt[i][j-1] : 0) + 1;
                    up[i][j] = (i ? up[i-1][j] : 0) + 1;
                }
            }
        }

        for(int l=min(n,m); l>0; l--){
            for(int i=0; i<n-l+1; ++i){
                for(int j=0; j<m-l+1; ++j){
                    if(min({up[i+l-1][j], up[i+l-1][j+l-1], lt[i][j+l-1], lt[i+l-1][j+l-1]})>=l)
                    return l*l;
                }
            }
        }
        
        return 0;
    }
};
// @lc code=end

int main(){
    Solution sol; int out;
    vvi grid;
    grid = {{1,1,1},{1,0,1},{1,1,1}};
    out = sol.largest1BorderedSquare(grid); deb(out);

    grid = {{1,1,0,0}};
    out = sol.largest1BorderedSquare(grid); deb(out);

    grid = {{1,1,1,1,1},
            {0,1,1,0,1},
            {1,1,0,1,1},
            {1,1,1,1,1}};
    out = sol.largest1BorderedSquare(grid); deb(out);

    grid = {{0,1,1,1,1,1,1,0},
            {1,1,1,1,1,1,1,1},
            {1,0,1,1,1,0,1,1},
            {1,1,1,1,0,1,1,1},
            {1,0,1,0,0,1,1,1},
            {0,1,1,1,1,0,1,1}};
    out = sol.largest1BorderedSquare(grid); deb(out);

    grid = {{1,1,1,1,0,1,1,1,1},
            {0,0,1,1,1,1,1,1,1},
            {0,1,0,1,1,1,0,1,0},
            {0,1,1,1,1,1,1,0,1},
            {1,0,0,1,1,1,1,1,1},
            {1,1,1,1,0,1,0,1,1},
            {1,0,1,1,0,1,1,1,1}};
    out = sol.largest1BorderedSquare(grid); deb(out);
    return 0;
}