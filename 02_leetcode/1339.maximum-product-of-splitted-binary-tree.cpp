/*
 * @lc app=leetcode id=1339 lang=cpp
 *
 * [1339] Maximum Product of Splitted Binary Tree
 *
 * https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/description/
 *
 * algorithms
 * Medium (35.32%)
 * Likes:    136
 * Dislikes: 15
 * Total Accepted:    7.8K
 * Total Submissions: 22.1K
 * Testcase Example:  '[1,2,3,4,5,6]'
 *
 * Given a binary tree root. Split the binary tree into two subtrees by
 * removing 1 edge such that the product of the sums of the subtrees are
 * maximized.
 * 
 * Since the answer may be too large, return it modulo 10^9 + 7.
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: root = [1,2,3,4,5,6]
 * Output: 110
 * Explanation: Remove the red edge and get 2 binary trees with sum 11 and 10.
 * Their product is 110 (11*10)
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input: root = [1,null,2,3,4,null,null,5,6]
 * Output: 90
 * Explanation:  Remove the red edge and get 2 binary trees with sum 15 and
 * 6.Their product is 90 (15*6)
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: root = [2,3,9,10,7,8,6,5,4,11,1]
 * Output: 1025
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: root = [1,1]
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * Each tree has at most 50000 nodes and at least 2 nodes.
 * Each node's value is between [1, 10000].
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

typedef long long ll;
const int mod = 1e9+7;

// disconnect either the left node, or the right node, 
// or the entire subtree
class Solution0 {
    ll maxProd;
    ll totSum;
public:
    int maxProduct(TreeNode* root) {
        maxProd = 0; totSum = 0;
        findSum(root);
        // deb(totSum);

        dfs(root);
        
        return maxProd%mod;
    }

    int dfs(TreeNode* root){
        if(!root) return 0;
        if(!root->left && !root->right) return root->val;
        

        ll left = dfs(root->left);
        ll right = dfs(root->right);
        ll sum = left + right + root->val;

        maxProd = max({maxProd, left * (totSum-left), right * (totSum-right), sum * (totSum-sum) });
        // deb(maxProd);
        return sum;

    }

    void findSum(TreeNode* root){
        if(!root) return;
        totSum+=root->val;
        findSum(root->left);
        findSum(root->right);
    }
};

class Solution {
    ll maxProd, sum;
public:
    int maxProduct(TreeNode* root) {
        // to calculate sum
        sum = 0;
        sum = dfs(root);
        // deb(sum);

        // to calcluate maxProd after correct sum is available
        maxProd = 0;
        dfs(root);

        return maxProd%mod;
    }

    ll dfs(TreeNode* root){
        if(!root) return 0;
        ll left = dfs(root->left);
        ll right = dfs(root->right);
        ll sub = root->val + left + right;

        maxProd = max(maxProd, sub*(sum-sub));

        return sub;
    }
};
// @lc code=end

int main(){
    Solution sol;
    vs trees = {
        "[1,2,3,4,5,6]",
        "[1,null,2,3,4,null,null,5,6]",
        "[2,3,9,10,7,8,6,5,4,11,1]",
        "[1,1]",
        "[]"
    };
    for(auto tree: trees){
        TreeNode* root = stringToTreeNode(tree);
        int prod = sol.maxProduct(root);
        deb(prod);
    }
    return 0;
}
