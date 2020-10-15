/*
 * @lc app=leetcode id=654 lang=cpp
 *
 * [654] Maximum Binary Tree
 *
 * https://leetcode.com/problems/maximum-binary-tree/description/
 *
 * algorithms
 * Medium (78.27%)
 * Likes:    1484
 * Dislikes: 203
 * Total Accepted:    115.6K
 * Total Submissions: 147.5K
 * Testcase Example:  '[3,2,1,6,0,5]'
 *
 * 
 * Given an integer array with no duplicates. A maximum tree building on this
 * array is defined as follow:
 * 
 * The root is the maximum number in the array. 
 * The left subtree is the maximum tree constructed from left part subarray
 * divided by the maximum number.
 * The right subtree is the maximum tree constructed from right part subarray
 * divided by the maximum number. 
 * 
 * 
 * 
 * 
 * Construct the maximum tree by the given array and output the root node of
 * this tree.
 * 
 * 
 * Example 1:
 * 
 * Input: [3,2,1,6,0,5]
 * Output: return the tree root node representing the following tree:
 * 
 * ⁠     6
 * ⁠   /   \
 * ⁠  3     5
 * ⁠   \    / 
 * ⁠    2  0   
 * ⁠      \
 * ⁠       1
 * 
 * 
 * 
 * Note:
 * 
 * The size of the given array will be in the range [1,1000].
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
    vector<int> a;
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& _a) {
        this->a = _a;
        int n = a.size(); int l(0), r(n-1);
        return create(l, r);
    }

    TreeNode* create(int l, int r){
        if(l>r) return NULL;
        if(l==r) return new TreeNode(a[l]);

        int mid = findMaxIndex(l,r);
        TreeNode* root = new TreeNode(a[mid]);
        root->left = create(l, mid-1);
        root->right = create(mid + 1, r);
        return root;
    }

    int findMaxIndex(int l, int r){
        int maxVal = a[l];
        int maxIx = l; // maxindex
        for(int i=l; i<=r; ++i)
            if(a[i]>maxVal){
                maxVal = a[i];
                maxIx = i;
            }
        return maxIx;
    }
};

// Ref: https://leetcode.com/problems/maximum-binary-tree/discuss/106146/C%2B%2B-O(N)-solution
// Using monotone stack (max stack)
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        vector<TreeNode*> stk;
        for(int i=0; i<(int)nums.size(); ++i){
            TreeNode* cur = new TreeNode(nums[i]);

            // Put smaller elements on cur's left
            while(stk.size() && stk.back()->val < cur->val){
                cur->left = stk.back();
                stk.pop_back();
            }

            // if a greater exists, put cur on its right
            if(!stk.empty())
                stk.back()->right = cur;
            stk.push_back(cur);
        }
        return stk.front(); // max
    }
};


class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* root = new TreeNode(1e9);
        stack<TreeNode*> stk;
        stk.push(root);
        
        for(auto num: nums){
            TreeNode* now = new TreeNode(num);
            if(num>stk.top()->val){
                TreeNode* prev = NULL;
                while(num>=stk.top()->val){ 
                    prev = stk.top();
                    stk.pop();
                }
                stk.top()->right = now;
                now->left = prev;
            }else{
                stk.top()->right = now;
            }
            stk.push(now);
        }
        
        return root->right;
        
    }
};

// @lc code=end

int main(){
    Solution sol;
    vi a = { 3,2};
    TreeNode* root = sol.constructMaximumBinaryTree(a);
    string out = treeNodeToString(root); deb(out);
    return 0;
}
