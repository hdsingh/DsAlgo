// Source: https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/
#include <bits/stdc++.h>
using namespace std;

class Graph{
    int n; // total vertices
    vector<list<int>> adj; //adjacency list of graph
    vector<bool> visited; // store if vertex has been visited
public:
    void bfs(int v);
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


void Graph::bfs(int s){
    queue<int> q;

    visited[s] = true;
    q.push(s);

    while(!q.empty()){
        s = q.front();
        q.pop();
        cout<<s<<" ";

        for(int v: adj[s]){
            if(!visited[v]){
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int main(){
    Graph g(4); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3);

    g.bfs(2);
    return 0;
}