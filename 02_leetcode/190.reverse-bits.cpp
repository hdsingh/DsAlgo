/*
 * @lc app=leetcode id=190 lang=cpp
 *
 * [190] Reverse Bits
 *
 * https://leetcode.com/problems/reverse-bits/description/
 *
 * algorithms
 * Easy (32.86%)
 * Likes:    669
 * Dislikes: 239
 * Total Accepted:    204.8K
 * Total Submissions: 612.8K
 * Testcase Example:  '00000010100101000001111010011100'
 *
 * Reverse bits of a given 32 bits unsigned integer.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: 00000010100101000001111010011100
 * Output: 00111001011110000010100101000000
 * Explanation: The input binary string 00000010100101000001111010011100
 * represents the unsigned integer 43261596, so return 964176192 which its
 * binary representation is 00111001011110000010100101000000.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 11111111111111111111111111111101
 * Output: 10111111111111111111111111111111
 * Explanation: The input binary string 11111111111111111111111111111101
 * represents the unsigned integer 4294967293, so return 3221225471 which its
 * binary representation is 10111111111111111111111111111111.
 * 
 * 
 * 
 * Note:
 * 
 * 
 * Note that in some languages such as Java, there is no unsigned integer type.
 * In this case, both input and output will be given as signed integer type and
 * should not affect your implementation, as the internal binary representation
 * of the integer is the same whether it is signed or unsigned.
 * In Java, the compiler represents the signed integers using 2's complement
 * notation. Therefore, in Example 2 above the input represents the signed
 * integer -3 and the output represents the signed integer -1073741825.
 * 
 * 
 * 
 * 
 * Follow up:
 * 
 * If this function is called many times, how would you optimize it?
 * 
 */
#include "cpp.h"
#include "extra.h"
using namespace std;

// App1: take out as 0000..0,
// Start iteration from the 0th index of num.
// if n[i] is 1 the set the corresponding reversed index bit(31-i).

// @lc code=start
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t out = 0;
        for(int i=0; i<32; i++, n>>=1){
            out<<=1;
            out |= n&1;
        }
        return out;
    }

    uint32_t reverseBits1(uint32_t n) {
        uint32_t out = 0; // all 32 0's initially
        for(int i=0; i<32; i++){
            if(n & 1<<i)   // if bit at ith pos is  set then
                out |= 1<<(31-i); // set the bit at rev pos(31-i) by ORing
                // setbit(out, 31-i);
        }
        return (out);
    }

    void setbit(uint32_t &n, int pos){
        n = n|1<<pos;
    }
};
// @lc code=end

int main(){
    Solution s;

    cout<<setprecision(32)<<s.reverseBits(43261596)<<endl;
    cout<<setprecision(32)<<s.reverseBits(4294967293)<<endl;


    // int a = 0b00000010100101000001111010011100;
    // int b = 0b00111001011110000010100101000000;
    // cout<<setprecision(32)<<a<<endl;
    // cout<<setprecision(32)<<b<<endl;
    // cout<<setprecision(32)<<a+b<<endl;
    

    // cout<<a+b;
    // for(int i=0;i<32; i++){
        // cout<<"0";
    // }
    return 0;
}