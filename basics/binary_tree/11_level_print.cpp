#include "node.h"

// BST
//			40        
//		  /    \
//		 20     55
//		/ \      \
//	   10  30    60
//        /  \   /
//       4   6  7

node* Tree(){
    node* root = new node(40);
    root->left = new node(20);
    root->right = new node(55);
    root->left->left = new node(10);
    root->left->right = new node(30);
    root->right->right = new node(60);
    root->left->right->left = new node(4);
    root->left->right->right = new node(6);
    root->right->right->left = new node(7);
    return root;
};

// Using 2 queues
void levelPrint1(node* root){
    if(!root) return;
    queue<node*> q1,q2;
    q1.push(root);
    node* cur;

    while(!q1.empty() || !q2.empty()){
        while(!q1.empty()){
            cur = q1.front();
            cout<<cur->data<<" ";
            q1.pop();
            if(cur->left) q2.push(cur->left);
            if(cur->right) q2.push(cur->right);
        }

        cout<<endl;

        while(!q2.empty()){
            cur = q2.front();
            cout<<cur->data<<" ";
            q2.pop();
            if(cur->left) q1.push(cur->left);
            if(cur->right) q1.push(cur->right);
        }
        cout<<endl;
    }

}

// using NULL as delimiter
void levelPrint2(node* root){
    if(!root) return;
    queue<node*> q;
    node* cur;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        cur = q.front();
        q.pop();
        if (cur){
            cout<<cur->data<<" ";
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }else{
            if(!q.empty()) q.push(NULL);
            cout<<endl;
        }        
    }
}


int main(){
    node* root = Tree();
    levelPrint1(root);
    cout<<endl;
    levelPrint2(root);
    cout<<endl;
    // levelPrint3(root);
}