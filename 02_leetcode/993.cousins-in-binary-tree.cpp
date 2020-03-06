/*
 * @lc app=leetcode id=993 lang=cpp
 *
 * [993] Cousins in Binary Tree
 *
 * https://leetcode.com/problems/cousins-in-binary-tree/description/
 *
 * algorithms
 * Easy (52.16%)
 * Likes:    444
 * Dislikes: 29
 * Total Accepted:    40.6K
 * Total Submissions: 77.9K
 * Testcase Example:  '[1,2,3,4]\n4\n3'
 *
 * In a binary tree, the root node is at depth 0, and children of each depth k
 * node are at depth k+1.
 * 
 * Two nodes of a binary tree are cousins if they have the same depth, but have
 * different parents.
 * 
 * We are given the root of a binary tree with unique values, and the values x
 * and y of two different nodes in the tree.
 * 
 * Return true if and only if the nodes corresponding to the values x and y are
 * cousins.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * Input: root = [1,2,3,4], x = 4, y = 3
 * Output: false
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
 * Output: true
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * 
 * 
 * Input: root = [1,2,3,null,4], x = 2, y = 3
 * Output: false
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The number of nodes in the tree will be between 2 and 100.
 * Each node has a unique integer value from 1 to 100.
 * 
 * 
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
template <typename T>void print(T v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<v.size(); i++)cout<<setw(w)<<i<<" ";cout<<endl;}for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(w)<<*i<<" ";cout<<endl;}
#include "Tree.h"

// Level order
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        TreeNode* cur = root;
        queue<TreeNode*> q;
        q.push(cur);

        while(q.size()){
            int prev_par = -1;
            int breadth = q.size();
            for(int i=0; i<breadth; ++i){
                cur = q.front(); q.pop();

                if(cur->left){
                    q.push(cur->left);
                    if(cur->left->val==x || cur->left->val==y){
                        if(prev_par==-1)
                            prev_par = cur->val;
                        else if(prev_par!=cur->val)
                            return true;
                    }

                }

                if(cur->right){
                    q.push(cur->right);
                    if(cur->right->val==x || cur->right->val==y){
                        if(prev_par==-1)
                            prev_par = cur->val;
                        else if(prev_par!=cur->val)
                            return true;
                    }
                }
            }
        }

        return false;    
    }
};
// @lc code=end

int main(){
    Solution sol;
    TreeNode* root; bool out; int x,y; string s;
    s = "[1,2,3,4]"; x = 4; y = 3;
    root = stringToTreeNode(s);out = sol.isCousins(root, x, y); deb(out);

    s = "[1,2,3,null,4,null,5]"; x=5; y =4;
    root = stringToTreeNode(s);out = sol.isCousins(root, x, y); deb(out);
    
    s = "[1,2,3,null,4]"; x = 2, y = 3;
    root = stringToTreeNode(s);out = sol.isCousins(root, x, y); deb(out);

    return 0;
}
