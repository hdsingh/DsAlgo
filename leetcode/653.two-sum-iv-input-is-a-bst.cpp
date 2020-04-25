/*
 * @lc app=leetcode id=653 lang=cpp
 *
 * [653] Two Sum IV - Input is a BST
 *
 * https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/
 *
 * algorithms
 * Easy (54.32%)
 * Likes:    1193
 * Dislikes: 128
 * Total Accepted:    121.9K
 * Total Submissions: 224.2K
 * Testcase Example:  '[5,3,6,2,4,null,7]\n9'
 *
 * Given a Binary Search Tree and a target number, return true if there exist
 * two elements in the BST such that their sum is equal to the given target.
 * 
 * Example 1:
 * 
 * 
 * Input: 
 * ⁠   5
 * ⁠  / \
 * ⁠ 3   6
 * ⁠/ \   \
 * 2   4   7
 * 
 * Target = 9
 * 
 * Output: True
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 
 * ⁠   5
 * ⁠  / \
 * ⁠ 3   6
 * ⁠/ \   \
 * 2   4   7
 * 
 * Target = 28
 * 
 * Output: False
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
template <typename T>void print(T v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<v.size(); i++)cout<<setw(w)<<i<<" ";cout<<endl;}for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(w)<<*i<<" ";cout<<endl;}
#include "Tree.h"

// preorder
class Solution {
public:
    bool findTarget(TreeNode* root, int T) {
        unordered_set<int> seen;
        TreeNode* cur = root;
        stack<TreeNode*> stk;
        stk.push(root);

        while(stk.size()){
            cur = stk.top(); stk.pop();
            // deb(cur->val);
            if(seen.find(T - cur->val)!=seen.end())
                return true;
            else 
                seen.insert(cur->val);
            
            if(cur->right) stk.push(cur->right);
            if(cur->left) stk.push(cur->left);
        }


        return false;
    }
};
// @lc code=end

int main(){
    Solution sol;
    string s = "[5,3,6,2,4,null,7]";
    node* root = stringToTreeNode(s);
    bool out = sol.findTarget(root, 2);
    deb(out);
    
    return 0;
}
