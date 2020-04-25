#include "node.h"

// BST
//			10        
//		  /    \
//		 20     30
//		/ \      \
//	   40  50    60
//        /  \   / \ 
//       70  80 90  100

node* Tree(){
    node* root = new node(10);
    root->left = new node(20);
    root->right = new node(30);
    root->left->left = new node(40);
    root->left->right = new node(50);
    root->right->right = new node(60);
    root->left->right->left = new node(70);
    root->left->right->right = new node(80);
    root->right->right->left = new node(90);
    root->right->right->right = new node(100);
    return root;
};

// using 2 stack
void spiral1(node* root){
    stack<node*> s1, s2;
    node* cur = root;
    s1.push(root);

    while(!s1.empty() && s2.empty()){
        while(!s1.empty()){
            cur = s1.top();
            s1.pop();
            cout<<cur->data<<" ";
            if(cur->left) s2.push(cur->left);
            if(cur->right) s2.push(cur->right);
        }
        cout<<endl;
        while(!s2.empty()){
            cur = s2.top();
            s2.pop();
            cout<<cur->data<<" ";
            if(cur->right) s1.push(cur->right);
            if(cur->left) s1.push(cur->left);
        }
        cout<<endl;
    }
}

// using deque
void spiral2(node* root){
    deque<node*> dq;
    dq.push_front(NULL);
    node* cur;
    dq.push_front(root);

    while(dq.size()>1){
        cout<<endl;

        cur = dq.front();
        while(cur){
            cout<<cur->data<<" ";
            dq.pop_front();
            
            if(cur->left) dq.push_back(cur->left);
            if(cur->right) dq.push_back(cur->right);
            
            cur = dq.front();
        }
        
        cout<<endl;
        cur = dq.back();
        while(cur){
            cout<<cur->data<<" ";
            dq.pop_back();
            
            if(cur->right) dq.push_front(cur->right);
            if(cur->left) dq.push_front(cur->left);

            cur = dq.back();
        }
    }
}



int main(){
    node* root = Tree();
    spiral1(root);
    cout<<endl;
    spiral2(root);
}