#include <bits/stdc++.h>
using namespace std;
#include "Tree.h"

class Codec {
    void serialize(TreeNode* root, ostringstream &out){
        if(!root){
            out<<"# ";
        }else{
            out<<root->val<<" ";
            serialize(root->left, out);
            serialize(root->right, out);
        }
    }

    TreeNode* deserialize(istringstream &inp) {
        string val; 
        inp>>val;
        if(val=="#")
            return NULL;
    
        TreeNode* root = new TreeNode(stoi(val));
        root->left = deserialize(inp);
        root->right = deserialize(inp);
        return root;
    }
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        serialize(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream inp(data);
        return deserialize(inp);
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    return 0;
}