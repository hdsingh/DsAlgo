/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 *
 * https://leetcode.com/problems/majority-element/description/
 *
 * algorithms
 * Easy (54.07%)
 * Likes:    2070
 * Dislikes: 181
 * Total Accepted:    453.1K
 * Total Submissions: 829.7K
 * Testcase Example:  '[3,2,3]'
 *
 * Given an array of size n, find the majority element. The majority element is
 * the element that appears more than ⌊ n/2 ⌋ times.
 * 
 * You may assume that the array is non-empty and the majority element always
 * exist in the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,2,3]
 * Output: 3
 * 
 * Example 2:
 * 
 * 
 * Input: [2,2,1,1,1,2,2]
 * Output: 2
 * 
 * 
 */
#include "cpp.h"
#include "extra.h"
using namespace std;

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        nth_element(nums.begin(), nums.begin()+n/2, nums.end());
        return nums[n/2];
    }

    // Bit manipulation
    int majorityElement2(vector<int>& nums) {
        int majority = 0;

        for(unsigned int i=0,  mask = 1; i<32; i++, mask<<=1){
            
            int count = 0;
            for(int num: nums)
                if(num & mask)
                    count++;

            if(count>nums.size()/2)
                majority |= mask;
        }

        return majority;

    }

    static bool comp(pair<int, int> a, pair <int, int> b){
        return a.second < b.second;
    }

    int majorityElement1(vector<int>& nums) {
        unordered_map<int, int> count;
        for(int num: nums)
            count[num]++;

        auto i =  *max_element(count.begin(), count.end(), comp);
        return i.first;

    }
};
// @lc code=end

int main(){
    Solution s;
    vvi tests = {{3,2,3},{2,2,1,1,1,2,2}};
    for(auto test: tests)
        cout<<s.majorityElement(test)<<endl;
        
    return 0;
}