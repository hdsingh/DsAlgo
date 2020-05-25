/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
 *
 * https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/
 *
 * algorithms
 * Medium (53.25%)
 * Likes:    1371
 * Dislikes: 43
 * Total Accepted:    254.1K
 * Total Submissions: 476.8K
 * Testcase Example:  '[3,1,4,null,2]\n1'
 *
 * Given a binary search tree, write a function kthSmallest to find the kth
 * smallest element in it.
 * 
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
 * 
 * Example 1:
 * 
 * 
 * Input: root = [3,1,4,null,2], k = 1
 * ⁠  3
 * ⁠ / \
 * ⁠1   4
 * ⁠ \
 * 2
 * Output: 1
 * 
 * Example 2:
 * 
 * 
 * Input: root = [5,3,6,2,4,null,null,1], k = 3
 * ⁠      5
 * ⁠     / \
 * ⁠    3   6
 * ⁠   / \
 * ⁠  2   4
 * ⁠ /
 * ⁠1
 * Output: 3
 * 
 * 
 * Follow up:
 * What if the BST is modified (insert/delete operations) often and you need to
 * find the kth smallest frequently? How would you optimize the kthSmallest
 * routine?
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

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int i(0);
        int res;
        // do inorder traversal
        stack<TreeNode*> s;
        TreeNode* cur = root;

        while(!s.empty()|| cur){
            while(cur){
                s.push(cur);
                cur =cur->left;
            }
            if(!cur){
                cur = s.top(); s.pop();
                res = cur->val;
                i++;
                if(i==k) break;
                cur = cur->right;
            }
        }
        return res;
    }
};


// inorder tiem traversal
class Solution {
    int t,ans,k;
public:
    int kthSmallest(TreeNode* root, int K) {
        t = 0, ans = 0, k = K;
        dfs(root);
        return ans;
    }

    void dfs(TreeNode* root){
        if(!root) return;
        dfs(root->left);
        ++t;
        if(ans==0 && t==k){
            ans = root->val;
            return;
        }
        dfs(root->right);
    }
};
