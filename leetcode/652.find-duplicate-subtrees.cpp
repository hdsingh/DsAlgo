#include <bits/stdc++.h>
using namespace std;
#include "Tree.h"


class Solution {
    unordered_map<int,int> hash_count;
    unordered_map<string,int> hash_id;
    vector<TreeNode*> out;
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return out;
    }
    
    string dfs(TreeNode* root){
        if(!root) return "#";
        string cur_hash = to_string(root->val) + "," + 
                dfs(root->left) + ","  + dfs(root->right);
        
        int cur_id = -1;
        if(!hash_id.count(cur_hash)){
            cur_id = hash_id.size();
            hash_id[cur_hash] = cur_id;
        }else{
            cur_id = hash_id[cur_hash];
        }
        
        if(++hash_count[cur_id]==2){
            out.push_back(root);
        }
        return to_string(cur_id);
    }
};

class Solution {
    unordered_map<string, int> seen;
    vector<TreeNode*> out;
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return out;
    }
    
    string dfs(TreeNode* root){
        if(!root) return "#";
        string cur = to_string(root->val) + "," + dfs(root->left) + ","  + dfs(root->right);
        if(++seen[cur]==2){
            out.push_back(root);
        }
        return cur;
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    return 0;
}