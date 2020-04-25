/*
 * @lc app=leetcode id=312 lang=cpp
 *
 * [312] Burst Balloons
 *
 * https://leetcode.com/problems/burst-balloons/description/
 *
 * algorithms
 * Hard (49.07%)
 * Likes:    1700
 * Dislikes: 49
 * Total Accepted:    76.9K
 * Total Submissions: 156.5K
 * Testcase Example:  '[3,1,5,8]'
 *
 * Given n balloons, indexed from 0 to n-1. Each balloon is painted with a
 * number on it represented by array nums. You are asked to burst all the
 * balloons. If the you burst balloon i you will get nums[left] * nums[i] *
 * nums[right] coins. Here left and right are adjacent indices of i. After the
 * burst, the left and right then becomes adjacent.
 * 
 * Find the maximum coins you can collect by bursting the balloons wisely.
 * 
 * Note:
 * 
 * 
 * You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can
 * not burst them.
 * 0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100
 * 
 * 
 * Example:
 * 
 * 
 * Input: [3,1,5,8]
 * Output: 167 
 * Explanation: nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  -->
 * []
 * coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
 * 
 */
#include "cpp.h"
using namespace std;

typedef std::vector<int> vi;
typedef std::vector<vector<int>> vvi;
template<class T, class U> inline void max_self(T &x, U y) { if (y > x) x = y; }

// @lc code=start
class Solution2 {
public:
    int maxCoins(vector<int>& dims) {
        // insert 1 at begin and end
        dims.insert(dims.begin(), 1);
        dims.push_back(1);
        
        int n = dims.size();
        vvi dp(n, vi(n, 0));


        for(int len=1; len<n; len++){
            for(int i=1; i<n-len; i++){
                int j = i+len;

                for(int k=i; k<j; k++)
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k+1][j] + dims[i-1]*dims[k]*dims[j]);
                
            }
        }

        return dp[1][n-1];
        
    }
};

// Using matrix chain multiplication
class Solution1 {
public:
    int maxCoins(vector<int>& dims) {
        // insert 1 at begin and end
        dims.insert(dims.begin(), 1);
        dims.push_back(1);

        int n = dims.size();
        vvi dp(n, vi(n, 0));

        // initialize for d=0 (along the diagonal): already done
        // for(int i=0; i<n; i++) dp[i][i] = dims[i];

        for(int len=1; len<n; len++){
            for(int i=1; i<n-len; i++){
                int j = i+len;
                int min_cost = INT_MIN;

                for(int k=i; k<j; k++){
                    int cost = dp[i][k] + dp[k+1][j] + dims[i-1]*dims[k]*dims[j];
                    min_cost = max(min_cost, cost);
                }
                dp[i][j] = min_cost;
            }
        }

        // print_vv(dp);

        return dp[1][n-1];
        
    }
};

// dp[L]R] = maximum coins gained by bursting from L to R
//  xaL.....i.......Rbxxxxxxxx
//  if we burst baloon i(by trying for all i in L to R) and max,
// dp[L][R] = max( A[L-1]*a[i]*a[R+1] + dp[L][i-1] + dp[i+1][R])
class Solution {
public:
    int maxCoins(vector<int>& a) {
        int n = a.size();

        vvi dp(n, vi(n));
        for(int l=n-1; l>=0; l--){
            for(int r=l; r<n; r++){
                for(int i=l; i<=r; i++){
                    max_self(dp[l][r], (i ? dp[l][i-1] : 0) + (i+1<n ? dp[i+1][r] : 0) 
                             + (l ? a[l-1] : 1)  * a[i] * (r+1<n ? a[r+1] : 1) );
                }
            }
        }

        // print_vv(dp);

        return dp[0][n-1];
    }
};

// @lc code=end
int main(){
    Solution sol;
    vi nums = {3,1,5,8};
    cout<<sol.maxCoins(nums)<<endl;

    return 0;
}