/*
 * @lc app=leetcode id=140 lang=cpp
 *
 * [140] Word Break II
 *
 * https://leetcode.com/problems/word-break-ii/description/
 *
 * algorithms
 * Hard (28.65%)
 * Likes:    1269
 * Dislikes: 286
 * Total Accepted:    182.6K
 * Total Submissions: 636.7K
 * Testcase Example:  '"catsanddog"\n["cat","cats","and","sand","dog"]'
 *
 * Given a non-empty string s and a dictionary wordDict containing a list of
 * non-empty words, add spaces in s to construct a sentence where each word is
 * a valid dictionary word. Return all such possible sentences.
 * 
 * Note:
 * 
 * 
 * The same word in the dictionary may be reused multiple times in the
 * segmentation.
 * You may assume the dictionary does not contain duplicate words.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * s = "catsanddog"
 * wordDict = ["cat", "cats", "and", "sand", "dog"]
 * Output:
 * [
 * "cats and dog",
 * "cat sand dog"
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * s = "pineapplepenapple"
 * wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
 * Output:
 * [
 * "pine apple pen apple",
 * "pineapple pen apple",
 * "pine applepen apple"
 * ]
 * Explanation: Note that you are allowed to reuse a dictionary word.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input:
 * s = "catsandog"
 * wordDict = ["cats", "dog", "sand", "and", "cat"]
 * Output:
 * []
 * 
 */
#include "cpp.h"
using namespace std;

typedef std::vector<int> vi;
typedef std::vector<vector<int>> vvi;

// @lc code=start
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int> dp(n+1);
        dp[0] = 1;
        unordered_set<string> dict;
        int max_len = 0;
        for(auto word: wordDict){
            max_len = max((int)word.length(), max_len);
            dict.insert(word);
        }
        
        for(int i=1; i<=n; i++){
            for(int j=i-1; j>=0; j--){
                if(dp[j]){
                    string sub = s.substr(j, i-j);
                    if(dict.find(sub)!=dict.end()){
                        dp[i] = 1;
                        break;
                    }
                }
            }
        }

        // print(dp);
        vector<string> out;
        if(dp[n]){
            string sen = ""; //sentence
            form_words(0, sen, out, dp, s, dict, n, max_len);      
        }
        return out;
    }
    
    void form_words(int beg, string sen, vector<string> &out, vector<int> &dp, string &s, unordered_set<string> dict, int &n, int &max_len){
        // cout<<beg<<" "<<n<<" :";
        // print(sen);

        // termination condition
        if(beg>=n){
            out.push_back(sen);
            // print(sen);
            return;
        }
        
        // explore + recurse

        for(int i=beg; i<=min(beg+max_len, n-1); i++){
            if(dp[i+1]){
                string substring = s.substr(beg, i-beg+1);
                if(dict.find(substring)!=dict.end()){
                    form_words(i+1, sen+substring+" ", out, dp, s, dict, n, max_len);
                }
            }
        }
    }

};
// @lc code=end
int main(){
    Solution sol;
    vs out;

    string s = "catsanddog";
    vector<string> worddict = {"cat", "cats", "and", "sand", "dog"};
    out = sol.wordBreak(s, worddict);
    print(out);

    s = "pineapplepenapple";
    worddict = {"apple", "pen", "applepen", "pine", "pineapple"};
    out = sol.wordBreak(s, worddict);
    print(out);

    s = "catsandog";
    worddict = {"cats", "dog", "sand", "and", "cat"};
    out = sol.wordBreak(s, worddict);
    print(out);
}
