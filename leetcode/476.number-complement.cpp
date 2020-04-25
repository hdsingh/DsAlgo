/*
 * @lc app=leetcode id=476 lang=cpp
 *
 * [476] Number Complement
 *
 * https://leetcode.com/problems/number-complement/description/
 *
 * algorithms
 * Easy (62.70%)
 * Likes:    601
 * Dislikes: 76
 * Total Accepted:    117K
 * Total Submissions: 186.3K
 * Testcase Example:  '5'
 *
 * Given a positive integer, output its complement number. The complement
 * strategy is to flip the bits of its binary representation.
 * 
 * Note:
 * 
 * The given integer is guaranteed to fit within the range of a 32-bit signed
 * integer.
 * You could assume no leading zero bit in the integer’s binary
 * representation.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: 5
 * Output: 2
 * Explanation: The binary representation of 5 is 101 (no leading zero bits),
 * and its complement is 010. So you need to output 2.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: 1
 * Output: 0
 * Explanation: The binary representation of 1 is 1 (no leading zero bits), and
 * its complement is 0. So you need to output 0.
 * 
 * 
 */
#include "cpp.h"
#include "extra.h"
using namespace std;

// @lc code=start
class Solution {
public:
    int findComplement(int num) {
        int out = 0;
        int times = log2(num)+1;
        
        for(int i=0; i<times; i++){
            int mask = 1<<i;
            num^=mask;
        }
        return num;
    }
};
// @lc code=end
int main(){
    Solution s;
    vi tests = {5,1};
    for(int test: tests){
        cout<<s.findComplement(test)<<endl;
    }
}
