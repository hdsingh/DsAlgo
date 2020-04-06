// Topological sorting for Directed Acyclic Graph (DAG) 
// is a linear ordering of vertices such that for every 
// directed edge uv, vertex u comes before v in the ordering. 
// Topological Sorting for a graph is not possible if the graph 
// is not a DAG.

#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<bool> vb;

// Better methods
// 1. DFS+Coloring + Cycle detection (CF 770C)
// 2. Kahns Algo : BFS + Cycle Detection(LC 207)

// Simple method
int n; // number of vertices
vvi adj;
vi ans;
vb visited;

void dfs(int v){
    visited[v] = true;
    for(int to: adj[v])
        if(!visited[to])
            dfs(to);

    ans.push_back(v);
}

void topologicalSort(){
    visited.assign(n, false);
    ans.clear();

    forn(i,n)
        if(!visited[i])
            dfs(i);
    
    reverse(all(ans));
}

int main(){
    n = 6;
    adj.resize(n);
    vvi edges = {{5,2},{5,0},{4,0},{4,1},{2,3},{3,1}};
    for(auto e: edges)
        adj[e[0]].push_back(e[1]);
    
    topologicalSort();
    
    for(auto x: ans) cout<<x<<" "; cout<<endl;

    return 0;
}
