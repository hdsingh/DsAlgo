#include "node.h"

//     sample inorder tree
//			40        
//		  /    \
//		 20     60
//		/ \     /
//	   10  30  50

node* Tree(){
    node* root = new node(40);
    root->left = new node(20);
    root->right = new node(60);
    root->left->left = new node(10);
    root->left->right = new node(30);
    root->right->left = new node(50);
    return root;
};

void inorderTraversal(node* root){
    if(!root) return;
    stack<node*> s;
    node* cur = root;
    s.push(cur);
    cur= cur->left;

    while(cur || !s.empty()){
        while(cur){
            s.push(cur);
            cur = cur->left;
        }
        cur = s.top();
        s.pop();
        cout<<cur->data<<" ";
        cur = cur->right;
    }
}


int main(){
    node* root = Tree();
    inorderTraversal(root);
}