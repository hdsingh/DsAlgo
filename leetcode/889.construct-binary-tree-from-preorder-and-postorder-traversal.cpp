/*
 * @lc app=leetcode id=889 lang=cpp
 *
 * [889] Construct Binary Tree from Preorder and Postorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (64.55%)
 * Likes:    648
 * Dislikes: 42
 * Total Accepted:    30.3K
 * Total Submissions: 46.9K
 * Testcase Example:  '[1,2,4,5,3,6,7]\n[4,5,2,6,7,3,1]'
 *
 * Return any binary tree that matches the given preorder and postorder
 * traversals.
 * 
 * Values in the traversals pre and post are distinct positive integers.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: pre = [1,2,4,5,3,6,7], post = [4,5,2,6,7,3,1]
 * Output: [1,2,3,4,5,6,7]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= pre.length == post.length <= 30
 * pre[] and post[] are both permutations of 1, 2, ..., pre.length.
 * It is guaranteed an answer exists. If there exists multiple answers, you can
 * return any of them.
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
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
template <typename T>void print(T v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<v.size(); i++)cout<<setw(w)<<i<<" ";cout<<endl;}for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(w)<<*i<<" ";cout<<endl;}
template <typename T>void print_vv(T v){if(v.size()==0) {cout<<"Empty"<<endl; return;} int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}
#include "Tree.h"

// Observation based
// Ref: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/discuss/161268/C%2B%2BJavaPython-One-Pass-Real-O(N)
class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int n = pre.size();
        if(!n) return NULL;
        stack<TreeNode*> stk;
        TreeNode* root = new TreeNode(pre[0]);
        stk.push(root);
        
        for(int i=1, j=0; i<n; ++i){
            TreeNode* cur = new TreeNode(pre[i]);
            while(stk.top()->val==post[j]){
                stk.pop(); ++j;
            }
            if(!stk.top()->left)
                stk.top()->left = cur;
            else 
                stk.top()->right = cur;
            
            stk.push(cur);
        }
        
        return root;
    }
};

// pre: [root,[..left...][..right..]]
// post: [[..left..],[..right..], root]
class Solution0 {
    map<int,int> loc;
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int n = pre.size();
        for(int i=0; i<n; ++i){
            loc[post[i]] = i;
        }
        return dfs(0,n-1,0,n-1, pre, post);
    }
    
    TreeNode* dfs(int pre_st, int pre_end, int post_st, int post_end, vector<int> &pre, vector<int> &post){
        if(pre_st>pre_end || post_st>post_end) return NULL;
        TreeNode* cur = new TreeNode(pre[pre_st]);
        if(pre_st==pre_end) return cur;
        
        int idx = loc[pre[pre_st+1]];
        
        int len = idx-post_st + 1;
        cur->left = dfs(pre_st+1, pre_st + 1 + len-1, post_st, idx, pre, post);
        cur->right = dfs(pre_st+len+1, pre_end, idx+1, post_end-1, pre, post);
        
        return cur;
    }
};

// @lc code=end

int main(){
    Solution sol;
    vi pre = { 1,2,4,5,3,6,7 }, post = { 4,5,2,6,7,3,1 };
    TreeNode* root = sol.constructFromPrePost(pre,post); 
    string out = treeNodeToString(root); deb(out);
    return 0;
}
