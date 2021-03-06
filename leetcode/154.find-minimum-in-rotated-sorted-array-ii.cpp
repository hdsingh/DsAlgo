/*
 * @lc app=leetcode id=154 lang=cpp
 *
 * [154] Find Minimum in Rotated Sorted Array II
 *
 * https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/description/
 *
 * algorithms
 * Hard (39.96%)
 * Likes:    588
 * Dislikes: 166
 * Total Accepted:    150K
 * Total Submissions: 375.2K
 * Testcase Example:  '[1,3,5]'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 * 
 * (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
 * 
 * Find the minimum element.
 * 
 * The array may contain duplicates.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,3,5]
 * Output: 1
 * 
 * Example 2:
 * 
 * 
 * Input: [2,2,2,0,1]
 * Output: 0
 * 
 * Note:
 * 
 * 
 * This is a follow up problem to Find Minimum in Rotated Sorted Array.
 * Would allow duplicates affect the run-time complexity? How and why?
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
// 
// Now everything same as prev(LC153)
// for the case when mid and high have same element, shift high towards left (high--)

// @lc code=start

// Try to find the piviot pt, 
// in case a[mid]==a[n-1], decrease n.
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int lt = -1, rt = n;
        while(1+lt<rt && n>0){
            int mid = lt + (rt-lt)/2;
            if(nums[mid]==nums[n-1])
                --n, rt = min(rt,n);
            else if(nums[mid]<=nums[n-1])
                rt = mid;
            else 
                lt = mid;
        }
    
        return nums[rt];
    }
};
class Solution {
public:
    int findMin(vector<int>& a) {
        int n = a.size();
        int l = 0, r = n-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            
            if(a[mid]>a[r])
                l = mid + 1;
            else if(a[mid]<a[r]) // dont go beyond mid, since it could be the min element
                r = mid;
            else 
                r--;
            
            cout<<"\n";
        }
        return a[l];
    }
};

// The pivot will lie in the unsorted part,
// [4,5,6,7,1,2,3]
// if a[mid]>a[rt](ex: 7>3), i.e unsorted it lies from [mid+1, rt]
// else if a[lt]>a[mid] (unsorted), it lies from [lt+1, mid] (ex 4>1)
// else the entire array is sorted i.e a[l]<=a[mid]<=a[rt]
// So decrease rt.
class Solution {
public:
    int findMin(vector<int>& a) {
        int n = a.size();
        int lt = 0, rt = n-1;
        while(lt<rt){
            int mid = lt + (rt-lt)/2;
            if(a[mid]>a[rt])
                lt = mid+1;
            else if(a[lt]>a[mid])
                rt = mid, ++lt;
            else 
                --rt;
        }
        return a[lt];
    }
};

// Draw a graph and observe.
class Solution {
public:
    int findMin(vector<int>& a) {
        int n = a.size();
        int lt = 0, rt = n-1;
        while(lt<rt){
            int mid = lt + (rt-lt)/2;
            if(a[mid]>a[rt])
                lt = mid+1;
            else if(a[mid]<a[rt])
                rt = mid;
            else 
                --rt;
        }
        return a[rt];
    }
};


// @lc code=end
int main(){
    Solution sol;
    vi nums = {3,4,5,1,2};
    cout<<sol.findMin(nums)<<endl;

    nums = {4,5,6,7,0,1,2};
    cout<<sol.findMin(nums)<<endl;

    nums = {3,3,1,3};
    cout<<sol.findMin(nums)<<endl;

    nums = {3,3};
    cout<<sol.findMin(nums)<<endl;

    nums = {1,2,1};
    cout<<sol.findMin(nums)<<endl;
}
