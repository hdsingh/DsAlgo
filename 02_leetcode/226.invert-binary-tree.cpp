/*
 * @lc app=leetcode id=226 lang=cpp
 *
 * [226] Invert Binary Tree
 *
 * https://leetcode.com/problems/invert-binary-tree/description/
 *
 * algorithms
 * Easy (59.57%)
 * Likes:    2010
 * Dislikes: 35
 * Total Accepted:    361.9K
 * Total Submissions: 606.9K
 * Testcase Example:  '[4,2,7,1,3,6,9]'
 *
 * Invert a binary tree.
 * 
 * Example:
 * 
 * Input:
 * 
 * 
 * ⁠    4
 * ⁠  /   \
 * ⁠ 2     7
 * ⁠/ \   / \
 * 1   3 6   9
 * 
 * Output:
 * 
 * 
 * ⁠    4
 * ⁠  /   \
 * ⁠ 7     2
 * ⁠/ \   / \
 * 9   6 3   1
 * 
 * Trivia:
 * This problem was inspired by this original tweet by Max Howell:
 * 
 * Google: 90% of our engineers use the software you wrote (Homebrew), but you
 * can’t invert a binary tree on a whiteboard so f*** off.
 * 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// #include "cpp.h"
// #include "node.h"
// #include "extra.h"
// using namespace std;
typedef TreeNode node;

class Solution {
public:
    // Recursive
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;

        node* right = invertTree(root->right);
        node* left = invertTree(root->left);

        root->right = left;
        root->left = right;

        return root;
    }

    // Iterative
    TreeNode* invertTreeIter(TreeNode* root) {
        if (!root) return root;
        queue<node*> q;
        
        q.push(root);

        while(!q.empty()){
            node* cur = q.front(); q.pop();
            
            // Switch nodes
            node* temp = cur->left;
            cur->left = cur->right;
            cur->right = temp;

            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
        }
        return root;
    }
};

// int main() {
//     string line;
//     while (getline(cin, line)) {
//         TreeNode* root = stringToTreeNode(line);
        
//         TreeNode* ret = Solution().invertTree(root);

//         string out = treeNodeToString(ret);

//         cout<<out<<endl;
        
//     }
//     return 0;
// }
