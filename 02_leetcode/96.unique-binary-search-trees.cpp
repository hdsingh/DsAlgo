/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 *
 * https://leetcode.com/problems/unique-binary-search-trees/description/
 *
 * algorithms
 * Medium (47.68%)
 * Likes:    2156
 * Dislikes: 84
 * Total Accepted:    228.4K
 * Total Submissions: 473K
 * Testcase Example:  '3'
 *
 * Given n, how many structurally unique BST's (binary search trees) that store
 * values 1 ... n?
 * 
 * Example:
 * 
 * 
 * Input: 3
 * Output: 5
 * Explanation:
 * Given n = 3, there are a total of 5 unique BST's:
 * 
 * ⁠  1         3     3      2      1
 * ⁠   \       /     /      / \      \
 * ⁠    3     2     1      1   3      2
 * ⁠   /     /       \                 \
 * ⁠  2     1         2                 3
 * 
 * 
 */
#include "cpp.h"
using namespace std;

typedef std::vector<int> vi;
typedef std::vector<vector<int>> vvi;

// @lc code=start
class Solution {
    vi dp;
public:
    // Compact version
    int numTrees(int n) {
        vi G(n+1, 0);
        G[0] = G[1] = 1;
    
        for(int i=2; i<=n; i++) 
            for(int j=1; j<=i; j++)
                G[i] += G[j-1] * G[i-j];
        
        return G[n];
    }

    int f(int c, int n){
        int l = c-1;
        int r = n-c;
        if(!l) return dp[r];
        if(!r) return dp[l];
        return dp[l] * dp[r];
    }

    int trees(int n){
        int sum(0);
        for(int i=1; i<=n; i++)
            sum+=f(i, n);

        return sum;
    }

    int numTrees1(int n) {
        dp.resize(n+1);
        dp[0] = 0;
        dp[1] = 1;
        for(int i=2; i<=n; i++)
            dp[i] = trees(i);

        return dp[n];
    }
};
// @lc code=end

int main(){
    Solution s;
    for(int i=0; i<10; i++)
        cout<<s.numTrees(i)<<endl;
}