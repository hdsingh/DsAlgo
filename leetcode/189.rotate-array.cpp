/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
 *
 * https://leetcode.com/problems/rotate-array/description/
 *
 * algorithms
 * Easy (31.40%)
 * Likes:    1701
 * Dislikes: 666
 * Total Accepted:    354.5K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,2,3,4,5,6,7]\n3'
 *
 * Given an array, rotate the array to the right by k steps, where k is
 * non-negative.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3,4,5,6,7] and k = 3
 * Output: [5,6,7,1,2,3,4]
 * Explanation:
 * rotate 1 steps to the right: [7,1,2,3,4,5,6]
 * rotate 2 steps to the right: [6,7,1,2,3,4,5]
 * rotate 3 steps to the right: [5,6,7,1,2,3,4]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [-1,-100,3,99] and k = 2
 * Output: [3,99,-1,-100]
 * Explanation: 
 * rotate 1 steps to the right: [99,-1,-100,3]
 * rotate 2 steps to the right: [3,99,-1,-100]
 * 
 * 
 * Note:
 * 
 * 
 * Try to come up as many solutions as you can, there are at least 3 different
 * ways to solve this problem.
 * Could you do it in-place with O(1) extra space?
 * 
 */
#include "cpp.h"
#include "extra.h"
using namespace std;

// @lc code=start
class Solution {
public:
    // using reverse
    void rotate(vector<int>& nums, int k){
        k = k%nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());


    }
    // Using Cyclic Replacements
    void rotate2(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==1) return;
        if(k%n==0) return;
        int times = n;

        for(int start=0; times>0; start++){
            int i = start;
            int prev = nums[start];
            do{
                int n_i = (i+k)%n;
                int temp = nums[n_i];
                nums[n_i] = prev;
                prev = temp;
                i = n_i;
            }while(times-- && i!=start);
        }
    }

    void rotate1(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==1) return;
        if(k%n==0) return;

        queue<int> q;
        k = k%n;
        for(int i=n-k; i!=n; i++){
            q.push(nums[i]);
        }

        for(int i=n-1; i>=k; i--){
            nums[i] = nums[i-k];
            // print(nums);
        }

        for(int i=0; i<k; i++){
            nums[i] = q.front(); q.pop();
        }
        
    }
};
// @lc code=end
int main(){
    Solution s;
    vi nums; int k;
    nums = {1,2,3}; k=2;

    s.rotate(nums, k);

    print(nums);

}
