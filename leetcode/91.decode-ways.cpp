/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 *
 * https://leetcode.com/problems/decode-ways/description/
 *
 * algorithms
 * Medium (22.85%)
 * Likes:    1801
 * Dislikes: 2043
 * Total Accepted:    308.8K
 * Total Submissions: 1.3M
 * Testcase Example:  '"12"'
 *
 * A message containing letters from A-Z is being encoded to numbers using the
 * following mapping:
 * 
 * 
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * 
 * 
 * Given a non-empty string containing only digits, determine the total number
 * of ways to decode it.
 * 
 * Example 1:
 * 
 * 
 * Input: "12"
 * Output: 2
 * Explanation: It could be decoded as "AB" (1 2) or "L" (12).
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "226"
 * Output: 3
 * Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2
 * 6).
 * 
 */
#include "cpp.h"
using namespace std;

typedef std::vector<int> vi;
typedef std::vector<vector<int>> vvi;

// @lc code=start

// Approach 1: Recursive
class Solution1 {
public:
    int numDecodings(string s) {
        return decode(0, s);
    }

    int decode(int pos, string s){
        int out=0;
        int n = s.size();
        if(pos==n){
            // deb(pos);
            return 1;
        }
        else if (pos>n)
            return 0;
        
        if(s[pos]=='0') return 0;
        

        out+= decode(pos+1, s);

        if(pos+1<n)
            if(stoi(s.substr(pos, 2))<27 && stoi(s.substr(pos, 2))>0){
                out+= decode(pos+2, s);
                // deb(s.substr(pos, 2));
            }
        
        return out;        
    }
};

// Approach : Use DP table with rec
class Solution {
public:
    int numDecodings(string s) {
        vi dp(s.size(), -1);
        return decode(0, s, dp);
    }

    int decode(int pos, string s, vi &dp){
        int out=0;
        int n = s.size();

        if(pos==n)
            return 1;
        else if (pos>n)
            return 0;
        
        if(dp[pos]!=-1) return dp[pos];

        if(s[pos]=='0') {
            dp[pos] = 0;
            return 0;
            }


        out+= decode(pos+1, s, dp);

        if(pos+1<n)
            if(stoi(s.substr(pos, 2))<27 && stoi(s.substr(pos, 2))>0)
                out+= decode(pos+2, s, dp);

        dp[pos] = out;
        return out;        
    }
};
// @lc code=end
int main(){
    Solution s;
    cout<<s.numDecodings("12")<<endl;
    cout<<s.numDecodings("226")<<endl;
    cout<<s.numDecodings("1234")<<endl;
    cout<<s.numDecodings("20202")<<endl;
    cout<<s.numDecodings("200202")<<endl;
}

