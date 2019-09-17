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

void postorderIter1Stack(node* root){
    stack<node*> s;
    node* cur = root;

    while(cur || !s.empty()){
        if(cur){
            s.push(cur);
            cur = cur->left;
        }
        else{
            if(s.top()->right)
                cur = s.top()->right;
            else{
                node* temp = s.top();
                cout<<temp->data<<" ";
                s.pop();
                // if the temp is right child of stack's top node i.e.
                // to check if its both sides have been visited
                while(!s.empty() && temp==s.top()->right){
                    temp = s.top();
                    cout<<temp->data<<" ";
                    s.pop();
                }
            }
        }
    }
}

int main(){
    node* root = Tree();
    postorderIter1Stack(root);

}