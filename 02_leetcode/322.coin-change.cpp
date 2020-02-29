/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 *
 * https://leetcode.com/problems/coin-change/description/
 *
 * algorithms
 * Medium (31.76%)
 * Likes:    2392
 * Dislikes: 85
 * Total Accepted:    261.4K
 * Total Submissions: 809.6K
 * Testcase Example:  '[1,2,5]\n11'
 *
 * You are given coins of different denominations and a total amount of money
 * amount. Write a function to compute the fewest number of coins that you need
 * to make up that amount. If that amount of money cannot be made up by any
 * combination of the coins, return -1.
 * 
 * Example 1:
 * 
 * 
 * Input: coins = [1, 2, 5], amount = 11
 * Output: 3 
 * Explanation: 11 = 5 + 5 + 1
 * 
 * Example 2:
 * 
 * 
 * Input: coins = [2], amount = 3
 * Output: -1
 * 
 * 
 * Note:
 * You may assume that you have an infinite number of each kind of coin.
 * 
 */
// #include "cpp.h"
// #include "extra.h"
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


// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
		int max_val = amount+1;
		vector<int> dp(amount+1, max_val);
		dp[0] = 0;
		for(int coin: coins)
			for(int i=coin; i<=amount; i++)
				dp[i] = min(dp[i], dp[i-coin]+1);
		
		return dp[amount] > amount ? -1 : dp[amount];
    }
};

// Knapsack style forward DP
class Solution {
	const int inf = 1e9;
public:
    int coinChange(vector<int>& coins, int T) {
        int n = coins.size();
        sort(all(coins));  // for pruning
        vi dp(T+1, inf);

        dp[0] = 0;
        for(int t=0; t<=T; ++t){
          for(auto c: coins){
            if(t<=T-c)
              min_self(dp[t+c], dp[t]+1);
            else break; // for pruning
          }
        }

        return dp[T]==inf ? -1 : dp[T];
    }
};
// @lc code=end
int main(){
    Solution s;
    vector<int> coins = {2,3,5};
    // cout<<s.coinChange(coins, 16)<<endl;
    // coins = {1,2,5};
    // cout<<s.coinChange(coins, 11)<<endl;
    // coins = {2};
    // cout<<s.coinChange(coins, 3)<<endl;

    coins = {1, 32994};
    cout<<s.coinChange(coins, 2)<<endl;

    // coins = {186,419,83,408};
    // cout<<s.coinChange(coins, 6249)<<endl;

}

