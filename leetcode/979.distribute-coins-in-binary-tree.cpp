/*
 * @lc app=leetcode id=979 lang=cpp
 *
 * [979] Distribute Coins in Binary Tree
 *
 * https://leetcode.com/problems/distribute-coins-in-binary-tree/description/
 *
 * algorithms
 * Medium (68.02%)
 * Likes:    1075
 * Dislikes: 36
 * Total Accepted:    29.8K
 * Total Submissions: 43.8K
 * Testcase Example:  '[3,0,0]'
 *
 * Given the root of a binary tree with N nodes, each node in the tree has
 * node.val coins, and there are N coins total.
 * 
 * In one move, we may choose two adjacent nodes and move one coin from one
 * node to another.  (The move may be from parent to child, or from child to
 * parent.)
 * 
 * Return the number of moves required to make every node have exactly one
 * coin.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: [3,0,0]
 * Output: 2
 * Explanation: From the root of the tree, we move one coin to its left child,
 * and one coin to its right child.
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input: [0,3,0]
 * Output: 3
 * Explanation: From the left child of the root, we move two coins to the root
 * [taking two moves].  Then, we move one coin from the root of the tree to the
 * right child.
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * 
 * 
 * Input: [1,0,2]
 * Output: 2
 * 
 * 
 * 
 * Example 4:
 * 
 * 
 * 
 * 
 * Input: [1,0,0,null,3]
 * Output: 4
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1<= N <= 100
 * 0 <= node.val <= N
 * 
 * 
 * 
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

// Post order
// Think of each moves as excess arrows that could be thrown by 
// each node and required by a node, right side can borrow from  root,
// left can borrow directly form centre, instead of borrowing from the other side.
// Hence excess = root->val - 1
// scare  = 1 - root->val, ( -ve excess)
// moves = abs(excess) + left + right
// Ref: https://leetcode.com/problems/distribute-coins-in-binary-tree/discuss/221939/C%2B%2B-with-picture-post-order-traversal
class Solution {
    int res = 0;
public:
    int distributeCoins(TreeNode* root) {
        res = 0;
        dfs(root);
        return res;
    }

    int dfs(TreeNode* root){
        if(!root) return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);

        res+=abs(left) + abs(right);
        return root->val - 1 + left + right;
        
    }
};
// @lc code=end

int main(){
    Solution sol;
    vs ss = {
        "[3,0,0]",
        "[0,3,0]",
        "[1,0,2]",
        "[1,0,0,null,3]",
    };
    for(auto s: ss){
        int out = sol.distributeCoins(stringToTreeNode(s)); deb(out);
    }
    return 0;
}
