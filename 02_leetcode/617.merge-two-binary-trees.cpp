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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// #include "cpp.h"
// #include "node.h"
// #include "extra.h"
// using namespace std;

typedef TreeNode node;

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        // base
        if(!t1) return t2;
        if(!t2) return t1;

        stack<node*> s1, s2;
        TreeNode* res = t1;
        s1.push(t1);
        s2.push(t2);

        while(!s1.empty()){
            TreeNode* a = s1.top(); s1.pop();
            TreeNode* b = s2.top(); s2.pop();

            a->val += b->val;

            // Push the childern
        
            if(a->right && b->right){
                s1.push(a->right); s2.push(b->right);
            }
            else if(a->right || b->right){
                a->right= a->right? a->right:b->right;
            }

            if(a->left && b->left){
                s1.push(a->left); s2.push(b->left);
            }
            else if(a->left || b->left){
                a->left= a->left? a->left:b->left;
            }

        }

        return res;

    }
};

// int main() {
//     string line;
//     while (getline(cin, line)) {
//         TreeNode* t1 = stringToTreeNode(line);
//         getline(cin, line);
//         TreeNode* t2 = stringToTreeNode(line);

//         TreeNode* ret = Solution().mergeTrees(t1, t2);

//         string out = treeNodeToString(ret);
//         cout << out << endl;
//     }
//     return 0;
// }
