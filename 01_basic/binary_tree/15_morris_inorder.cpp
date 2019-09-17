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

void morris(node* root){
    node* cur = root;
    while(cur){
        if (!cur->left){
            cout<<cur->data<<" ";
            cur = cur->right;
        }
        else{
            // pred = predecessor
            node* pred = cur->left;
            // find pred
            while(pred->right && pred->right!=cur){
                pred = pred->right;
            }
            // Make the link
            if(!pred->right){
                pred->right = cur;
                cur=cur->left;
            }
            // break the link
            else{
                pred->right = NULL;
                cout<<cur->data<<" ";
                cur = cur->right;
            }
        }
    }
}

int main(){
    node* root = Tree();
    morris(root);
}