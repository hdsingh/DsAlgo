/*
 * @lc app=leetcode id=303 lang=cpp
 *
 * [303] Range Sum Query - Immutable
 *
 * https://leetcode.com/problems/range-sum-query-immutable/description/
 *
 * algorithms
 * Easy (39.64%)
 * Likes:    538
 * Dislikes: 840
 * Total Accepted:    153.5K
 * Total Submissions: 387.1K
 * Testcase Example:  '["NumArray","sumRange","sumRange","sumRange"]\n[[[-2,0,3,-5,2,-1]],[0,2],[2,5],[0,5]]'
 *
 * Given an integer array nums, find the sum of the elements between indices i
 * and j (i ≤ j), inclusive.
 * 
 * Example:
 * 
 * Given nums = [-2, 0, 3, -5, 2, -1]
 * 
 * sumRange(0, 2) -> 1
 * sumRange(2, 5) -> -1
 * sumRange(0, 5) -> -3
 * 
 * 
 * 
 * Note:
 * 
 * You may assume that the array does not change.
 * There are many calls to sumRange function.
 * 
 * 
 */
#include "cpp.h"
#include "extra.h"
using namespace std;

// @lc code=start
class NumArray {
    private:
        vector<int> sums;
public:
    NumArray(vector<int>& nums) {

        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum = sum + nums[i];
            sums.push_back(sum);
        }
    }
    
    int sumRange(int i, int j) {
        if(i==0) return sums[j];
        return sums[j] - sums[i-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
// @lc code=end

int main(){
    vi nums;
    nums = {-2, 0, 3, -5, 2, -1};
    NumArray s(nums);
    cout<<s.sumRange(0,2)<<endl;
    cout<<s.sumRange(2,5)<<endl;
    cout<<s.sumRange(0,5)<<endl;

}