/*
 * @lc app=leetcode id=897 lang=cpp
 *
 * [897] Increasing Order Search Tree
 *
 * https://leetcode.com/problems/increasing-order-search-tree/description/
 *
 * algorithms
 * Easy (67.35%)
 * Likes:    480
 * Dislikes: 430
 * Total Accepted:    54.2K
 * Total Submissions: 80.3K
 * Testcase Example:  '[5,3,6,2,4,null,8,1,null,null,null,7,9]'
 *
 * Given a binary search tree, rearrange the tree in in-order so that the
 * leftmost node in the tree is now the root of the tree, and every node has no
 * left child and only 1 right child.
 * 
 * 
 * Example 1:
 * Input: [5,3,6,2,4,null,8,1,null,null,null,7,9]
 * 
 * ⁠      5
 * ⁠     / \
 * ⁠   3    6
 * ⁠  / \    \
 * ⁠ 2   4    8
 * /        / \ 
 * 1        7   9
 * 
 * Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]
 * 
 * ⁠1
 * \
 * 2
 * \
 * 3
 * \
 * 4
 * \
 * 5
 * \
 * 6
 * \
 * 7
 * \
 * 8
 * \
 * ⁠                9  
 * 
 * Note:
 * 
 * 
 * The number of nodes in the given tree will be between 1 and 100.
 * Each node will have a unique integer value from 0 to 1000.
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
template <typename T>void print(T v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<v.size(); i++)cout<<setw(w)<<i<<" ";cout<<endl;}for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(w)<<*i<<" ";cout<<endl;}
#include "Tree.h"

class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        if(!root) return root;
        stack<TreeNode*> stk;
        TreeNode* dummy = new TreeNode(0);
        TreeNode* out = dummy;
        TreeNode* cur = root;

        while(cur || !stk.empty()){
            while(cur){
                stk.push(cur);
                cur = cur->left;
            }

            cur = stk.top();
            stk.pop();

            // deb(cur->val);
            out->right = cur;
            out = out->right;
            out->left = NULL;

            cur = cur->right;
        }

        return dummy->right;

    }
};
// @lc code=end

int main(){
    Solution sol; string s; TreeNode* root;
    s = "[5,3,6,2,4,null,8,1,null,null,null,7,9]";
    root = stringToTreeNode(s);
    root = sol.increasingBST(root);
    s = treeNodeToString(root); deb(s);
    return 0;
}
