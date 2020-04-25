/*
 * @lc app=leetcode id=188 lang=cpp
 *
 * [188] Best Time to Buy and Sell Stock IV
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/
 *
 * algorithms
 * Hard (27.37%)
 * Likes:    1104
 * Dislikes: 67
 * Total Accepted:    110.6K
 * Total Submissions: 404.1K
 * Testcase Example:  '2\n[2,4,1]'
 *
 * Say you have an array for which the i-th element is the price of a given
 * stock on day i.
 * 
 * Design an algorithm to find the maximum profit. You may complete at most k
 * transactions.
 * 
 * Note:
 * You may not engage in multiple transactions at the same time (ie, you must
 * sell the stock before you buy again).
 * 
 * Example 1:
 * 
 * 
 * Input: [2,4,1], k = 2
 * Output: 2
 * Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit
 * = 4-2 = 2.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,2,6,5,0,3], k = 2
 * Output: 7
 * Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit
 * = 6-2 = 4.
 * Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 =
 * 3.
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
    int maxProfit(int k, vector<int>& p) {
        int n = p.size();
        if(k>= n/2){ // infinite transactions
            // add the diff of local maximia and minima
            int total = 0;
            for(int i=1; i<n; i++){
                if(p[i]>p[i-1])
                    total+= p[i] - p[i-1];
            }
            return total;
        }

        vvi buy(k+1, vi(n+1));
        vvi sell(k+1, vi(n+1));
        for(int i=1; i<=k; i++)
            buy[i][0] = INT_MIN;

        for(int i=1; i<=n; i++){
            for(int j=1; j<=k; j++){
                sell[j][i] = max(sell[j][i-1], buy[j][i-1] + p[i-1]);
                buy[j][i] = max(buy[j][i-1], sell[j-1][i-1] - p[i-1]);

            }
        }
        return sell[k][n];
    }
};
// @lc code=end

// Same with comments
// buy new trans. starts  : inc. transaction, in buy we pay so -prices[i]
// sell            ends   : same transaction, that staterd on buying,
// we sell so  get money hence, +prices[i]
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
		if(k>=n/2){
			// same as buy and selling multiple times without any restriction
			int tot = 0;
			for(int i=1; i<n; ++i)
				if(prices[i-1]<prices[i])
					tot+=prices[i] - prices[i-1];
			return tot;
		}
		vvi buy(k+1, vi(n+1)); // buy profit
		vvi sell(k+1, vi(n+1)); // sell profit

        // if Initial price -v -inf, only then we can get max by buying
        // -prices[i] in the 1st transaction
		for(int j=1; j<=k; ++j)
			buy[j][0] = INT_MIN;

		for(int i=1; i<=n; ++i){
			for(int j=1; j<=k; ++j){
				buy[j][i] = max(buy[j][i-1], sell[j-1][i-1] - prices[i-1]); 
				// at by trans. starts, so either till prev profit, or
				// sell till prev trans. and pay the price
				sell[j][i] = max(sell[j][i-1], buy[j][i-1] + prices[i-1]);
				// here transaction will remain same, 
			}
		}

		// print_vv(buy);
		// print_vv(sell);
		return sell[k][n];
    }
};


int main(){
    Solution sol;
    vi p; int k; int out;
    p = { 2,4,1 }, k = 2;
    // out = sol.maxProfit(k, p); deb(out);

    p = { 3,2,6,5,0,3 }, k = 2;
    out = sol.maxProfit(k, p); deb(out);
    return 0;
}