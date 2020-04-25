#include "node.h"

// BST
//       10
//      /  \
//    -5    25
//    / \     \
// -10  5     36

node* sampleBST(){
    node* root = new node(10);
    root->left = new node(-5);
    root->right = new node(25);
    root->left->left = new node(-10);
    root->left->right = new node(5);
    root->right->right = new node(36);
    return root;
}

node* searchBST(node* root, int key){
    if (!root) return new node(-1);// or NULL

    if (root->data==key) return root;
    
    if (root->data<key)
        return searchBST(root->right, key);
    else
        return searchBST(root->left, key);
}


node* searchBSTiter(node* root, int key){
    node* cur = root;
    while(cur){
        if(cur->data==key)
            return cur;
        if(cur->data<key)
            cur = cur->right;
        else
            cur= cur->left;
    }
    return cur?cur:new node(-1); // or NULL
}


int main(){
    node* root = sampleBST();
    int key = 36;
    node* ans = searchBST(root, key);
    cout<<ans->data<<endl;
    node* ans2 = searchBSTiter(root, key);
    cout<<ans2->data;

}