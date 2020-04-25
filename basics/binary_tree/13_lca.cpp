#include "node.h"

// BST
//			10        
//		  /     \
//		-10      30
//		  \      /  \
//	       8    25   60
//       /  \    \    \ 
//      6   9    28   78

node* sampleBST(){
    node* root = new node(10);
    root->left = new node(-10);
    root->right = new node(30);
    root->left->right = new node(8);
    root->right->left = new node(25);
    root->right->right = new node(60);
    root->left->right->left = new node(6);
    root->left->right->left = new node(8);
    root->right->left->right = new node(28);
    root->right->right->right = new node(78);
    return root;
};


node* lcaBST(node* root, int n1, int n2){
    if(root->data<min(n1,n2))
        return lcaBST(root->right, n1,n2);
    else if(root->data>max(n1, n2))
        return lcaBST(root->left, n1, n2);
    else 
        return root;
}
 
//          3
//        /   \
//       6     8
//     /  \      \ 
//    2   11     13
//        / \    /
//       9   5   7



node* sampleTree(){
    node* root = new node(3);
    root->left = new node(6);
    root->right = new node(8);
    root->left->left = new node(2);
    root->left->right = new node(11);
    root->left->right->left = new node(9);
    root->left->right->right = new node(5);
    root->right->right = new node(13);
    root->right->right->left = new node(7);
    return root;
};

node* lca(node* root, const int &n1, const int &n2){
    if(!root) return NULL;
    if(root->data == n1 || root->data==n2) return root;

    node* left = lca(root->left, n1, n2);
    node* right = lca(root->right, n1, n2);

    if(!left && !right) return NULL;
    if(left && right) return root;
    return left ? left : right;
}


int main(){
    node* root = sampleBST();
    // node* res = lcaBST(root, 28, 78); //30
    // node* res = lcaBST(root, 6, 9); //8
    node* res = lcaBST(root, 30, 78); //30
    cout<<res->data<<endl;

    root = sampleTree();
    res = lca(root, 11, 13);
    cout<<res->data<<endl;
}