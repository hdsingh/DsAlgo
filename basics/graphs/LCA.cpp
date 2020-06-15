#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout<<#x<<" "<<x<<endl;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

const int nax = 100;
int n;
vvi adj(nax);

int timer;
const int LG = log2(nax)+1;
vvi parent(LG, vi(nax+1)); // par[i][j] is 2^i th par of j
vi level(nax), tin(nax), tout(nax);

void dfs(int node, int par, int lvl){
    tin[node] = ++timer;
    parent[0][node] = par;
    level[node] = lvl;
    for(auto ad: adj[node]){
        if(ad==par) continue;
        dfs(ad, node, lvl+1);
    }
    tout[node] = ++timer;
}

void init(){
    dfs(1,0,0); 
    
    // precompute lca parent array
    for(int i=1; i<LG; ++i)
        for(int j=1; j<=n; ++j)
            if(parent[i-1][j])
                parent[i][j] = parent[i-1][parent[i-1][j]];
}

int lca(int u, int v){
    // u to be deeper
    if(level[u]<level[v])
        swap(u,v);
    
    int dif = level[u] - level[v];
    // move it up by dif, using its bin representation
    for(int i=LG-1; i>=0; --i)
        if((dif>>i) & 1)
            u = parent[i][u];
    
    // now both u and v are same level
    if(u==v) return u;

    // check what is the max height that we can move up, such that par's are different
    for(int i=LG-1; i>=0; --i){
        if(parent[i][u] && parent[i][u]!=parent[i][v]){
            u = parent[i][u];
            v = parent[i][v];
        }
    }

    return parent[0][u];
}

// move u above by h
int walk(int u, int h){
    for(int i=LG-1; i>=0; --i)
        if((h>>i) & 1)
            u = parent[i][u];
    return u;
}

int dist(int u, int v){
    return level[u] + level[v] - 2*level[lca(u,v)];
}

bool is_ancestor(int u, int v){
    return tin[u]<=tin[v] && tout[u]>=tout[v];
}

int main(){
    vvi edges = {{1,2},{1,4},{2,3},{4,5},{4,6}};
    for(auto e: edges)
        adj[e[0]].push_back(e[1]), adj[e[1]].push_back(e[0]);

    init();
    deb(dist(5,4));
    return 0;
}

// https://leetcode.com/problems/kth-ancestor-of-a-tree-node/