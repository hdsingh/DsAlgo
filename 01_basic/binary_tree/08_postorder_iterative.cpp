#include "node.h"

//     sample postorder tree
//			60        
//		  /    \
//		 30    50
//		/ \     /
//	   10  20  40

node* Tree(){
    node* root = new node(60);
    root->left = new node(30);
    root->right = new node(50);
    root->left->left = new node(10);
    root->left->right = new node(20);
    root->right->left = new node(40);
    return root;
};

void postOrderTraversal(node* root){
    if (!root) return;
    stack<node*> s1, s2;
    node* cur = root;
    s1.push(cur);

    while(!s1.empty()){
         cur = s1.top();
         s1.pop();
         s2.push(cur);
         
         if(cur->left) s1.push(cur->left);
         if(cur->right) s1.push(cur->right);
    }

    // print elements
    while(!s2.empty()){
        cur = s2.top();
        cout<<cur->data<<" ";
        s2.pop();
    }

}

int main(){
    node* root = Tree();
    postOrderTraversal(root);

}