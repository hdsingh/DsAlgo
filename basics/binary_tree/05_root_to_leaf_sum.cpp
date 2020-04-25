#include "node.h"


//     sample tree
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

bool rootToLeafSum(node* root, int sum, vector<int>& res){
    if(!root) return false;

    // Leaf Node
    if(!root->left && !root->right){
        if(root->data==sum){
            res.push_back(root->data);
            return true;
        }else return false;
    }

    if (rootToLeafSum(root->left, sum -root->data, res)){
        res.push_back(root->data);
        return true;
    }
    if (rootToLeafSum(root->right, sum -root->data, res)){
        res.push_back(root->data);
        return true;
    }
    return false;
}


int main(){
    node* root = Tree();
    vector<int> res;
    cout<<rootToLeafSum(root, 150, res)<<endl;

    for(int x: res)
        cout << x<<" ";

}