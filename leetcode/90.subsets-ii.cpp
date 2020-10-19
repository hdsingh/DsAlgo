/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 *
 * https://leetcode.com/problems/subsets-ii/description/
 *
 * algorithms
 * Medium (43.64%)
 * Likes:    1110
 * Dislikes: 54
 * Total Accepted:    228.2K
 * Total Submissions: 519K
 * Testcase Example:  '[1,2,2]'
 *
 * Given a collection of integers that might contain duplicates, nums, return
 * all possible subsets (the power set).
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,2]
 * Output:
 * [
 * ⁠ [2],
 * ⁠ [1],
 * ⁠ [1,2,2],
 * ⁠ [2,2],
 * ⁠ [1,2],
 * ⁠ []
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
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> sub;
        vector<vector<int>> sol;
        subHelper(nums, 0, sub, sol);
        return sol;
    }

    void subHelper(vector<int> &nums, int begin, vector<int> sub, vector<vector<int>> &sol){
        sol.push_back(sub);

        for(int i=begin; i<nums.size(); i++){
            if(i!=begin) if(nums[i]==nums[i-1]) continue;
            sub.push_back(nums[i]);
            subHelper(nums, i+1, sub, sol);
            sub.pop_back();
        }
    }
};
// Because (in the state space tree of 122), we want to skip if the 
// next element is same as prev, but in case we are begining this check 
// would not be performed.


class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans = {{}};
        
        for(int i=0; i<n; ++i){
            int prev_len = ans.size();
            int j = i;
            while(j+1<n && nums[j+1]==nums[i]) ++j;
            
            for(int pos=0; pos<prev_len; ++pos){
                vector<int> cur = ans[pos];
                for(int times=1; times<=j-i+1; ++times){
                    cur.push_back(nums[i]);
                    ans.push_back(cur);
                }   
            }
            
            i = j;
        }
        
        return ans;
    }
};

// @lc code=end
int main(){
    Solution s;
    vi nums = {4,4,4,1,4};
    auto out = s.subsetsWithDup(nums);
    print_vv(out);
}
