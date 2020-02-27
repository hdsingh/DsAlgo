/*
 * @lc app=leetcode id=1140 lang=cpp
 *
 * [1140] Stone Game II
 *
 * https://leetcode.com/problems/stone-game-ii/description/
 *
 * algorithms
 * Medium (60.22%)
 * Likes:    157
 * Dislikes: 33
 * Total Accepted:    5.6K
 * Total Submissions: 9.3K
 * Testcase Example:  '[2,7,9,4,4]'
 *
 * Alex and Lee continue their games with piles of stones.  There are a number
 * of piles arranged in a row, and each pile has a positive integer number of
 * stones piles[i].  The objective of the game is to end with the most
 * stones. 
 * 
 * Alex and Lee take turns, with Alex starting first.  Initially, M = 1.
 * 
 * On each player's turn, that player can take all the stones in the first X
 * remaining piles, where 1 <= X <= 2M.  Then, we set M = max(M, X).
 * 
 * The game continues until all the stones have been taken.
 * 
 * Assuming Alex and Lee play optimally, return the maximum number of stones
 * Alex can get.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: piles = [2,7,9,4,4]
 * Output: 10
 * Explanation:  If Alex takes one pile at the beginning, Lee takes two piles,
 * then Alex takes 2 piles again. Alex can get 2 + 4 + 4 = 10 piles in total.
 * If Alex takes two piles at the beginning, then Lee can take all three piles
 * left. In this case, Alex get 2 + 7 = 9 piles in total. So we return 10 since
 * it's larger. 
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= piles.length <= 100
 * 1 <= piles[i] <= 10 ^ 4
 * 
 */
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

// DP[i][M] : max score that can be gained till a[i: ], using multiplier M
// So we will try out all possible multipliers
// Rec relation: 
//  max_self(dp[i][x] , suf[i] - dp[i+x][max(m,x)]
// the maximum that can be gained by a player till i for a multiplier M,
// could be found by minimising the gain of opponent,
// If we use multiplier x, the next player will use max(x,m)
// Our answer is dp[0][1], max gain till 0 position and the multiplier M will be 1 in the beginning
// Since we are starting from end, we will assume the multiplier M to be max possible
// and decrease it
// @lc code=start
class Solution {
public:
    int stoneGameII(vector<int>& p) {
        int n = p.size();
        vi suf(n+1);
        for(int i=n-1; i>=0; i--)
            suf[i] = suf[i+1] + p[i];
        
        vvi dp(n+1, vi(n+1)); 
        // max num of stones player 1 can get till i, m

        for(int i=n-1; i>=0; i--){
            for(int m=n-1; m>=0; m--){
                for(int x=1; x<=2*m && i+x<=n; x++){
                    max_self(dp[i][m], suf[i] - dp[i+x][max(m, x)] );
                }
            }
        }

        // print(suf);
        // print_vv(dp);
        return dp[0][1];
    }
};
// @lc code=end

int main(){
    Solution sol;
    vi p = {2,7,9,4,4};
    int out;
    // out = sol.stoneGameII(p);
    deb(out);
    p = {1,2,3,4,5,100};
    out = sol.stoneGameII(p);
    deb(out);
    return 0;
}
