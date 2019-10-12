/*
 * @lc app=leetcode id=1143 lang=cpp
 *
 * [1143] Longest Common Subsequence
 *
 * https://leetcode.com/problems/longest-common-subsequence/description/
 *
 * algorithms
 * Medium (57.62%)
 * Likes:    198
 * Dislikes: 8
 * Total Accepted:    11.1K
 * Total Submissions: 19.5K
 * Testcase Example:  '"abcde"\n"ace"'
 *
 * Given two strings text1 and text2, return the length of their longest common
 * subsequence.
 * 
 * A subsequence of a string is a new string generated from the original string
 * with some characters(can be none) deleted without changing the relative
 * order of the remaining characters. (eg, "ace" is a subsequence of "abcde"
 * while "aec" is not). A common subsequence of two strings is a subsequence
 * that is common to both strings.
 * 
 * 
 * 
 * If there is no common subsequence, return 0.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: text1 = "abcde", text2 = "ace" 
 * Output: 3  
 * Explanation: The longest common subsequence is "ace" and its length is 3.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: text1 = "abc", text2 = "abc"
 * Output: 3
 * Explanation: The longest common subsequence is "abc" and its length is 3.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: text1 = "abc", text2 = "def"
 * Output: 0
 * Explanation: There is no such common subsequence, so the result is 0.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= text1.length <= 1000
 * 1 <= text2.length <= 1000
 * The input strings consist of lowercase English characters only.
 * 
 * 
 */
#include "cpp.h"
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string t1, string t2) {
        int a = t1.size();
        int b = t2.size();
        vector<vector<int>> T(a+1, vector<int>(b+1));
        
        for(int i = 1; i<=a; i++){
            for(int j =1; j<=b; j++){

                if(t1[i-1]==t2[j-1])
                    T[i][j] = 1 + T[i-1][j-1];
                else
                    T[i][j] = max(T[i-1][j], T[i][j-1]);
            }
        }
        return T[a][b];
    }


    int longestCommonSubsequenceRec(string text1, string text2) {
        return LCS(text1, text2, 0, 0);
    }

    int LCS(string a, string b, int i, int j){
        if(i>=a.length() || j>=b.length()) return 0;

        if(a[i] == b[j]) return 1 + LCS(a, b, i+1, j+1);

        if(a[i]!=b[j]) return max(LCS(a, b, i+1, j), LCS(a, b, i, j+1));

        return 0;
    }
};

int main(){
    Solution sol;
    int t;
    string a, b;
    scanf("%d\n", &t);
    while(t--){
        getline(cin,a);
        getline(cin,b);
        cout<<sol.longestCommonSubsequence(a, b)<<endl;
    }
}
