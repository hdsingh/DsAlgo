/*
 * @lc app=leetcode id=1250 lang=cpp
 *
 * [1250] Check If It Is a Good Array
 *
 * https://leetcode.com/problems/check-if-it-is-a-good-array/description/
 *
 * algorithms
 * Hard (38.51%)
 * Likes:    11
 * Dislikes: 52
 * Total Accepted:    1.2K
 * Total Submissions: 3K
 * Testcase Example:  '[12,5,7,23]'
 *
 * Given an array nums of positive integers. Your task is to select some subset
 * of nums, multiply each element by an integer and add all these numbers. The
 * array is said to be good if you can obtain a sum of 1 from the array by any
 * possible subset and multiplicand.
 * 
 * Return True if the array is good otherwise return False.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [12,5,7,23]
 * Output: true
 * Explanation: Pick numbers 5 and 7.
 * 5*3 + 7*(-2) = 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [29,6,10]
 * Output: true
 * Explanation: Pick numbers 29, 6 and 10.
 * 29*1 + 6*(-3) + 10*(-1) = 1
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [3,6]
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^9
 * 
 * 
 */
#include "cpp.h"
using namespace std;

typedef std::vector<int> vi;
typedef std::vector<vector<int>> vvi;

// @lc code=start
class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        if(nums.empty()) return 0;
        int gc = nums[0];
        for(int i=1; i<nums.size(); i++){
            gc = __gcd(gc, nums[i]);
        }
        return gc==1;
    }
};
// @lc code=end

int main(){
    Solution s;
    vi nums = {12,5,7,23};
    cout<<s.isGoodArray(nums)<<endl;
    nums = {29,6,10};
    cout<<s.isGoodArray(nums)<<endl;
    nums = {};
    cout<<s.isGoodArray(nums)<<endl;


}