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
    // int nmax = 9;
    bool calculated = false;
    vector<vector<TreeNode*>> trees;
public:
    vector<TreeNode*> generateTrees(int n) {
        if(!n) return {};
        if(!calculated)
            precalc(9);
        return trees[n];
    }

    void precalc(int nmax){
        // int nmax = 9;
        trees.resize(nmax+1);
        trees[0] = {NULL};
        trees[1] = {new TreeNode(1)};
        
        for(int i=2; i<=nmax; ++i){
            for(int centre = 1; centre<=i; ++centre){
                int left = centre - 1;
                int right = i-centre;
                for(auto l: trees[left]){
                    for(auto r: increment_vals(trees[right], centre)){
                        // deb(centre);
                        TreeNode* root = new TreeNode(centre);
                        root->left = l;
                        root->right = r;
                        trees[i].push_back(root);
                    }
                }
            }
        }
        calculated = true;
    }

    vector<TreeNode*> increment_vals(vector<TreeNode*> &_roots, int val){
        vector<TreeNode*> roots;
        for(auto root: _roots){
            TreeNode* cloned = clone(root);
            dfs(cloned, val);
            roots.push_back(cloned);
        }
        return roots;
    }

    void dfs(TreeNode* &root, const int &val){
        if(!root) return;
        root->val+=val;
        dfs(root->left, val);
        dfs(root->right, val);
    }

    TreeNode* clone(TreeNode * root){
        if(!root) return root;
        TreeNode *newRoot = new TreeNode(root->val);
        newRoot->left = clone(root->left);
        newRoot->right = clone(root->right);
        return newRoot;
    }
};
// @lc code=end

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
