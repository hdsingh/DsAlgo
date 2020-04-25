/*
 * @lc app=leetcode id=326 lang=cpp
 *
 * [326] Power of Three
 *
 * https://leetcode.com/problems/power-of-three/description/
 *
 * algorithms
 * Easy (41.84%)
 * Likes:    340
 * Dislikes: 1201
 * Total Accepted:    210K
 * Total Submissions: 501.5K
 * Testcase Example:  '27'
 *
 * Given an integer, write a function to determine if it is a power of three.
 * 
 * Example 1:
 * 
 * 
 * Input: 27
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 0
 * Output: false
 * 
 * Example 3:
 * 
 * 
 * Input: 9
 * Output: true
 * 
 * Example 4:
 * 
 * 
 * Input: 45
 * Output: false
 * 
 * Follow up:
 * Could you do it without using any loop / recursion?
 */
#include "cpp.h"
#include "extra.h"
using namespace std;

// @lc code=start
class Solution {
public:
    bool isPowerOfThree(int n) {
        // int max_pow3 = pow(3, 19);
        // return n>0 && max_pow3%n==0;
        return n>0 && 1162261467%n==0;
    }

    bool isPowerOfThree1(int n) {
        if(n>1) while(n%3==0) n/=3;
        return n==1;
    }
};
// @lc code=end

unsigned long bin(int n){
    return stoul(bitset<32>(n).to_string());
};

string bins(int n){
    return bitset<32>(n).to_string();
}

int main(){
    Solution s;
    vi tests = {27, 0, 9, 45, -3, 337};
    for(int test: tests){
        cout<<s.isPowerOfThree(test)<<endl;
    }
    cout<<std::setprecision(32)<<pow(3, 19)<<endl;
    // cout<<INT_MAX;
}