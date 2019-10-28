/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 *
 * https://leetcode.com/problems/single-number/description/
 *
 * algorithms
 * Easy (61.41%)
 * Likes:    2963
 * Dislikes: 115
 * Total Accepted:    553.7K
 * Total Submissions: 895.5K
 * Testcase Example:  '[2,2,1]'
 *
 * Given a non-empty array of integers, every element appears twice except for
 * one. Find that single one.
 * 
 * Note:
 * 
 * Your algorithm should have a linear runtime complexity. Could you implement
 * it without using extra memory?
 * 
 * Example 1:
 * 
 * 
 * Input: [2,2,1]
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [4,1,2,1,2]
 * Output: 4
 * 
 * 
 */
#include "cpp.h"
#include "extra.h"
using namespace std;

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int out=0;
        for(int num: nums)
            out^=num;
        return out;
    }
};
// @lc code=end

