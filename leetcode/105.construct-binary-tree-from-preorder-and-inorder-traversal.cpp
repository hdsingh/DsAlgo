/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (43.08%)
 * Likes:    2084
 * Dislikes: 58
 * Total Accepted:    256.3K
 * Total Submissions: 593.1K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 * 
 * Note:
 * You may assume that duplicates do not exist in the tree.
 * 
 * For example, given
 * 
 * 
 * preorder = [3,9,20,15,7]
 * inorder = [9,3,15,20,7]
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
// Preorder:[[root].[......left.....][....right.....]]
// Inorder: [[.......left......][root][....right....]]
class Solution {
    int n;
    map<int, int> inPos; //record position of inorder indexes
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        n = inorder.size();
        inPos.clear();
        for(int i=0; i<n; ++i)
            inPos[inorder[i]] = i;
        return build(0,0,n-1, preorder, inorder);
    }

    TreeNode* build(int preStart, int inStart, int inEnd, vi &preorder, vi &inorder){
        if(preStart>=n || inStart>inEnd)
            return NULL;
        
        TreeNode* root = new TreeNode(preorder[preStart]);
        int inRootPos = inPos[root->val];

        root->left = build(preStart+1,inStart,inRootPos-1,preorder, inorder);
        root->right = build(preStart + inRootPos - inStart + 1, inRootPos+1,inEnd, preorder, inorder);

        return root;
    }
};
// @lc code=end

int main(){
    Solution sol;
    vi preorder, inorder;
    preorder = { 3,9,20,15,7 }; inorder = { 9,3,15,20,7 };
    TreeNode* root = sol.buildTree(preorder, inorder);
    string out = treeNodeToString(root); deb(out);
    return 0;
}
