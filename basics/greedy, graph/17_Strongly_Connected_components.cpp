// Refer: https://www.geeksforgeeks.org/strongly-connected-components/
// Refer: https://www.youtube.com/watch?v=RpgcYiky7uw&list=PLrmLmBdmIlpu2f2g8ltqaaCZiq6GJvl1j
#include <bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    vector<list<int>> adj;
    void fillOrder(int v, vector<bool> &visited, stack<int> &s);
    void DFSUtil(int v, vector<bool> &visited);
public:
    Graph(int V);
    void addEdge(int v, int w);
    void printSCC();
    Graph getTranspose();    
};

Graph::Graph(int V){
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int v, int w){
    // The graph is directed
    adj[v].push_back(w);
}

void Graph::fillOrder(int v, vector<bool> &visited, stack<int> &s){
    visited[v] = true;

    // Recur for all the vertices adjacent to this vertex
    for(int i: adj[v]){
        if(!visited[i])
            fillOrder(i, visited, s);
    }

	// All vertices reachable from v are processed by now, push v 
    s.push(v);
}

void Graph::DFSUtil(int v, vector<bool> &visited){
    visited[v] = true;
    cout<<v<<" ";

    for(int i: adj[v])
        if(!visited[i])
            DFSUtil(i, visited);
}

Graph Graph::getTranspose(){
    Graph rev_g(V);

    for(int v=0; v<V; v++) // for all vertices
        for(int i: adj[v]) // for all vertices(i) adj to this vertex(v)
            rev_g.adj[i].push_back(v);
            //make edge i to v (earlier v to i)
    
    return rev_g;
}

void Graph::printSCC(){
    // init visited as false
    vector<bool> visited(V, false);
    stack<int> s;

    // fill vertices in order of finishing time
    for(int i=0; i<V; i++)
        if(!visited[i])
            fillOrder(i, visited, s);
    
    // reverse the edges bw vertices
    Graph rev_g = getTranspose();

    // set visited as false
    visited.assign(V, false);

	// Now process all vertices in order defined by Stack 
    while(!s.empty()){
        int v = s.top(); s.pop();

        // Print Strongly connected component of the popped vertex
        if(!visited[v]){
            rev_g.DFSUtil(v, visited);
            cout<<endl;
        }
    }
}


int main(){
    
    Graph g(5); 
	g.addEdge(1, 0); 
	g.addEdge(0, 2); 
	g.addEdge(2, 1); 
	g.addEdge(0, 3); 
	g.addEdge(3, 4); 

	cout << "Following are strongly connected components in "
			"given graph \n"; 
	g.printSCC(); 

    return 0;
}