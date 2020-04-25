/*
 * @lc app=leetcode id=1248 lang=cpp
 *
 * [1248] Count Number of Nice Subarrays
 *
 * https://leetcode.com/problems/count-number-of-nice-subarrays/description/
 *
 * algorithms
 * Medium (45.29%)
 * Likes:    16
 * Dislikes: 0
 * Total Accepted:    2.2K
 * Total Submissions: 4.8K
 * Testcase Example:  '[1,1,2,1,1]\n3'
 *
 * Given an array of integers nums and an integer k. A subarray is called nice
 * if there are k odd numbers on it.
 * 
 * Return the number of nice sub-arrays.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,1,2,1,1], k = 3
 * Output: 2
 * Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and
 * [1,2,1,1].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [2,4,6], k = 1
 * Output: 0
 * Explanation: There is no odd numbers in the array.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
 * Output: 16
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 50000
 * 1 <= nums[i] <= 10^5
 * 1 <= k <= nums.length
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
    int numberOfSubarrays(vector<int>& a, int k) {
        
        int n = a.size();
        vector<int> sums(n+1, 0);
        for(int i=1; i<=n; i++)
            sums[i] += sums[i-1] + a[i-1]%2;
        
        int out = 0;
        for(int i=0; i<n; i++){
            auto it = equal_range(sums.begin(), sums.end(), sums[i]+k);
            out+= it.second - it.first;
        }
        
        return out;

    }
};
// @lc code=end
int main(){
    Solution s;
    vector<vvi> arrs = {{{1,1,2,1,1},{3}},
                {{2,4,6},{1}},
                {{2,2,2,1,2,2,1,2,2,2},{2}}};

    for(auto a: arrs){
        cout<<s.numberOfSubarrays(a[0], a[1][0])<<endl;
    }

   
}