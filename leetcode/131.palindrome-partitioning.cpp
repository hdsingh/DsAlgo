/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 *
 * https://leetcode.com/problems/palindrome-partitioning/description/
 *
 * algorithms
 * Medium (43.71%)
 * Likes:    1258
 * Dislikes: 51
 * Total Accepted:    191.3K
 * Total Submissions: 437.7K
 * Testcase Example:  '"aab"'
 *
 * Given a string s, partition s such that every substring of the partition is
 * a palindrome.
 * 
 * Return all possible palindrome partitioning of s.
 * 
 * Example:
 * 
 * 
 * Input: "aab"
 * Output:
 * [
 * ⁠ ["aa","b"],
 * ⁠ ["a","a","b"]
 * ]
 * 
 * 
 */
#include "cpp.h"
using namespace std;

typedef std::vector<string> vs;
typedef std::vector<vector<string>> vvs;

// @lc code=start
class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vs sub; 
        vvs res;
        createPartition(0, sub, res, s);

        return res;
    }

    void createPartition(int start, vs &sub, vvs &res, string &s){
        int n = s.size();
        if(start>=n){
            res.push_back(sub);
            return;
        }

        for(int i=start; i<n; i++){
            string temp = s.substr(start, i-start+1);
            if(isPalindrome(temp)){
                sub.push_back(temp);
                createPartition(i+1, sub, res, s);
                sub.pop_back();
            }
        }

    }

    bool isPalindrome(string &s){
        int n = s.size();
        int start(0), end(n-1);

        while(start<=end){
            if(s[start++]!=s[end--])
                return false;
        }

        return true;
    }
};
// @lc code=end
int main(){
    Solution sol;
    vvs out;
    out = sol.partition("aab");
    print_vv(out);

    string s = "abba";
    // cout<<sol.isPalindrome(s);

}
