// Refer: https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/
#include <bits/stdc++.h>
using namespace std;

// Number of vertices in the graph 
#define V 9 

void printDist(int dist[]){
    cout<<"Edge\tDistance\n";
    for(int i=0; i<V; i++){
        cout<<i<<" \t "<<dist[i]<<endl;
    }
}

// A utility function to find the vertex with  
// minimum Distance value, from the set of vertices  
// not yet included in MST
int minDistance(int dist[], bool visited[]){
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
void dijkstra(int graph[V][V], int src){

    // To save minmimum Distance of an egde
    int dist[V];

    // To record vertices which have been included
    bool visited[V];

    // Initialize all Distance as infinite
    for(int i=0; i<V; i++){
        dist[i]=INT_MAX; visited[i]=false;
    }

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

int main(){

    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } }; 
  
    dijkstra(graph, 0); 


    return 0;   
}