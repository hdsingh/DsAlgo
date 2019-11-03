/*
 * @lc app=leetcode id=1249 lang=cpp
 *
 * [1249] Minimum Remove to Make Valid Parentheses
 *
 * https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/description/
 *
 * algorithms
 * Medium (51.60%)
 * Likes:    16
 * Dislikes: 1
 * Total Accepted:    2.2K
 * Total Submissions: 4.1K
 * Testcase Example:  '"lee(t(c)o)de)"'
 *
 * Given a string s of '(' , ')' and lowercase English characters. 
 * 
 * Your task is to remove the minimum number of parentheses ( '(' or ')', in
 * any positions ) so that the resulting parentheses string is valid and return
 * any valid string.
 * 
 * Formally, a parentheses string is valid if and only if:
 * 
 * 
 * It is the empty string, contains only lowercase characters, or
 * It can be written as AB (A concatenated with B), where A and B are valid
 * strings, or
 * It can be written as (A), where A is a valid string.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "lee(t(c)o)de)"
 * Output: "lee(t(c)o)de"
 * Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "a)b(c)d"
 * Output: "ab(c)d"
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "))(("
 * Output: ""
 * Explanation: An empty string is also valid.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: s = "(a(b(c)d)"
 * Output: "a(b(c)d)"
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 10^5
 * s[i] is one of  '(' , ')' and lowercase English letters.
 * 
 */
#include "cpp.h"
using namespace std;

typedef std::vector<int> vi;
typedef std::vector<vector<int>> vvi;

// @lc code=start
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string out1;
        int count=0;
        // Forward pass
        for(auto c: s){
            if(c!='(' && c!=')'){
                out1+=c;
            }
            else if(c=='('){
                out1+=c;
                count++;
            }else{ // ')'
                if(count){
                    out1+=c;
                    count--;
                }
            }
        }

        // print(out1);
        count=0;
        string out2;
        for(auto it = out1.rbegin(); it!=out1.rend(); it++){
            char c = *it;
            if(c!='(' && c!=')')
                out2+=c;
            else if(c==')'){
                out2+=c;
                count++;
            }else{
                if(count){
                    out2+=c;
                    count--;
                }
            }
        }

        reverse(out2.begin(), out2.end());
        return out2;        
    }
};

// Dont use stack unless really required
class Solution1 {
public:
    string minRemoveToMakeValid(string s) {
        string out1;
        stack<char> k;
        // Forward pass
        for(auto c: s){
            if(c!='(' && c!=')'){
                out1+=c;
            }
            else if(c=='('){
                out1+=c;
                k.push(c);
            }else{ // ')'
                if(!k.empty()){
                        k.pop();
                    out1+=c;
                }
            }
        }

        // print(out1);
        k = stack<char>();
        string out2;
        for(auto it = out1.rbegin(); it!=out1.rend(); it++){
            char c = *it;
            if(c!='(' && c!=')')
                out2+=c;
            else if(c==')'){
                out2+=c;
                k.push(c);
            }else{
                if(!k.empty()){
                        k.pop();
                    out2+=c;
                }
            }
        }

        reverse(out2.begin(), out2.end());
        return out2;        
    }
};
// @lc code=end

int main(){
    Solution sol;
    string s;
    cout<<sol.minRemoveToMakeValid("lee(t(c)o)de)")<<endl;
    cout<<sol.minRemoveToMakeValid("a)b(c)d")<<endl;
    cout<<sol.minRemoveToMakeValid("))((")<<endl;
    cout<<sol.minRemoveToMakeValid("(a(b(c)d)")<<endl;

    stack<char> st;
    st.top();
}