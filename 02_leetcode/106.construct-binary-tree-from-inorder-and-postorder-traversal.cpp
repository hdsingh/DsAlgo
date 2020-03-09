/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (43.20%)
 * Likes:    1284
 * Dislikes: 28
 * Total Accepted:    193.6K
 * Total Submissions: 447.8K
 * Testcase Example:  '[9,3,15,20,7]\n[9,15,7,20,3]'
 *
 * Given inorder and postorder traversal of a tree, construct the binary tree.
 * 
 * Note:
 * You may assume that duplicates do not exist in the tree.
 * 
 * For example, given
 * 
 * 
 * inorder = [9,3,15,20,7]
 * postorder = [9,15,7,20,3]
 * 
 * Return the following binary tree:
 * 
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
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
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
template <typename T>void print(T v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<v.size(); i++)cout<<setw(w)<<i<<" ";cout<<endl;}for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(w)<<*i<<" ";cout<<endl;}
template <typename T>void print_vv(T v){if(v.size()==0) {cout<<"Empty"<<endl; return;} int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}
#include "Tree.h"

// Fact: 
// Inorder: [[....left....][root][....right...]]
// PostOrd: [[....left...][....right....][root]]
class Solution {
    int n;
    map<int,int> inPos; // record index of 
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        inPos.clear();
        n = inorder.size();
        for(int i=0; i<n;++i)
            inPos[inorder[i]] = i;
        return build(n-1, 0, n-1, inorder, postorder);
    }

    TreeNode* build(int postEnd, int inStart, int inEnd, vi &inorder, vi & postorder){
        if(inStart>inEnd || postEnd<0)
            return NULL;
        TreeNode* root = new TreeNode(postorder[postEnd]);
        int rootInPos = inPos[root->val];

        root->right = build(postEnd-1, rootInPos+1, inEnd, inorder, postorder);
        root->left = build(postEnd - (inEnd - rootInPos + 1), inStart, rootInPos-1, inorder, postorder);
                                     // len of right
        return root;
    }
};
// @lc code=end

int main(){
    Solution sol;
    vi inorder, postorder;
    inorder = { 9,3,15,20,7 }; postorder = { 9,15,7,20,3 };
    TreeNode* root = sol.buildTree(inorder, postorder);
    string out = treeNodeToString(root); deb(out);
    return 0;
}
