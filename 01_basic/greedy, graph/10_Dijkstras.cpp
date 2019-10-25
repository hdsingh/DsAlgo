// Refer: https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/
#include <bits/stdc++.h>
using namespace std;

// Number of vertices in the graph 
#define V 9 

void printDist(vector<int> &dist){
    cout<<"Edge\tDistance\n";
    for(int i=0; i<V; i++){
        cout<<i<<" \t "<<dist[i]<<endl;
    }
}

// A utility function to find the vertex with  
// minimum Distance value, from the set of vertices  
// not yet included in MST
int minDistance(vector<int> &dist, vector<bool> &visited){
    int min = INT_MAX, min_index;

    for(int v=0; v<V; v++){
        if(!visited[v] && dist[v]<=min){
            min = dist[v]; min_index=v;
        }
    }
    return min_index;
}

// Dijkstra's single source shortest path - Greedy approach
// repeat for V times, each time find a vertex with 
// min Distance and perform reduction over all its adjacent edges
void dijkstra(vector<vector<int>> &graph, int src){

    // To save minmimum Distance of an egde
    vector<int> dist(V, INT_MAX);

    // To record vertices which have been included
    vector<bool> visited(V, false);

    // initialize starting vertex with weigth 0
    dist[src]=0;

    // The MST will have V vertices
    for(int count=0; count<V; count++){
        
        // Find the index of vertex with minimum Distance
        // from the vertices not yet included
        int u = minDistance(dist, visited);
        // add the picked vertex
        visited[u] = true;

        // update Distance of its adjacent vertices
        // and set their parent as this min vertex
        for(int v=0; v<V; v++){
            // if not visited and is non-0 (adjacent vertex)
            // then perform reduction
            // (graph[u][v] is non zero only for adjacent vertices)
            if(!visited[v] && graph[u][v] && dist[u] != INT_MAX
               && dist[u]+graph[u][v]<dist[v]){
                dist[v] = dist[u]+graph[u][v];
            }
        }
    }
    printDist(dist);
}

// Completely similar to prims
// Difference : Reduction is performed here, while only weight/dist
//              initialisation happens in prim

typedef pair<int, int> pii;
const int inf = 1e9;

int Dijkstra_for_adjList(vector<vector<int>>& edges, int n, int src) {
    // n starting from 1
    vector<vector<pii> >adj(n+1);
    // e : {u, v, w}
    for(auto &e: edges){
        adj[e[0]].push_back({e[1], e[2]});
    }
    
    vector<int> dist(n+1, inf);
    dist[src]=0;
    // use pq to get minimum weight node/vertex
    priority_queue<pii, vector<pii>, greater<pii>> pq; //weight, v
    pq.push({0, src});

    int u, v, w;
    vector<bool> visited(n+1, false);

    // explore aj vertices of u, and change their weight
    while(!pq.empty()){
        pii p = pq.top(); pq.pop();
        u = p.second;

        if(visited[u]) continue;

        for(auto to: adj[u]){
            v = to.first, w = to.second;
            if(dist[u]+w < dist[v]){
                dist[v] = dist[u]+w;
                pq.push({dist[v], v});
            }
        }

    }

    for(int i=1; i<=n; i++){
        cout<<i<<"  "<<dist[i]<<endl;
    }
}

int main(){

    vector<vector<int>> graph = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } }; 
  
    dijkstra(graph, 0); 
    cout<<endl;

    vector<vector<int>> edges = {{2,1,1}, {2,3,1}, {3,4,1}}; //{u, v, w}
    Dijkstra_for_adjList(edges, 4, 2);



    return 0;   
}