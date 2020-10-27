#include <bits/stdc++.h>
using namespace std;

class Solution {
    int n;
    int mx_dist;
    vector<vector<int>> adj;
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        this->n = n;
        adj.assign(n,{});
        for(auto ed: edges){
            adj[ed[0]-1].push_back(ed[1]-1);
            adj[ed[1]-1].push_back(ed[0]-1);
        }
        
        vector<int> ans(n-1);
        for(int mask=0; mask<(1<<n); ++mask){
            int dist = count(mask);
            if(dist>0)
                ans[dist-1]++;
        }
        return ans;
    }
    
    // check if the given subset is connected and find max dist
    int count(int mask){
        int root = -1;
        if(__builtin_popcount(mask)<=1) 
            return 0;
        
        for(int i=0; i<n; ++i){
            if((mask>>i)&1){
                root = i;
                break;
            }
        }
    
        mx_dist = 0;
        find_dist(root, mask);
        if(mask!=0) return 0; // check all nodes are visited
        return mx_dist;
    }
    
    int find_dist(int root, int &mask){
        mask&= ~(1<<root); // visited
        int d1 = 0, d2 = 0;
        for(auto ad: adj[root]){
            if((mask>>ad)&1){
                int cur = 1 + find_dist(ad,mask);
                if(cur>d1){
                    d2 = d1;
                    d1 = cur;
                }else if(cur>d2){
                    d2 = cur;
                }
            }
        }
        mx_dist = max({d1+d2,mx_dist});
        return max(d1,d2);
    }
};


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    return 0;
}