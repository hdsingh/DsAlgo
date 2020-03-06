/*
 * @lc app=leetcode id=538 lang=cpp
 *
 * [538] Convert BST to Greater Tree
 *
 * https://leetcode.com/problems/convert-bst-to-greater-tree/description/
 *
 * algorithms
 * Easy (53.54%)
 * Likes:    1653
 * Dislikes: 108
 * Total Accepted:    106K
 * Total Submissions: 197.5K
 * Testcase Example:  '[5,2,13]'
 *
 * Given a Binary Search Tree (BST), convert it to a Greater Tree such that
 * every key of the original BST is changed to the original key plus sum of all
 * keys greater than the original key in BST.
 * 
 * Example:
 * 
 * 
 * Input: The root of a Binary Search Tree like this:
 * ⁠             5
 * ⁠           /   \
 * ⁠          2     13
 * 
 * Output: The root of a Greater Tree like this:
 * ⁠            18
 * ⁠           /   \
 * ⁠         20     13
 * 
 * 
 * Note: This question is the same as 1038:
 * https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/
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

// Reverse inorder
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        if(!root) return root;
        TreeNode* cur = root;
        stack<TreeNode*> stk;

        int sum = 0;
    
        while(cur || !stk.empty()){
            while(cur){
                stk.push(cur);
                cur = cur->right;
            }

            cur = stk.top(); stk.pop(); 

            // deb(cur->val);
            cur->val+=sum;
            sum = cur->val;
            
            cur = cur->left;
        }
        return root;
    }
};
// @lc code=end

int main(){
    Solution sol;
    vi a = {1,2,3,4,5,6,7};
    a = {2,5,13};
    node* root = sortedArrayToBST(a);
    root = sol.convertBST(root);
    string s = treeNodeToString(root);
    deb(s);
    
    return 0;
}

// @lc code=end

