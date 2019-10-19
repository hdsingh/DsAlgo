#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x <<  " " << x << endl;

enum Color{WHITE, GRAY, BLACK};

class Graph{
    int V;
    list<int>* adj; //adjacency lists
    bool DFSUtil(int v, int color[]);
public:
    Graph(int V); // constructor
    void addEdge(int v, int w);
    bool isCyclic();
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}

// returns true if cycle exists
bool Graph::DFSUtil(int u, int color[]){
    color[u] = GRAY;

    for(int i: adj[u]){
        if(color[i]==BLACK) continue; //already processed

        if(color[i]==GRAY) return true; //being processed, results in cycle

        if(color[i]==WHITE)
            if(DFSUtil(i, color)) return true;
    }

    color[u] = BLACK;
    return false; 
}

bool Graph::isCyclic(){
    // initialize all vertices as white
    int *color = new int[V];
    for(int i=0; i<V; i++)
        color[i] = WHITE;
    
    // Do DFS traversal beginning with all vertices
    for(int i=0; i<V; i++){
        if(color[i]==WHITE){
            if(DFSUtil(i, color)) //if cycle exists
                return true;
        }
    }

    return false;
};

int main(){
    Graph g(4);
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    // g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    // g.addEdge(3, 3); 
  
    if (g.isCyclic()) 
        cout << "Graph contains cycle"<<endl; 
    else
        cout << "Graph doesn't contain cycle"<<endl; 
  
    return 0; 
}