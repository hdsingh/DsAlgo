/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-postorder-traversal/description/
 *
 * algorithms
 * Hard (50.16%)
 * Likes:    1108
 * Dislikes: 58
 * Total Accepted:    289.5K
 * Total Submissions: 576.4K
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the postorder traversal of its nodes' values.
 * 
 * Example:
 * 
 * 
 * Input: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 * 
 * Output: [3,2,1]
 * 
 * 
 * Follow up: Recursive solution is trivial, could you do it iteratively?
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
    vi postorderTraversal(node* root){
        vi res;
        stack<node*> s;
        node* cur = root;

        while(!s.empty() || cur){
            if(cur){
                s.push(cur);
                cur = cur->left;
            }else{
                if(s.top()->right){
                    cur = s.top()->right;
                }else{
                    node* temp = s.top();
                    s.pop();
                    res.push_back(temp->val);
                    while(!s.empty() && s.top()->right==temp){
                        temp = s.top();
                        s.pop();
                        res.push_back(temp->val);
                    }
                }
            }
        }
        return res;
    }

    // Iterative 2 stack
    vi postorderTraversal2Stack(node* root){
        vi res{};
        if(!root) return res;
        stack<node*> s1, s2;
        s1.push(root);
        node* cur;

        while(!s1.empty()){
            cur = s1.top();
            s1.pop();
            s2.push(cur);

            if(cur->left) s1.push(cur->left);
            if(cur->right) s1.push(cur->right);
        }

        while(!s2.empty()){
            cur = s2.top();
            res.push_back(cur->val);
            s2.pop();
        }
        
        return res;
    }


    vector<int> postorderTraversalRec(TreeNode* root) {
        vi res;
        postorder(root, res);
        return res;
    }

    void postorder(node* root, vi &res){
        if (!root) return;

        postorder(root->left, res);
        postorder(root->right, res);
        res.push_back(root->val);
    }
};

// int main() {
//     string line;
//     while (getline(cin, line)) {
//         TreeNode* root = stringToTreeNode(line);
        
//         vector<int> ret = Solution().postorderTraversal(root);

//         string out = integerVectorToString(ret);
//         cout << out << endl;
//     }
//     return 0;
// }