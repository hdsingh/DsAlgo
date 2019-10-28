/*
 * @lc app=leetcode id=260 lang=cpp
 *
 * [260] Single Number III
 *
 * https://leetcode.com/problems/single-number-iii/description/
 *
 * algorithms
 * Medium (58.13%)
 * Likes:    1035
 * Dislikes: 83
 * Total Accepted:    118.2K
 * Total Submissions: 201.9K
 * Testcase Example:  '[1,2,1,3,2,5]'
 *
 * Given an array of numbers nums, in which exactly two elements appear only
 * once and all the other elements appear exactly twice. Find the two elements
 * that appear only once.
 * 
 * Example:
 * 
 * 
 * Input:  [1,2,1,3,2,5]
 * Output: [3,5]
 * 
 * Note:
 * 
 * 
 * The order of the result is not important. So in the above example, [5, 3] is
 * also correct.
 * Your algorithm should run in linear runtime complexity. Could you implement
 * it using only constant space complexity?
 * 
 */
#include "cpp.h"
#include "extra.h"
using namespace std;

// @lc code=start

// Xor all the elements => 'xor' (includes both a,b)(all others have been zeroed)(c^c=0)
// now since a and b are different there would be atleast one bit set in the 'xor'.
// So lets find a and b by using any set bit at pos p in the 'xor'.
// xor1 = xor of all elements having 1 at pos p
// xor2 = xor of allthe elements having 0 at p
// xor1 = a, xor2 = b; (Since all other elements appearing twice will be zerod out)
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x = 0; // Stores xor of all elements
        for(int num: nums)
            x^=num;
        
        cout<<x<<endl;
        // Find the bit which is 1 or the pos of right most set bit
        // int pos_set = 0; // rightmost pos which is set in xor
        // while(!(x&1)){
        //     pos_set++;
        //     x>>=1;
        // }
        int pos_set = ffs(x)-1;

        int a(0), b(0);

        for(int num: nums){
            if(num & (1<<pos_set)) a^=num; // if bit at pos is set then perform xor with a
            else b^=num;
        }

        return {a, b};
    }

    vector<int> singleNumber1(vector<int>& nums) {
        vi out;
        map<int, int> count;
        for(int num: nums)
            count[num]++;
        
        for(auto e: count)
            if(e.second==1)
                out.push_back(e.first);
        
        return out;
    }
};
// @lc code=end
int main(){
    Solution s;
    vvi tests = {{1,2,1,3,2,5}};
    for(vi test: tests){
        print(s.singleNumber(test));
    }
}
