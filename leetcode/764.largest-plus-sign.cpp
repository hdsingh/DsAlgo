/*
 * @lc app=leetcode id=764 lang=cpp
 *
 * [764] Largest Plus Sign
 *
 * https://leetcode.com/problems/largest-plus-sign/description/
 *
 * algorithms
 * Medium (45.23%)
 * Likes:    352
 * Dislikes: 79
 * Total Accepted:    17.4K
 * Total Submissions: 38.5K
 * Testcase Example:  '5\n[[4,2]]'
 *
 * 
 * In a 2D grid from (0, 0) to (N-1, N-1), every cell contains a 1, except
 * those cells in the given list mines which are 0.  What is the largest
 * axis-aligned plus sign of 1s contained in the grid?  Return the order of the
 * plus sign.  If there is none, return 0.
 * 
 * An "axis-aligned plus sign of 1s of order k" has some center grid[x][y] = 1
 * along with 4 arms of length k-1 going up, down, left, and right, and made of
 * 1s.  This is demonstrated in the diagrams below.  Note that there could be
 * 0s or 1s beyond the arms of the plus sign, only the relevant area of the
 * plus sign is checked for 1s.
 * 
 * 
 * Examples of Axis-Aligned Plus Signs of Order k:
 * Order 1:
 * 000
 * 010
 * 000
 * 
 * Order 2:
 * 00000
 * 00100
 * 01110
 * 00100
 * 00000
 * 
 * Order 3:
 * 0000000
 * 0001000
 * 0001000
 * 0111110
 * 0001000
 * 0001000
 * 0000000
 * 
 * 
 * Example 1:
 * Input: N = 5, mines = [[4, 2]]
 * Output: 2
 * Explanation:
 * 11111
 * 11111
 * 11111
 * 11111
 * 11011
 * In the above grid, the largest plus sign can only be order 2.  One of them
 * is marked in bold.
 * 
 * 
 * Example 2:
 * Input: N = 2, mines = []
 * Output: 1
 * Explanation:
 * There is no plus sign of order 2, but there is of order 1.
 * 
 * 
 * Example 3:
 * Input: N = 1, mines = [[0, 0]]
 * Output: 0
 * Explanation:
 * There is no plus sign, so return 0.
 * 
 * 
 * Note:
 * N will be an integer in the range [1, 500].
 * mines will have length at most 5000.
 * mines[i] will be length 2 and consist of integers in the range [0, N-1].
 * (Additionally, programs submitted in C, C++, or C# will be judged with a
 * slightly smaller time limit.)
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

// O(n^3)
class Solution1 {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vvi grid(n, vi(n, 1));
        for(auto mine: mines)
            grid[mine[0]][mine[1]] = 0;
        
        vvi hor(n, vi(n)); vvi ver(n, vi(n));
        forn(i, n){
            hor[i][0] = grid[i][0];
            fore(j, 1, n)
                hor[i][j] = hor[i][j-1] + grid[i][j];
        }

        forn(j, n){
            ver[0][j] = grid[0][j];
            fore(i, 1, n){
                ver[i][j] = ver[i-1][j] + grid[i][j];
            }
        }

        int maxsz = 0;
        forn(i, n){
            forn(j, n){
                if(grid[i][j]){
                    maxsz = 1;
                    break;
                }
            }
        }

        // print_vv(hor);
        // print_vv(ver);

        forn(i, n){
            forn(j, n){
                if(grid[i][j]){
                    int ex =  min({i, n-i-1, j, n-j-1}); //extension possible
                    for(int k=1; k<=ex; k++){
                        int hsum = (hor[i][j+k] - (j-k-1>=0 ? hor[i][j-k-1] : 0));
                        int vsum = (ver[i+k][j] - (i-k-1>=0 ? ver[i-k-1][j] : 0));
                        int sum = hsum+vsum - 1;
                        if(sum == 4*k+1){
                            maxsz = max(maxsz, 1+k);
                        }
                        else 
                            break;
                    }
                }
                
            }
        }

        return maxsz;
    }
};

class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vvi grid(n, vi(n, n));
        for(auto &m: mines)
            grid[m[0]][m[1]] = 0;
        
        // forn(i, n){
        //     for(int j=0, l=0, u=0; j<n; j++){
        //         min_self(grid[i][j], l = (grid[i][j]==0 ? 0 : l+1)); //left
        //         min_self(grid[j][i], u = (grid[j][i]==0 ? 0 : u+1)); // up
        //     }

        //     for(int j=n-1, r=0, d=0; j>=0; j--){
        //         min_self(grid[i][j], r = (grid[i][j]==0 ? 0 : r+1)); // right
        //         min_self(grid[j][i], d = (grid[j][i]==0 ? 0 : d+1));
        //     }

        // }

        forn(i, n){
            for(int j=0, k=n-1, r=0, d=0, l=0, u=0; j<n, k>=0; j++, k--){
                min_self(grid[i][j], l = (grid[i][j]==0 ? 0 : l+1)); //left
                min_self(grid[j][i], u = (grid[j][i]==0 ? 0 : u+1)); // up
                min_self(grid[i][k], r = (grid[i][k]==0 ? 0 : r+1)); // right
                min_self(grid[k][i], d = (grid[k][i]==0 ? 0 : d+1)); // down
            }
        }

        int maxv = 0;
        forn(i, n)
            forn(j, n)
                max_self(maxv, grid[i][j]);
        
        return maxv;

    }
};

class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vvi grid(n, vi(n,1));
        for(auto mine: mines)
            grid[mine[0]][mine[1]] = 0;

        vvi dp(n, vi(n, n));
        
        for(int i=0; i<n; ++i){
            int l = dp[i][0] = grid[i][0];
            for(int j=1; j<n; ++j){
                min_self(dp[i][j], l = (grid[i][j] ? l + 1 : 0));
            }
            
            int r = dp[i][n-1] = grid[i][n-1];
            for(int j=n-2; j>=0; --j)
                min_self(dp[i][j], r = (grid[i][j] ? r + 1 : 0));
        }
        
        for(int j=0; j<n; ++j){
            int u = dp[0][j] = grid[0][j];
            for(int i=1; i<n; ++i)
                min_self(dp[i][j], u = (grid[i][j] ? u + 1 : 0));
    
            int d = dp[n-1][j] = grid[n-1][j];        
            for(int i=n-2; i>=0; --i)
                min_self(dp[i][j], d = (grid[i][j] ? d + 1 : 0));
        }
        // cout<<grid<<dp;

        int ans = 0;
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;        
    }
};

class Solution0 {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vvi grid(n, vi(n,1));
        for(auto mine: mines)
            grid[mine[0]][mine[1]] = 0;
        // cout<<grid;
        
        vvi left(grid), right(grid), up(grid), down(grid);
        
        for(int i=0; i<n; ++i){
            for(int j=1; j<n; ++j)
                if(left[i][j])
                    left[i][j]+=left[i][j-1];
            
            for(int j=n-2; j>=0; --j)
                if(right[i][j])
                    right[i][j]+=right[i][j+1];
        }
        
        for(int j=0; j<n; ++j){
            for(int i=1; i<n; ++i)
                if(up[i][j])
                    up[i][j]+=up[i-1][j];
            
            for(int i=n-2; i>=0; --i)
                if(down[i][j])
                    down[i][j]+=down[i+1][j];
        }
        
        int ans = 0;
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                int cur = min({left[i][j], right[i][j], up[i][j], down[i][j]});
                ans = max(ans, cur);
            }
        }
        return ans;        
    }
};

// @lc code=end


int main(){
    Solution sol; int N, out; vvi mines;
    N = 5; mines = {{4,2}};
    out = sol.orderOfLargestPlusSign(N, mines); deb(out);

    N = 2; mines = {};
    out = sol.orderOfLargestPlusSign(N, mines); deb(out);

    N = 1; mines = {{0,0}};
    out = sol.orderOfLargestPlusSign(N, mines); deb(out);

    N = 3; mines = {{0,0}};
    out = sol.orderOfLargestPlusSign(N, mines); deb(out); 

    return 0;
};
