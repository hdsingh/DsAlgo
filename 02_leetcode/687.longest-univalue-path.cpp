/*
 * @lc app=leetcode id=687 lang=cpp
 *
 * [687] Longest Univalue Path
 *
 * https://leetcode.com/problems/longest-univalue-path/description/
 *
 * algorithms
 * Easy (35.12%)
 * Likes:    1367
 * Dislikes: 373
 * Total Accepted:    79.1K
 * Total Submissions: 224.8K
 * Testcase Example:  '[5,4,5,1,1,5]'
 *
 * Given a binary tree, find the length of the longest path where each node in
 * the path has the same value. This path may or may not pass through the
 * root.
 * 
 * The length of path between two nodes is represented by the number of edges
 * between them.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input:
 * 
 * 
 * ⁠             5
 * ⁠            / \
 * ⁠           4   5
 * ⁠          / \   \
 * ⁠         1   1   5
 * 
 * 
 * Output: 2
 * 
 * 
 * 
 * Example 2:
 * 
 * Input:
 * 
 * 
 * ⁠             1
 * ⁠            / \
 * ⁠           4   5
 * ⁠          / \   \
 * ⁠         4   4   5
 * 
 * 
 * Output: 2
 * 
 * 
 * 
 * Note: The given binary tree has not more than 10000 nodes. The height of the
 * tree is not more than 1000.
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
    int mxlen;
public:
    int longestUnivaluePath(TreeNode* root) {
        mxlen = 0;
        dfs(root);
        return mxlen;
    }

    int dfs(TreeNode* root){
        if(!root) return 0;
        
        int left = dfs(root->left);  
        int right = dfs(root->right);
        int aleft = 0; int aright = 0;
        if(root->left && root->left->val==root->val)
            aleft = left+1;
        if(root->right && root->right->val==root->val)
            aright = right + 1;
        
        mxlen = max(mxlen, aleft + aright);
        return max(aleft, aright);
    }
};
// @lc code=end

int main(){
    Solution sol; string  s; int len;
    s = "[5,4,5,1,1,null,5]";
    len = sol.longestUnivaluePath(stringToTreeNode(s)); deb(len);
    s = "[1,4,5,4,4,null,5]";
    len = sol.longestUnivaluePath(stringToTreeNode(s)); deb(len);
    return 0;
}
