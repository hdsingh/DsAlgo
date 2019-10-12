/*
 * @lc app=leetcode id=523 lang=cpp
 *
 * [523] Continuous Subarray Sum
 *
 * https://leetcode.com/problems/continuous-subarray-sum/description/
 *
 * algorithms
 * Medium (24.25%)
 * Likes:    789
 * Dislikes: 1066
 * Total Accepted:    77.3K
 * Total Submissions: 319.1K
 * Testcase Example:  '[23,2,4,6,7]\n6'
 *
 * Given a list of non-negative numbers and a target integer k, write a
 * function to check if the array has a continuous subarray of size at least 2
 * that sums up to a multiple of k, that is, sums up to n*k where n is also an
 * integer.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [23, 2, 4, 6, 7],  k=6
 * Output: True
 * Explanation: Because [2, 4] is a continuous subarray of size 2 and sums up
 * to 6.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [23, 2, 6, 4, 7],  k=6
 * Output: True
 * Explanation: Because [23, 2, 6, 4, 7] is an continuous subarray of size 5
 * and sums up to 42.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The length of the array won't exceed 10,000.
 * You may assume the sum of all the numbers is in the range of a signed 32-bit
 * integer.
 * 
 * 
 */
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size() < 2) return false;
        if(k == 0)
        {
            for(int i = 1; i < nums.size(); i++)
            {
                if(nums[i] == 0 && nums[i - 1] == 0) return true;
            }
            return false;
        }else{
            int i = 0;
            map<int, int> res;
            while(true)
            {
                if(i != 0 && nums[i] % k == 0)
                {
                    return true;
                }else{
                    if(res.find(nums[i] % k) == res.end())
                    { 
                         res[nums[i] % k] = i;
                    }else{
                         if(i - res[nums[i] % k] > 1) return true;
                    }
                }
                i++;
                if(i == nums.size()) return false;
                nums[i] += nums[i - 1];
            }
        }
    }
};

