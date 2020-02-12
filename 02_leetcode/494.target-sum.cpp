/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 *
 * https://leetcode.com/problems/target-sum/description/
 *
 * algorithms
 * Medium (45.96%)
 * Likes:    1725
 * Dislikes: 81
 * Total Accepted:    119.2K
 * Total Submissions: 259.2K
 * Testcase Example:  '[1,1,1,1,1]\n3'
 *
 * 
 * You are given a list of non-negative integers, a1, a2, ..., an, and a
 * target, S. Now you have 2 symbols + and -. For each integer, you should
 * choose one from + and - as its new symbol.
 * ⁠
 * 
 * Find out how many ways to assign symbols to make sum of integers equal to
 * target S.  
 * 
 * 
 * Example 1:
 * 
 * Input: nums is [1, 1, 1, 1, 1], S is 3. 
 * Output: 5
 * Explanation: 
 * 
 * -1+1+1+1+1 = 3
 * +1-1+1+1+1 = 3
 * +1+1-1+1+1 = 3
 * +1+1+1-1+1 = 3
 * +1+1+1+1-1 = 3
 * 
 * There are 5 ways to assign symbols to make the sum of nums be target 3.
 * 
 * 
 * 
 * Note:
 * 
 * The length of the given array is positive and will not exceed 20. 
 * The sum of elements in the given array will not exceed 1000.
 * Your output answer is guaranteed to be fitted in a 32-bit integer.
 * 
 * 
 */
#include "cpp.h"
using namespace std;

typedef std::vector<int> vi;
typedef std::vector<vector<int>> vvi;

// @lc code=start
// Using subset sum
// There are two subsets: P and N having pos and neg integers
// Ques =             sum(P) - sum(N) = Target
// We know:           sum(P) + sum(N) = sum(nums)
//  sum(P) - sum(N) + sum(P) + sum(N) = sum(nums) + Target
//                           2 sum(P) = sum(nums) + Target
//                             sum(P) = (sum(nums) + Target)/2
// So we need to find num of ways a subset could have sum(P) = (sum(nums) + Target)/2
class Solution3 {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum<target || (sum+target)%2) return 0;

        int T = (sum + target)/2;

        vi dp(T+1);
        dp[0] = 1;
        
        // 1d Knapsack
        for(int num: nums)
            for(int j=T; j>=num; j--)
                dp[j] = dp[j] + dp[j - num];
        
        // print(dp);

        return dp[T];

    }
};

// Recursion + Memo
class Solution2 {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        // int count = 0;
        int n = nums.size();
        vvi memo(n, vi(2001, INT_MIN)); // i, sum
        return calculate(0,0,nums,S, memo);
    }

    int calculate(int i, int sum, vi &nums, int &S, vvi &memo){
        if(i==nums.size()){
            if(sum==S){
                // count++;
                return 1;
            }
            else return 0;
        }
        if(memo[i][sum+1000]!=INT_MIN) 
            return memo[i][sum+1000];

        int plus = calculate(i+1, sum + nums[i], nums, S, memo);
        int minus = calculate(i+1, sum - nums[i], nums, S, memo);

        memo[i][sum+1000] = plus + minus;
        return memo[i][sum+1000];

    }
};

// Recursion
class Solution1 {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int count = 0;
        calculate(0,0,nums,S,count);
        return count;
    }

    void calculate(int i, int sum, vi &nums, int &S, int &count){
        if(i==nums.size()){
            if(sum==S) count++;
            return;
        }

        calculate(i+1, sum + nums[i], nums, S, count);
        calculate(i+1, sum - nums[i], nums, S, count);
    }
};

// 2d dp
class Solution4 {
public:
    int findTargetSumWays(vector<int>& a, int t) {
        int n = a.size();
        int nax = 2001;
        int sum = accumulate(a.begin(), a.end(), 0);
        if(t>sum) return 0;
        
        vvi dp(n, vi(nax));
        // total number of ways to create sum t using first i stones
        
        dp[0][a[0]+1000] = 1;
        dp[0][-a[0]+1000] += 1; // be careful to do +=1, because in case of 0, this should be 2
        for(int i=1; i<n; i++){
            for(int j=-1000; j<=1000; j++){
                if(dp[i-1][j+1000]){
                    dp[i][a[i] + j + 1000] += dp[i-1][j+1000];
                    dp[i][-a[i] + j + 1000] += dp[i-1][j+1000];
                }
            }
        }

        return dp[n-1][t+1000];
    }
};

// 1d dp
class Solution5 {
public:
    int findTargetSumWays(vector<int>& a, int t) {
        int n = a.size();
        int nax = 2001;
        int sum = accumulate(a.begin(), a.end(), 0);
        if(t>sum) return 0;
        
        vi dp(nax);
        // total number of ways to create sum t using first i stones
        
        dp[a[0]+1000] = 1;
        dp[-a[0]+1000] += 1; // be careful to do +=1, because in case of 0, this should be 2
        for(int i=1; i<n; i++){
            vi ndp(nax);
            for(int j=-1000; j<=1000; j++){
                if(dp[j+1000]){
                    ndp[a[i] + j + 1000] += dp[j+1000];
                    ndp[-a[i] + j + 1000] += dp[j+1000];
                }
            }
            dp = ndp;
        }

        return dp[t+1000];
    }
};

class Solution {
public:
    int findTargetSumWays(vector<int>& a, int t) {
        int n = a.size();
        int sum = accumulate(a.begin(), a.end(), 0);
        if(t>sum) return 0;

        vi dp(2*sum+1);
        dp[0+sum] = 1;
        for(int i=0; i<n; i++){
            vi ndp(2*sum+1);
            for(int k=0; k<2*sum+1; k++){
                if(dp[k]!=0){
                    ndp[k+a[i]]+=dp[k];
                    ndp[k-a[i]]+=dp[k];
                }
            }
            dp = ndp;
        }
        return dp[sum+t];
    }
};

// @lc code=end
int main(){
    Solution sol;
    vi nums = {1,1,1,1,1};
    cout<<sol.findTargetSumWays(nums,3)<<endl;

    nums = {1,1,1,4,1};
    cout<<sol.findTargetSumWays(nums,3)<<endl;

    nums = { 0,0,0,0,0,0,0,0,1 };
    cout<<sol.findTargetSumWays(nums,1)<<endl;
}