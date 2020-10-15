#include <bits/stdc++.h>
using namespace std;
#include "Tree.h"

class Codec {
    int pos;
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string out;
        stack<TreeNode*> stk;
        TreeNode* cur;
        if(root) stk.push(root);
        
        while(stk.size()){
            cur = stk.top(); stk.pop();
            
            char buf[sizeof(int)];
            memcpy(buf, &(cur->val), sizeof(int));
            for(int i=0; i<(int)sizeof(int); ++i)
                out+=buf[i];
            
            if(cur->right) stk.push(cur->right);
            if(cur->left) stk.push(cur->left);
        }
        return out;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        pos = 0;
        return dfs(data,INT_MAX);
    }
    
    
    TreeNode* dfs(string &data, int bound){
        if(pos>=data.size()) return NULL;
        
        int val;
        memcpy(&val, &data[pos], sizeof(int));
        
        if(val>bound) return NULL;
        
        TreeNode* cur = new TreeNode(val);
        
        pos+=sizeof(int);
        
        cur->left = dfs(data,cur->val);
        cur->right = dfs(data, bound);
        return cur;
    }
};

class Codec1 {
    int pos;
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string out;
        stack<TreeNode*> stk;
        TreeNode* cur;
        if(root) stk.push(root);
        
        while(stk.size()){
            cur = stk.top(); stk.pop();
            out+=to_string(cur->val)+"#";
            if(cur->right) stk.push(cur->right);
            if(cur->left) stk.push(cur->left);
        }
        return out;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        pos = 0;
        return dfs(data,INT_MAX);
    }
    
    TreeNode* dfs(string &data, int bound){
        if(pos>=data.size() || get_next(data,0)>bound)
            return NULL;
        TreeNode* cur = new TreeNode(get_next(data,1));
        
        cur->left = dfs(data,cur->val);
        cur->right = dfs(data, bound);
        return cur;
    }
    
    int get_next(string &data, int remove){
        int npos = pos;
        string cur_num;
        while(npos<data.size() && data[npos]!='#'){
            cur_num+=data[npos++];
        }
        if(remove) pos = npos+1;
        return stoi(cur_num);
    }
};


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    return 0;
}