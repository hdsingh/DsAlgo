/*
 * @lc app=leetcode id=342 lang=cpp
 *
 * [342] Power of Four
 *
 * https://leetcode.com/problems/power-of-four/description/
 *
 * algorithms
 * Easy (40.69%)
 * Likes:    355
 * Dislikes: 165
 * Total Accepted:    126.5K
 * Total Submissions: 309.8K
 * Testcase Example:  '16'
 *
 * Given an integer (signed 32 bits), write a function to check whether it is a
 * power of 4.
 * 
 * Example 1:
 * 
 * 
 * Input: 16
 * Output: true
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 5
 * Output: false
 * 
 * 
 * Follow up: Could you solve it without loops/recursion?
 */
#include "cpp.h"
#include "extra.h"
using namespace std;

// pow(4,0): 00000000000000001
// pow(4,1): 00000000000000100
// pow(4,2): 00000000000010000
// pow(4,3): 00000000001000000
// pow(4,4): 00000000100000000
// pow(4,5): 00000010000000000
// pow(4,6): 00001000000000000
// pow(4,7): 00100000000000000
// 240:      00000000011110000
// @lc code=start

// Approach: Count the 1's and 0's in num
// To be pow of 4: c1 should be 1 and c0(>0) should be multiple of 2;
class Solution {
public:
    bool isPowerOfFour(int num) {
        return num>0 && (num & (num-1))==0 && (num & 0b01010101010101010101010101010101); 
        // 1. Greater than 0
        // 2. Only one 1 bit in binary notation
        // 3. check 1's bit is at odd position
        //    0x55555555 is a hexametrical number，it is 1010101010101010101010101010101 in binary with a length of 32. 
        //    To make sure the 1 locates in the odd location.
    }


    bool isPowerOfFour2(int  num) {
        if(num>1) while(num%4==0) num/=4;
        return num==1;
    }

    bool isPowerOfFour1(long  num) {
        if(num==1) return true;
        if(num<0) return false;

        int c0(0), c1(0);
        while(num){
            if(num&1) c1++;
            else c0++;
            num>>=1;
        }

        if(c1==1 && c0 && c0%2==0) return true;
        return false;
    }
};
// @lc code=end

int main(){
    Solution s;
    vi tests= {0, 1, 2,4,6,8,16,32,64,240,-240, INT_MIN};
    vi ans =  {0,1,0,1,0,0,1,0,1,0,0,0};
    for(int i=0; i<tests.size(); i++){
        // cout<<test<<endl;
        bool out =  s.isPowerOfFour(tests[i]);
        cout<<out<<": "<<ans[i]<<endl;
        // cout<<endl;
    }
}