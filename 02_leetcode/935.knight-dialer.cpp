/*
 * @lc app=leetcode id=935 lang=cpp
 *
 * [935] Knight Dialer
 *
 * https://leetcode.com/problems/knight-dialer/description/
 *
 * algorithms
 * Medium (43.10%)
 * Likes:    386
 * Dislikes: 151
 * Total Accepted:    24K
 * Total Submissions: 55.6K
 * Testcase Example:  '1'
 *
 * A chess knight can move as indicated in the chess diagram below:
 * 
 * .           
 * 
 * 
 * 
 * This time, we place our chess knight on any numbered key of a phone pad
 * (indicated above), and the knight makes N-1 hops.  Each hop must be from one
 * key to another numbered key.
 * 
 * Each time it lands on a key (including the initial placement of the knight),
 * it presses the number of that key, pressing N digits total.
 * 
 * How many distinct numbers can you dial in this manner?
 * 
 * Since the answer may be large, output the answer modulo 10^9 + 7.
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
 * Input: 1
 * Output: 10
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 2
 * Output: 20
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 3
 * Output: 46
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= N <= 5000
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
template <typename T>void print_vv(T v){int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}
template <class T, class U> void print_m(map<T,U> m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}

// DP
class Solution1 {
public:
    int knightDialer(int N) {
        vvi dirs = {{1,2},{-1,2},{1,-2}, {-1,-2}, {2,1},{-2,1},{2,-1},{-2,-1}};
        vvi grid(4, vi(3));
        forn(i, 3){
            forn(j, 3){
                grid[i][j] = 3*i + 1 + j;
            }
        }
        
        int dp[N][4][3];
        memset(dp, 0, sizeof dp);
        // vector<vvi> dp(N, vvi(4, vi(3)));
        forn(i, 3){
            forn(j, 3){
                dp[0][i][j] = 1;
            }
        }
        dp[0][3][1]  = 1; // number 0

        // print_vv(dp[0]);

        for(int k=1; k<N; k++){
            for(int i=0; i<4; i++){
                for(int j=0; j<3; j++){
                    if(i==3 && (j==0 || j==2)) continue;
                    for(vi dir : dirs){
                        int old_i = i+dir[0];
                        int old_j = j+dir[1];
                        if(0<=old_i && old_i<4 && 0<=old_j && old_j<3 && ( !(old_i==3 &&(old_j==0 || old_j==2) ) ))
                            add_self(dp[k][i][j], dp[k-1][old_i][old_j]);
                    }
                }
            }
        }

        int cnt = 0;
        forn(i, 4){
            forn(j, 3){
                add_self(cnt, dp[N-1][i][j]);
            }
        }

        return cnt;
    }
};

// using simple obeservation and trying out 3-4 steps prctically
class Solution {
public:
    int knightDialer(int N) {
        vvi nbr = { {4,6},//0
                {6,8},//1
                {7,9},//2
                {4,8},//3
                {3,9,0},//4
                {},//5
                {1,7,0},//6
                {6,2},//7
                {1,3},//8
                {4,2}//9
                };
    
        vi dp(10,1);
        // print(dp);
        for(int k=1; k<N; k++){
            vi ndp(10);
            for(int i=0; i<10; i++){
                for(int nb : nbr[i])
                    add_self(ndp[i], dp[nb]);
            }
            dp = ndp;
        }

        int cnt = 0;
        for(int i=0; i<10; i++)
            add_self(cnt, dp[i]);
        
        return cnt;
    }
};
// @lc code=end

int main(){
    Solution sol; int out, n;
    fore(i,4995,5001){
        out = sol.knightDialer(i);
        deb2(i, out);
    }
    // n = 4252;
    // out = sol.knightDialer(n); deb(out);
    return 0;
}

