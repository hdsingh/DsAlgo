/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 *
 * https://leetcode.com/problems/perfect-squares/description/
 *
 * algorithms
 * Medium (43.43%)
 * Likes:    1839
 * Dislikes: 156
 * Total Accepted:    220.8K
 * Total Submissions: 508.3K
 * Testcase Example:  '12'
 *
 * Given a positive integer n, find the least number of perfect square numbers
 * (for example, 1, 4, 9, 16, ...) which sum to n.
 * 
 * Example 1:
 * 
 * 
 * Input: n = 12
 * Output: 3 
 * Explanation: 12 = 4 + 4 + 4.
 * 
 * Example 2:
 * 
 * 
 * Input: n = 13
 * Output: 2
 * Explanation: 13 = 4 + 9.
 */
#include "cpp.h"
using namespace std;

typedef std::vector<int> vi;
typedef std::vector<vector<int>> vvi;

// @lc code=start
// Basic approach
class Solution {
public:
    int numSquares(int n) {
        if(n<=0) return 0;
        if(isPerfectSquare(n)) return 1;
        static vi squares(n+1, INT_MAX);
        squares[0] = 0;
        
        if(squares[n]!=INT_MAX) return squares[n];

        for(int i=1; i<n+1; i++){
                int sq = sqrt(i);
                int min_sqrs = INT_MAX;
                for(int j=sq; j>0; j--){
                    min_sqrs  = min(1 + squares[i - j*j], min_sqrs);
                }
                squares[i] = min_sqrs;
        }

        return squares[n];
    }

    bool isPerfectSquare(const int & num){
        float sq = sqrt(num);
        return (sq - floor(sq)==0);
    }
};
// @lc code=end
int main(){
    Solution sol;
    cout<<sol.numSquares(13)<<endl;//3
    cout<<sol.numSquares(12)<<endl;//2
    // deb(sol.isPerfectSquare(0));  
}
