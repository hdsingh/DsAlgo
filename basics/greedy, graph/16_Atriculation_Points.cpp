// Refer: https://www.geeksforgeeks.org/articulation-points-or-cut-vertices-in-a-graph/
#include <bits/stdc++.h>
using namespace std;

#define NIL -1

class Graph{
    int V;
    vector<list<int>> adj;
    void APUtil(int u, int &time, vector<bool> &visited, vector<int> &disc_time, vector<int> &low_time, vector<int> &parent, vector<bool> &ap);
public:
    Graph(int V);
    void addEdge(int v, int w);
    void AP();
};

Graph::Graph(int V){
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int v, int w){
    // The graph is unidirected
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void Graph::APUtil(int u, int &time, vector<bool> &visited, vector<int> &disc_time, vector<int> &low_time, vector<int> &parent, vector<bool> &ap){
    int children = 0;
    visited[u] = true;

    disc_time[u] = low_time[u] = time++;

    // If v is not visited yet, then make it a child of u 
	// in DFS tree and recur for it 
    for(int v: adj[u]){
        if(!visited[v]){
            children++;
            parent[v] = u;
            APUtil(v, time, visited, disc_time, low_time, parent, ap);

            // Low time: minimum of low_time of all the ajdjacent vertices,
            low_time[u] = min(low_time[u], low_time[v]);

            // u is an articulation point in following cases 
			// (1) u is root of DFS tree and has two or more chilren. 
            if(parent[u]==NIL && children>=2)
                ap[u] = true;

			// (2) If u is not root and low value of one of its child is more 
			// than discovery value of u.
            if(parent[u]!=NIL && low_time[v] >= disc_time[u])
                ap[u] = true;

        }
        // Update low value of u for parent function calls.
        else if (v != parent[u]){
            low_time[u] = min(low_time[u], disc_time[v]);
        }
    }
}

// A recursive function that find articulation points using DFS traversal 
// u --> The vertex to be visited next 
// visited[] --> keeps tract of visited vertices 
// disc[] --> Stores discovery times of visited vertices 
// parent[] --> Stores parent vertices in DFS tree 
// ap[] --> Store articulation points 
void Graph::AP(){
    vector<bool> visited(V, false);
    vector<int> disc_time(V, 0);
    vector<int> low_time(V, 0);
    vector<int> parent(V, NIL);
    vector<bool> ap(V, false);
    int time = 0;

    for(int i=0; i<V; i++){
        if(!visited[i])
            APUtil(i, time, visited, disc_time, low_time, parent, ap);
    }
    
    for(int i=0; i<V; i++){
        if(ap[i]) cout<<i<<" ";
    }
    cout<<endl;

}

int main(){
    cout << "\nArticulation points in first graph \n"; 
	Graph g1(5); 
	g1.addEdge(1, 0); 
	g1.addEdge(0, 2); 
	g1.addEdge(2, 1); 
	g1.addEdge(0, 3); 
	g1.addEdge(3, 4); 
	g1.AP(); 

	cout << "\nArticulation points in second graph \n"; 
	Graph g2(4); 
	g2.addEdge(0, 1); 
	g2.addEdge(1, 2); 
	g2.addEdge(2, 3); 
	g2.AP(); 

	cout << "\nArticulation points in third graph \n"; 
	Graph g3(7); 
	g3.addEdge(0, 1); 
	g3.addEdge(1, 2); 
	g3.addEdge(2, 0); 
	g3.addEdge(1, 3); 
	g3.addEdge(1, 4); 
	g3.addEdge(1, 6); 
	g3.addEdge(3, 5); 
	g3.addEdge(4, 5); 
	g3.AP(); 

	return 0; 
}

// Low time: minimum of visited time of all the ajdjacent vertices,
// Conditions for atriculation point
// 1. Root with 2 or more independent childern
// 2. Visited time <= low time of adjacent vertices