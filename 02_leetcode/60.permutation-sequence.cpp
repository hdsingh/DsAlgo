/*
 * @lc app=leetcode id=60 lang=cpp
 *
 * [60] Permutation Sequence
 *
 * https://leetcode.com/problems/permutation-sequence/description/
 *
 * algorithms
 * Medium (34.07%)
 * Likes:    1009
 * Dislikes: 267
 * Total Accepted:    152.9K
 * Total Submissions: 445.6K
 * Testcase Example:  '3\n3'
 *
 * The set [1,2,3,...,n] contains a total of n! unique permutations.
 * 
 * By listing and labeling all of the permutations in order, we get the
 * following sequence for n = 3:
 * 
 * 
 * "123"
 * "132"
 * "213"
 * "231"
 * "312"
 * "321"
 * 
 * 
 * Given n and k, return the k^th permutation sequence.
 * 
 * Note:
 * 
 * 
 * Given n will be between 1 and 9 inclusive.
 * Given k will be between 1 and n! inclusive.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 3, k = 3
 * Output: "213"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 4, k = 9
 * Output: "2314"
 * 
 * 
 */
#include "cpp.h"
#include "extra.h"
using namespace std;

// @lc code=start
class Solution {
public:
    string getPermutation(int n, int k) {
        string out;
        vector<int> fact(n+1);
        fact[0] = 1;
        for(int i=1; i<=n; i++){
            fact[i] = i*fact[i-1];
        }

        vector<int> nums;
        for(int i=1; i<=n; i++){
            nums.push_back(i);
        }
        k--;

        for(int i=1; i<=n; i++){
            int index = k/fact[n-i];
            out+=to_string(nums[index]);
            nums.erase(nums.begin()+index);
            k = k-index*fact[n-i];
        }

        return out;        
    }
    
            
};
// @lc code=end
int main(){
    Solution s;
    cout<<s.getPermutation(2,2);

}