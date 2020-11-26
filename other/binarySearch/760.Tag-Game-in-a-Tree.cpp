#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(int st, vector<vector<int>> &adj){
    int n = adj.size();
    vector<int> dist(n,-1);
    queue<int> q;
    dist[st] = 0;
    q.push(st);
    
    while(!q.empty()){
        int top = q.front();
        q.pop();
        for(auto ad: adj[top]){
            if(~dist[ad]) continue;
            dist[ad] = dist[top] + 1;
            q.push(ad);
        }
    }
    
    return dist;
}

int solve(vector<vector<int>>& edges, int u, int v) {
    int n = edges.size()+1;
    vector<vector<int>> adj(n);
    for(auto ed: edges){
        int x = ed[0], y = ed[1];
        adj[x].push_back(y); adj[y].push_back(x);
    }
    vector<int> d1 = bfs(u, adj); // me
    vector<int> d2 = bfs(v, adj); // opp
   
    int ans = d1[v] + d1[v]-1;
    for(int i=0; i<n; ++i){
        if(d1[i]-d2[i]>1)
            ans = max(d1[i]+d1[i]-1, ans);
    }
    
    return ans;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    return 0;
}