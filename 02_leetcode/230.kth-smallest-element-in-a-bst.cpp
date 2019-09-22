/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
 *
 * https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/
 *
 * algorithms
 * Medium (53.25%)
 * Likes:    1371
 * Dislikes: 43
 * Total Accepted:    254.1K
 * Total Submissions: 476.8K
 * Testcase Example:  '[3,1,4,null,2]\n1'
 *
 * Given a binary search tree, write a function kthSmallest to find the kth
 * smallest element in it.
 * 
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
 * 
 * Example 1:
 * 
 * 
 * Input: root = [3,1,4,null,2], k = 1
 * ⁠  3
 * ⁠ / \
 * ⁠1   4
 * ⁠ \
 * 2
 * Output: 1
 * 
 * Example 2:
 * 
 * 
 * Input: root = [5,3,6,2,4,null,null,1], k = 3
 * ⁠      5
 * ⁠     / \
 * ⁠    3   6
 * ⁠   / \
 * ⁠  2   4
 * ⁠ /
 * ⁠1
 * Output: 3
 * 
 * 
 * Follow up:
 * What if the BST is modified (insert/delete operations) often and you need to
 * find the kth smallest frequently? How would you optimize the kthSmallest
 * routine?
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
typedef vector<int> vi;
typedef TreeNode node;

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int i(0);
        int res;
        // do inorder traversal
        stack<node*> s;
        node* cur = root;

        while(!s.empty()|| cur){
            while(cur){
                s.push(cur);
                cur =cur->left;
            }
            if(!cur){
                cur = s.top(); s.pop();
                res = cur->val;
                i++;
                if(i==k) break;
                cur = cur->right;
            }
        }
        return res;
    }
};

// int main() {
//     string line;
//     while (getline(cin, line)) {
//         TreeNode* root = stringToTreeNode(line);
//         getline(cin, line);
//         int k = stringToInteger(line);
        
//         int ret = Solution().kthSmallest(root, k);

//         string out = to_string(ret);
//         cout << out << endl;
//     }
//     return 0;
// }

