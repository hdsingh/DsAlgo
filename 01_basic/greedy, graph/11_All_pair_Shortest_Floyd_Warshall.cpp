#include <bits/stdc++.h>
using namespace std;

#define V 4
#define INF 99999

void floydWarshall(int dist[][V]){
    for(int k=0; k<V; k++){
        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                if (dist[i][k] < INF && dist[k][j] < INF) // to check negative weights
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            if(dist[i][j] == INF)
                cout<<"INF"<<"   ";
            else
                cout<<dist[i][j]<<"     "; 
        }
        cout<<endl;
    }
}

int main(){
    int graph[V][V] = { {0, 5, INF, 10},  
                        {INF, 0, 3, INF},  
                        {INF, INF, 0, 1},  
                        {INF, INF, INF, 0}  
                    };  

    floydWarshall(graph); 
    return 0;
}