/*
 * @lc app=leetcode id=778 lang=cpp
 *
 * [778] Swim in Rising Water
 *
 * https://leetcode.com/problems/swim-in-rising-water/description/
 *
 * algorithms
 * Hard (50.84%)
 * Likes:    467
 * Dislikes: 40
 * Total Accepted:    19.5K
 * Total Submissions: 38.3K
 * Testcase Example:  '[[0,2],[1,3]]'
 *
 * On an N x N grid, each square grid[i][j] represents the elevation at that
 * point (i,j).
 * 
 * Now rain starts to fall. At time t, the depth of the water everywhere is t.
 * You can swim from a square to another 4-directionally adjacent square if and
 * only if the elevation of both squares individually are at most t. You can
 * swim infinite distance in zero time. Of course, you must stay within the
 * boundaries of the grid during your swim.
 * 
 * You start at the top left square (0, 0). What is the least time until you
 * can reach the bottom right square (N-1, N-1)?
 * 
 * Example 1:
 * 
 * 
 * Input: [[0,2],[1,3]]
 * Output: 3
 * Explanation:
 * At time 0, you are in grid location (0, 0).
 * You cannot go anywhere else because 4-directionally adjacent neighbors have
 * a higher elevation than t = 0.
 * 
 * You cannot reach point (1, 1) until time 3.
 * When the depth of water is 3, we can swim anywhere inside the grid.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
 * Output: 16
 * Explanation:
 * ⁠0  1  2  3  4
 * 24 23 22 21  5
 * 12 13 14 15 16
 * 11 17 18 19 20
 * 10  9  8  7  6
 * 
 * The final route is marked in bold.
 * We need to wait until time 16 so that (0, 0) and (4, 4) are connected.
 * 
 * 
 * Note:
 * 
 * 
 * 2 <= N <= 50.
 * grid[i][j] is a permutation of [0, ..., N*N - 1].
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
template <class T, class U> void print_m(unordered_map<T,U> m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}


// Brute Force + Pruning on the basis of minTime
// i.e if a new_time>min_time, it can never form minimum;
// TLE
class Solution0 {
    int min_time, n;
    vvi visited, memo;
    const vvi dirs = {{0,1},{0,-1},{1,0},{-1,0}};
public:
    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();
        int startTime = grid[0][0];
        min_time = INT_MAX;
        visited.clear(); visited.resize(n, vi(n));
        visited[0][0] = 1;
        dfs(0,0, startTime, grid);
        return min_time;
    }

    void dfs(int x, int y, int time, vvi &grid){
        if(x==n-1 && y==n-1){
            min_time = min(min_time, time);
            return;
        }

        for(auto &dir: dirs){
            int nx = x + dir[0];
            int ny = y + dir[1];
            if(is_valid(nx, ny) && !visited[nx][ny]){
                visited[nx][ny] = 1;
                int new_time = max(time, grid[nx][ny]);
                if(new_time>min_time) continue;
                dfs(nx, ny, new_time, grid);
                visited[nx][ny] = 0;
            }
        }
    }

    bool is_valid(const int &x, const int &y){
        if(x>=0 && x<n && y>=0 && y<n) return true;
        return false;
    }
};

// Union Find : We can time starting from 0 and going till N*N
// in each second, a grid cell whose elevation is equal to time 
// becomes valid. we can merge this cells with its neighbours
// if the elevation of neighbours is less(ie. if they have already submerged in
// water and it is possible to swim to them)
// In order to locate the cell with elevation in O(1) unordered_map will be used
// Unite will be done on the basis of position and would terminate when pos 0 ans n*n-1 
// are connected
// complexity : O(inv-akkerman(n^2)) ~ O(n^2)
class Solution1 {
    int n;
    const vvi dirs = {{0,1},{0,-1},{1,0},{-1,0}};
    vi par;
public:
    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();
        par.clear(); par.resize(n*n);
        iota(all(par),0);

        unordered_map<int,int> loc;
        forn(i, n)
            forn(j,n)
                loc[grid[i][j]] = i*n+j;

        int time;
        for(time = 0; time<n*n; ++time){
            int pos = loc[time];
            int x = pos/n; 
            int y = pos%n;
            for(auto &dir: dirs){
                int nx = x + dir[0];
                int ny = y + dir[1];
                if(!is_valid(nx,ny, time, grid)) continue;
                unite(pos, nx*n + ny);
            }
            if(is_connected(0, n*n-1)) break;
        }

        return time;
    }

    bool is_valid(int x, int y, int time, vvi &grid){
        if(x>=0 && x<n && y>=0 && y<n && grid[x][y]<time) return true;
        return false;
    }

    void unite(int x, int y){
        x = find_par(x);
        y = find_par(y);
        par[y] = x;
    }

    int find_par(int x){
        if(par[x]==x) return x;
        return par[x] = find_par(par[x]);
    }

    bool is_connected(int x, int y){
        return find_par(x) == find_par(y);
    }

};


// Dijkstras:
// Find a path to reach the end such that the value of maximum 
// node in the path is minimized.
// Relaxation of node(nx,ny) will be done by weight_loc(nx,ny) = max(cur_w, grid[nx][ny]) 
// O(n^2 * logn) (to visit all the cells + PQ)
class Solution {
    int n;
    const vvi dirs = {{0,1},{0,-1},{1,0},{-1,0}};
public:
    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();
        vi visited(n*n);

        // vvi minWt(n, vi(n)); 
        // the same grid can be used to keep track of minWt, so not needed

        pii cur = {grid[0][0], 0}; // weight, loc
        priority_queue<pii, vector<pii>, greater<pii>> q;
        q.push(cur);

        while(!q.empty()){
            pii cur = q.top(); q.pop();
            int cur_w = cur.first; int cur_loc = cur.second;
            if(visited[cur_loc]) continue;
            visited[cur_loc] = 1;
            int x = cur_loc/n; int y = cur_loc%n;
            // deb2(x,y);
            // minWt[x][y] = cur_w;
            grid[x][y] = cur_w;

            for(auto &dir: dirs){
                int nx = x + dir[0]; 
                int ny = y + dir[1];
                if(is_valid(nx,ny) && !visited[nx*n + ny]){
                    // deb2(x,y);
                    // deb2(nx,ny);
                    q.push({max(cur_w, grid[nx][ny]), nx*n+ny});
                }
            }
        }

        // print_vv(minWt);
        // print_vv(grid);
        return grid[n-1][n-1];

        // return minWt[n-1][n-1];
    }

    bool is_valid(int x, int y){
        return (x>=0 && x<n && y>=0 && y<n);
    }
};

// @lc code=end

int main(){
    Solution sol; vvi grid; int out;
    grid = {{0,2},
            {1,3}};
    out = sol.swimInWater(grid); deb(out);

    grid = {{0,1,2},
            {9,5,3},
            {7,8,4}};
    out = sol.swimInWater(grid); deb(out);

    grid = {{0,1,2,3,4},{24,23,22,21,5},{12,13,14,15,16},{11,17,18,19,20},{10,9,8,7,6}};
    out = sol.swimInWater(grid); deb(out);

    grid = {{3,19,34,15,7,21},{31,25,8,0,16,27},{4,1,13,18,28,17},{6,2,24,23,10,35},{20,5,22,12,32,29},{33,11,9,14,30,26}};
    out = sol.swimInWater(grid); deb(out);

    grid = {{26,99,80,1,89,86,54,90,47,87},{9,59,61,49,14,55,77,3,83,79},{42,22,15,5,95,38,74,12,92,71},{58,40,64,62,24,85,30,6,96,52},{10,70,57,19,44,27,98,16,25,65},{13,0,76,32,29,45,28,69,53,41},{18,8,21,67,46,36,56,50,51,72},{39,78,48,63,68,91,34,4,11,31},{97,23,60,17,66,37,43,33,84,35},{75,88,82,20,7,73,2,94,93,81}};
    out = sol.swimInWater(grid); deb(out);

    return 0;
}