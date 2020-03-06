/*
 * @lc app=leetcode id=112 lang=cpp
 *
 * [112] Path Sum
 *
 * https://leetcode.com/problems/path-sum/description/
 *
 * algorithms
 * Easy (39.83%)
 * Likes:    1452
 * Dislikes: 429
 * Total Accepted:    413.4K
 * Total Submissions: 1M
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,null,1]\n22'
 *
 * Given a binary tree and a sum, determine if the tree has a root-to-leaf path
 * such that adding up all the values along the path equals the given sum.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * 
 * Given the below binary tree and sum = 22,
 * 
 * 
 * ⁠     5
 * ⁠    / \
 * ⁠   4   8
 * ⁠  /   / \
 * ⁠ 11  13  4
 * ⁠/  \      \
 * 7    2      1
 * 
 * 
 * return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
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

class Solution {
    int sum;
    bool found;
public:
    bool hasPathSum(TreeNode* root, int _sum) {
       sum = _sum;
       found = false;
       if(!root && !sum) return true;
       if(!root) return false;
       dfs(root, 0);
       return found;
    }

    void dfs(TreeNode* root, int cursum){
        if(!root->left && !root->right){
            if(cursum+root->val==sum)
                found = true;
            return;
        }

        cursum+=root->val;
        if(root->left) dfs(root->left, cursum);
        if(root->right) dfs(root->right, cursum);
    }
};

// @lc code=end

int main(){
    Solution sol;
    string s = "[1,0,1,1,2,0,-1,0,1,-1,0,-1,0,1,0]"; int sum =2;
    TreeNode* root = stringToTreeNode(s);
    bool out = sol.hasPathSum(root, sum); deb(out);
    return 0;
}
