// Source : https://www.geeksforgeeks.org/detect-cycle-undirected-graph/
#include<iostream> 
#include <list> 
#include <limits.h> 
using namespace std; 

// Class for an undirected graph 
class Graph 
{ 
    int V;    // No. of vertices 
    list<int> *adj;    // Pointer to an array containing adjacency lists 
    bool isCyclicUtil(int v, bool visited[], int parent); 
public: 
    Graph(int V);   // Constructor 
    void addEdge(int v, int w);   // to add an edge to graph 
    bool isCyclic();   // returns true if there is a cycle 
}; 

Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
  
void Graph::addEdge(int v, int w) 
{ 
    adj[v].push_back(w); // Add w to v’s list. 
    adj[w].push_back(v); // Add v to w’s list. 
}

// for each vertex, check its adj vertices
// if any of them has been visited return true 
// else visit its that adj vertices and perform same check
bool Graph::isCyclicUtil(int v, bool visited[], int parent) {
    visited[v] = true;
    
    for(int adj_v: adj[v]){
        if(adj_v==parent) continue;
        else if (visited[adj_v])
        {
            return true;
        }
        else{
            return isCyclicUtil(adj_v, visited, v);
        }
    }
}

bool Graph::isCyclic(){
    bool *visited = new bool[V];
    for(int i=0; i<V; i++) visited[i]=false;

    // for each of the vertex, if its not visited check its adj vertices
    for(int u=0; u<V; u++){
        if(!visited[u])
            if(isCyclicUtil(u, visited, -1))
                return true;
    }
    return false;
}

int main() 
{ 
    Graph g1(5); 
    g1.addEdge(1, 0); 
    g1.addEdge(0, 2); 
    g1.addEdge(2, 1); 
    g1.addEdge(0, 3); 
    g1.addEdge(3, 4); 
    g1.isCyclic()? cout << "Graph contains cycle\n": 
                   cout << "Graph doesn't contain cycle\n"; 
  
    Graph g2(3); 
    g2.addEdge(0, 1); 
    g2.addEdge(1, 2); 
    g2.isCyclic()? cout << "Graph contains cycle\n": 
                   cout << "Graph doesn't contain cycle\n"; 
  
    return 0; 
}