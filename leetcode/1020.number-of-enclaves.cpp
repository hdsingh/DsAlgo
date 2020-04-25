/*
 * @lc app=leetcode id=1020 lang=cpp
 *
 * [1020] Number of Enclaves
 *
 * https://leetcode.com/problems/number-of-enclaves/description/
 *
 * algorithms
 * Medium (55.71%)
 * Likes:    178
 * Dislikes: 17
 * Total Accepted:    13.1K
 * Total Submissions: 23.6K
 * Testcase Example:  '[[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]'
 *
 * Given a 2D array A, each cell is 0 (representing sea) or 1 (representing
 * land)
 * 
 * A move consists of walking from one land square 4-directionally to another
 * land square, or off the boundary of the grid.
 * 
 * Return the number of land squares in the grid for which we cannot walk off
 * the boundary of the grid in any number of moves.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
 * Output: 3
 * Explanation: 
 * There are three 1s that are enclosed by 0s, and one 1 that isn't enclosed
 * because its on the boundary.
 * 
 * Example 2:
 * 
 * 
 * Input: [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
 * Output: 0
 * Explanation: 
 * All 1s are either on the boundary or can reach the boundary.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= A.length <= 500
 * 1 <= A[i].length <= 500
 * 0 <= A[i][j] <= 1
 * All rows have the same size.
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

// Do DFS for unvisited land cells(starting on the boundary), marking them a visited
// Count all the unvisited land cells
class Solution0 {
    int tot, n,m;
    const vvi dirs = {{0,1},{0,-1},{1,0},{-1,0}};
public:
    int numEnclaves(vvi &a) {
        n = a.size(); m = a[0].size(); tot = 0;
        for(int i=0; i<n; ++i){
            if(a[i][0]==1) dfs(i,0,a);
            if(a[i][m-1]==1) dfs(i,m-1,a);
        }

        for(int j=0; j<m; ++j){
            if(a[0][j]==1) dfs(0,j,a);
            if(a[n-1][j]==1) dfs(n-1, j,a);
        }

        // Count unvisited
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(a[i][j]==1) ++tot;
            }
        }

        // print_vv(a);

        return tot;
    }

    void dfs(int x, int y, vvi &a){
        if(x<0 || x>=n || y<0 || y>=m || a[x][y]==0) return;
        a[x][y] = 0;
        dfs(x+1, y, a);
        dfs(x-1, y, a);
        dfs(x, y+1, a);
        dfs(x, y-1, a);
    }
};

// BFS
class Solution {
public:
    int numEnclaves(vector<vector<int>>& a) {
        int tot = 0;
        int n = a.size(); int m = a[0].size();
        queue<pair<int,int>> q;

        // push in boundaries
        forn(i,n){
            forn(j,m){
                if((i*j==0 || i==n-1 || j==m-1) && a[i][j]==1)
                    q.push({i,j});
            }
        }

        // Mark boundaues and connected land as visited
        while(!q.empty()){
            int x = q.front().first; int y = q.front().second; q.pop();
            // if invalid continue
            if(x<0 || x==n || y<0 || y==m || a[x][y]!=1) continue;
            a[x][y] = 0;
            q.push({x+1,y}); q.push({x-1,y});
            q.push({x,y+1}); q.push({x,y-1});
        }

        // count unvisited
        forn(i,n)
            forn(j,m)
                tot+=a[i][j];
        // print_vv(a);
        
        return tot;

    }
};

// @lc code=end

int main(){
    Solution sol; vvi a; int out;
    a = {{0,0,0,0},
         {1,0,1,0},
         {0,1,1,0},
         {0,0,0,0}};
    out = sol.numEnclaves(a); deb(out);

    a = {{0,1,1,0},
         {0,0,1,0},
         {0,0,1,0},
         {0,0,0,0}};
    out = sol.numEnclaves(a); deb(out);

    return 0;
}
