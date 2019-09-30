/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 *
 * https://leetcode.com/problems/move-zeroes/description/
 *
 * algorithms
 * Easy (55.11%)
 * Likes:    2396
 * Dislikes: 86
 * Total Accepted:    532.1K
 * Total Submissions: 963.4K
 * Testcase Example:  '[0,1,0,3,12]'
 *
 * Given an array nums, write a function to move all 0's to the end of it while
 * maintaining the relative order of the non-zero elements.
 * 
 * Example:
 * 
 * 
 * Input: [0,1,0,3,12]
 * Output: [1,3,12,0,0]
 * 
 * Note:
 * 
 * 
 * You must do this in-place without making a copy of the array.
 * Minimize the total number of operations.
 * 
 */

#include "cpp.h"
#include "extra.h"
using namespace std;
// @lc code=start

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int p1 = 0;
        int p2 = 1;
        while(p2<nums.size()){
            if(nums[p1]!=0){ p1++; p2++;}
            else{
                if(nums[p2]==0) p2++;
                else{ //p2!=0
                    swap(nums[p1], nums[p2]);
                    p1++; p2++;
                }
            }
        }
        // print(nums);
    }
};

// @lc code=end

int main(){
    Solution s;
    vi nums = {0,1};
    s.moveZeroes(nums);
    print(nums);
}


