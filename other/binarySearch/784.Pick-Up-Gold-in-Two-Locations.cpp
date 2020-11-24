#include <bits/stdc++.h>
using namespace std;

typedef tuple<int,int,int> tii; // {cost, x, y}
const int inf = 1e8;
const vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
vector<vector<int>> dijkstra(int stX, int stY, vector<vector<int>> &mat){
    int n = mat.size(), m = mat[0].size();
    vector<vector<int>> dist(n, vector<int>(m, inf));
    vector<vector<bool>> vis(n, vector<bool>(m));
    dist[stX][stY] = mat[stX][stY];
    priority_queue<tii, vector<tii>, greater<tii>> pq;
    pq.push({mat[stX][stY],stX, stY});
    
    while(!pq.empty()){
        auto [cost, x, y] =  pq.top();
        pq.pop();
        vis[x][y] = 1;
        if(cost>dist[x][y]) continue;
        
        for(auto dir: dirs){
            int nx = x + dir[0], ny = y + dir[1];
            if(nx<0 || nx>=n || ny<0 || ny>=m || vis[nx][ny])
                continue;
            if(cost + mat[nx][ny]<dist[nx][ny]){
                dist[nx][ny] = cost + mat[nx][ny];
                pq.push({dist[nx][ny], nx, ny});
            }
        }
    }
    
    return dist;
}

int solve(vector<vector<int>>& mat, int row, int col, int erow0, int ecol0, int erow1, int ecol1) {
    int n = mat.size(); if(!n) return 0;
    int m = mat[0].size(); if(!m) return 0;
    
    vector<vector<int>> dist1 = dijkstra(row, col, mat);
    vector<vector<int>> dist2 = dijkstra(erow0, ecol0, mat);
    vector<vector<int>> dist3 = dijkstra(erow1, ecol1, mat);
    
    int ans = inf;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            int curCost = dist1[i][j] + dist2[i][j] + dist3[i][j];
            curCost-=2*mat[i][j];
            ans = min(ans, curCost);
        }
    }
    
    return ans;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    return 0;
}