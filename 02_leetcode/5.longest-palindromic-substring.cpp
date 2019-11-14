/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (27.89%)
 * Likes:    4365
 * Dislikes: 399
 * Total Accepted:    660K
 * Total Submissions: 2.4M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, find the longest palindromic substring in s. You may
 * assume that the maximum length of s is 1000.
 * 
 * Example 1:
 * 
 * 
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "cbbd"
 * Output: "bb"
 * 
 * 
 */
#include "cpp.h"
using namespace std;

typedef std::vector<int> vi;
typedef std::vector<vector<int>> vvi;

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int start(0),end(0); // l and r of longest pal
        int max_len = 0;

        for(int i=0; i<n; i++){
            int a = palAroundCenter(i,i,s); // aba
            int b = palAroundCenter(i,i+1,s); // abba
            int len = max(a,b);

            if(len>end-start){
                start = i -  (len-1)/2; 
                end = i + len/2;
            }
        }

        return s.substr(start, end-start+1);

    }

    int palAroundCenter(int l, int r, string &s){
        while(l>=0 && r<s.size() && s[l]==s[r]){
            l--;
            r++;
        }
        return r-l-1;
    }
};
// @lc code=end
int main(){
    Solution sol;
    cout<<sol.longestPalindrome("babad")<<endl;
    cout<<sol.longestPalindrome("cbbd")<<endl;


}