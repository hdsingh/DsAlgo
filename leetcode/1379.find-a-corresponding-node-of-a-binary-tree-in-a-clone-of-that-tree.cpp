/*
 * @lc app=leetcode id=1379 lang=cpp
 *
 * [1379] Find a Corresponding Node of a Binary Tree in a Clone of That Tree
 *
 * https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/description/
 *
 * algorithms
 * Medium (87.50%)
 * Likes:    38
 * Dislikes: 56
 * Total Accepted:    4.4K
 * Total Submissions: 5.1K
 * Testcase Example:  '[7,4,3,null,null,6,19]\n3'
 *
 * Given two binary trees original and cloned and given a reference to a node
 * target in the original tree.
 * 
 * The cloned tree is a copy of the original tree.
 * 
 * Return a reference to the same node in the cloned tree.
 * 
 * Note that you are not allowed to change any of the two trees or the target
 * node and the answer must be a reference to a node in the cloned tree.
 * 
 * Follow up: Solve the problem if repeated values on the tree are allowed.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: tree = [7,4,3,null,null,6,19], target = 3
 * Output: 3
 * Explanation: In all examples the original and cloned trees are shown. The
 * target node is a green node from the original tree. The answer is the yellow
 * node from the cloned tree.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: tree = [7], target =  7
 * Output: 7
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: tree = [8,null,6,null,5,null,4,null,3,null,2,null,1], target = 4
 * Output: 4
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: tree = [1,2,3,4,5,6,7,8,9,10], target = 5
 * Output: 5
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: tree = [1,2,null,3], target = 2
 * Output: 2
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [1, 10^4].
 * The values of the nodes of the tree are unique.
 * target node is a node from the original tree and is not null.
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
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
template <typename T>void print(T v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<v.size(); i++)cout<<setw(w)<<i<<" ";cout<<endl;}for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(w)<<*i<<" ";cout<<endl;}
template <typename T>void print_vv(T v){if(v.size()==0) {cout<<"Empty"<<endl; return;} int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}
#include "Tree.h"

class Solution0 {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(!original) return NULL;
        if(original==target) return cloned;
        TreeNode *left(NULL), *right(NULL);
        if(original->left)
            left = getTargetCopy(original->left, cloned->left, target);
        if(left) return left;
        
        if(original->right)
            right = getTargetCopy(original->right, cloned->right, target);
        
        return right;
    }
};


class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(!original) return NULL;
        if(original==target) return cloned;
        TreeNode *left(NULL), *right(NULL);
        return getTargetCopy(original->left, cloned->left, target) ?  : getTargetCopy(original->right, cloned->right, target);       
        
    }
};

// @lc code=end

int main(){
    Solution sol;
    string tree = "[7,4,3,null,null,6,19]";
    TreeNode* root = stringToTreeNode(tree); 
    TreeNode* cloned = stringToTreeNode(tree);

    return 0;
}
