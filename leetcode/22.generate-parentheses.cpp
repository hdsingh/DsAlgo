/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 *
 * https://leetcode.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (56.94%)
 * Likes:    3392
 * Dislikes: 201
 * Total Accepted:    401.3K
 * Total Submissions: 699.7K
 * Testcase Example:  '3'
 *
 * 
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 * 
 * 
 * 
 * For example, given n = 3, a solution set is:
 * 
 * 
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
 * 
 */
#include "cpp.h"
#include "extra.h"
using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string in = "";
        vector<string> res;
        gP(in, res, n, 0);
        // left : no of '(' remaining
        // right : no of ')' remaining
        return res;
    }

    void gP(string in, vector<string> &res, int left, int right){

        if(!left && !right) {
            res.push_back(in);
            return;
        }

        
        if(left>0) gP(in+"(",res, left-1, right+1);
        if(right>0) gP(in+")", res, left, right-1);
    }    

};

// @lc code=end
int main(){
    Solution s;
    vs out = s.generateParenthesis(3);
    print(out);
}
