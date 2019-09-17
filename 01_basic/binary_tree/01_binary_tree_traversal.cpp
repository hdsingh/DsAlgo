#include "node.h"

//     sample inorder tree
//			40        
//		  /    \
//		 20     60
//		/ \     /
//	   10  30  50

node* inorderTree(){
    node* root = new node(40);
    root->left = new node(20);
    root->right = new node(60);
    root->left->left = new node(10);
    root->left->right = new node(30);
    root->right->left = new node(50);
    return root;
};

void inorder(node* root){
    if(root){
        inorder(root->left);
        cout<<root->data<<endl;
        inorder(root->right);
    }
}

// ######################

//     sample preorder tree
//			10        
//		  /    \
//		 20    50
//		/ \     /
//	   30  40  60

node* preorderTree(){
    node* root = new node(10);
    root->left = new node(20);
    root->right = new node(50);
    root->left->left = new node(30);
    root->left->right = new node(40);
    root->right->left = new node(60);
    return root;
};

void preorder(node* root){
    if(root){
        cout<<root->data<<endl;
        preorder(root->left);
        preorder(root->right);
    }
}

// ######################

//     sample postorder tree
//			60        
//		  /    \
//		 30    50
//		/ \     /
//	   10  20  40

node* postorderTree(){
    node* root = new node(60);
    root->left = new node(30);
    root->right = new node(50);
    root->left->left = new node(10);
    root->left->right = new node(20);
    root->right->left = new node(40);
    return root;
};

void postorder(node* root){
    if(root){
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<endl;
    }
}

// int main(){
//     node* in = inorderTree();
//     inorder(in);
//     cout<<endl;

    // node* pre = preorderTree();
    // preorder(pre);
    // cout<<endl;

    // node* post = postorderTree();
    // postorder(post);
    // cout<<endl;

// }