/*
 * @lc app=leetcode id=1293 lang=cpp
 *
 * [1293] Shortest Path in a Grid with Obstacles Elimination
 *
 * https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/description/
 *
 * algorithms
 * Hard (39.92%)
 * Likes:    131
 * Dislikes: 1
 * Total Accepted:    3.5K
 * Total Submissions: 8.8K
 * Testcase Example:  '[[0,0,0],[1,1,0],[0,0,0],[0,1,1],[0,0,0]]\n1'
 *
 * Given a m * n grid, where each cell is either 0 (empty) or 1 (obstacle). In
 * one step, you can move up, down, left or right from and to an empty cell.
 * 
 * Return the minimum number of steps to walk from the upper left corner (0, 0)
 * to the lower right corner (m-1, n-1) given that you can eliminate at most k
 * obstacles. If it is not possible to find such walk return -1.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: 
 * grid = 
 * [[0,0,0],
 * [1,1,0],
 * ⁠[0,0,0],
 * [0,1,1],
 * ⁠[0,0,0]], 
 * k = 1
 * Output: 6
 * Explanation: 
 * The shortest path without eliminating any obstacle is 10. 
 * The shortest path with one obstacle elimination at position (3,2) is 6. Such
 * path is (0,0) -> (0,1) -> (0,2) -> (1,2) -> (2,2) -> (3,2) -> (4,2).
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 
 * grid = 
 * [[0,1,1],
 * [1,1,1],
 * [1,0,0]], 
 * k = 1
 * Output: -1
 * Explanation: 
 * We need to eliminate at least two obstacles to find such a walk.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * grid.length == m
 * grid[0].length == n
 * 1 <= m, n <= 40
 * 1 <= k <= m*n
 * grid[i][j] == 0 or 1
 * grid[0][0] == grid[m-1][n-1] == 0
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

// Ref: https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/discuss/452434/Java-BFS-Concise-and-Clean-O(m*n*k)
//      https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/discuss/453880/C%2B%2B-0ms-BFS-track-remaining-k-and-take-a-shortcut
// Use q({x,y,remaining k})
// Optimisation: at each point we check if the remaining distance is less than the, remaining 
// turns to eliminate obstacles, if so we directly return the manhatttan distance
class Solution {
    vvi dirs = {{0,1},{0,-1},{1,0},{-1,0}};
public:
    int shortestPath(vector<vector<int>>& grid, int K) {
        int n = grid.size(), m = grid[0].size();
        int minSteps = (0, n+m-2), obstacles = minSteps -1;
        if(obstacles<K) return minSteps;

        if(n==1 && m==1) return 0;
        bool vis[n][m][K+1];
        memset(vis, 0, sizeof(vis));

        queue<array<int,3>> q;
        q.push({0,0,0}); //x,y, removed obstacles
        vis[0][0][0] = 1;

        int dist = -1;
        while(q.size()){
            ++dist;
            int sz = q.size();

            for(int i=0; i<sz; ++i){
                int x = q.front()[0], y = q.front()[1], curk = q.front()[2];
                q.pop();

                if(x==n-1 && y==m-1) return dist;

                for(auto dir: dirs){
                    int nx = x + dir[0], ny = y + dir[1];
                    if(nx<0 || nx>=n || ny<0 || ny>=m) continue;

                    int nk = curk + grid[nx][ny]; // number of obstacles eliminated so far

                    int stepsToTar = n-nx-1 + m-ny-1;
                    // if stepsToTarget from nx, ny is less than K-eleminated obs(remining turs to eliminate)
                    // then we can directly go to target
                    if(stepsToTar<K-nk) return dist + 1 + stepsToTar;

                    if(nk<=K && !vis[nx][ny][nk]){
                        vis[nx][ny][nk] = 1;
                        q.push({nx,ny,nk});
                    }
                }
            }
        }

        return -1;
    }
};
// @lc code=end

int main(){
    Solution sol; vvi grid; int k; int out;
    grid = 
        {{0,0,0},
        {1,1,0},
        {0,0,0},
        {0,1,1},
        {0,0,0}}, 
        k = 1;
    out = sol.shortestPath(grid, k); deb(out);

    grid = 
        {{0,1,1},
        {1,1,1},
        {1,0,0}}, 
        k = 1;
    out = sol.shortestPath(grid, k); deb(out);

    grid ={{0,1,1,0}}, k = 1;
    out = sol.shortestPath(grid, k); deb(out);

    grid = {{0,1,0,0,0,1,0,0},
            {0,1,0,1,0,1,0,1},
            {0,0,0,1,0,0,1,0}}; 
    k = 1;
    out = sol.shortestPath(grid, k); deb(out);
    return 0;
}
