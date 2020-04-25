/*
 * @lc app=leetcode id=216 lang=cpp
 *
 * [216] Combination Sum III
 *
 * https://leetcode.com/problems/combination-sum-iii/description/
 *
 * algorithms
 * Medium (52.97%)
 * Likes:    736
 * Dislikes: 39
 * Total Accepted:    137.2K
 * Total Submissions: 257.5K
 * Testcase Example:  '3\n7'
 *
 * 
 * Find all possible combinations of k numbers that add up to a number n, given
 * that only numbers from 1 to 9 can be used and each combination should be a
 * unique set of numbers.
 * 
 * Note:
 * 
 * 
 * All numbers will be positive integers.
 * The solution set must not contain duplicate combinations.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: k = 3, n = 7
 * Output: [[1,2,4]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: k = 3, n = 9
 * Output: [[1,2,6], [1,3,5], [2,3,4]]
 * 
 * 
 */
#include "cpp.h"
#include "extra.h"
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> sol;
        vector<int> sub;
        csHelper(k, n, 1, sub, sol);
        return sol;
    }

    void csHelper(int level, int target, int begin, vector<int> &sub, vector<vector<int>> &sol){
        // terminating condition
        if(level==0 && target==0){
            sol.push_back(sub);
            return;
        }

        // exploration + recursion
        for(int i=begin; i<10; i++){
            sub.push_back(i);
            csHelper(level-1, target-i, i+1, sub, sol);
            sub.pop_back();
        }

    }
};
// @lc code=end
int main(){
    Solution s;
    auto out = s.combinationSum3(3, 9);
    print_vv(out);
}

