// #include "node.h"
#include "01_binary_tree_traversal.cpp"

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

node* insert(node* root, int key){
    node* newnode = new node(key);
    if (!root) return NULL;
    node* cur = root;
    node* prev = NULL;

    while(cur!=NULL){
        prev = cur;
        if (cur->data<=key)
            cur = cur->right;
        else
            cur = cur->left;
    }

    if (prev->data<=key)
        prev->right = newnode;
    else
        prev->left = newnode;
    
    return root;

}


int main(){
    int key = 5;
    node* root = sampleBST();
    inorder(root);
    cout<<endl;

    root = insert(root, 5);
    inorder(root);
}