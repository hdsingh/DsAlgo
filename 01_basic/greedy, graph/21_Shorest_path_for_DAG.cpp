// Refer: https://www.geeksforgeeks.org/shortest-path-for-directed-acyclic-graphs/
// Refer: https://cp-algorithms.com/graph/topological-sort.html
// https://www.geeksforgeeks.org/topological-sorting/

#include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX 

// Graph is represented using adjacency list. Every node of adjacency list  
// contains vertex number of the vertex to which edge connects. It also  
// contains weight of the edge 
class AdjNode 
{ 
    int v; 
    int weight; 
public: 
    AdjNode(int _v, int _w)  { v = _v;  weight = _w;} 
    int getV()       {  return v;  } 
    int getWeight()  {  return weight; } 
}; 

class Graph{
    int n; // total vertices
    vector<list<AdjNode>> adj; //adjacency list of graph
    vector<bool> visited; // store if vertex has been visited
    vector<int> ans; //result , being used as a stack here
    void dfs(int v);
public:
    Graph(int n);
    void addEdge(int u, int v, int w); 
    void topologicalSort();
    void shortestPath(int s);
};

// Constructor
Graph::Graph(int n){
    this->n = n; //number of nodes
    adj.resize(n);
}

// Add edge in adjacency list
void Graph::addEdge(int u, int v, int w){
    AdjNode node(v, w);
    adj[u].push_back(node); // Add w to v’s list. 
}

// After all the adjacent vertices that have not been visited initially,
// have been visited, push the main vertex to the stack 
void Graph::dfs(int u){
    visited[u] = true;

    for(auto i = adj[u].begin(); i!=adj[u].end(); i++){
        int v = i->getV();
        if(!visited[v])
            dfs(v);
    }

    ans.push_back(u);
}

void Graph::topologicalSort(){
    visited.assign(n, false);
    ans.clear();

    for(int i=0; i<n; i++){
        if(!visited[i])
            dfs(i);
    }
    
    // since ans is being used as stack, pop out from stack
    // reverse(ans.begin(), ans.end());
    // for(int a: ans) cout<<a<<" ";
}

void Graph::shortestPath(int s){
    // get topologically sorted order of nodes
    topologicalSort();

    vector<int> dist(n, INF);
    dist[s] = 0;

    // Process vertices in topological order
    for(auto it = ans.rbegin(); it!=ans.rend(); it++){
        int u = *it;

        if(dist[u]!=INF){
            for(auto v_it = adj[u].begin(); v_it!=adj[u].end(); v_it++){
                int v = v_it->getV();
                int w = v_it->getWeight();
                if(dist[u] + w < dist[v])
                    dist[v] = dist[u] + w;
            }
        }
        
    }

    for(int i=0; i<n; i++){
        (dist[i] == INF)? cout << "INF ": cout << dist[i] << " "; 
    }
    cout<<endl;
}

// Following is complete algorithm for finding shortest distances.
// 1) Initialize dist[] = {INF, INF, ….} and dist[s] = 0 where s is the source vertex.
// 2) Create a toplogical order of all vertices.
// 3) Do following for every vertex u in topological order.
// ………..Do following for every adjacent vertex v of u
// ………………if (dist[v] > dist[u] + weight(u, v))
// ………………………dist[v] = dist[u] + weight(u, v)

int main(){
    Graph g(6); 
    g.addEdge(0, 1, 5); 
    g.addEdge(0, 2, 3); 
    g.addEdge(1, 3, 6); 
    g.addEdge(1, 2, 2); 
    g.addEdge(2, 4, 4); 
    g.addEdge(2, 5, 2); 
    g.addEdge(2, 3, 7); 
    g.addEdge(3, 4, -1); 
    g.addEdge(4, 5, -2); 
  
    int s = 1; 
    g.shortestPath(s);

    return 0;
}

// Topological sorting for Directed Acyclic Graph (DAG) 
// is a linear ordering of vertices such that for every 
// directed edge uv, vertex u comes before v in the ordering. 
// Topological Sorting for a graph is not possible if the graph 
// is not a DAG.