/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 *
 * https://leetcode.com/problems/combinations/description/
 *
 * algorithms
 * Medium (49.69%)
 * Likes:    967
 * Dislikes: 56
 * Total Accepted:    232K
 * Total Submissions: 462.5K
 * Testcase Example:  '4\n2'
 *
 * Given two integers n and k, return all possible combinations of k numbers
 * out of 1 ... n.
 * 
 * Example:
 * 
 * 
 * Input: n = 4, k = 2
 * Output:
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 * 
 * 
 */
#include "cpp.h"
#include "extra.h"
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> sol;
        vector<int> sub;
        comHelper(n, k, 1, sub, sol);
        return sol;
    }

    void comHelper(int n, int level, int begin, vector<int> &sub,vector<vector<int>> &sol){
        // terminating condition
        if(level==0){
            sol.push_back(sub);
            return;
        }
        if(level<0) return;

        // explore + recurse
        for(int i = begin; i<=n; i++){
            sub.push_back(i);
            comHelper(n, level-1, i+1, sub, sol);
            sub.pop_back();
        }
    }
};
// @lc code=end

int main(){
    Solution s;
    auto out = s.combine(4,2);
    print_vv(out);
}