/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
 *
 * algorithms
 * Medium (45.10%)
 * Likes:    1676
 * Dislikes: 62
 * Total Accepted:    110K
 * Total Submissions: 243.8K
 * Testcase Example:  '[1,2,3,0,2]'
 *
 * Say you have an array for which the i^th element is the price of a given
 * stock on day i.
 * 
 * Design an algorithm to find the maximum profit. You may complete as many
 * transactions as you like (ie, buy one and sell one share of the stock
 * multiple times) with the following restrictions:
 * 
 * 
 * You may not engage in multiple transactions at the same time (ie, you must
 * sell the stock before you buy again).
 * After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1
 * day)
 * 
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3,0,2]
 * Output: 3 
 * Explanation: transactions = [buy, sell, cooldown, buy, sell]
 * 
 */
#include "cpp.h"
using namespace std;

typedef std::vector<int> vi;
typedef std::vector<vector<int>> vvi;

// @lc code=start
 
//       B 
//     /  \\
//    S---- R
// Buy->R,sell
// S ->R
// R->R, B, S
// Based on State space possibilities analysis
class Solution0 {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n<=1) return 0;
        vi hold(n,0);
        vi buy(n,0);
        vi sell(n,0);
        buy[0] = -prices[0];
        sell[0] = INT_MIN;

        for(int i=1; i<n; i++){
            buy[i] = max(buy[i-1], hold[i-1]-prices[i]);
            hold[i] = max(hold[i-1], sell[i-1]);
            sell[i] = max(sell[i-1], buy[i-1]+prices[i]);
        }

        return max(hold[n-1], sell[n-1]);

    }
};

const int inf = 1e9;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> buy(n+1, -inf), sell(n+1);
    
        for(int i=1; i<=n; ++i){
            int p = prices[i-1];
            buy[i] = max((i-2>=0 ? sell[i-2] : 0) - p, buy[i-1]);
            sell[i] = max(buy[i-1] + p, sell[i-1]);
        }

        return sell[n];
    }
};
// @lc code=end

int main(){
    Solution sol;
    vi prices = {1,2,3,0,2};
    prices = {2,5,7,1,4};
    cout<<sol.maxProfit(prices)<<endl;

    return 0;
}