/*
 * @lc app=leetcode id=1162 lang=cpp
 *
 * [1162] As Far from Land as Possible
 *
 * https://leetcode.com/problems/as-far-from-land-as-possible/description/
 *
 * algorithms
 * Medium (41.79%)
 * Likes:    245
 * Dislikes: 16
 * Total Accepted:    11.8K
 * Total Submissions: 28.1K
 * Testcase Example:  '[[1,0,1],[0,0,0],[1,0,1]]'
 *
 * Given an N x N grid containing only values 0 and 1, where 0 represents water
 * and 1 represents land, find a water cell such that its distance to the
 * nearest land cell is maximized and return the distance.
 * 
 * The distance used in this problem is the Manhattan distance: the distance
 * between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.
 * 
 * If no land or water exists in the grid, return -1.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: [[1,0,1],[0,0,0],[1,0,1]]
 * Output: 2
 * Explanation: 
 * The cell (1, 1) is as far as possible from all the land with distance 2.
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input: [[1,0,0],[0,0,0],[0,0,0]]
 * Output: 4
 * Explanation: 
 * The cell (2, 2) is as far as possible from all the land with distance
 * 4.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= grid.length == grid[0].length <= 100
 * grid[i][j] is 0 or 1
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

// Locate all the land cells by DFS and start a BFS from them, each level
// marking visited with the depth
// to save visited space, lets mark with 100 
class Solution {
    int n,m;
    queue<pii> q;
    const vvi dirs = {{0,1},{0,-1},{1,0},{-1,0}};
    int cnt_land = 0;
public:
    int maxDistance(vector<vector<int>>& grid) {
        n = grid.size(); m = grid[0].size();
        cnt_land = 0;
        q = {};

        forn(i,n){
            forn(j,m){
                if(grid[i][j]==1)
                    dfs(i,j,grid);
            }
        }

        if(cnt_land==0  || cnt_land==n*m) return -1;
        // print_vv(grid);

        int depth = 1;
        while(!q.empty()){
            ++depth;
            int breadth = q.size();
            for(int i=0; i<breadth; ++i){
                int x = q.front().first;
                int y = q.front().second; q.pop();
                for(auto dir: dirs){
                    int nx = x+dir[0]; int ny = y + dir[1];
                    if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]==0){
                        grid[nx][ny] = depth;
                        q.push({nx,ny});
                    }
                }
            }
        }
        
        // print_vv(grid);

        return depth-1;
    }

    void dfs(int x, int y, vvi &grid){
        if(x<0 ||x>=n || y<0 || y>=m) return;
        if(grid[x][y]!=1){
            // add surrounding water cells to queue and mark them a visited
            if(grid[x][y]==0){
                q.push({x,y});
                grid[x][y] = 100;
            }
            return;
        };
        grid[x][y] = 100;
        ++cnt_land;
        dfs(x+1,y,grid); dfs(x-1,y,grid);
        dfs(x,y+1,grid); dfs(x,y-1,grid);
    }
};
// @lc code=end

int main(){
    Solution sol; vvi grid; int out;
    grid = {{1,0,1},{0,0,0},{1,0,1}};
    out = sol.maxDistance(grid); deb(out);

    grid = {{1,0,0},{0,0,0},{0,0,0}};
    out = sol.maxDistance(grid); deb(out);

    grid = {{1,1,1,1,1},{1,1,1,1,1},{1,1,1,1,1},{1,1,1,1,1},{1,1,1,1,1}};
    // grid = {{1},{1}};
    out = sol.maxDistance(grid); deb(out);


    return 0;
}
