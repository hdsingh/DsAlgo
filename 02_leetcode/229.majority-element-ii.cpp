/*
 * @lc app=leetcode id=229 lang=cpp
 *
 * [229] Majority Element II
 *
 * https://leetcode.com/problems/majority-element-ii/description/
 *
 * algorithms
 * Medium (33.06%)
 * Likes:    1079
 * Dislikes: 125
 * Total Accepted:    116K
 * Total Submissions: 347.3K
 * Testcase Example:  '[3,2,3]'
 *
 * Given an integer array of size n, find all elements that appear more than ⌊
 * n/3 ⌋ times.
 * 
 * Note: The algorithm should run in linear time and in O(1) space.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,2,3]
 * Output: [3]
 * 
 * Example 2:
 * 
 * 
 * Input: [1,1,1,3,3,2,2,2]
 * Output: [1,2]
 * 
 */
#include "cpp.h"
#include "extra.h"
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> count;
        vector<int> out;

        for(int num: nums){
            if (++count[num] > n/3){
                out.push_back(num);
                count[num] = INT_MIN;
            }            
        }

        return out;
    }
    
    vector<int> majorityElement1(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> count;
        vector<int> out;

        for(int num: nums){
            count[num]++;
        }

        for(auto e: count)
            if(e.second > n/3)
                out.push_back(e.first);
        
        return out;
    }
};
// @lc code=end
int main(){
    Solution s;
    vvi tests = {{3,2,3}, {1,1,1,3,3,2,2,2}};
    
    for(vi test: tests){
        print(s.majorityElement(test));
    }
}
