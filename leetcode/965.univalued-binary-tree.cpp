/*
 * @lc app=leetcode id=965 lang=cpp
 *
 * [965] Univalued Binary Tree
 *
 * https://leetcode.com/problems/univalued-binary-tree/description/
 *
 * algorithms
 * Easy (67.24%)
 * Likes:    353
 * Dislikes: 39
 * Total Accepted:    70.7K
 * Total Submissions: 105K
 * Testcase Example:  '[1,1,1,1,1,null,1]'
 *
 * A binary tree is univalued if every node in the tree has the same value.
 * 
 * Return true if and only if the given tree is univalued.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [1,1,1,1,1,null,1]
 * Output: true
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [2,2,2,5,2]
 * Output: false
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The number of nodes in the given tree will be in the range [1, 100].
 * Each node's value will be an integer in the range [0, 99].
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

// recursion
class Solution0 {
    int val;
public:
    bool isUnivalTree(TreeNode* root) {
        if(!root) return true;
        val = root->val;
        return dfs(root->left) && dfs(root->right);
    }

    bool dfs(TreeNode* root){
        if(!root) return true;
        return root->val==val && dfs(root->left) && dfs(root->right);
    }
};

// Preorder
class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        if(!root) return true;
        int val = root->val;
        stack<TreeNode*> stk;
        stk.push(root);

        while(!stk.empty()){
            TreeNode* cur = stk.top(); stk.pop();
            if(cur->val!=val) return false;

            if(cur->right) stk.push(cur->right);
            if(cur->left) stk.push(cur->left);
        }

        return true;
    }
};

// @lc code=end

int main(){
    Solution sol; TreeNode * root; vector<string> ss; bool out;
    ss = {
        "[1,1,1,1,1,null,1]",
        "[2,2,2,5,2]",
    };
    for(auto s: ss){
        root = stringToTreeNode(s);
        out = sol.isUnivalTree(root); deb(out);
    }
    return 0;
}