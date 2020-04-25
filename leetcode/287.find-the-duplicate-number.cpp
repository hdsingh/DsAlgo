/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 *
 * https://leetcode.com/problems/find-the-duplicate-number/description/
 *
 * algorithms
 * Medium (50.97%)
 * Likes:    3051
 * Dislikes: 355
 * Total Accepted:    230.9K
 * Total Submissions: 448.9K
 * Testcase Example:  '[1,3,4,2,2]'
 *
 * Given an array nums containing n + 1 integers where each integer is between
 * 1 and n (inclusive), prove that at least one duplicate number must exist.
 * Assume that there is only one duplicate number, find the duplicate one.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,3,4,2,2]
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,1,3,4,2]
 * Output: 3
 * 
 * Note:
 * 
 * 
 * You must not modify the array (assume the array is read only).
 * You must use only constant, O(1) extra space.
 * Your runtime complexity should be less than O(n^2).
 * There is only one duplicate number in the array, but it could be repeated
 * more than once.
 * 
 * 
 */
#include "cpp.h"
using namespace std;

typedef std::vector<int> vi;
typedef std::vector<vector<int>> vvi;

// @lc code=start
class Solution1 {
public:
    int findDuplicate(vector<int>& nums) {
        int hare = 0;
        int tort = 0;

        int out;
        while(true){          
            tort = nums[tort];
            hare = nums[nums[hare]];
            // cout<<"tort "<<tort<<" : "<<nums[tort]<<endl;
            // cout<<"hare "<<hare<<" : "<<nums[hare]<<endl;

            if(nums[hare]==nums[tort])
                break;

        }

        // Find enterance to cycle
        int ptr1 = nums[0];
        int ptr2 = nums[tort];
        while(ptr1!=ptr2){
            ptr1 = nums[ptr1];
            ptr2 = nums[ptr2];
        }

        return ptr1;
    }
};

// Using binary search
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int low=1;
        int high = nums.size()-1;

        while(low<high){
            int mid = low + (high-low)/2;

            int count = 0;
            for(auto num: nums)
                if(num<=mid) count++;    
            
            if(count>mid) high = mid;
            else low = mid + 1;
        }

        return low;
    }
};

// @lc code=end
int main(){
    Solution sol;
    vi nums = {1,3,4,2,2};
    cout<<sol.findDuplicate(nums)<<endl;

    nums = {3,1,3,4,2};
    cout<<sol.findDuplicate(nums)<<endl;

    nums = {1,4,2,3,5,4};
    cout<<sol.findDuplicate(nums)<<endl;
    
}

