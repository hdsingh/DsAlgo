// Refer: https://www.geeksforgeeks.org/topological-sorting-indegree-based-solution/
// Refer: https://www.youtube.com/watch?v=tFpvX8T0-Pw

// same algo used for both topsort and cycle detection 
#include <bits/stdc++.h>
using namespace std;

// 1. Find indeg of all vertices
// 2. push into q all the vertices having indeg=0;
// 3. pop out the vertex from q and print it
// for all the adj vertices, dec indegree // this is like deteching the used vertex
// if indeg =0, push adj[v] in q
// if cnt != num of vertices, cycle is present
void kahns(int n, vector<vector<int>> edges){
    vector<vector<int>> adj(n);
    vector<int> indegree(n, 0);
    for(auto e: edges){
        adj[e[0]].push_back(e[1]);
        indegree[e[1]]++;
    }

    queue<int> q;
    for(int i=0; i<n; i++)
        if(indegree[i]==0)
            q.push(i);
    
    int cnt=0;
    while(!q.empty()){
        int u = q.front(); q.pop();
        cout<<u<<" ";

        for(int v: adj[u]){
            indegree[v]--;
            if(indegree[v]==0)
                q.push(v);
        }

        cnt++;
    }


    if(cnt!=n){
        cout<<"Cycle Found"<<endl;
        return;
    }
    cout<<endl;

}

int main(){
    vector<vector<int>> edges = {{5,2}, {5,0},
                         {4,0}, {4,1},
                         {2,3}, {3,1} };

    vector<int> out;
    kahns(6, edges);

    edges = {{0,1},{1,2},{2,0}};
    kahns(3, edges);


}