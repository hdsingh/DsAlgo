/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
 *
 * algorithms
 * Medium (43.18%)
 * Likes:    1178
 * Dislikes: 69
 * Total Accepted:    252.2K
 * Total Submissions: 583.5K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the zigzag level order traversal of its nodes'
 * values. (ie, from left to right, then right to left for the next level and
 * alternate between).
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
 * return its zigzag level order traversal as:
 * 
 * [
 * ⁠ [3],
 * ⁠ [20,9],
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> out{};
        if(!root) return out;
        vector<int> inner;
        deque<node*> dq;
        
        dq.push_front(NULL);
        dq.push_front(root);
        node* cur = dq.front();

        while(dq.size()>1 && cur){
            while(cur){
                // cout<<"i: "<<cur->val<<" ";
                inner.push_back(cur->val);
                dq.pop_front();

                if(cur->left) dq.push_back(cur->left);
                if(cur->right) dq.push_back(cur->right);

                cur = dq.front();
            }
            // cout<<endl;
            // cout<<"inn1: ";
            // print(inner);
            if (inner.size()>0)
                out.push_back(inner);
            inner.clear();

            dq.push_front(NULL);
            cur = dq.back();

            while(cur){
                // cout<<"j: "<<cur->val<<" ";
                inner.push_back(cur->val);
                dq.pop_back();

                if(cur->right) dq.push_front(cur->right);
                if(cur->left) dq.push_front(cur->left);

                cur = dq.back();
            }

            dq.push_back(NULL);
            cur = dq.front();
            // cout<<endl;
            // cout<<"inn2: ";
            // cout<<"size: "<<inner.size();
            // print(inner);
            if (inner.size()>0)
                out.push_back(inner);
            inner.clear();

        }
        // return vector<vector<int>>{};
        return out;
    }
};

// int main() {
//     string line;
//     while (getline(cin, line)) {
//         TreeNode* root = stringToTreeNode(line);
        
//         vector<vector<int>> ret = Solution().zigzagLevelOrder(root);

//         for (vi v: ret)
//             print(v);
        
//         cout<<"----"<<endl;
//     }
//     return 0;
// }


