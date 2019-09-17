#include "node.h"

//     sample tree
//			40        
//		  /    \
//		 20     60
//		/ \     /
//	   10  30  50

node* Tree1(){
    node* root = new node(40);
    root->left = new node(20);
    root->right = new node(60);
    root->left->left = new node(10);
    root->left->right = new node(30);
    root->right->left = new node(50);
    return root;
};

node* Tree2(){
    node* root = new node(40);
    root->left = new node(20);
    root->right = new node(60);
    root->left->left = new node(10);
    root->left->right = new node(30);
    root->right->left = new node(70);
    node* root1 = Tree1();
    return root;
};

bool sameTree(node* root1, node* root2){
    if (!root1 && !root2) return true;
    if (!root1 || !root2) return false;

    if (root1->data==root2->data && 
        sameTree(root1->left, root2->left) &&
        sameTree(root1->right, root2->right)) return true;
}

int sizeofTree(node* root){
    if (!root) return 0;

    int left = sizeofTree(root->left);
    int right = sizeofTree(root->right);
    return left + right + 1;

}

int heightofTree(node* root){
    if (!root) return 0;

    int left = heightofTree(root->left);
    int right = heightofTree(root->right);
    return max(left, right) + 1;

}

int main(){
    node* root1 = Tree1();
    node* root2 = Tree2();
    cout<<sameTree(root1, root2)<<endl;
    cout<<sameTree(root1, root1)<<endl;
    cout<<sizeofTree(root1)<<endl;
    cout<<heightofTree(root1)<<endl;
}