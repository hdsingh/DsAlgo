/*
 * @lc app=leetcode id=235 lang=cpp
 *
 * [235] Lowest Common Ancestor of a Binary Search Tree
 *
 * https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/
 *
 * algorithms
 * Easy (47.98%)
 * Likes:    1642
 * Dislikes: 94
 * Total Accepted:    360.9K
 * Total Submissions: 750.1K
 * Testcase Example:  '[6,2,8,0,4,7,9,null,null,3,5]\n2\n8'
 *
 * Given a binary search tree (BST), find the lowest common ancestor (LCA) of
 * two given nodes in the BST.
 * 
 * According to the definition of LCA on Wikipedia: “The lowest common ancestor
 * is defined between two nodes p and q as the lowest node in T that has both p
 * and q as descendants (where we allow a node to be a descendant of itself).”
 * 
 * Given binary search tree:  root = [6,2,8,0,4,7,9,null,null,3,5]
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
 * Output: 6
 * Explanation: The LCA of nodes 2 and 8 is 6.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
 * Output: 2
 * Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant
 * of itself according to the LCA definition.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * All of the nodes' values will be unique.
 * p and q are different and both values will exist in the BST.
 * 
 * 
 */

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
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define deb(x) cout<<#x<<" "<<x<<endl;
#define deb2(x, y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define deb3(x, y, z) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
template <typename T>void print(T v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<v.size(); i++)cout<<setw(w)<<i<<" ";cout<<endl;}for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(w)<<*i<<" ";cout<<endl;}
#include "Tree.h"

class Solution0 {
    TreeNode *p, *q;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* _p, TreeNode* _q) {
        p = _p; q = _q;
        if(p->val>q->val) swap(p,q);
        return dfs(root);     
    }

    TreeNode* dfs(TreeNode* root){
        if(!root) return root;

        if(root->val==p->val || root->val==q->val) return root;

        TreeNode* left = dfs(root->left);
        TreeNode* right = dfs(root->right);

        if(left && right) return root;
        if(left || right) return left ? left : right;
        return NULL;
    }
};
// Ref: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/discuss/64980/C%2B%2B-Recursive-and-Iterative
class Solution1 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return root;

        // if rootval is greater than both , Lca must be on left side
        if(p->val<root->val && q->val < root->val)
            return lowestCommonAncestor(root->left, p, q);
        
        // root is less than both, must be on right side
        if(p->val>root->val && q->val > root->val)
            return lowestCommonAncestor(root->right, p, q);
        
        return root;
    }
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return root;
        TreeNode* cur = root;

        while(cur){
            if(p->val < cur->val && q->val < cur->val)
                cur = cur->left;
            else if(p->val > cur->val && q->val> cur->val)
                cur = cur->right;
            else break;
        }

        return cur;        
    }
};

// @lc code=end

int main(){
    Solution sol;
    string s; TreeNode *p, *q, *root, *out;
    p = new TreeNode(2); q = new TreeNode(0);
    s = "[6,2,8,0,4,7,9,null,null,3,5]"; 
    root = stringToTreeNode(s); 
    out = sol.lowestCommonAncestor(root, p, q); deb(out->val);
    return 0;
}