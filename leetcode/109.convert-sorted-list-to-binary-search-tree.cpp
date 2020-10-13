#include <bits/stdc++.h>
using namespace std;
#include "Tree.h"
#include "LinkedList.h"

// inorder traversal property
class Solution {
    ListNode* headnode;
public:
    TreeNode* sortedListToBST(ListNode* head) {
        headnode = head;
        int len = 0;
        auto cur = head;
        while(cur){
            ++len; 
            cur =  cur->next;
        }
        return bst(0,len-1);
    }
    
    TreeNode* bst(int lt, int rt){
        if(lt>rt) return NULL;
        int mid = (lt+rt)/2;
        
        TreeNode* left = bst(lt,mid-1);
        
        TreeNode *root = new TreeNode(headnode->val);
        headnode = headnode->next;
        root->left = left;
        
        root->right = bst(mid+1, rt);
        
        return root;
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    return 0;
}