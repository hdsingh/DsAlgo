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

#include "cpp.h"
#include "node.h"
using namespace std;

class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        int res = 0;
        sumBST(root, L, R, res);
        return res;
    }

    void sumBST(TreeNode* root, int L, int R, int& res){
        if(root){
            sumBST(root->left, L, R, res);
            int temp = root->val;
            if (temp>=L && temp<=R){
                // cout<<"t: "<<temp<<" ";
                res+=temp;
            }
            sumBST(root->right, L, R, res);
        }
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);
        getline(cin, line);
        int L = stringToInteger(line);
        getline(cin, line);
        int R = stringToInteger(line);
        
        int ret = Solution().rangeSumBST(root, L, R);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}