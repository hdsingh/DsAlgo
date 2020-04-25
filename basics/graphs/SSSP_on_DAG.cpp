// Single Source Shortest Path on Directed Acyclic Graph
// Refer: https://www.geeksforgeeks.org/shortest-path-for-directed-acyclic-graphs/

// Following is complete algorithm for finding shortest distances.
// 1) Initialize dist[] = {INF, INF, ….} and dist[s] = 0 where s is the source vertex.
// 2) Create a toplogical order of all vertices.
// 3) Do following for every vertex u in topological order.
// ………..Do following for every adjacent vertex v of u
// ………………if (dist[v] > dist[u] + weight(u, v))
// ………………………dist[v] = dist[u] + weight(u, v)

#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
typedef vector<bool> vb;

template <typename T>void print(T v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<v.size(); i++)cout<<setw(w)<<i<<" ";cout<<endl;}for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(w)<<*i<<" ";cout<<endl;}


#define to first
#define weight second
const int inf = 1e7;

int n; 
vector<vector<pii>> adj;
vi dist;
vi ans;
vb visited;

void dfs(int v){
    visited[v] = true;
    for(auto e: adj[v])
        if(!visited[e.to])
            dfs(e.to);

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

void ssp_in_dag(int src){
    topologicalSort(); // stores TopSort order in ans
    // print(ans);

    dist.resize(n,inf);
    
    dist[src] = 0;

    for(auto u: ans)
        for(auto e: adj[u])
            dist[e.to] = min(dist[e.to], dist[u] + e.weight);

}

int main(){
    n = 7;
    vvi info = {
      // u, v, w 
        {0, 1, 3},
        {0, 2, 2},
        {0, 5, 3},
        {1, 3, 1},
        {1, 2, 6},
        {2, 3, 1},
        {2, 4, 10},
        {3, 4, 5},
        {5, 4, 7}
    };


    adj.resize(n); 
    for(auto e: info)
        adj[e[0]].push_back({e[1],e[2]});

    int src = 0;
    ssp_in_dag(src);

    // Toporder:  6  0  5  1  2  3  4 

    // Dist :     0  3  2  3  8  3 inf 

    print(dist,1);
    
    return 0;
}
