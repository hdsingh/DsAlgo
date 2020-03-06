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
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        
        TreeNode* left = invertTree(root->right);
        TreeNode* right = invertTree(root->left);
        
        root->left = left;
        root->right = right;
        return root;
    }
};

// It does not matters in which order nodes in a level are visited,
// only what matters is inversion of l and r
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        TreeNode *cur = root;
        queue<TreeNode*> q;
        q.push(cur);

        while(q.size()){
            cur = q.front(); q.pop();
            swap(cur->left, cur->right);
            
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
        }

        return root;
    }
};
// @lc code=end

int main(){
    Solution sol;
    string s = "[4,2,7,1,3,6,9,10,11,12,13]";
    TreeNode* root = stringToTreeNode(s);
    root = sol.invertTree(root);
    s = treeNodeToString(root);
    deb(s);
    return 0;
}
