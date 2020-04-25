/*
 * @lc app=leetcode id=518 lang=cpp
 *
 * [518] Coin Change 2
 *
 * https://leetcode.com/problems/coin-change-2/description/
 *
 * algorithms
 * Medium (44.11%)
 * Likes:    1002
 * Dislikes: 41
 * Total Accepted:    61.2K
 * Total Submissions: 136.8K
 * Testcase Example:  '5\n[1,2,5]'
 *
 * You are given coins of different denominations and a total amount of money.
 * Write a function to compute the number of combinations that make up that
 * amount. You may assume that you have infinite number of each kind of
 * coin.
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: amount = 5, coins = [1, 2, 5]
 * Output: 4
 * Explanation: there are four ways to make up the amount:
 * 5=5
 * 5=2+2+1
 * 5=2+1+1+1
 * 5=1+1+1+1+1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: amount = 3, coins = [2]
 * Output: 0
 * Explanation: the amount of 3 cannot be made up just with coins of 2.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: amount = 10, coins = [10] 
 * Output: 1
 * 
 * 
 * 
 * 
 * Note:
 * 
 * You can assume that
 * 
 * 
 * 0 <= amount <= 5000
 * 1 <= coin <= 5000
 * the number of coins is less than 500
 * the answer is guaranteed to fit into signed 32-bit integer
 * 
 * 
 */
#include "cpp.h"
#include "extra.h"
using namespace std;

// @lc code=start
class Solution {
public:
    // Same as approach1 : removing redundant code
    // Since dp[i] doesn't change for j<coins[i]
    int change(int amount, vector<int> &coins){
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;

        // for(int i = 1; i<=coins.size(); i++){
        //     for(int j=coins[i-1]; j<=amount; j++)
        //         dp[j] = dp[j] + dp[j - coins[i-1]];
        // }

        for(int coin: coins){
            for(int j=coin; j<=amount; j++){
                dp[j] = dp[j] + dp[j-coin];
            }
            // print(dp);
        }

        return dp[amount];
    }

    // Approach 1
    // Refer: https://www.youtube.com/watch?v=DJ4a7cmjZY0
    int change1(int amount, vector<int>& coins) {
        int n_coins = coins.size();
        vector<vector<int>> dp(n_coins+1, vector<int>(amount+1, 0));

        // max ways to make change for amt 0 will be 1, doing nothing
        dp[0][0] = 1;

        for(int i=1; i <= n_coins; i++){
            
            dp[i][0] = 1; // All elements at 0th index in row are 1
            for(int j=1; j <= amount; j++){
                
                int currentCoinValue = coins[i-1];
                int withoutThisCoin = dp[i-1][j];
                int withThisCoin = (j >= currentCoinValue) ? dp[i][j - currentCoinValue] : 0;

                dp[i][j] = withoutThisCoin + withThisCoin;
            }
            // Total ways for dp[i][j] are ways with and without this coin;
            // without this coin: all the ways in preious row, same col
            // with this coin: if amount_j > val of coin then dp[same row][amount without present amount]
        }

        return dp[n_coins][amount];        
    }
};

// dp[i][j] : the number of combinations to make up amount j by using the first i types of coins
// State transition:

// 1. not using the ith coin, only using the first i-1 coins to make up amount j, then we have dp[i-1][j] ways.
// 2. using the ith coin, since we can use unlimited same coin, we need to know how many ways to make up amount j - coins[i-1] by using first i coins(including ith), which is dp[i][j-coins[i-1]]

// @lc code=end
int main(){
    Solution s;
    int amount; vi coins;

    amount = 5; coins = {1,2,5}; 
    cout<<s.change(amount, coins)<<endl;

    amount = 3; coins = {2}; 
    cout<<s.change(amount, coins)<<endl;

    amount = 10; coins = {10}; 
    cout<<s.change(amount, coins)<<endl;

    cout<<endl;
    cout<<endl;

    amount = 11; coins = {2,5}; 
    cout<<s.change(amount, coins)<<endl;

}
