// https://www.geeksforgeeks.org/longest-path-undirected-tree/
#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x <<  " " << x << endl;
#define fo(i,n) for(int i=0;i<n;i++)
#define rep(i, a, b) for (int i = int(a); i <=int(b); i++)
#define all(x) x.begin(), x.end()
typedef std::vector<int> vi;
typedef std::vector<vector<int>> vvi;
typedef std::vector<string> vs;
typedef std::vector<bool> vb;
typedef std::pair<int, int> pii;
const int inf = 1e9;

template <typename T>
void print(T v){
    for(auto i= v.begin(); i!=v.end(); i++)
        cout<<*i<<" ";
    cout<<endl; 
}

class Solution {
public:
    int treeDiameter(vector<vector<int>>& edges) {
        int V = edges.size()+1;
        if(V-1==0) return 0;
        vvi adj(V);
        for(auto e: edges){
            // undirected
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        // Do dfs for two times
        // 1. find the end point: bfs first time gives the end point
        // 2. do bfs once again starting from this point to get starting point
        auto p1 = bfs(edges[0][0], V, adj);
        auto p2 = bfs(p1.first,V, adj);

        return p2.second;
    }

    // returns farthest node and its distance from u;
    pair<int,int> bfs(int u, int V, vvi &adj){
        // Mark all nodes as unvisited having dist -1 from u
        vi dist(V, -1);

        queue<int> q;
        // visit u
        dist[u] = 0;
        q.push(u);

        while(!q.empty()){
            u = q.front();
            q.pop();

            for(int v: adj[u]){
                if(dist[v]==-1){
                    dist[v] = dist[u]+1;
                    q.push(v);
                }
            }
        }

        // Find the max distance
        int max_d = *max_element(dist.begin(), dist.end());
        int max_node = max_element(dist.begin(), dist.end()) - dist.begin();

        return {max_node, max_d};
    }
};

int main(){
    Solution s;
    vvi edges = {{0,1},{1,2},{2,3},{1,4},{4,5}};
    cout<<s.treeDiameter(edges)<<endl;

    edges = {{0,1},{0,2}};
    cout<<s.treeDiameter(edges)<<endl;

    edges = {};
    cout<<s.treeDiameter(edges)<<endl;

    return 0;
}