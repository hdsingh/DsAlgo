#include "node.h"

// BST
//			40        
//		  /    \
//		 20     55
//		/ \      \
//	   10  30    60

node* Tree(){
    node* root = new node(40);
    root->left = new node(20);
    root->right = new node(55);
    root->left->left = new node(10);
    root->left->right = new node(30);
    root->right->right = new node(60);
    return root;
};

void levelOrder(node* root){
    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        node* cur = q.front();
        cout<<cur->data<<" ";

        if(cur->left) q.push(cur->left);
        if(cur->right) q.push(cur->right);
        q.pop();
    }
}

int main(){
    node* root = Tree();
    levelOrder(root);
}