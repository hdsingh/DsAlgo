/*
 * @lc app=leetcode id=698 lang=cpp
 *
 * [698] Partition to K Equal Sum Subsets
 *
 * https://leetcode.com/problems/partition-to-k-equal-sum-subsets/description/
 *
 * algorithms
 * Medium (43.98%)
 * Likes:    1125
 * Dislikes: 64
 * Total Accepted:    59.2K
 * Total Submissions: 134.6K
 * Testcase Example:  '[4,3,2,3,5,2,1]\n4'
 *
 * Given an array of integers nums and a positive integer k, find whether it's
 * possible to divide this array into k non-empty subsets whose sums are all
 * equal.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [4, 3, 2, 3, 5, 2, 1], k = 4
 * Output: True
 * Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3),
 * (2,3) with equal sums.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= k <= len(nums) <= 16.
 * 0 < nums[i] < 10000.
 * 
 * 
 */
#include "cpp.h"
using namespace std;

typedef std::vector<int> vi;
typedef std::vector<vector<int>> vvi;

// https://github.com/bephrem1/backtobackswe/blob/master/Dynamic%20Programming%2C%20Recursion%2C%20%26%20Backtracking/PartitionIntoKEqualSumSubsets/PartitionIntoKEqualSumSubsets.java
// @lc code=start
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        if(n<k) return false;
        int sum = accumulate(all(nums),0);
        if(sum%k || k<=0) return false;
        vector<bool> visited(n, false);

        return canPartition(0, nums, visited, k, 0, sum/k);      
    }

    bool canPartition(int start, vi &nums, vector<bool> &visited, int k, int curBucketSum, int target){
        if(k==1) return true;

        if(curBucketSum == target)
            return canPartition(0,nums, visited, k-1, 0, target);
        
        for(int i=start; i<nums.size(); i++){
            if(!visited[i] && curBucketSum + nums[i] <=target){
                visited[i] = true;
                if(canPartition(i+1, nums, visited,k,curBucketSum+nums[i],target))
                    return true;
                visited[i] = false;
            }
        }
        return false;
    }
};
// @lc code=end
int main(){
    Solution sol;
    vi nums = {4, 3, 2, 3, 5, 2, 1};
    int k = 4;
    cout<<sol.canPartitionKSubsets(nums,k)<<endl;

    nums = {10,10,10,7,7,7,7,7,7,6,6,6};
    cout<<sol.canPartitionKSubsets(nums,3)<<endl;


}

