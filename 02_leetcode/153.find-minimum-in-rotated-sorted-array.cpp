/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 *
 * https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (43.83%)
 * Likes:    1355
 * Dislikes: 187
 * Total Accepted:    343.1K
 * Total Submissions: 782.2K
 * Testcase Example:  '[3,4,5,1,2]'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 * 
 * (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
 * 
 * Find the minimum element.
 * 
 * You may assume no duplicate exists in the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,4,5,1,2] 
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [4,5,6,7,0,1,2]
 * Output: 0
 * 
 * 
 */
#include "cpp.h"
using namespace std;

typedef std::vector<int> vi;
typedef std::vector<vector<int>> vvi;

// if the value of the element in mid is larger then element at end,
// move the low to mid+1 (eg: [4,5,6,7,0,1,2]) bec min lies in right of mid
// if the value of the element at the mid is lesser than at end,
// eg([6,7,0,1,2,3,4,5]), shift high towards mid, since min would be in left half
// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;

        while(low<high){
            int mid = low + (high-low)/2;

            if(nums[mid]>nums[high])
                low = mid+1;
            else 
                high = mid;
        }
        return nums[low];
    }
};
// @lc code=end
int main(){
    Solution sol;
    vi nums = {3,4,5,1,2};
    cout<<sol.findMin(nums)<<endl;

    nums = {4,5,6,7,0,1,2};
    cout<<sol.findMin(nums)<<endl;

    nums = {4,5,6,7,7,0,1,1,2,2,3,};
    cout<<sol.findMin(nums)<<endl;

}
