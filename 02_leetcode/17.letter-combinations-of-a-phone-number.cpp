/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (42.94%)
 * Likes:    2632
 * Dislikes: 337
 * Total Accepted:    455.5K
 * Total Submissions: 1.1M
 * Testcase Example:  '"23"'
 *
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent.
 * 
 * A mapping of digit to letters (just like on the telephone buttons) is given
 * below. Note that 1 does not map to any letters.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * Note:
 * 
 * Although the above answer is in lexicographical order, your answer could be
 * in any order you want.
 * 
 */
#include "cpp.h"
#include "extra.h"
using namespace std;

// @lc code=start
class Solution {
public:
    unordered_map<char, string> um;
    
    void fill_um(unordered_map<char, string> &um){
        um.insert({'2', "abc"});
        um.insert({'3', "def"});
        um.insert({'4', "ghi"});
        um.insert({'5', "jkl"});
        um.insert({'6', "mno"});
        um.insert({'7', "pqrs"});
        um.insert({'8', "tuv"});
        um.insert({'9', "wxyz"});
    }

    vector<string> letterCombinations(string digits) {
        vector<string> out;
        if (digits.size()==0) return out;
        fill_um(um);
        string in = "";
        lcom(digits, 0, in, out);
        return out;
    }

    void lcom(string &digits, int loc, string &in, vector<string> &out){
        
        // base case
        if(loc==digits.size()) out.push_back(in);

        // exploration + recursion
        string button = um[digits[loc]];
        for(int i = 0; i<button.size(); i++){
            string in_copy = in;
            char temp = button[i];
            in_copy +=temp;
            lcom(digits, loc+1, in_copy, out);
        }
        
    }
};
// @lc code=end
int main(){
    Solution s;
    string digits = "23";
    vector<string> out = s.letterCombinations(digits);
    print(out);
}
