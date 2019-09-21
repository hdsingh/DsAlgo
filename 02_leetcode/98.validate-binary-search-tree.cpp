/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
 *
 * https://leetcode.com/problems/validate-binary-search-tree/description/
 *
 * algorithms
 * Medium (26.26%)
 * Likes:    2370
 * Dislikes: 350
 * Total Accepted:    469.9K
 * Total Submissions: 1.8M
 * Testcase Example:  '[2,1,3]'
 *
 * Given a binary tree, determine if it is a valid binary search tree (BST).
 * 
 * Assume a BST is defined as follows:
 * 
 * 
 * The left subtree of a node contains only nodes with keys less than the
 * node's key.
 * The right subtree of a node contains only nodes with keys greater than the
 * node's key.
 * Both the left and right subtrees must also be binary search trees.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * ⁠   2
 * ⁠  / \
 * ⁠ 1   3
 * 
 * Input: [2,1,3]
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * ⁠   5
 * ⁠  / \
 * ⁠ 1   4
 * / \
 * 3   6
 * 
 * Input: [5,1,4,null,null,3,6]
 * Output: false
 * Explanation: The root node's value is 5 but its right child's value is 4.
 * 
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
typedef vector<int> vi;
typedef TreeNode node;


class Solution {
public:
    bool isValidBST(TreeNode* root){
        if(!root) return true;
        stack<node*> s;
        stack<long> min_vs;
        stack<long> max_vs;
        node* cur; long cur_min, cur_max;

        s.push(root); min_vs.push(LONG_MIN); max_vs.push(LONG_MAX);

        while(!s.empty()){
            // pop
            cur = s.top(); s.pop();
            cur_min = min_vs.top(); min_vs.pop();
            cur_max = max_vs.top(); max_vs.pop();

            if (cur->val <= cur_min || cur->val >= cur_max) return false;
            
            // push right, left
            if(cur->right){
                s.push(cur->right);
                min_vs.push(cur->val);
                max_vs.push(cur_max);
            }
            
            if(cur->left){
                s.push(cur->left);
                min_vs.push(cur_min);
                max_vs.push(cur->val);
            }
            
        }

        return true;

    }

    // Preorder (each element in )
    bool isValidBSTPreorder(TreeNode* root){
        if(!root) return true;

        stack<node*> s;
        node* cur = root;
        long last = LONG_MIN;

        while(!s.empty() || cur){
            while(cur){
                s.push(cur);
                cur = cur->left;
            }

            cur = s.top();
            s.pop();
            // cout<<cur->val<<" ";
            if (cur->val<=last) return false;
            last = cur->val;
            cur = cur->right;
        }
        return true;
    }

    // Recursive
    bool isValidBST1(TreeNode* root) {
        return isBST(root, LONG_MIN, LONG_MAX);
    }

    bool isBST(node* root, long min, long max){
        if(!root) return true; // Empty tree is a BST

        bool ls = isBST(root->left, min, root->val);
        bool rs = isBST(root->right, root->val, max);

        return (ls && rs && root->val>min && root->val<max);

    }
};


// int main() {
//     string line;
//     while (getline(cin, line)) {
//         TreeNode* root = stringToTreeNode(line);
        
//         bool ret = Solution().isValidBST(root);

//         string out = boolToString(ret);
//         cout << out << endl;
//     }
//     return 0;
// }
