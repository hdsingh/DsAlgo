/*
 * @lc app=leetcode id=1302 lang=cpp
 *
 * [1302] Deepest Leaves Sum
 *
 * https://leetcode.com/problems/deepest-leaves-sum/description/
 *
 * algorithms
 * Medium (83.52%)
 * Likes:    216
 * Dislikes: 20
 * Total Accepted:    20K
 * Total Submissions: 24.1K
 * Testcase Example:  '[1,2,3,4,5,null,6,7,null,null,null,null,8]'
 *
 * Given a binary tree, return the sum of values of its deepest leaves.
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
 * Output: 15
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

// Level Order traversal
class Solution0 {
public:
    int deepestLeavesSum(TreeNode* root) {
        int sum = 0;
        int mxdepth = maxDepth(root);
        TreeNode* cur = root;
        queue<TreeNode*> q;
        q.push(cur);

        int curDepth = 0;
        while(q.size()){
            ++curDepth;
            int breadth = q.size();
            for(int i=0; i< breadth; ++i){
                cur = q.front(); q.pop();

                if (curDepth==mxdepth){
                    sum+=cur->val;
                }

                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
        }
        return sum;
    }

    int maxDepth(TreeNode* root){
        if(!root) return 0;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return 1 + max(left, right);
    }
};

// without finding depth, just reset sum and sum the nodes at each level
class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        int sum = 0;
        TreeNode* cur = root;
        queue<TreeNode*> q;
        q.push(cur);

        while(q.size()){
            sum = 0;
            int breadth = q.size();
            for(int i=0; i< breadth; ++i){
                cur = q.front(); q.pop();

                sum+=cur->val;
                
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
        }
        return sum;
    }
};
// @lc code=end

int main(){
    Solution sol;
    
    return 0;
}
