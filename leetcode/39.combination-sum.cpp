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

class Solution {
    vector<int> cur;
    vector<vector<int>> ans;
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int X) {
        sort(nums.begin(), nums.end());
        ans.clear();
        dfs(0,X, nums);
        return ans;
    }
    
    void dfs(int pos, int X, vector<int> &nums){
        if(X==0){
            ans.push_back(cur);
            return;
        }
        if(pos>=nums.size() || X<0) return;
        
        for(int i=pos; i<nums.size() && nums[i]<=X; ++i){
            cur.push_back(nums[i]);
            dfs(i,X-nums[i], nums);
            cur.pop_back();
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