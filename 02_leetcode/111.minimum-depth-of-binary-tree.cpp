/*
 * @lc app=leetcode id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
 *
 * https://leetcode.com/problems/minimum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (36.57%)
 * Likes:    1062
 * Dislikes: 596
 * Total Accepted:    370.3K
 * Total Submissions: 1M
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, find its minimum depth.
 * 
 * The minimum depth is the number of nodes along the shortest path from the
 * root node down to the nearest leaf node.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * 
 * Given binary tree [3,9,20,null,null,15,7],
 * 
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * return its minimum depth = 2.
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

class Solution0 {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        return 1 + (left && right ? min(left, right) : max(left, right));
    }
};

// level order with early break, at any level, when a leaf node
// found, return depth
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        TreeNode* cur = root;
        queue<TreeNode*> q;
        q.push(cur);

        int depth =0;
        while(q.size()){
            ++depth;
            int breadth = q.size();
            for(int i=0; i<breadth; ++i){
                cur = q.front(); q.pop();
                
                if(!cur->left && !cur->right)
                    return depth;
                

                if(cur->right) q.push(cur->right);
                if(cur->left) q.push(cur->left);
            }
        }
        return -1; // code will never reach here
    }
};
// @lc code=end

int main(){
    Solution sol;
    string s = "[3,9,20,null,null,15,7]";
    int depth = sol.minDepth(stringToTreeNode(s)); deb(depth);
    return 0;
}
