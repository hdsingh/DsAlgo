// Source: https://cp-algorithms.com/graph/topological-sort.html
// https://www.geeksforgeeks.org/topological-sorting/

#include <bits/stdc++.h>
using namespace std;

class Graph{
    int n; // total vertices
    vector<list<int>> adj; //adjacency list of graph
    vector<bool> visited; // store if vertex has been visited
    vector<int> ans; //result , being used as a stack here
    void dfs(int v);
public:
    Graph(int n);
    void addEdge(int v, int w); 
    void topologicalSort();
};

// Constructor
Graph::Graph(int n){
    this->n = n;
    adj.resize(n);
}

// Add edge in adjacency list
void Graph::addEdge(int v, int w){
    adj[v].push_back(w); // Add w to v’s list. 
}

// After all the adjacent vertices that have not been visited initially,
// have been visited, push the main vertex to the stack 
void Graph::dfs(int v){
    visited[v] = true;
    for(int u: adj[v]){
        if(!visited[u])
            dfs(u);
    }
    ans.push_back(v);
}

void Graph::topologicalSort(){
    visited.assign(n, false);
    ans.clear();

    for(int i=0; i<n; i++){
        if(!visited[i])
            dfs(i);
    }
    
    // since ans is being used as stack, pop out from stack
    reverse(ans.begin(), ans.end());
    for(int a: ans) cout<<a<<" ";
}

int main(){
    Graph g(6);
    g.addEdge(5, 2); 
    g.addEdge(5, 0); 
    g.addEdge(4, 0); 
    g.addEdge(4, 1); 
    g.addEdge(2, 3); 
    g.addEdge(3, 1);

    g.topologicalSort();
    return 0;
}

// Topological sorting for Directed Acyclic Graph (DAG) 
// is a linear ordering of vertices such that for every 
// directed edge uv, vertex u comes before v in the ordering. 
// Topological Sorting for a graph is not possible if the graph 
// is not a DAG.