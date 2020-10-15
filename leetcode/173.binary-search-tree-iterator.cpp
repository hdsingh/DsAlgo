#include <bits/stdc++.h>
using namespace std;
#include "Tree.h"

class BSTIterator {
    stack<TreeNode*> stk;
    TreeNode* cur;
public:
    BSTIterator(TreeNode* root) {
        cur = root;
    }
    
    /** @return the next smallest number */
    int next() {
        while(cur){
            stk.push(cur);
            cur = cur->left;
        }
        cur = stk.top(); stk.pop();
        int out = cur->val;
        cur = cur->right;
        return out;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return (cur || !stk.empty());
    }
};


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    return 0;
}