/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647] Palindromic Substrings
 *
 * https://leetcode.com/problems/palindromic-substrings/description/
 *
 * algorithms
 * Medium (58.41%)
 * Likes:    1761
 * Dislikes: 89
 * Total Accepted:    130.9K
 * Total Submissions: 224K
 * Testcase Example:  '"abc"'
 *
 * Given a string, your task is to count how many palindromic substrings in
 * this string.
 * 
 * The substrings with different start indexes or end indexes are counted as
 * different substrings even they consist of same characters.
 * 
 * Example 1:
 * 
 * 
 * Input: "abc"
 * Output: 3
 * Explanation: Three palindromic strings: "a", "b", "c".
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "aaa"
 * Output: 6
 * Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The input string length won't exceed 1000.
 * 
 * 
 * 
 */
#include "cpp.h"
using namespace std;

typedef std::vector<int> vi;
typedef std::vector<vector<int>> vvi;

// Approach: For each pos in string, count the num of pals around it
// pass a single pos in both l,r to get num pals around one center
// pass l, r=l+1 to get pals around two centers 
// @lc code=start
class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        for(int i=0; i<s.size(); i++){
            // Pal with one center, a, aba
            // This will also count the single letter(since 'a' is a palindrome around itself)
            count+=numPals(i,i,s);

            // Pal around two centers: aa, abba
            count+=numPals(i,i+1,s);
        }

        return count;
    }

    // More efficient
    int numPals(int l, int r, string &s){
        int count = 0;
        while(l>=0 && r<s.size() && s[l--]==s[r++]) 
            ++count;
        return count; 
    }
};
// @lc code=end
int main(){
    Solution sol;
    cout<<sol.countSubstrings("aaa")<<endl;
    cout<<sol.countSubstrings("abc")<<endl;
    cout<<sol.countSubstrings("axcac")<<endl;
    // cout<<sol.numPals(1,2, "abba");

}
