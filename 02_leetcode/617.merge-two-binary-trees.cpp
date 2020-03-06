/*
 * @lc app=leetcode id=617 lang=cpp
 *
 * [617] Merge Two Binary Trees
 *
 * https://leetcode.com/problems/merge-two-binary-trees/description/
 *
 * algorithms
 * Easy (71.11%)
 * Likes:    2054
 * Dislikes: 140
 * Total Accepted:    207.2K
 * Total Submissions: 291.3K
 * Testcase Example:  '[1,3,2,5]\n[2,1,3,null,4,null,7]'
 *
 * Given two binary trees and imagine that when you put one of them to cover
 * the other, some nodes of the two trees are overlapped while the others are
 * not.
 * 
 * You need to merge them into a new binary tree. The merge rule is that if two
 * nodes overlap, then sum node values up as the new value of the merged node.
 * Otherwise, the NOT null node will be used as the node of new tree.
 * 
 * Example 1:
 * 
 * 
 * Input: 
 * Tree 1                     Tree 2                  
 * ⁠         1                         2                             
 * ⁠        / \                       / \                            
 * ⁠       3   2                     1   3                        
 * ⁠      /                           \   \                      
 * ⁠     5                             4   7                  
 * Output: 
 * Merged tree:
 * 3
 * / \
 * 4   5
 * / \   \ 
 * 5   4   7
 * 
 * 
 * 
 * 
 * Note: The merging process must start from the root nodes of both trees.
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
typedef long long ll;
typedef vector<int> vi;

#include "Tree.h"

class Solution1 {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(!t1) return t2;
        if(!t2) return t1;

        t1->val +=t2->val;
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);

        return t1;   
    }
};

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(!t1) return t2;
        if(!t2) return t1;
		stack<TreeNode*> stk1, stk2;
		stk1.push(t1); stk2.push(t2);
		
		while(!stk1.empty()){
			TreeNode* a = stk1.top(); stk1.pop();
			TreeNode* b = stk2.top(); stk2.pop();

			a->val +=b->val;

			if(a->right && b->right)
				stk1.push(a->right), stk2.push(b->right);
			else if(a->right || b->right)
				a->right = a->right ? a->right : b->right;

			if(a->left && b->left)
				stk1.push(a->left), stk2.push(b->left);
			else if(a->left || b->left)
				a->left = a->left ? a->left : b->left;
		}

		return t1;
    }
};

int main(){
	Solution sol; string s1, s2, s3; node *t1, *t2, *out;
	s1 = "[1,3,2,5]";
	s2 = "[2,1,3,null,4,null,7]";
    // s1 = "[]"; s2 = "[1]";
	t1 = stringToTreeNode(s1);
	t2 = stringToTreeNode(s2);
    // s1 = treeNodeToString(t1); s2 = treeNodeToString(t2); deb2(s1,s2);
	out = sol.mergeTrees(t1, t2);
	s3 = treeNodeToString(out); deb(s3);
	return 0;
}
