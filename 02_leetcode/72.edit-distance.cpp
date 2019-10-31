/*
 * @lc app=leetcode id=72 lang=cpp
 *
 * [72] Edit Distance
 *
 * https://leetcode.com/problems/edit-distance/description/
 *
 * algorithms
 * Hard (39.33%)
 * Likes:    2626
 * Dislikes: 41
 * Total Accepted:    204.5K
 * Total Submissions: 511.6K
 * Testcase Example:  '"horse"\n"ros"'
 *
 * Given two words word1 and word2, find the minimum number of operations
 * required to convert word1 to word2.
 * 
 * You have the following 3 operations permitted on a word:
 * 
 * 
 * Insert a character
 * Delete a character
 * Replace a character
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: word1 = "horse", word2 = "ros"
 * Output: 3
 * Explanation: 
 * horse -> rorse (replace 'h' with 'r')
 * rorse -> rose (remove 'r')
 * rose -> ros (remove 'e')
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: word1 = "intention", word2 = "execution"
 * Output: 5
 * Explanation: 
 * intention -> inention (remove 't')
 * inention -> enention (replace 'i' with 'e')
 * enention -> exention (replace 'n' with 'x')
 * exention -> exection (replace 'n' with 'c')
 * exection -> execution (insert 'u')
 * 
 * 
 */
#include "cpp.h"
using namespace std;

// @lc code=start
class Solution {
public:
    int minDistance(string a, string b) {
        int a_len = a.length();
        int b_len = b.length();
        if(a_len==0) return b_len;
        if(b_len==0) return a_len;

        int dp[a_len+1][b_len+1];
        for(int i=0; i<=a_len; i++) dp[i][0] = i; // horizontally along a
        for(int j=0; j<=b_len; j++) dp[0][j] = j; // vertically along b

        for(int i=1; i<=a_len; i++){
            for(int j=1; j<=b_len; j++){
                int insert = dp[i][j-1] + 1; // dp[i][j-1] + cost_of_insert;
                int del = dp[i-1][j] + 1; // dp[i-1][j] + cost_of_del;
                int cost_of_replace = a[i-1] == b[j-1] ? 0 : 1;
                int replace = dp[i-1][j-1] + cost_of_replace;
                
                // dp[i][j] = min(insert, del, replace)
                dp[i][j] = min(min(insert, del), replace);
            }
        }

        return dp[a_len][b_len];
    }
};

// @lc code=end
int main(){
    Solution s;
    string a, b;
    a = "horse"; b = "ros";
    cout<<s.minDistance(a, b)<<endl;
    
    a = "intention"; b = "execution";
    cout<<s.minDistance(a, b)<<endl;

    return 0;
}