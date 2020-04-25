/*
 * @lc app=leetcode id=137 lang=cpp
 *
 * [137] Single Number II
 *
 * https://leetcode.com/problems/single-number-ii/description/
 *
 * algorithms
 * Medium (47.06%)
 * Likes:    1019
 * Dislikes: 281
 * Total Accepted:    184.2K
 * Total Submissions: 387.8K
 * Testcase Example:  '[2,2,3,2]'
 *
 * Given a non-empty array of integers, every element appears three times
 * except for one, which appears exactly once. Find that single one.
 * 
 * Note:
 * 
 * Your algorithm should have a linear runtime complexity. Could you implement
 * it without using extra memory?
 * 
 * Example 1:
 * 
 * 
 * Input: [2,2,3,2]
 * Output: 3
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [0,1,0,1,0,1,99]
 * Output: 99
 * 
 */
#include "cpp.h"
#include "extra.h"
using namespace std;

// @lc code=start

// Count the number of set bits for all the integers
// Mod the sum at every pos by 3
// Now bitsum has bits set only for the num being repeated
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int> bitsum(32, 0);

        for(int num: nums)
            for(int i=0; i<32; i++)
                if (num&1<<i) bitsum[i]++;
        
        for(int &bit: bitsum)
            bit%=3;

        int out=0;
        for(int i=0; i<32; i++)
            if(bitsum[i])
                out|=1<<i;
        
        return out;
    }
};
// @lc code=end
int main(){
    Solution s;
    vvi numss = {{3,3,3,1}, {0,1,0,1,0,1,99}};
    for(vi nums: numss)
        cout<<s.singleNumber(nums)<<endl;
}
