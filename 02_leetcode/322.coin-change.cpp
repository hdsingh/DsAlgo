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

