/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 *
 * https://leetcode.com/problems/subsets/description/
 *
 * algorithms
 * Medium (54.98%)
 * Likes:    2442
 * Dislikes: 58
 * Total Accepted:    428K
 * Total Submissions: 769.6K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a set of distinct integers, nums, return all possible subsets (the
 * power set).
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * Example:
 * 
 * 
 * Input: nums = [1,2,3]
 * Output:
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 * 
 */
#include "cpp.h"
#include "extra.h"
using namespace std;

// @lc code=start
class Solution1 {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> sub = {};
        vector<vector<int>> sol;
        subsetHelper(nums, 0, sub, sol);
        return sol;
    }

    void subsetHelper(vector<int> &nums, int begin, vector<int> &sub, vector<vector<int>> &sol){
        int n = nums.size();
        sol.push_back(sub);
        // termination
        if(n==0){
            return;
        }

        // exp + rec
        for(int i=0; i<n; i++){
            if(sub.size()>0) {
                if(*(sub.end()-1)<=nums[i]){
                    sub.push_back(nums[i]);
                    
                    vector<int> temp;
                    temp.insert(temp.begin(), nums.begin(), nums.begin()+i);
                    temp.insert(temp.begin(), nums.begin()+i+1, nums.end());
                    subsetHelper(temp, i, sub, sol);
                    sub.pop_back();
                }
            }else{
                sub.push_back(nums[i]);

                    vector<int> temp;
                    temp.insert(temp.begin(), nums.begin(), nums.begin()+i);
                    temp.insert(temp.begin(), nums.begin()+i+1, nums.end());
                    subsetHelper(temp, i, sub, sol);
                    sub.pop_back();
            }
        }
    }
};

class Solution2 {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> sub = {};
        vector<vector<int>> sol;
        subsetHelper(nums, 0, sub, sol);
        return sol;
    }

    void subsetHelper(vector<int> &nums, int begin, vector<int> &sub, vector<vector<int>> &sol){
        int n = nums.size();
        sol.push_back(sub);

        // exp + rec
        for(int i=begin; i<n; i++){
            sub.push_back(nums[i]);
            subsetHelper(nums, i+1, sub, sol);
            sub.pop_back();
        }
    }
};

// Bitmasks
class Solution3 {
public:
    vector<vector<int>> subsets(vector<int>& a) {
        int n = a.size();

        vvi out;
        for(int mask=0; mask<(1<<n); mask++){
            vi cur;
            for(int i=0; i<n; i++){
                if( mask & (1<<i) )
                    cur.push_back(a[i]);
            }
            out.push_back(cur);
        }
        return out;
    }
};

// Simple iteration
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& a) {
        int n = a.size();
        vvi out = {{}};
        for(int x: a){
            vvi cur = out;
            for(auto &c: cur){
                c.push_back(x);
                out.push_back(c);
            }
        }
        return out;
    }
};

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans = {{}};
        for(int num: nums){
            int prev_len = ans.size();
            for(int i=0; i<prev_len; ++i){
                ans.push_back(ans[i]);
                ans.back().push_back(num);
            }
        }
        return ans;
    }
};
// @lc code=end

int main(){
    vi nums = {1,2,3,4};
    Solution s;
    auto out = s.subsets(nums);
    print_vv(out);
}