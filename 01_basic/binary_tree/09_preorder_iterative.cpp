#include "node.h"

//     sample preorder tree
//			10        
//		  /    \
//		 20    50
//		/ \     /
//	   30  40  60

node* Tree(){
    node* root = new node(10);
    root->left = new node(20);
    root->right = new node(50);
    root->left->left = new node(30);
    root->left->right = new node(40);
    root->right->left = new node(60);
    return root;
};


void preorderTraversal(node* root){
    if(!root) return;
    stack<node*> s;
    node* cur = root;
    s.push(cur);


    while(!s.empty()){
        cur = s.top();
        s.pop();
        cout<<cur->data<<" ";

        if(cur->right) s.push(cur->right);
        if(cur->left) s.push(cur->left);
    }
}

int main(){
    node* root = Tree();
    preorderTraversal(root);

}