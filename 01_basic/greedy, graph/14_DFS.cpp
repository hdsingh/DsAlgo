// Source: https://cp-algorithms.com/graph/depth-first-search.html
#include <bits/stdc++.h>
using namespace std;

class Graph{
    int n; // total vertices
    vector<list<int>> adj; //adjacency list of graph
    vector<bool> visited; // store if vertex has been visited
public:
    void dfs(int v);
    Graph(int n);
    void addEdge(int v, int w); 
};

// Constructor
Graph::Graph(int n){
    this->n = n;
    adj.resize(n);
    visited.assign(n, false);
}

// Add edge in adjacency list
void Graph::addEdge(int v, int w){
    adj[v].push_back(w); // Add w to v’s list. 
}


void Graph::dfs(int v){
    visited[v] = true;
    cout<<v<<" ";
    for(int u: adj[v]){
        if(!visited[u])
            dfs(u);
    }
}

int main(){
    Graph g(6);
    g.addEdge(5, 2); 
    g.addEdge(5, 0); 
    g.addEdge(4, 0); 
    g.addEdge(4, 1); 
    g.addEdge(2, 3); 
    g.addEdge(3, 1);

    g.dfs(5);
    return 0;
}