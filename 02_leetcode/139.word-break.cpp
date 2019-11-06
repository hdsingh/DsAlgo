/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 *
 * https://leetcode.com/problems/word-break/description/
 *
 * algorithms
 * Medium (36.51%)
 * Likes:    2869
 * Dislikes: 157
 * Total Accepted:    406.7K
 * Total Submissions: 1.1M
 * Testcase Example:  '"leetcode"\n["leet","code"]'
 *
 * Given a non-empty string s and a dictionary wordDict containing a list of
 * non-empty words, determine if s can be segmented into a space-separated
 * sequence of one or more dictionary words.
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
 * Input: s = "leetcode", wordDict = ["leet", "code"]
 * Output: true
 * Explanation: Return true because "leetcode" can be segmented as "leet
 * code".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "applepenapple", wordDict = ["apple", "pen"]
 * Output: true
 * Explanation: Return true because "applepenapple" can be segmented as "apple
 * pen apple".
 * Note that you are allowed to reuse a dictionary word.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
 * Output: false
 * 
 * 
 */
#include "cpp.h"
using namespace std;

typedef std::vector<int> vi;
typedef std::vector<vector<int>> vvi;
typedef std::vector<vector<string>> vvs;

// @lc code=start

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        unordered_set<string> dict;
        int max_len = 0;
        for(auto word: wordDict){
            dict.insert(word);
            max_len = max((int)word.length(), max_len);
        }

        vector<int> dp(n+1);
        dp[0] = 1; // 

        for(int i=1; i<=n; i++){
            for(int j=i-1; j>=max(i-max_len, 0); j--){
                if(dp[j]){
                    string sub = s.substr(j, i-j);
                    if(dict.find(sub)!=dict.end()){
                        dp[i] = 1;
                        break;
                    }
                }
            }
        }

        return dp[n];        
    }
};

// Recursive
class Solution3 {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        for(auto word: wordDict)
            dict.insert(word);
        return findBreak(0, s, dict);
    }

    bool findBreak(int beg, string s, unordered_set<string> &dict){
        int n = s.size();
        if(beg>=s.size()) return false;

        for(int i=beg; i<=n; i++){
            string sub = s.substr(beg, i-beg);
            print(sub);
            if(dict.find(sub)!=dict.end()){
                if(i==n) return true;
                if(findBreak(i, s, dict))
                    return true;
            }
        }

        return false;
    }
};

class Solution2 {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        for(auto word: wordDict)
            dict.insert(word);
        return findBreak(s, dict);
    }

    bool findBreak(string s, unordered_set<string> &dict){
        int n = s.size();

        for(int i=1; i<=n; i++){
            string sub1 = s.substr(0, i);
            deb(sub1);
            if(dict.find(sub1)!=dict.end()){
                string sub2 = s.substr(i, n-i);
                deb(sub2);
                if(findBreak(sub2, dict))
                    return true;
            }
        }

        return false;
    }
};

class Solution1 {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        for(auto w: wordDict)
            dict.insert(w);
        return findBreak(s, dict);
    }

    bool findBreak(string s, unordered_set<string> &dict){
        
        int size = s.size();

        if(size==0) return true;

        for(int i=1; i<=size; i++){
            print(s.substr(0, i));
            if( dict.find(s.substr(0, i))!=dict.end()){
                print(s.substr(i, size-i));
                if(findBreak(s.substr(i, size-i), dict))
                    return true;
            }
        }

        return false;
    }
};

// @lc code=end
int main(){
    Solution sol;
    string s = "leetcode";
    vs wordDict = {"leet", "code"};
    cout<<sol.wordBreak(s, wordDict)<<endl;   

    s = "applepenapple"; wordDict = {"apple", "pen"};
    cout<<sol.wordBreak(s, wordDict)<<endl;   

    s = "catsandog"; wordDict = {"cats", "dog", "sand", "and", "cat"};
    cout<<sol.wordBreak(s, wordDict)<<endl; 

    s = "aaaab";
    wordDict = {"a","aa"};
    cout<<sol.wordBreak(s, wordDict)<<endl; 


}
