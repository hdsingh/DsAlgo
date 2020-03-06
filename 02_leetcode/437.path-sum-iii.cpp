/*
 * @lc app=leetcode id=437 lang=cpp
 *
 * [437] Path Sum III
 *
 * https://leetcode.com/problems/path-sum-iii/description/
 *
 * algorithms
 * Easy (44.83%)
 * Likes:    2774
 * Dislikes: 207
 * Total Accepted:    153.7K
 * Total Submissions: 342K
 * Testcase Example:  '[10,5,-3,3,2,null,11,3,-2,null,1]\n8'
 *
 * You are given a binary tree in which each node contains an integer value.
 * 
 * Find the number of paths that sum to a given value.
 * 
 * The path does not need to start or end at the root or a leaf, but it must go
 * downwards
 * (traveling only from parent nodes to child nodes).
 * 
 * The tree has no more than 1,000 nodes and the values are in the range
 * -1,000,000 to 1,000,000.
 * 
 * Example:
 * 
 * root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8
 * 
 * ⁠     10
 * ⁠    /  \
 * ⁠   5   -3
 * ⁠  / \    \
 * ⁠ 3   2   11
 * ⁠/ \   \
 * 3  -2   1
 * 
 * Return 3. The paths that sum to 8 are:
 * 
 * 1.  5 -> 3
 * 2.  5 -> 2 -> 1
 * 3. -3 -> 11
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
    int sum;
    int count;
public:
    int pathSum(TreeNode* root, int _sum) {
        sum = _sum;
        count = 0;
        unordered_map<int, int> seen;
        int pre = 0;
        seen[0] = 1;
        dfs(root, seen, pre);
        return count;
    }

    void dfs(TreeNode* root, unordered_map<int, int> &seen, int &pre){
        if(!root) return;

        pre +=root->val;
        if(seen.find(pre-sum)!=seen.end())
            count+=seen[pre-sum];
        seen[pre]++;

        if(root->left) dfs(root->left, seen, pre);
        if(root->right) dfs(root->right,seen, pre);

        seen[pre]--;
        pre-=root->val;
    }
};
// @lc code=end

int main(){
    Solution sol; string s; int sum, out; TreeNode* root;
    s = "[10,5,-3,3,2,null,11,3,-2,null,1]", sum = 8;
    root = stringToTreeNode(s);
    out = sol.pathSum(root, sum); deb(out);

    return 0;
}
