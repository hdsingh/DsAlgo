/*
 * @lc app=leetcode id=934 lang=cpp
 *
 * [934] Shortest Bridge
 *
 * https://leetcode.com/problems/shortest-bridge/description/
 *
 * algorithms
 * Medium (46.13%)
 * Likes:    506
 * Dislikes: 40
 * Total Accepted:    19.2K
 * Total Submissions: 41.5K
 * Testcase Example:  '[[0,1],[1,0]]'
 *
 * In a given 2D binary array A, there are two islands.  (An island is a
 * 4-directionally connected group of 1s not connected to any other 1s.)
 * 
 * Now, we may change 0s to 1s so as to connect the two islands together to
 * form 1 island.
 * 
 * Return the smallest number of 0s that must be flipped.  (It is guaranteed
 * that the answer is at least 1.)
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [[0,1],[1,0]]
 * Output: 1
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[0,1,0],[0,0,0],[0,0,1]]
 * Output: 2
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
 * Output: 1
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= A.length = A[0].length <= 100
 * A[i][j] == 0 or A[i][j] == 1
 * 
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

// Find island 1 using DFS and grow it using BFS.
class Solution {
    int n,m;
    queue<pii> q;
    const vvi dirs = {{0,1},{0,-1},{1,0},{-1,0}};
public:
    int shortestBridge(vector<vector<int>>& a) {
        n = a.size(); m = a[0].size(); q = {};

        bool found = false;
        forn(i,n){
            forn(j,m){
                if(a[i][j]==1){
                    dfs(i,j,a);
                    found = true;
                    break;
                }
            }
            if(found) break;
        }

        // print_vv(a);

        int x,y;
        int dist = -1; 
        while(q.size()){
            ++dist;
            int breadth = q.size();
            for(int i=0; i<breadth; ++i){
                x = q.front().first; y = q.front().second; q.pop();
                // deb2(x,y);
                for(auto dir: dirs){
                    int nx = x + dir[0]; int ny = y + dir[1];
                    // if valid
                    if(nx>=0 && nx<n && ny>=0 && ny<m && a[nx][ny]!=2){
                        if(a[nx][ny]==1){
                            // print_vv(a);
                            return dist;
                        }
                        else{
                            a[nx][ny] = 2;
                            q.push({nx,ny});
                        }
                    }
                }
            }
        }        

        return -1; // code should not reach here for a valid input;        
    }
    
    // visit all elements of first island marking with 2.
    // Also save these elements into q to do BFS later
    void dfs(int x, int y, vvi &a){
        if(x<0 || x>=n || y<0 || y>=m || a[x][y]!=1) return;
        a[x][y] = 2;
        q.push({x,y});
        dfs(x+1,y,a); dfs(x-1, y,a);
        dfs(x,y+1,a); dfs(x,y-1,a);
    }

    
};
// @lc code=end

int main(){
    Solution sol; vvi a; int out;
    a = {{0,1},{1,0}};
    out = sol.shortestBridge(a); deb(out);

    a = {{0,1,0},{0,0,0},{0,0,1}};
    out = sol.shortestBridge(a); deb(out);

    a = {{1,1,1,1,1},{1,0,0,0,1},{1,0,1,0,1},{1,0,0,0,1},{1,1,1,1,1}};
    out = sol.shortestBridge(a); deb(out);

    a = {{0,0,1,0,1},
         {0,1,1,0,1},
         {0,1,0,0,1},
         {0,0,0,0,0},
         {0,0,0,0,0}};
    out = sol.shortestBridge(a); deb(out);

    return 0;
}
