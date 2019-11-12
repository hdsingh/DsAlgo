/*
 * @lc app=leetcode id=264 lang=cpp
 *
 * [264] Ugly Number II
 *
 * https://leetcode.com/problems/ugly-number-ii/description/
 *
 * algorithms
 * Medium (37.91%)
 * Likes:    1189
 * Dislikes: 74
 * Total Accepted:    121K
 * Total Submissions: 319.1K
 * Testcase Example:  '10'
 *
 * Write a program to find the n-th ugly number.
 * 
 * Ugly numbers are positive numbers whose prime factors only include 2, 3,
 * 5. 
 * 
 * Example:
 * 
 * 
 * Input: n = 10
 * Output: 12
 * Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10
 * ugly numbers.
 * 
 * Note:  
 * 
 * 
 * 1 is typically treated as an ugly number.
 * n does not exceed 1690.
 * 
 */
#include "cpp.h"
using namespace std;

typedef std::vector<int> vi;
typedef std::vector<vector<int>> vvi;

// @lc code=start
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> results(1,1);
        int i=0; int j=0; int k=0;
        

        while(results.size()<n){
            results.push_back(min(min(results[i]*2, results[j]*3), results[k]*5));
            int last = results.back();
            if(last == results[i]*2) i++;
            if(last == results[j]*3) j++;
            if(last == results[k]*5) k++;
        }

        return results.back();
    }
};
// @lc code=end
int main(){
    Solution sol;
    cout<<sol.nthUglyNumber(1)<<endl;
    cout<<sol.nthUglyNumber(2)<<endl;
    cout<<sol.nthUglyNumber(3)<<endl;

    cout<<sol.nthUglyNumber(1690)<<endl;

}