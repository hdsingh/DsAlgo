/*
 * @lc app=leetcode id=650 lang=cpp
 *
 * [650] 2 Keys Keyboard
 *
 * https://leetcode.com/problems/2-keys-keyboard/description/
 *
 * algorithms
 * Medium (47.44%)
 * Likes:    778
 * Dislikes: 54
 * Total Accepted:    40.4K
 * Total Submissions: 85.1K
 * Testcase Example:  '3'
 *
 * Initially on a notepad only one character 'A' is present. You can perform
 * two operations on this notepad for each step:
 * 
 * 
 * Copy All: You can copy all the characters present on the notepad (partial
 * copy is not allowed).
 * Paste: You can paste the characters which are copied last time.
 * 
 * 
 * 
 * 
 * Given a number n. You have to get exactly n 'A' on the notepad by performing
 * the minimum number of steps permitted. Output the minimum number of steps to
 * get n 'A'.
 * 
 * Example 1:
 * 
 * 
 * Input: 3
 * Output: 3
 * Explanation:
 * Intitally, we have one character 'A'.
 * In step 1, we use Copy All operation.
 * In step 2, we use Paste operation to get 'AA'.
 * In step 3, we use Paste operation to get 'AAA'.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The n will be in the range [1, 1000].
 * 
 * 
 * 
 * 
 */
#include "cpp.h"
using namespace std;

typedef std::vector<int> vi;
typedef std::vector<vector<int>> vvi;

// @lc code=start
// Recursive
// it takes 2 step to double a num and 3 steps to triple
class Solution {
public:
    int minSteps(int n) {
        if(n==1) return 0;
        
        for(int i=2; i<n; i++)
            if(n%i==0) return i+minSteps(n/i);

        return n;       
    }
};

// @lc code=end

int main(){
    Solution s;
    for(int i=0; i<10; i++){
        cout<<i<<" : "<<s.minSteps(i)<<endl;
    }
}
