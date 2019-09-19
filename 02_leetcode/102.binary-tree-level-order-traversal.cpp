/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (50.08%)
 * Likes:    1775
 * Dislikes: 46
 * Total Accepted:    432.3K
 * Total Submissions: 862.3K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the level order traversal of its nodes' values.
 * (ie, from left to right, level by level).
 * 
 * 
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 
 * return its level order traversal as:
 * 
 * [
 * ⁠ [3],
 * ⁠ [9,20],
 * ⁠ [15,7]
 * ]
 * 
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return vector<vector<int>>{};
        vector<vector<int>> out;
        vector<int> inner;
        queue<node*> q;
        q.push(root);
        q.push(NULL);
        
        while(true){
            node* cur = q.front(); q.pop();
            
            if(cur){
                inner.push_back(cur->val);
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }else{
                out.push_back(inner);
                inner.clear();
                if (q.size()==0) break;
                q.push(NULL);
            }
        }
        return out;
        // return vector<vector<int>> {{},{}};
    }
};

// int main() {
//     string line;
//     while (getline(cin, line)) {
//         TreeNode* root = stringToTreeNode(line);
        
//         vector<vector<int>> ret = Solution().levelOrder(root);

//         for (vi v: ret)
//             print(v);
        
//         cout<<"----"<<endl;
//     }
//     return 0;
// }

