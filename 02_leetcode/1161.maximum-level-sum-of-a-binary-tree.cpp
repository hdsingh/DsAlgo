/*
 * @lc app=leetcode id=1161 lang=cpp
 *
 * [1161] Maximum Level Sum of a Binary Tree
 *
 * https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/description/
 *
 * algorithms
 * Medium (72.02%)
 * Likes:    123
 * Dislikes: 9
 * Total Accepted:    15.5K
 * Total Submissions: 21.9K
 * Testcase Example:  '[1,7,0,7,-8,null,null]'
 *
 * Given the root of a binary tree, the level of its root is 1, the level of
 * its children is 2, and so on.
 * 
 * Return the smallest level X such that the sum of all the values of nodes at
 * level X is maximal.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: [1,7,0,7,-8,null,null]
 * Output: 2
 * Explanation: 
 * Level 1 sum = 1.
 * Level 2 sum = 7 + 0 = 7.
 * Level 3 sum = 7 + -8 = -1.
 * So we return the level with the maximum sum which is level 2.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The number of nodes in the given tree is between 1 and 10^4.
 * -10^5 <= node.val <= 10^5
 * 
 * 
 */

// @lc code=start

//  * Definition for a binary tree node.
#include "cpp.h"
#include "extra.h"
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    // BFS
    int maxLevelSum(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> q({root});
        int level = 1;
        int max_sum = 0;
        int max_level = 1;

        while(!q.empty()){
            int count = q.size();
            int level_sum = 0;
            while(count--){
                TreeNode *node = q.front(); q.pop();
                level_sum+=node->val;

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            level++;
            if(level_sum>max_sum) max_level = level;

            max_sum=max(max_sum, level_sum);
            
        }
        return max_level;
    }

    int maxLevelSumDFS(TreeNode* root) {
        vector<int> level_sum(100, 0);
        dfs(root, 1, level_sum);

        return max_element(level_sum.begin(), level_sum.end()) - level_sum.begin();
    }

    void dfs(TreeNode* root, int level, vector<int> &level_sum){
        level_sum[level]+=root->val;

        if(root->left) dfs(root->left, level+1, level_sum);
        if(root->right) dfs(root->right, level+1, level_sum);
    }
};
// @lc code=end
int main(){

}
