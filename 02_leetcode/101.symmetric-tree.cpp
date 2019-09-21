/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
 *
 * https://leetcode.com/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (44.36%)
 * Likes:    2640
 * Dislikes: 57
 * Total Accepted:    462.3K
 * Total Submissions: 1M
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric
 * around its center).
 * 
 * For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
 * 
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠/ \ / \
 * 3  4 4  3
 * 
 * 
 * 
 * 
 * But the following [1,2,2,null,3,null,3] is not:
 * 
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠  \   \
 * ⁠  3    3
 * 
 * 
 * 
 * 
 * Note:
 * Bonus points if you could solve it both recursively and iteratively.
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
    // Iterative 
    bool isSymmetric(node* root){
        if(!root) return true;
        queue<node*> q;
        node* cur_l; node* cur_r;

        if(!root->left || !root->right){ //any one or both are null
            // if one null and other not
            if(root->left!=root->right) return false;
        }
        else { //if(root->left && root->right) i.e both exist
            if(root->left->val != root->right->val)
                return false;
            q.push(root->left);
            q.push(root->right);
        }
            

        while(!q.empty()){
            cur_l= q.front(); q.pop();
            cur_r= q.front(); q.pop();

            if(cur_l->val!=cur_r->val)
                return false;
            else{
                // ll,rr
                if(!cur_l->left || !cur_r->right){
                    if(cur_l->left!=cur_r->right) return false;
                }else{
                    q.push(cur_l->left);
                    q.push(cur_r->right);
                }

                // lr,rl
                if(!cur_l->right || !cur_r->left){
                    if(cur_l->right!=cur_r->left) return false;
                }else{
                    q.push(cur_l->right);
                    q.push(cur_r->left);
                }
            }
        }

        return true;

    }

    // Recursive
    bool isSymmetricRec(TreeNode* root) {
        if(!root) return true;
        return isSymmetricHelper(root->left, root->right);
    }
    
    bool isSymmetricHelper(node* left, node* right){
        if(!left || !right)
            return left==right;
        if(left->val!=right->val)
            return false;
        return isSymmetricHelper(left->left, right->right) && isSymmetricHelper(left->right, right->left);
    }
};

// int main() {
//     string line;
//     while (getline(cin, line)) {
//         TreeNode* root = stringToTreeNode(line);
        
//         bool ret = Solution().isSymmetric(root);

//         string out = boolToString(ret);
//         cout << out << endl;
//     }
//     return 0;
// }
