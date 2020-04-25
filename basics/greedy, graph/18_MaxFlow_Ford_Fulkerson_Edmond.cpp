#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

bool bfs(vvi &graph, int s, int t, vi &parent){
    int n = graph.size();
    vector<bool> visited(n, false);

    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while(!q.empty()){
        int u = q.front(); q.pop();

        for(int v=0; v<n; v++){
            if(!visited[v] && graph[u][v]>0){
                q.push(v);
                visited[v]=true;
                parent[v]=u;
            }
        }
    }

    // If we reached sink in BFS starting from source, then return 
	// true, else false 
    return visited[t];
}

int fordFulkerson(vvi &graph, int s, int t){
    int n = graph.size();
    int u, v;

    // Create a residual graph and fill the residual graph with 
	// given capacities in the original graph as residual capacities 
	// in residual graph 
    vvi rGraph = graph;
    vi parent(n, -1);
    int max_flow = 0;

    // Augment/Check the flow while there is path from source to sink 
    while(bfs(rGraph, s, t, parent)){

        int path_flow = INT_MAX;

		// Find minimum residual capacity of the edges along the 
		// path filled by BFS. Or we can say find the maximum flow 
		// through the path found.
        for(v=t; v!=s; v--){
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }

        // update residual capacities of the edges and reverse edges 
		// along the path 
        for(v=t; v!=s; v=parent[v]){
            u = parent[v];
            rGraph[u][v] -=path_flow;
            rGraph[v][u] +=path_flow;
        }

        // Add path flow to overall flow 
        max_flow += path_flow;
    }

    return max_flow;
}

int main(){
    vvi graph = {   {0, 16, 13, 0, 0, 0}, 
                    {0, 0, 10, 12, 0, 0}, 
                    {0, 4, 0, 0, 14, 0}, 
                    {0, 0, 9, 0, 0, 20}, 
                    {0, 0, 0, 7, 0, 4}, 
                    {0, 0, 0, 0, 0, 0} 
                };
    cout<<fordFulkerson(graph, 0, 5)<<endl;                         
    return 0;
}
