/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 *
 * https://leetcode.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (42.12%)
 * Likes:    1291
 * Dislikes: 46
 * Total Accepted:    279.5K
 * Total Submissions: 656.7K
 * Testcase Example:  '[1,1,2]'
 *
 * Given a collection of numbers that might contain duplicates, return all
 * possible unique permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,1,2]
 * Output:
 * [
 * ⁠ [1,1,2],
 * ⁠ [1,2,1],
 * ⁠ [2,1,1]
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
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> sol;
        vector<int> sub;
        sort(nums.begin(), nums.end());
        perHelper(nums, sub, sol);
        return sol;
    }
    
    void perHelper(vector<int> &nums, vector<int> &sub, vector<vector<int>> &sol){
        int n = nums.size();
        // termination
        if(n==0){
            sol.push_back(sub);
            return;
        }

        // exp+rec
        for(int i=0; i<n;i++){
            if(i-1>=0) if(nums[i]==nums[i-1]) continue;
            sub.push_back(nums[i]);
            vector<int> temp; // to exclude used element
            temp.insert(temp.end(), nums.begin(), nums.begin()+i);
            temp.insert(temp.end(), nums.begin()+i+1, nums.end());
            perHelper(temp, sub, sol);
            sub.pop_back();
        }
    }    
};

// Logic: If in the nums, an element is repeating again (is same as prev),
    //    then don't use it and skip(continue)
    //    for better understanding draw a permutation tree of (1,1,2) and check


// @lc code=end
int main(){
    Solution s;
    vi nums = {1,1,2};
    auto out = s.permuteUnique(nums);
    print_vv(out);
    return 0;
}

