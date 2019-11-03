/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
 *
 * https://leetcode.com/problems/diameter-of-binary-tree/description/
 *
 * algorithms
 * Easy (47.66%)
 * Likes:    1793
 * Dislikes: 111
 * Total Accepted:    171.9K
 * Total Submissions: 360.6K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * 
 * Given a binary tree, you need to compute the length of the diameter of the
 * tree. The diameter of a binary tree is the length of the longest path
 * between any two nodes in a tree. This path may or may not pass through the
 * root.
 * 
 * 
 * 
 * Example:
 * Given a binary tree 
 * 
 * ⁠         1
 * ⁠        / \
 * ⁠       2   3
 * ⁠      / \     
 * ⁠     4   5    
 * 
 * 
 * 
 * Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].
 * 
 * 
 * Note:
 * The length of path between two nodes is represented by the number of edges
 * between them.
 * 
 */
#include "cpp.h"
#include "node.h"
using namespace std;

typedef std::vector<int> vi;
typedef std::vector<vector<int>> vvi;

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL) 
        return 0; 
        int ans = INT_MIN; // This will store the final answer 
        findDiameter(root, ans); 
        return ans; 
    }

    int findDiameter(TreeNode *root, int &dia){
        if(!root) return 0;

        int left = findDiameter(root->left, dia);
        int right = findDiameter(root->right, dia);

        dia = max(dia, left+right);

        return 1+max(left,right);
    }

};
// @lc code=end
int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);;
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->left = new TreeNode(7);


    Solution s;
    cout<<s.diameterOfBinaryTree(root);

}
