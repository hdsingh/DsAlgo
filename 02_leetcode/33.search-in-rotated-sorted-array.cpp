/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (33.16%)
 * Likes:    2918
 * Dislikes: 358
 * Total Accepted:    476.7K
 * Total Submissions: 1.4M
 * Testcase Example:  '[4,5,6,7,0,1,2]\n0'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 * 
 * (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
 * 
 * You are given a target value to search. If found in the array return its
 * index, otherwise return -1.
 * 
 * You may assume no duplicate exists in the array.
 * 
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [4,5,6,7,0,1,2], target = 0
 * Output: 4
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [4,5,6,7,0,1,2], target = 3
 * Output: -1
 * 
 */
#include "cpp.h"
using namespace std;

typedef std::vector<int> vi;
typedef std::vector<vector<int>> vvi;

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(!n) return -1;
        // if(n==1) return nums[0];
        int low = 0;
        int high = n - 1;
        
        // Find the min element index
        while(low<high){
            int mid = low + (high-low)/2;

            if(nums[mid]>nums[high])
                low = mid + 1;
            else if(nums[mid] < nums[high])
                high = mid;
            else
                high--;
        }

        int min_val_index = low;
        low = 0;
        high = n-1;
        
        // Account for rotation
        while(low<=high){
            int mid = low + (high-low)/2;
            int realmid = (mid+min_val_index)%n;

            if(nums[realmid]==target) return realmid;
            else if(nums[realmid]<target)
                low = mid + 1;
            else
                high = mid - 1;
        }     

        return -1;
        
    }
};
// @lc code=end
int main(){
    Solution sol;
    vi nums; int target;

    nums = {4,5,6,7,0,1,2};
    target = 0;
    cout<<sol.search(nums,target)<<endl;

    nums = {4,5,6,7,0,1,2};
    target = 3;
    cout<<sol.search(nums,target)<<endl;

    nums = {65};
    target = 1;
    cout<<sol.search(nums,target)<<endl;


}