#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int src, dest, weight;
};

void printDist(vector<int> dist) 
{ 
    printf("Vertex   Distance from Source\n"); 
    for (int i = 0; i < dist.size(); ++i) 
        printf("%d \t\t %d\n", i, dist[i]); 
}

void BellmanFord(vector<Edge> edges, int V, int E, int src_vertex){
    // 1. initialize distance of all vertices from src_vertex as INF
    vector<int> dist(V, INT_MAX);
    dist[src_vertex] = 0;

    // 2. Relax all edges V-1 times;
    for(int times=0; times<V; times++){
        for(int j=0; j<E; j++){
            int u = edges[j].src;
            int v = edges[j].dest;
            int weight = edges[j].weight;
            if(dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }

    // Check cycle, if dist decreases even after V-1 times then
    // cycle exists
    for(int j=0; j<E; j++){
        int u = edges[j].src;
        int v = edges[j].dest;
        int weight = edges[j].weight;
        if(dist[u] + weight < dist[v]){
            cout<<"Contains a cycle"<<endl;
            return;
        }
    }
    
    printDist(dist);
}

int main(){
    vector<Edge> edges;
    int V = 5, E = 8, src_vertex = 0;

    edges = {{0,1,-1}, //edge 0
             {0,2,4},  //edge 1
             {1,2,3},
             {1,3,2},
             {1,4,2},
             {3,2,5},
             {3,1,1},
             {4,3,-3}};
    BellmanFord(edges, V, E, src_vertex);

}