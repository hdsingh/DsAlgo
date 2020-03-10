/*
 * @lc app=leetcode id=959 lang=cpp
 *
 * [959] Regions Cut By Slashes
 *
 * https://leetcode.com/problems/regions-cut-by-slashes/description/
 *
 * algorithms
 * Medium (65.10%)
 * Likes:    584
 * Dislikes: 116
 * Total Accepted:    14.2K
 * Total Submissions: 21.9K
 * Testcase Example:  '[" /","/ "]'
 *
 * In a N x N grid composed of 1 x 1 squares, each 1 x 1 square consists of a
 * /, \, or blank space.  These characters divide the square into contiguous
 * regions.
 * 
 * (Note that backslash characters are escaped, so a \ is represented as
 * "\\".)
 * 
 * Return the number of regions.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * [
 * " /",
 * "/ "
 * ]
 * Output: 2
 * Explanation: The 2x2 grid is as follows:
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * [
 * " /",
 * "  "
 * ]
 * Output: 1
 * Explanation: The 2x2 grid is as follows:
 * 
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input:
 * [
 * "\\/",
 * "/\\"
 * ]
 * Output: 4
 * Explanation: (Recall that because \ characters are escaped, "\\/" refers to
 * \/, and "/\\" refers to /\.)
 * The 2x2 grid is as follows:
 * 
 * 
 * 
 * 
 * Example 4:
 * 
 * 
 * Input:
 * [
 * "/\\",
 * "\\/"
 * ]
 * Output: 5
 * Explanation: (Recall that because \ characters are escaped, "/\\" refers to
 * /\, and "\\/" refers to \/.)
 * The 2x2 grid is as follows:
 * 
 * 
 * 
 * 
 * Example 5:
 * 
 * 
 * Input:
 * [
 * "//",
 * "/ "
 * ]
 * Output: 3
 * Explanation: The 2x2 grid is as follows:
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= grid.length == grid[0].length <= 30
 * grid[i][j] is either '/', '\', or ' '.
 * 
 * 
 * 
 * 
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

// Upscale each '/' and '\\' to 3*3 grid
//  0 0 1
//  0 1 0
//  1 0 0  
// represents '/'
// Now we ca simply find the number of groups or number of islands
class Solution {
    vvi grid;
    int n,m;
public:
    int regionsBySlashes(vector<string>& oldGrid) {
        grid.clear();
        int oldn = oldGrid.size();
        int oldm = oldGrid[0].size();
        
        n = oldn*3; m = oldm*3;
        grid.resize(n,vi(m));
        
        for(int oi=0; oi<oldn; ++oi){
            for(int oj=0; oj<oldm; ++oj){
                if(oldGrid[oi][oj]=='/'){
                    grid[3*oi][3*oj+2] = 1;
                    grid[3*oi+1][3*oj+1] = 1;
                    grid[3*oi+2][3*oj] = 1;
                }else if(oldGrid[oi][oj]=='\\'){
                    grid[3*oi][3*oj] = 1;
                    grid[3*oi+1][3*oj+1] = 1;
                    grid[3*oi+2][3*oj+2] = 1;
                }
            }
        }

        // print_vv(oldGrid);
        // print_vv(grid);

        int groups = 0;
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(grid[i][j]==0){
                    ++groups;
                    dfs(i,j);
                }
            }
        }
    
        return groups;        
    }

    void dfs(int x, int y){
        if(x<0 || x>=n || y<0 || y>=m || grid[x][y]==1) return;
        grid[x][y] = 1;
        dfs(x+1,y); dfs(x-1,y);
        dfs(x,y+1); dfs(x,y-1);
    }
};
// @lc code=end

int main(){
    Solution sol; vs grid; int out;
    grid = {
        " /",
        "/ "
        };
    out = sol.regionsBySlashes(grid); deb(out);

    grid = {
    " /",
    "  "
    };
    out = sol.regionsBySlashes(grid); deb(out);

    grid = {
    "\\/",
    "/\\"
    };
    out = sol.regionsBySlashes(grid); deb(out);


    grid = {
    "/\\",
    "\\/"
    };
    out = sol.regionsBySlashes(grid); deb(out);


    grid = {
    "//",
    "/ "
    };
    out = sol.regionsBySlashes(grid); deb(out);

    return 0;
}
