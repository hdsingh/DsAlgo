/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 *
 * https://leetcode.com/problems/longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (41.41%)
 * Likes:    3163
 * Dislikes: 73
 * Total Accepted:    276K
 * Total Submissions: 663.6K
 * Testcase Example:  '[10,9,2,5,3,7,101,18]'
 *
 * Given an unsorted array of integers, find the length of longest increasing
 * subsequence.
 * 
 * Example:
 * 
 * 
 * Input: [10,9,2,5,3,7,101,18]
 * Output: 4 
 * Explanation: The longest increasing subsequence is [2,3,7,101], therefore
 * the length is 4. 
 * 
 * Note: 
 * 
 * 
 * There may be more than one LIS combination, it is only necessary for you to
 * return the length.
 * Your algorithm should run in O(n^2) complexity.
 * 
 * 
 * Follow up: Could you improve it to O(n log n) time complexity?
 * 
 */
// Refer: https://www.youtube.com/watch?v=fV-TF4OvZpk
#include "cpp.h"
using namespace std;

typedef std::vector<int> vi;
typedef std::vector<vector<int>> vvi;

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(!n) return 0;
        vi lens(n, 1);

        for(int i=1; i<n; i++)
            for(int j=0; j<i; j++)
                if(nums[j]<nums[i]) // increasing sunsequence
                    lens[i] = max(lens[i], lens[j]+1);
                    // or
                    // if(lens[j]+1 > lens[i])
                    //     lens[i] = lens[j]+1;

        return *max_element(lens.begin(), lens.end());
    }
};
// @lc code=end
int main(){
    Solution s;
    vi nums;
    nums = {10,9,2,5,3,7,101,18};
    cout<<s.lengthOfLIS(nums)<<endl;
    nums = {};
    cout<<s.lengthOfLIS(nums)<<endl;
    
    return 0;
}
