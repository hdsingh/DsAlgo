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

class Solution0 {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(all(nums),0);
        int n = nums.size();
        if(sum%2) return false;
        sum/=2;
        vector<vb> dp(n+1, vb(sum+1));
        dp[0][0] = 1;
    
        for(int i=1; i<=n; ++i){
            for(int s=0; s<=sum; ++s){
                dp[i][s] = dp[i-1][s];

                if(s-nums[i-1]>=0  && dp[i-1][s-nums[i-1]])
                dp[i][s] = 1;
            }
        }

        return dp[n][sum];
    }
};


class Solution {
public:
    bool canPartition(vector<int>& a) {
        int sum = accumulate(all(a),0);
        if(sum%2) return 0;
        sum/=2;
        vector<bool> dp(sum+1);
        dp[0] = 1;
        for(auto x: a){
            for(int s=sum-x; s>=0; --s)
                if(dp[s])
                    dp[s+x] = 1;
            if(dp[sum]) return 1;
        }
        return dp[sum];
    }
};


// Better implementation using bits
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        const int nax = 100;
        const int nsz = 200;
        int sum = accumulate(nums.begin(), nums.end(),0);
        if(sum&1) return false;

        bitset<nax*nsz/2 + 1> bits(1);
        for(auto x: nums)
            bits|= (bits<<x);
        
        return bits[sum/2];
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

