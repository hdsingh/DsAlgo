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
        int maj1 = INT_MAX, maj2 = INT_MAX, cnt1 = 0, cnt2 = 0;
        for(auto num: nums){
            if(num==maj1) ++cnt1;
            else if(num==maj2) ++cnt2;
            else if(cnt1==0){
                maj1 = num;
                cnt1 = 1;
            }else if(cnt2==0){
                maj2 = num;
                cnt2 = 1;
            }else{
                --cnt1;
                --cnt2;
            }
        }
        
        vector<int> out;
        for(auto op: {maj1, maj2}){
            int cnt = 0;
            for(auto num: nums)
                if(num==op)
                    ++cnt;
            if(cnt>nums.size()/3)
                out.push_back(op);
        }
        return out;
    }
};

int main(){
    Solution s;
    vvi tests = {{3,2,3}, {1,1,1,3,3,2,2,2}};
    
    for(vi test: tests){
        print(s.majorityElement(test));
    }
}
