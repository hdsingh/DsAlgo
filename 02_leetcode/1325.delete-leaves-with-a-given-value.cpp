/*
 * @lc app=leetcode id=1325 lang=cpp
 *
 * [1325] Delete Leaves With a Given Value
 *
 * https://leetcode.com/problems/delete-leaves-with-a-given-value/description/
 *
 * algorithms
 * Medium (73.13%)
 * Likes:    182
 * Dislikes: 4
 * Total Accepted:    11.7K
 * Total Submissions: 16K
 * Testcase Example:  '[1,2,3,2,null,2,4]\n2'
 *
 * Given a binary tree root and an integer target, delete all the leaf nodes
 * with value target.
 * 
 * Note that once you delete a leaf node with value target, if it's parent node
 * becomes a leaf node and has the value target, it should also be deleted (you
 * need to continue doing that until you can't).
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: root = [1,2,3,2,null,2,4], target = 2
 * Output: [1,null,3,null,4]
 * Explanation: Leaf nodes in green with value (target = 2) are removed
 * (Picture in left). 
 * After removing, new nodes become leaf nodes with value (target = 2) (Picture
 * in center).
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input: root = [1,3,3,3,2], target = 3
 * Output: [1,3,null,null,2]
 * 
 * 
 * Example 3:
 * 
 * 
 * 
 * 
 * Input: root = [1,2,null,2,null,2], target = 2
 * Output: [1]
 * Explanation: Leaf nodes in green with value (target = 2) are removed at each
 * step.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: root = [1,1,1], target = 1
 * Output: []
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: root = [1,2,3], target = 1
 * Output: [1,2,3]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= target <= 1000
 * Each tree has at most 3000 nodes.
 * Each node's value is between [1, 1000].
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

class Solution {
    int T;
public:
    TreeNode* removeLeafNodes(TreeNode* root, int _target) {
        T = _target;
        removeLeaf(root);
        return root;
    }

    void removeLeaf(TreeNode* &root){
        if(!root) return;
        removeLeaf(root->left);
        removeLeaf(root->right);

        if(!root->left && !root->right && root->val==T)
            root = NULL;
    }
};
// @lc code=end

int main(){
    Solution sol;
    vector<pair<string, int>> rt = {
        {"[1,2,3,2,null,2,4]", 2},
        {"[1,3,3,3,2]", 3},
        {"[1,2,null,2,null,2]",2},
        {"[1,1,1]",1},
        {"[1,2,3]",1},
    };
    for(auto p : rt){
        TreeNode* root = sol.removeLeafNodes(stringToTreeNode(p.first), p.second);
        string out = treeNodeToString(root); deb(out);
    }
    return 0;
}
