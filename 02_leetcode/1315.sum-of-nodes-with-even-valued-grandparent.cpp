/*
 * @lc app=leetcode id=1315 lang=cpp
 *
 * [1315] Sum of Nodes with Even-Valued Grandparent
 *
 * https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/description/
 *
 * algorithms
 * Medium (83.69%)
 * Likes:    191
 * Dislikes: 8
 * Total Accepted:    13.8K
 * Total Submissions: 16.5K
 * Testcase Example:  '[6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]'
 *
 * Given a binary tree, return the sum of values of nodes with even-valued
 * grandparent.  (A grandparent of a node is the parent of its parent, if it
 * exists.)
 * 
 * If there are no nodes with an even-valued grandparent, return 0.
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
 * Output: 18
 * Explanation: The red nodes are the nodes with even-value grandparent while
 * the blue nodes are the even-value grandparents.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is between 1 and 10^4.
 * The value of nodes is between 1 and 100.
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

// Inorder 
class Solution0 {
    int sum;
public:
    int sumEvenGrandparent(TreeNode* root) {
        sum = 0;
        if(!root) return 0;
        TreeNode* cur = root;
        stack<TreeNode*> stk;

        while(cur || stk.size()){
            while(cur){
                stk.push(cur);
                cur = cur->left;
            }

            cur = stk.top(); stk.pop();
            if(!(cur->val&1))
                add_grandChild(cur);
            cur = cur->right;
        }

        return sum;
    }

    void add_grandChild(TreeNode* cur){
        if(cur->left){
            if(cur->left->left) sum+=cur->left->left->val;
            if(cur->left->right) sum+=cur->left->right->val;
        }
        if(cur->right){
            if(cur->right->left) sum +=cur->right->left->val;
            if(cur->right->right) sum+=cur->right->right->val;
        }
    }
};

// Level Order
class Solution {
    int sum;
public:
    int sumEvenGrandparent(TreeNode* root) {
        if(!root) return 0;
        sum = 0;
        TreeNode* cur = root;
        queue<TreeNode*> q;
        q.push(cur);

        while(q.size()){
            int breadth = q.size();
            for(int i=0; i<breadth; ++i){
                cur = q.front(); q.pop();
                if(!(cur->val&1))
                    add_grandChild(cur);
                
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
        } 
        return sum;
    }

    void add_grandChild(TreeNode* cur){
        if(cur->left){
            if(cur->left->left) sum+=cur->left->left->val;
            if(cur->left->right) sum+=cur->left->right->val;
        }
        if(cur->right){
            if(cur->right->left) sum +=cur->right->left->val;
            if(cur->right->right) sum+=cur->right->right->val;
        }
    }
};
// @lc code=end

int main(){
    Solution sol;
    
    return 0;
}
