/*
 * @lc app=leetcode id=501 lang=cpp
 *
 * [501] Find Mode in Binary Search Tree
 *
 * https://leetcode.com/problems/find-mode-in-binary-search-tree/description/
 *
 * algorithms
 * Easy (41.10%)
 * Likes:    743
 * Dislikes: 286
 * Total Accepted:    74.4K
 * Total Submissions: 180.9K
 * Testcase Example:  '[1,null,2,2]'
 *
 * Given a binary search tree (BST) with duplicates, find all the mode(s) (the
 * most frequently occurred element) in the given BST.
 * 
 * Assume a BST is defined as follows:
 * 
 * 
 * The left subtree of a node contains only nodes with keys less than or equal
 * to the node's key.
 * The right subtree of a node contains only nodes with keys greater than or
 * equal to the node's key.
 * Both the left and right subtrees must also be binary search trees.
 * 
 * 
 * 
 * 
 * For example:
 * Given BST [1,null,2,2],
 * 
 * 
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  2
 * 
 * 
 * 
 * 
 * return [2].
 * 
 * Note: If a tree has more than one mode, you can return them in any order.
 * 
 * Follow up: Could you do that without using any extra space? (Assume that the
 * implicit stack space incurred due to recursion does not count).
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

// in BST inorder traversal, gives values in correct order
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        if(!root) return {};
        if(!root->left && !root->right) return {root->val};

        vector<int> modes;
        int curCount = 0;
        int maxCount = -1;
        int prevVal = root->val;

        stack<TreeNode*> stk;
        TreeNode* cur = root;
        
        int val = cur->val;
        while(stk.size() || cur){
            while(cur){
                stk.push(cur);
                cur = cur->left;
            }

            cur = stk.top(); stk.pop();

            if(prevVal!=cur->val){
                prevVal = cur->val;
                curCount = 0;
            }
            ++curCount;
            if(curCount>maxCount){
                maxCount = curCount;
                modes.clear();
                modes.push_back(cur->val);
            }else if(curCount == maxCount){
                modes.push_back(cur->val);
            }
            
            cur = cur->right;
        }

        return modes;
    }
};
// @lc code=end

int main(){
    Solution sol;
    string s ="[1,null,2,2]";
    // s = "[1,null,2]";
    // s = "[100]";
    // s = "[6,5,7,5,5,6,8,null,null,null,null,6,null,null,null]";
    // s = "[6,null,7,6,8]";
    TreeNode *root = stringToTreeNode(s);
    vi modes = sol.findMode(root); print(modes);
    return 0;
}
