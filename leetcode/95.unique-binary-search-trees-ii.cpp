/*
 * @lc app=leetcode id=95 lang=cpp
 *
 * [95] Unique Binary Search Trees II
 *
 * https://leetcode.com/problems/unique-binary-search-trees-ii/description/
 *
 * algorithms
 * Medium (36.94%)
 * Likes:    1544
 * Dislikes: 129
 * Total Accepted:    157.5K
 * Total Submissions: 421.2K
 * Testcase Example:  '3'
 *
 * Given an integer n, generate all structurally unique BST's (binary search
 * trees) that store values 1 ... n.
 * 
 * Example:
 * 
 * 
 * Input: 3
 * Output:
 * [
 * [1,null,3,2],
 * [3,2,null,1],
 * [3,1,null,null,2],
 * [2,1,3],
 * [1,null,2,null,3]
 * ]
 * Explanation:
 * The above output corresponds to the 5 unique BST's shown below:
 * 
 * ⁠  1         3     3      2      1
 * ⁠   \       /     /      / \      \
 * ⁠    3     2     1      1   3      2
 * ⁠   /     /       \                 \
 * ⁠  2     1         2                 3
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
class Solution {
    vector<vector<TreeNode*>> dp;
public:
    vector<TreeNode*> generateTrees(int n) {
        if(!n) return {};
        dp.resize(n+1);
        dp[0] = {NULL};
        dp[1] = {new TreeNode(1)};
        
        for(int i=2; i<=n; ++i){
            for(int center = 1; center<=i; ++center){
                int left = center-1;
                int right = i - center;
                for(auto lnode: dp[left]){
                    for(auto rnode: clone_and_inc(dp[right], center)){
                        TreeNode* root = new TreeNode(center);
                        root->left = lnode;
                        root->right = rnode;
                        dp[i].push_back(root);
                    }
                }
            }
        }
        
        return dp[n];
    }
    
    vector<TreeNode*> clone_and_inc(vector<TreeNode*> nodes, int val){
        vector<TreeNode*> out;
        for(auto node: nodes){
            TreeNode* cloned = clone(node, val);
            out.push_back(cloned);            
        }
        return out;
    }
    
    TreeNode* clone(TreeNode* root, int val){
        if(!root) return NULL;
        TreeNode* newNode = new TreeNode(root->val + val);
        newNode->left = clone(root->left, val);
        newNode->right = clone(root->right, val);
        return newNode;
    }

};

int main(){
    Solution sol;
    vi a = {0,3,5};
    for(auto x: a){
        vector<TreeNode*> trees = sol.generateTrees(x);
        deb(x);
        for(auto root: trees){
            string s = treeNodeToString(root);
            deb(s);
        }
        cout<<endl;
    }
    return 0;
}
