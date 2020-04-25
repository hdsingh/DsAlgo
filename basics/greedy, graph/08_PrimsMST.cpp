// Source: https://www.geeksforgeeks.org/prims-minimum-spanning-tree-mst-greedy-algo-5/
#include <bits/stdc++.h>
using namespace std;

#define V 5

void printMST(int parent[], int graph[V][V]){
    cout<<"Edge\tWeight\n";
    for(int i=1; i<V; i++){
        cout<<parent[i]<<" - "<<i<<"\t  "<<graph[i][parent[i]]<<endl;
    }
}

// A utility function to find the vertex with  
// minimum weight value, from the set of vertices  
// not yet included in MST
int minweight(int weight[], bool visited[]){
    int min = INT_MAX, min_index;

    for(int v=0; v<V; v++){
        if(visited[v]==false && weight[v]<min){
            min = weight[v]; min_index=v;
        }
    }
    return min_index;
}

// repeat for V times, each time find a vertex with 
// min weight and perform reduction over all its adjacent edges
void primMst(int graph[V][V]){

    // To store constructed MST
    int parent[V];

    // To save minmimum weight of an egde
    int weight[V];

    // To record vertices which have been included
    bool visited[V];

    // Initialize all weight as infinite
    for(int i=0; i<V; i++){
        weight[i]=INT_MAX; visited[i]=false;
    }

    // initialize starting vertex with weigth 0
    weight[0]=0;
    // root has no parent
    parent[0]=-1;

    // The MST will have V vertices
    for(int count=0; count<V; count++){
        
        // Find the index of vertex with minimum weight
        // from the vertices not yet included
        int u = minweight(weight, visited);
        // add the picked vertex
        visited[u] = true;

        // update weight of its adjacent vertices
        // and set their parent as this min vertex
        for(int v=0; v<V; v++){
            // if not yet included and non 0 (adjacent vertices)
            // graph[u][v] is non zero only for adjacent vertices
            if(visited[v] == false && graph[u][v] && graph[u][v]<weight[v]){
                weight[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }
    printMST(parent, graph);
}

//         2   3  
//     (0)--(1)--(2)  
//     |    / \   |  
//    6|  8/   \5 |7  
//     |  /     \ |  
//     (3)-------(4)  
//             9

int main(){
    int graph[V][V] = { { 0, 2, 0, 6, 0 },  
                        { 2, 0, 3, 8, 5 },  
                        { 0, 3, 0, 0, 7 },  
                        { 6, 8, 0, 0, 9 },  
                        { 0, 5, 7, 9, 0 } };
    
    primMst(graph);

    return 0;   
}