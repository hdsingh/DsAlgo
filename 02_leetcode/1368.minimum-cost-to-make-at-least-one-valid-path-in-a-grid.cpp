/*
 * @lc app=leetcode id=1368 lang=cpp
 *
 * [1368] Minimum Cost to Make at Least One Valid Path in a Grid
 *
 * https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/description/
 *
 * algorithms
 * Hard (51.69%)
 * Likes:    147
 * Dislikes: 4
 * Total Accepted:    4.5K
 * Total Submissions: 8.8K
 * Testcase Example:  '[[1,1,1,1],[2,2,2,2],[1,1,1,1],[2,2,2,2]]'
 *
 * Given a m x n grid. Each cell of the grid has a sign pointing to the next
 * cell you should visit if you are currently in this cell. The sign of
 * grid[i][j] can be:
 * 
 * 1 which means go to the cell to the right. (i.e go from grid[i][j] to
 * grid[i][j + 1])
 * 2 which means go to the cell to the left. (i.e go from grid[i][j] to
 * grid[i][j - 1])
 * 3 which means go to the lower cell. (i.e go from grid[i][j] to grid[i +
 * 1][j])
 * 4 which means go to the upper cell. (i.e go from grid[i][j] to grid[i -
 * 1][j])
 * 
 * 
 * Notice that there could be some invalid signs on the cells of the grid which
 * points outside the grid.
 * 
 * You will initially start at the upper left cell (0,0). A valid path in the
 * grid is a path which starts from the upper left cell (0,0) and ends at the
 * bottom-right cell (m - 1, n - 1) following the signs on the grid. The valid
 * path doesn't have to be the shortest.
 * 
 * You can modify the sign on a cell with cost = 1. You can modify the sign on
 * a cell one time only.
 * 
 * Return the minimum cost to make the grid have at least one valid path.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: grid = [[1,1,1,1],[2,2,2,2],[1,1,1,1],[2,2,2,2]]
 * Output: 3
 * Explanation: You will start at point (0, 0).
 * The path to (3, 3) is as follows. (0, 0) --> (0, 1) --> (0, 2) --> (0, 3)
 * change the arrow to down with cost = 1 --> (1, 3) --> (1, 2) --> (1, 1) -->
 * (1, 0) change the arrow to down with cost = 1 --> (2, 0) --> (2, 1) --> (2,
 * 2) --> (2, 3) change the arrow to down with cost = 1 --> (3, 3)
 * The total cost = 3.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: grid = [[1,1,3],[3,2,2],[1,1,4]]
 * Output: 0
 * Explanation: You can follow the path from (0, 0) to (2, 2).
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: grid = [[1,2],[4,3]]
 * Output: 1
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: grid = [[2,2,2],[2,2,2]]
 * Output: 3
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: grid = [[4]]
 * Output: 0
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 100
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

// Single source shortest path, 0-1 BFS
// Model this problem as shortest path finding.
// Consider each cell as node(u) of the graph connected with its adjacent cell(v)
// If the adj cell has the same direction, the cost is from u to v is 0 else 1
// One more optimisation: Instead of simple dijkstras use 0-1 BFS.
// Since the edge weights are binary 0/1, it is always going to be one of two
// hence no need to use Priority Queue
class Solution {
    const vvi dirs = {{0,1},{0,-1},{1,0},{-1,0}};
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vvi dist(n, vi(m, 1e9));  // dist to reach from 0 to cell(x,y)
        vector<vector<bool>> vis(n, vector<bool>(m));
        dist[0][0] = 0;
        deque<array<int, 2>> dq;
        dq.push_back({0,0});

        while(dq.size()){
            array<int,2> u = dq.front(); dq.pop_front();

            if(vis[u[0]][u[1]]) continue;
            vis[u[0]][u[1]] = true;

            for(int k = 0; k<4; ++k){
                int nx = u[0] + dirs[k][0], ny = u[1] + dirs[k][1];
                if(nx<0 || nx>=n || ny<0 || ny>=m) continue;

                int nd = dist[u[0]][u[1]];
                if(k+1!=grid[u[0]][u[1]])
                    ++nd;
                
                if(nd<dist[nx][ny]){
                    dist[nx][ny] = nd;

                    if(k+1==grid[u[0]][u[1]])
                        dq.push_front({nx,ny});
                    else 
                        dq.push_back({nx,ny});
                }
            }
        }
        return dist[n-1][m-1];
    }
};

// @lc code=end

int main(){
    Solution sol; vvi grid; int out;
    grid = {{1,1,1,1},{2,2,2,2},{1,1,1,1},{2,2,2,2}};
    out = sol.minCost(grid); deb(out);
    grid = {{1,1,3},{3,2,2},{1,1,4}};
    out = sol.minCost(grid); deb(out);

    grid = {{1,2},{4,3}};
    out = sol.minCost(grid); deb(out);

    grid = {{2,2,2},{2,2,2}};
    out = sol.minCost(grid); deb(out);

    grid = {{4}};
    out = sol.minCost(grid); deb(out);
    
    return 0;
}
