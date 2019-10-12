/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations/description/
 *
 * algorithms
 * Medium (57.33%)
 * Likes:    2527
 * Dislikes: 82
 * Total Accepted:    448.2K
 * Total Submissions: 774.3K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a collection of distinct integers, return all possible permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3]
 * Output:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 * 
 */
#include "cpp.h"
#include "extra.h"
using namespace std;

// @lc code=start
class Solution1 {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> sol;
        vector<int> sub;
        perHelper(nums, sub, sol);
        return sol;
    }

    void perHelper(vector<int>& nums, vector<int> &sub, vector<vector<int>> &sol){
        // termination
        if(nums.size()==0){
            sol.push_back(sub);
            return;
        }


        // explore + rec
        for(int i=0; i<nums.size(); i++){
            sub.push_back(nums[i]); // select element at i
            vector<int> temp; // to exclude the used element
            temp.insert(temp.end(), nums.begin(), nums.begin()+i);
            temp.insert(temp.end(), nums.begin()+i+1, nums.end());
            perHelper(temp, sub, sol);
            sub.pop_back();

        }
    }

};

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> sol;
        perHelper(nums, 0, sol);
        return sol;
    }

    void perHelper(vector<int>& nums, int begin,  vector<vector<int>> &sol){
        int n = nums.size();
        // termination
        if(begin==n){
            sol.push_back(nums);
            return;
        }

        // explore + rec
        for(int i=begin; i<n; i++){
            swap(nums[begin], nums[i]);
            perHelper(nums, begin+1, sol);
            swap(nums[begin], nums[i]);


        }
    }

};
// @lc code=end
int main(){
    Solution s;
    vi nums = {1,2,3};
    auto out = s.permute(nums);
    print_vv(out);

}
