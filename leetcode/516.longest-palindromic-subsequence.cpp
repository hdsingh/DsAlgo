/*
 * @lc app=leetcode id=516 lang=cpp
 *
 * [516] Longest Palindromic Subsequence
 *
 * https://leetcode.com/problems/longest-palindromic-subsequence/description/
 *
 * algorithms
 * Medium (49.25%)
 * Likes:    1204
 * Dislikes: 152
 * Total Accepted:    80.8K
 * Total Submissions: 163.9K
 * Testcase Example:  '"bbbab"'
 *
 * 
 * Given a string s, find the longest palindromic subsequence's length in s.
 * You may assume that the maximum length of s is 1000.
 * 
 * 
 * Example 1:
 * Input: 
 * 
 * "bbbab"
 * 
 * Output: 
 * 
 * 4
 * 
 * One possible longest palindromic subsequence is "bbbb".
 * 
 * 
 * Example 2:
 * Input:
 * 
 * "cbbd"
 * 
 * Output:
 * 
 * 2
 * 
 * One possible longest palindromic subsequence is "bb".
 * 
 */
#include "cpp.h"
using namespace std;

typedef std::vector<int> vi;
typedef std::vector<vector<int>> vvi;

// @lc code=start
// https://www.youtube.com/watch?v=_nCsPn7_OgI :Tushar Roy
// DP
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vvi dp(n, vi(n,0));

        // for len = 1
        for(int i=0; i<n; i++) dp[i][i] = 1;

        // Move diagonally
        // for len = 2 to n
        for(int len=2; len<=n; len++){
            for(int i=0; i<n-len+1; i++){
                int j = i+len-1;
                // cout<<i<<" "<<j<<endl;
                dp[i][j] = s[i]==s[j] ? 2 + dp[i+1][j-1] : max(dp[i+1][j], dp[i][j-1]);
            }
        }
        // print_vv(dp);

        return dp[0][n-1];
    }
};

// Rec + Memo
class Solution2 {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vvi memo(n, vi(n,-1));
        return lpsRec(0,s.size()-1,s, memo);
    }

    int lpsRec(int l, int r, string &s, vvi &memo){
        if(l==r) return 1; //aba
        if(l>r) return 0;  //abba

        if(memo[l][r]!=-1) return memo[l][r];

        return memo[l][r] = s[l]==s[r] ? 2 + lpsRec(l+1, r-1, s, memo) : max(lpsRec(l+1,r,s, memo), lpsRec(l,r-1,s, memo));

    }
};

// Simple recursion
class Solution1 {
public:
    int longestPalindromeSubseq(string s) {
        return lpsRec(0,s.size()-1,s);
    }

    int lpsRec(int l, int r, string &s){
        if(l==r) return 1; //aba
        if(l>r) return 0;  //abba

        return s[l]==s[r] ? 2 + lpsRec(l+1, r-1, s) : max(lpsRec(l+1,r,s), lpsRec(l,r-1,s));

    }
};
// @lc code=end
int main(){
    Solution sol;
    cout<<sol.longestPalindromeSubseq("bbbabb")<<endl;
    cout<<sol.longestPalindromeSubseq("happxah")<<endl;

    



}

