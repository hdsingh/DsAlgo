/*
 * @lc app=leetcode id=337 lang=cpp
 *
 * [337] House Robber III
 *
 * https://leetcode.com/problems/house-robber-iii/description/
 *
 * algorithms
 * Medium (49.76%)
 * Likes:    2150
 * Dislikes: 47
 * Total Accepted:    136.3K
 * Total Submissions: 273.9K
 * Testcase Example:  '[3,2,3,null,3,null,1]'
 *
 * The thief has found himself a new place for his thievery again. There is
 * only one entrance to this area, called the "root." Besides the root, each
 * house has one and only one parent house. After a tour, the smart thief
 * realized that "all houses in this place forms a binary tree". It will
 * automatically contact the police if two directly-linked houses were broken
 * into on the same night.
 * 
 * Determine the maximum amount of money the thief can rob tonight without
 * alerting the police.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,2,3,null,3,null,1]
 * 
 * ⁠    3
 * ⁠   / \
 * ⁠  2   3
 * ⁠   \   \ 
 * ⁠    3   1
 * 
 * Output: 7 
 * Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
 * 
 * Example 2:
 * 
 * 
 * Input: [3,4,5,1,3,null,1]
 * 
 * 3
 * ⁠   / \
 * ⁠  4   5
 * ⁠ / \   \ 
 * ⁠1   3   1
 * 
 * Output: 9
 * Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.
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
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
template <typename T>void print(T v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<v.size(); i++)cout<<setw(w)<<i<<" ";cout<<endl;}for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(w)<<*i<<" ";cout<<endl;}
template <typename T>void print_vv(T v){if(v.size()==0) {cout<<"Empty"<<endl; return;} int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}
#include "Tree.h"

typedef vector<int> vi;
const int robbed = 1;

class Solution {
public:
    int rob(TreeNode* root) {
        vi thisNodeis = dfs(root);
        return max(thisNodeis[robbed], thisNodeis[!robbed]); // not robbed, robbed
    }

    vi dfs(TreeNode* root){
        if(!root) return {0,0};
        vi left = dfs(root->left);
        vi right = dfs(root->right);
        vi thisNodeis = {0,0};
    
        // if cur is robbed, this children will definitely NOT be robbed
        thisNodeis[robbed] = left[!robbed] + right[!robbed] + root->val;

        // If cur is not robbed, its children may or may not get robbed
        thisNodeis[!robbed] = max(left[robbed], left[!robbed]) + max(right[robbed], right[!robbed]);

        return thisNodeis;
    }
};
// @lc code=end

int main(){
    Solution sol;
    vs trees = {
        "[3,2,3,null,3,null,1]",
        "[3,4,5,1,3,null,1]",
    };
    for(auto s: trees){
        TreeNode* root = stringToTreeNode(s);
        int out = sol.rob(root); deb(out);
    }
    return 0;
}
