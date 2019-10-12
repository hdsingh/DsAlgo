#include "node.h"

// BST
//			40        
//		  /    \
//		 20     55
//		/ \      \
//	   10  30    60

node* sampleBST(){
    node* root = new node(40);
    root->left = new node(20);
    root->right = new node(55);
    root->left->left = new node(10);
    root->left->right = new node(30);
    root->right->right = new node(60);
    return root;
};

bool isBSTutil(node* root, int min, int max){
    if (!root) return true;

    if (root->data<min || root->data>max)
        return false;

    return isBSTutil(root->left, min, root->data) && isBSTutil(root->right, root->data, max);
}

bool isBST(node* root){
    return isBSTutil(root, INT_MIN, INT_MAX);
}

int main(){
    node* root = sampleBST();
    cout<<isBST(root);
}