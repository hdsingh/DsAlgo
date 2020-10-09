#include <bits/stdc++.h>
using namespace std;
#include "Tree.h"

class Solution {
    int ans;
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int level = -1;
        TreeNode* cur = root;
        while(cur){
            ++level; cur = cur->left;
        }
        
        auto can = [&](int lev){
            vector<int> path;
            while(lev){
                path.push_back(lev&1);
                lev>>=1;
            }
            path.pop_back();
            reverse(path.begin(), path.end());

            cur = root;
            for(auto x: path){
                if(!cur) return false;
                if(!x) cur = cur->left;
                else cur = cur->right;
            }
            if(!cur) return false;
            return (!cur->left && !cur->right);
        };
        
        int lt = (1<<level) - 1, rt = (1<<(level+1));
        
        while(1+lt<rt){
            int mid = lt + (rt-lt)/2;
            if(can(mid)){
                lt = mid;
            }else
                rt = mid;
        }
        
        return lt;
    }
    
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s = "[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17]"; int out;
    Solution sol; TreeNode* root;
    root = stringToTreeNode(s);
    out = sol.countNodes(root); cout<<out<<"\n";
    return 0;
}