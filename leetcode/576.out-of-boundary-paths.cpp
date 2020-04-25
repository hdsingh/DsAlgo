/*
 * @lc app=leetcode id=576 lang=cpp
 *
 * [576] Out of Boundary Paths
 *
 * https://leetcode.com/problems/out-of-boundary-paths/description/
 *
 * algorithms
 * Medium (33.61%)
 * Likes:    389
 * Dislikes: 120
 * Total Accepted:    22.9K
 * Total Submissions: 68.1K
 * Testcase Example:  '2\n2\n2\n0\n0'
 *
 * There is an m by n grid with a ball. Given the start coordinate (i,j) of the
 * ball, you can move the ball to adjacent cell or cross the grid boundary in
 * four directions (up, down, left, right). However, you can at most move N
 * times. Find out the number of paths to move the ball out of grid boundary.
 * The answer may be very large, return it after mod 10^9 + 7.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: m = 2, n = 2, N = 2, i = 0, j = 0
 * Output: 6
 * Explanation:
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: m = 1, n = 3, N = 3, i = 0, j = 1
 * Output: 12
 * Explanation:
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * Once you move the ball out of boundary, you cannot move it back.
 * The length and height of the grid is in range [1,50].
 * N is in range [0,50].
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
template <typename T>void print_vv(T v){int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}
template <class T, class U> void print_m(map<T,U> m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}

class Solution {
public:
    int findPaths(int n, int m, int K, int x, int y) {
        if(K==0) return 0;
        vvi dirs = {{1,0}, {-1, 0}, {0,1}, {0,-1}};

        int dp[K][n][m];
        memset(dp, 0, sizeof(dp));
        // number of ways to reach i,j in kth move
        
        int ways = 0;
        dp[0][x][y] = 1;
        fore(k, 1, K){
            forn(i, n){
                forn(j, m){
                    for(vi d: dirs){
                        int old_i = i+d[0];
                        int old_j = j+d[1];
                        if(0<=old_i && old_i<n && 0<=old_j && old_j<m){
                            add_self(dp[k][i][j] , dp[k-1][old_i][old_j]);
                        }
                    }
                }
            }
        }

        fore(k, 0, K){
            forn(i, n){
                forn(j, m){
                    if(i==0) add_self(ways, dp[k][i][j]);
                    if(j==0) add_self(ways, dp[k][i][j]);
                    if(i==n-1) add_self(ways, dp[k][i][j]);
                    if(j==m-1) add_self(ways, dp[k][i][j]);
                    
                }
            }
        }
        
        return ways;
    }
};

// @lc code=end

int main(){
    Solution sol;
    int n, m, N,i,j, out;
    m = 2, n = 2, N = 2, i = 0, j = 0;
    out = sol.findPaths(m,n,N, i, j); deb(out);

    m = 1, n = 3, N = 3, i = 0, j = 1;
    out = sol.findPaths(m,n, N, i, j); deb(out);
    
    m = 10; n = 10; N = 0; i=5; j=5;
    out = sol.findPaths(m,n, N, i, j); deb(out);

    m = 36, n=5, N=50, i=15, j=3;
    out = sol.findPaths(m,n, N, i, j); deb(out);

    return 0;
}

