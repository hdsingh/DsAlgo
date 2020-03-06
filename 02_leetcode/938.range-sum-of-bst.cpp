/*
 * @lc app=leetcode id=938 lang=cpp
 *
 * [938] Range Sum of BST
 *
 * https://leetcode.com/problems/range-sum-of-bst/description/
 *
 * algorithms
 * Easy (78.10%)
 * Likes:    506
 * Dislikes: 94
 * Total Accepted:    96.2K
 * Total Submissions: 123.3K
 * Testcase Example:  '[10,5,15,3,7,null,18]\n7\n15'
 *
 * Given the root node of a binary search tree, return the sum of values of all
 * nodes with value between L and R (inclusive).
 * 
 * The binary search tree is guaranteed to have unique values.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [10,5,15,3,7,null,18], L = 7, R = 15
 * Output: 32
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [10,5,15,3,7,13,18,1,null,6], L = 6, R = 10
 * Output: 23
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The number of nodes in the tree is at most 10000.
 * The final answer is guaranteed to be less than 2^31.
 * 
 * 
 * 
 */
/**
 * Definition for a binary tree node.
 * struct node {
 *     int val;
 *     node *left;
 *     node *right;
 *     node(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define deb(x) cout<<#x<<" "<<x<<endl;
#define deb2(x, y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define deb3(x, y, z) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef vector<int> vi;

#include "Tree.h"

class Solution0 {
	int L, R;
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
		this->L = L;
		this->R = R;
		return dfs(root);
    }
	
	int dfs(TreeNode* root){
		if(!root) return 0;
		int val = root->val;
		int res = val >=L && val<=R ? val : 0;
		return res + (L<val ? dfs(root->left) : 0) + (val<R ? dfs(root->right) : 0);
	}
};

// Iterative
class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
		int res = 0;
        stack<TreeNode*> stk;
		if(root) stk.push(root);

		while(stk.size()){
			TreeNode* cur = stk.top(); stk.pop();
			
			if(L<=cur->val && cur->val<=R)
				res+=cur->val;
			if(L<cur->val && cur->left)
				stk.push(cur->left);
			if(cur->val<R && cur->right)
				stk.push(cur->right);
			
		}

		return res;
    }
};

int main(){
	Solution sol; int L, R, out;
	node* root = ExampleInTree();
	out = sol.rangeSumBST(root, 25, 55); deb(out);
	return 0;
}