#include <bits/stdc++.h>
using namespace std;

#define _deb(x) cout<<x;
void _print() {cerr << "]\n";} template <typename T, typename... V>void _print(T t, V... v) {_deb(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#define deb(x...) cerr << "[" << #x << "] = ["; _print(x)
#include "Tree.h"

class Solution0 {
    TreeNode* prev = nullptr;
public:
    void flatten(TreeNode* root) {
        if(root==nullptr) return;
        flatten(root->right);
        flatten(root->left);
        root->right = prev;
        root->left = nullptr;
        prev = root;
    }
};

class Solution {
public:
    void flatten(TreeNode* root) {
        while(root){
            if(root->left && root->right){
                TreeNode* right_most = root->left;
                while(right_most->right)
                    right_most = right_most->right;
                right_most->right = root->right;
            }

            if(root->left)
                root->right = root->left;
            root->left = NULL;
            root = root->right;
        }
    }
};

int main(){
    Solution sol; 
    string s = "[1,2,5,3,4,null,6]";
    TreeNode* root = stringToTreeNode(s);
    sol.flatten(root);
    s = treeNodeToString(root);
    deb(s);
    return 0;
}