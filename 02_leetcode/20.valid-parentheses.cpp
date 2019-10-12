/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (37.22%)
 * Likes:    3418
 * Dislikes: 163
 * Total Accepted:    714.5K
 * Total Submissions: 1.9M
 * Testcase Example:  '"()"'
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 * 
 * An input string is valid if:
 * 
 * 
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * 
 * 
 * Note that an empty string is also considered valid.
 * 
 * Example 1:
 * 
 * 
 * Input: "()"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "()[]{}"
 * Output: true
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "(]"
 * Output: false
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: "([)]"
 * Output: false
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: "{[]}"
 * Output: true
 * 
 * 
 */
#include "cpp.h"
#include "extra.h"
using namespace std;

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                stk.push(s[i]);
            }
                
            else { 
                if(!stk.size()) return false; // to handle "]"
                else if(stk.top()=='(' && s[i]==')') stk.pop();
                else if(stk.top()=='{' && s[i]=='}') stk.pop();
                else if(stk.top()=='[' && s[i]==']') stk.pop();
                else 
                    return false;
            }
        }

        return (!stk.size());
    }
};
// @lc code=end

int main(){
    Solution s;
    string p1="[]";
    cout<<s.isValid(p1);
}