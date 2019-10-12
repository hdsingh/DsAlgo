/*
 * @lc app=leetcode id=680 lang=cpp
 *
 * [680] Valid Palindrome II
 *
 * https://leetcode.com/problems/valid-palindrome-ii/description/
 *
 * algorithms
 * Easy (34.87%)
 * Likes:    898
 * Dislikes: 63
 * Total Accepted:    92.7K
 * Total Submissions: 265.4K
 * Testcase Example:  '"aba"'
 *
 * 
 * Given a non-empty string s, you may delete at most one character.  Judge
 * whether you can make it a palindrome.
 * 
 * 
 * Example 1:
 * 
 * Input: "aba"
 * Output: True
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: "abca"
 * Output: True
 * Explanation: You could delete the character 'c'.
 * 
 * 
 * 
 * Note:
 * 
 * The string will only contain lowercase characters a-z.
 * The maximum length of the string is 50000.
 * 
 * 
 */
#include "cpp.h"
using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        for(int i=0, j=s.size()-1; i<j; i++, j--){
            if(s[i]==s[j]) continue;
            else
                return is_palindromic(s, i+1, j) || is_palindromic(s, i, j-1);
        }
        return true;  
    }

    bool is_palindromic(string &s, int l, int r){
        for(int i=l, j=r; i<j; i++, j--){
            if(s[i]!=s[j]) return false;
        }
        return true;
    }
};

int main(){
    Solution sol;
    int t;
    string st;
    scanf("%d\n", &t);
    while(t--){
        getline(cin, st);
        bool res = sol.validPalindrome(st);
        cout<<res<<endl;
    }
}
