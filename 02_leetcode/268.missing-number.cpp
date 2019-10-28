/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 *
 * https://leetcode.com/problems/missing-number/description/
 *
 * algorithms
 * Easy (49.22%)
 * Likes:    1143
 * Dislikes: 1544
 * Total Accepted:    333.3K
 * Total Submissions: 673.5K
 * Testcase Example:  '[3,0,1]'
 *
 * Given an array containing n distinct numbers taken from 0, 1, 2, ..., n,
 * find the one that is missing from the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,0,1]
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [9,6,4,2,3,5,7,0,1]
 * Output: 8
 * 
 * 
 * Note:
 * Your algorithm should run in linear runtime complexity. Could you implement
 * it using only constant extra space complexity?
 */
#include "cpp.h"
#include "extra.h"
using namespace std;

// @lc code=start

// xor: a^a = 0
// x1 = a1^a2^a3;
// x2 = a1^a2^a3^a4;
// x1^x2 = a4;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int target = (n*(n+1))/2;

        int sum=0;
        for(int num: nums)
            sum+=num;
        
        return target-sum;
    }

    int missingNumber1(vector<int>& nums) {
        int x1(0), x2(0);

        for(int i=0; i<=nums.size(); i++)
            x1^=i;

        for(int num: nums)
            x2^=num;
        
        return x1^x2;
    }
};
// @lc code=end

