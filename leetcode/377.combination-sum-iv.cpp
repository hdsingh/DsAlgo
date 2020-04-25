/*
 * @lc app=leetcode id=377 lang=cpp
 *
 * [377] Combination Sum IV
 *
 * https://leetcode.com/problems/combination-sum-iv/description/
 *
 * algorithms
 * Medium (44.07%)
 * Likes:    982
 * Dislikes: 117
 * Total Accepted:    98.6K
 * Total Submissions: 223.7K
 * Testcase Example:  '[1,2,3]\n4'
 *
 * Given an integer array with all positive numbers and no duplicates, find the
 * number of possible combinations that add up to a positive integer target.
 * 
 * Example:
 * 
 * 
 * nums = [1, 2, 3]
 * target = 4
 * 
 * The possible combination ways are:
 * (1, 1, 1, 1)
 * (1, 1, 2)
 * (1, 2, 1)
 * (1, 3)
 * (2, 1, 1)
 * (2, 2)
 * (3, 1)
 * 
 * Note that different sequences are counted as different combinations.
 * 
 * Therefore the output is 7.
 * 
 * 
 * 
 * 
 * Follow up:
 * What if negative numbers are allowed in the given array?
 * How does it change the problem?
 * What limitation we need to add to the question to allow negative numbers?
 * 
 * Credits:
 * Special thanks to @pbrother for adding this problem and creating all test
 * cases.
 * 
 */
#include "cpp.h"
using namespace std;

typedef std::vector<int> vi;
typedef std::vector<vector<int>> vvi;

// @lc code=start
// Recursion + memoisation
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        unordered_map<int, int> memo;
        return csfinder(target, nums, memo);
        
    }

    int csfinder(int target,  vi &nums, unordered_map<int, int> &memo) {
        // Elimination
        if(target==0) return 1;
        if(target<0) return 0;

        if(memo.find(target)!=memo.end())
            return memo[target];

        int res = 0;
        for(auto num: nums)
            res += csfinder(target-num, nums, memo);
        
        return memo[target] = res;
        
    }
};

// DP
class Solution4 {
public:
    int combinationSum4(vector<int>& nums, int x) {
        int n = nums.size();

        vector<unsigned int> dp(x+1, 0);
        // number of ways to get a sum i
        dp[0] = 1;

        // Forward DP
        for(int t=0; t<=x; t++){
            for(auto num: nums){
                if(t+num<=x)
                    dp[t+num] += dp[t];
            }
        }

        return dp[x];
    }  
};

class Solution2 {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<unsigned int> dp(target+1, 0);
        dp[0] = 1;

        for(int i = 1; i<=target; i++){
            for(int num: nums){
                if(num<=i)
                    dp[i]+= dp[i-num];
            }
        }

        return dp[target];        
    }  
};

// Recursion
class Solution3 {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vi sub;
        int ways = 0;
        csfinder(target, sub , nums, ways);
        return ways;
    }

    void csfinder(int target,vi sub, vi &nums, int &ways) {
        // Elimination
        if(target==0){
            ways+=1;
            print(sub);
            return;
        }
        if(target<0) return;

        for(auto num: nums){
            if(num<=target){
                sub.push_back(num);
                csfinder(target-num, sub, nums, ways);
                sub.pop_back();
            }
        }
    }
};

// @lc code=end
int main(){
    Solution4 s;
    vi nums;
    int target;

    nums = {10000, 10001};
    target=20001;
    nums = {1,2,3}; target = 4;
    nums = { 3,33,333 }, target = 10000;
    cout<<s.combinationSum4(nums, target);
    return 0;

}
