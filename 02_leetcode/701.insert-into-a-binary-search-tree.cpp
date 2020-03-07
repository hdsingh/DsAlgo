/*
 * @lc app=leetcode id=701 lang=cpp
 *
 * [701] Insert into a Binary Search Tree
 *
 * https://leetcode.com/problems/insert-into-a-binary-search-tree/description/
 *
 * algorithms
 * Medium (78.70%)
 * Likes:    636
 * Dislikes: 64
 * Total Accepted:    86.1K
 * Total Submissions: 109.1K
 * Testcase Example:  '[4,2,7,1,3]\n5'
 *
 * Given the root node of a binary search tree (BST) and a value to be inserted
 * into the tree, insert the value into the BST. Return the root node of the
 * BST after the insertion. It is guaranteed that the new value does not exist
 * in the original BST.
 * 
 * Note that there may exist multiple valid ways for the insertion, as long as
 * the tree remains a BST after insertion. You can return any of them.
 * 
 * For example, 
 * 
 * 
 * Given the tree:
 * ⁠       4
 * ⁠      / \
 * ⁠     2   7
 * ⁠    / \
 * ⁠   1   3
 * And the value to insert: 5
 * 
 * 
 * You can return this binary search tree:
 * 
 * 
 * ⁠        4
 * ⁠      /   \
 * ⁠     2     7
 * ⁠    / \   /
 * ⁠   1   3 5
 * 
 * 
 * This tree is also valid:
 * 
 * 
 * ⁠        5
 * ⁠      /   \
 * ⁠     2     7
 * ⁠    / \   
 * ⁠   1   3
 * ⁠        \
 * ⁠         4
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

class Solution0 {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return new TreeNode(val);

        TreeNode* pos = findPos(root, val); // pos to insert
        TreeNode* newnode = new TreeNode(val);
        if(val<pos->val)
            pos->left = newnode;
        else 
            pos->right = newnode;
        
        return root;
    }

    TreeNode* findPos(TreeNode* root, int val){
        TreeNode* prev, *cur;
        prev = root; cur = root;
        while(cur){
            prev = cur;
            if(val <  cur->val)
                cur = cur->left;
            else 
                cur = cur->right;
        }

        return prev;
    }
};
// @lc code=end

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node = new TreeNode(val);
        if(!root) return node;

        TreeNode* cur = root;
        while(true){
            if(val < cur->val){
                if(cur->left){
                    cur = cur->left;
                }else {
                    cur->left = node;
                    break;
                }
            }else{
                if(cur->right){
                    cur = cur->right;
                }else{
                    cur->right = node;
                    break;
                }
            }
        }
        return root;
    }
};

int main(){
    Solution sol;
    
    return 0;
}
