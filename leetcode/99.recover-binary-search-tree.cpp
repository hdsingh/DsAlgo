#include <bits/stdc++.h>
using namespace std;
#include "Tree.h"


// Since bst inorder acts as a sorted array
// hence find two incorrect locs;
class Solution {
    TreeNode *prev, *first, *second;
public:
    void recoverTree(TreeNode* root) {
        prev = new TreeNode(INT_MIN);
        first = NULL, second = NULL;
        dfs(root);
        if(first && second)
            swap(first->val, second->val);
    }
    
    void dfs(TreeNode* root){
        if(!root) return;
        
        dfs(root->left);
        
        if(!first && prev->val>root->val){
            first = prev;
        }
        
        if(first && prev->val>root->val){
            second = root;
        }
        
        prev = root;
        
        dfs(root->right);
        
    }
};
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    return 0;
}