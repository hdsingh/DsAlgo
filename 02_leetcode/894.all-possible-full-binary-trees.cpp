/*
 * @lc app=leetcode id=894 lang=cpp
 *
 * [894] All Possible Full Binary Trees
 *
 * https://leetcode.com/problems/all-possible-full-binary-trees/description/
 *
 * algorithms
 * Medium (72.96%)
 * Likes:    662
 * Dislikes: 66
 * Total Accepted:    29.4K
 * Total Submissions: 40.3K
 * Testcase Example:  '7'
 *
 * A full binary tree is a binary tree where each node has exactly 0 or 2
 * children.
 * 
 * Return a list of all possible full binary trees with N nodes.  Each element
 * of the answer is the root node of one possible tree.
 * 
 * Each node of each tree in the answer must have node.val = 0.
 * 
 * You may return the final list of trees in any order.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: 7
 * Output:
 * [[0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]
 * Explanation:
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= N <= 20
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

// Full binary tree: every node has exactly 0 or 2 children
// Tree with even nodes can never be full bt
// for and odd N, different trees can be created by fixing a central node
// and changing odd nodes on bith sides
// ex: for 5
//     1         1
//   1   3     3   1
// similarly for 7: 
// (1,1,5), (3,1,3),(5,1,3)
const int nmax = 21;
class Solution {
    vector<vector<TreeNode*>> dp; // stores all variations of fbt for diff values of n 
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        if(!(n&1)) return {};
        dp.resize(nmax);
        if(dp[n].size()) return dp[n];
        dp[1] = {new TreeNode(0)};
        
        // deb(n);
        for(int i=3; i<=n; i+=2){
            // deb(i);
            if(dp[i].size()) continue; // to avoid recomputation
            for(int lnodes=1; lnodes<i; lnodes+=2){
                int rnodes = i-1-lnodes;
                // deb2(lnodes, rnodes);
                combine(lnodes,rnodes, i);
            }
        }

        return dp[n];   
    }

    void combine(int left, int right, int i){
        for(auto lsub : dp[left]){
            for(auto rsub: dp[right]){
                TreeNode* root = new TreeNode(0);
                root->left = lsub;
                root->right = rsub;
                dp[i].push_back(root);
            }
        }
    }
};
// @lc code=end

int main(){
    Solution sol;
    // for(int i=0; i<20; ++i){
    vi a = {1,2,3,4,5,9,10,15,19};
    // a = {7};
    for(auto i: a){
        deb(i);
        vector<TreeNode*> nodes = sol.allPossibleFBT(i);
        deb(nodes.size());
        for(auto root: nodes){
            string s = treeNodeToString(root);
            // deb(s);
        }
        cout<<endl;
    }
    return 0;
}
