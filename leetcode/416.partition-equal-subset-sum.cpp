/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 *
 * https://leetcode.com/problems/partition-equal-subset-sum/description/
 *
 * algorithms
 * Medium (41.76%)
 * Likes:    1642
 * Dislikes: 50
 * Total Accepted:    119.2K
 * Total Submissions: 285.1K
 * Testcase Example:  '[1,5,11,5]'
 *
 * Given a non-empty array containing only positive integers, find if the array
 * can be partitioned into two subsets such that the sum of elements in both
 * subsets is equal.
 * 
 * Note:
 * 
 * 
 * Each of the array element will not exceed 100.
 * The array size will not exceed 200.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [1, 5, 11, 5]
 * 
 * Output: true
 * 
 * Explanation: The array can be partitioned as [1, 5, 5] and [11].
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1, 2, 3, 5]
 * 
 * Output: false
 * 
 * Explanation: The array cannot be partitioned into equal sum subsets.
 * 
 * 
 * 
 * 
 */
#include "cpp.h"
using namespace std;

typedef std::vector<int> vi;
typedef std::vector<vector<int>> vvi;

// @lc code=start

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%2) return 0;
        int sum_2 = sum/2;

        vi K(sum_2+1, 0);
        K[0] = 1;
        
        for(int i=1; i<=n; i++){
            for(int j=sum_2; j>=nums[i-1]; j--){
                K[j] = K[j] ||  K[ j-nums[i-1] ];
            }
            if(K[sum_2]) return true;
        }

        return K[sum_2];
    }
};

// Using Knapsack 2d
class Solution1 {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%2) return 0;
        int sum_2 = sum/2;

        vvi K(n+1, vi(sum_2+1, 0));
        K[0][0] = 1;

        for(int i=0; i<=n; i++)
            K[i][0] = 1;
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=sum_2; j++){
                K[i][j] = K[i-1][j];
                if(nums[i-1]<=j)
                    K[i][j] = max(K[i][j], K[i-1][ j-nums[i-1] ]);
            }
        }
        
        // print_vv(K);

        return K[n][sum_2]; 
    
    }
};
// @lc code=end
int main(){
    Solution sol;
    vi nums = {1,2,3,5};
    cout<<sol.canPartition(nums)<<endl;

    nums = {1,5,9,7};
    cout<<sol.canPartition(nums)<<endl;

    nums = {1,2,3,4};
    cout<<sol.canPartition(nums)<<endl;
    
}

