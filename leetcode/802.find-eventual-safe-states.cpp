#include <bits/stdc++.h>
using namespace std;

// if a node is unsafe, terminate early so that it could never be marked as 
// safe(2).
class Solution {
    vector<int> col;
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int n = adj.size();
        col.assign(n,0);
        
        vector<int> ans;
        for(int i=0; i<n; ++i)
            if(is_safe(i, adj))
                ans.push_back(i);
    
        return ans;        
    }
    
    bool is_safe(int node, vector<vector<int>>& adj){
        if(col[node])
            return col[node]==2;
        col[node] = 1;
        for(auto ad: adj[node]){
            if(!col[ad] && !is_safe(ad, adj))
                return false;
            else if(col[ad]==1)
                return false;
        }
        col[node] = 2;
        return true;
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    return 0;
}