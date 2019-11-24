/*
 * @lc app=leetcode id=1269 lang=cpp
 *
 * [1269] Number of Ways to Stay in the Same Place After Some Steps
 *
 * https://leetcode.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps/description/
 *
 * algorithms
 * Hard (35.83%)
 * Likes:    42
 * Dislikes: 3
 * Total Accepted:    1.8K
 * Total Submissions: 5.1K
 * Testcase Example:  '3\n2'
 *
 * You have a pointer at index 0 in an array of size arrLen. At each step, you
 * can move 1 position to the left, 1 position to the right in the array or
 * stay in the same place  (The pointer should not be placed outside the array
 * at any time).
 * 
 * Given two integers steps and arrLen, return the number of ways such that
 * your pointer still at index 0 after exactly steps steps.
 * 
 * Since the answer may be too large, return it modulo 10^9 + 7.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: steps = 3, arrLen = 2
 * Output: 4
 * Explanation: There are 4 differents ways to stay at index 0 after 3 steps.
 * Right, Left, Stay
 * Stay, Right, Left
 * Right, Stay, Left
 * Stay, Stay, Stay
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: steps = 2, arrLen = 4
 * Output: 2
 * Explanation: There are 2 differents ways to stay at index 0 after 2 steps
 * Right, Left
 * Stay, Stay
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: steps = 4, arrLen = 2
 * Output: 8
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= steps <= 500
 * 1 <= arrLen <= 10^6
 * 
 * 
 */
#include "cpp.h"
using namespace std;
template <typename T>
void print_vv1(T v, bool same_line=true){
    for(auto i= 0; i<v.size(); i++){
        cout<<"{";
        for(auto j = 0; j!=v[i].size(); j++){
            cout<<setw(10)<<v[i][j]<<",";
        }
        cout<<"},";
        if(same_line) cout<<endl;
    }
    cout<<endl;
}


// @lc code=start
typedef std::vector<int> vi;
typedef std::vector<vector<int>> vvi;
const int big = 1e9+7;


class Solution {
public:
    int numWays(int steps, int arrLen) {
        int index_sz = min(steps/2+1, arrLen);
        vvi memo(steps+1, vi(index_sz, -1));

        int out = findWays(0, steps, arrLen, memo);
        // print_vv1(memo);
        return out;
    }

    long findWays(int index, int steps, int &arrLen, vvi &memo){
        if(index==0 && steps==0) return 1;
        if(index<0 || index>=arrLen || steps<0 || index>steps) return 0;

        if(memo[steps][index]!=-1) return memo[steps][index];
        long stay = findWays(index,steps-1, arrLen, memo);
        long left = findWays(index-1,steps-1, arrLen, memo);
        long right = findWays(index+1,steps-1, arrLen, memo);
        long out = (stay+left+right)%big;
        return memo[steps][index] = out;
    }
};
// @lc code=end
int main(){
    Solution sol;
    cout<<sol.numWays(10,10)<<endl;
    cout<<sol.numWays(2,4)<<endl;
    cout<<sol.numWays(4,2)<<endl;
    cout<<sol.numWays(4,3)<<endl;
    cout<<sol.numWays(7,21)<<endl;
    cout<<sol.numWays(500,969997)<<endl;
}
