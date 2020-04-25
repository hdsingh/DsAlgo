/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 *
 * https://leetcode.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (50.64%)
 * Likes:    2502
 * Dislikes: 75
 * Total Accepted:    403.6K
 * Total Submissions: 790.3K
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * Given a set of candidate numbers (candidates) (without duplicates) and a
 * target number (target), find all unique combinations in candidates where the
 * candidate numbers sums to target.
 * 
 * The same repeated number may be chosen from candidates unlimited number of
 * times.
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
 * Input: candidates = [2,3,6,7], target = 7,
 * A solution set is:
 * [
 * ⁠ [7],
 * ⁠ [2,2,3]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,3,5], target = 8,
 * A solution set is:
 * [
 * [2,2,2,2],
 * [2,3,3],
 * [3,5]
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
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
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
            std::system("clear");
            print(sub);
            print_vv(sol);
            cout<<"target: "<<target<<endl;;
            usleep(500000);
            if(selected<=target){
                sub.push_back(selected);
                csHelper(candidates, target-selected, sub, sol, i);
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
    // candidates = {2,3,6,7}; target = 7;
    candidates = {2,3,5}; target = 8;
    auto sol = s.combinationSum(candidates,target);
    print_vv(sol);
}