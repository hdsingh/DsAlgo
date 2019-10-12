/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 *
 * https://leetcode.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (43.39%)
 * Likes:    1117
 * Dislikes: 51
 * Total Accepted:    255.8K
 * Total Submissions: 583.5K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * Given a collection of candidate numbers (candidates) and a target number
 * (target), find all unique combinations in candidates where the candidate
 * numbers sums to target.
 * 
 * Each number in candidates may only be used once in the combination.
 * 
 * Note:
 * 
 * 
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: candidates = [10,1,2,7,6,1,5], target = 8,
 * A solution set is:
 * [
 * ⁠ [1, 7],
 * ⁠ [1, 2, 5],
 * ⁠ [2, 6],
 * ⁠ [1, 1, 6]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,5,2,1,2], target = 5,
 * A solution set is:
 * [
 * [1,2,2],
 * [5]
 * ]
 * 
 * 
 */
#include "cpp.h"
#include "extra.h"
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> sub = {};
        vector<vector<int>> sol;
        sort(candidates.begin(), candidates.end());
        csHelper(candidates, target, sub, sol, 0);
        return sol;
    }

    void csHelper(vector<int>& candidates, int target, vector<int> &sub, vector<vector<int>> &sol, int begin){
        // terminating condition
            
        if(target==0) sol.push_back(sub);

        // explore + recurse
        for(int i=begin; i<candidates.size(); i++){
            int selected = candidates[i];

            if(selected<=target){
                if(i && candidates[i-1]==candidates[i] && i>begin) continue;
                sub.push_back(selected);
                csHelper(candidates, target-selected, sub, sol, i+1);
                sub.pop_back();
            }
        }

    }
};
// @lc code=end

int main(){
    Solution s;
    vi candidates;
    int target;
    // candidates = {10,1,2,7,6,1,5}; target = 8;
    candidates = {2,5,2,1,2}; target = 5;
    auto sol = s.combinationSum2(candidates,target);
    print_vv(sol);
    vi a;
    cout<<a.size();
}