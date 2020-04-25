/*
 * @lc app=leetcode id=343 lang=cpp
 *
 * [343] Integer Break
 *
 * https://leetcode.com/problems/integer-break/description/
 *
 * algorithms
 * Medium (48.80%)
 * Likes:    698
 * Dislikes: 193
 * Total Accepted:    90.6K
 * Total Submissions: 185.7K
 * Testcase Example:  '2'
 *
 * Given a positive integer n, break it into the sum of at least two positive
 * integers and maximize the product of those integers. Return the maximum
 * product you can get.
 * 
 * Example 1:
 * 
 * 
 * 
 * Input: 2
 * Output: 1
 * Explanation: 2 = 1 + 1, 1 × 1 = 1.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 10
 * Output: 36
 * Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
 * 
 * Note: You may assume that n is not less than 2 and not larger than 58.
 * 
 * 
 */
#include "cpp.h"
using namespace std;

typedef std::vector<int> vi;
typedef std::vector<vector<int>> vvi;

// @lc code=start

class Solution {
public:
    int integerBreak(int n) {
        if(n<=2) return 1;
        if(n==3) return 2;

        if(n%3==0) 
            return pow(3, n/3);
        else if(n%3==1)
            return 4 * pow(3,n/3 -1);
        else
            return 2 * pow(3,n/3);
        
    }
};

// Represent n = max(3^x, 3^x + 2^y, 3^x+2^1), x>=y;
class Solution1 {
public:
    int integerBreak(int n) {
        if(n<=2) return 1;
        if(n==3) return 2;
        int x;

        if(n%3==0){ // 3^x
            x = n/3;
            return pow(3, x);
        }else if(n%3==1){
            x = n/3 -1;
            return 4 * pow(3,x);
        }else{ //n%3==2
            x = n/3;
            return 2 * pow(3,x);
        }
    }
};
// @lc code=end
int main(){
    Solution sol;
    for(int i=0; i<=58; i++){
        cout<<i<<" : "<<sol.integerBreak(i)<<endl;
    }
}

