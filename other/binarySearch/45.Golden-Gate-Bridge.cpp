#include <bits/stdc++.h>
using namespace std;

// main idea:
// visit only the nodes of island1 and add it in q
// mark -1 as visited
// start a bfs from it and continue outwards till we find other island.

class Solution{
    int n, m;
    const vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
public:
    int solve(vector<vector<int>> &mat){
        n = mat.size(), m = mat[0].size();
        queue<pair<int,int>> q;
        bool processed1 = false;
        for(int i=0; i<n; ++i){
            if(processed1) break;
            for(int j=0; j<m; ++j){
                if(mat[i][j]==1){
                    dfs(i,j,mat, q);
                    processed1 = true;
                    break;
                }
            }
        }
        
        vector<vector<int>> dist(n, vector<int>(m));
        while(!q.empty()){
            auto [x, y] = q.front(); q.pop();
            for(auto dir: dirs){
                int nx = x + dir[0], ny = y + dir[1];
                if(nx<0 || nx>=n || ny<0 || ny>=m || mat[nx][ny]==-1 || dist[nx][ny]!=0)
                    continue;
                if(mat[nx][ny]==1){
                    return dist[x][y];
                }
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx,ny});
            }
        }
        return -1;
    }
    
    void dfs(int x, int y, vector<vector<int>> &mat, queue<pair<int,int>> &q){
        mat[x][y] = -1; // visited
        q.push({x,y});
        for(auto dir: dirs){
            int nx = x + dir[0], ny = y + dir[1];
            if(nx<0 || nx>=n || ny<0 || ny>=m || mat[nx][ny]!=1)
                continue;
            dfs(nx,ny,mat,q);
        }
    }
};

int solve(vector<vector<int>>& matrix) {
    Solution sol; return sol.solve(matrix);   
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    return 0;
}