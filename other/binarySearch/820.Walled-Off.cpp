#include <bits/stdc++.h>
using namespace std;

const vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};

class Solution{
public:
    int solve(vector<vector<int>> &mat){
        if(!canReachEnd(mat)) return 0;
        int n = mat.size(); if(!n) return 0;
        int m = mat[0].size(); if(!m) return 0;
        vector<vector<int>> adj(n*m);
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(mat[i][j]) continue;
                for(auto dir: dirs){
                    int ni = i + dir[0], nj = j + dir[1];
                    if(ni<0 || ni>=n || nj<0 || nj>=m || mat[ni][nj])
                        continue;
                    adj[i*m+j].push_back(ni*m+nj);
                }
            }
        }
        
        int N = n*m; 
        vector<int> tin(N), low(N);
        vector<bool> vis(N);
        vector<int> articulate;
        int T = 0;
        dfs(0,-1, adj, tin, low, vis,articulate, T);

        for(auto pt: articulate){
            int x = pt/m , y = pt%m;
            mat[x][y] = 1;
        }    

        return canReachEnd(mat) ? 2 : 1;
    }
    
    void dfs(int node, int par, vector<vector<int>> &adj, vector<int> &tin, 
    vector<int> &low, vector<bool> &vis, vector<int> &articulate, int &T){
        low[node] = tin[node] = T++;
        vis[node] = 1;
        int child = 0;
        for(auto ad: adj[node]){
            if(ad==par) continue;
            if(vis[ad]){
                // back edge
                low[node] = min(low[node], tin[ad]);
            }else{
                dfs(ad,node,adj,tin,low,vis,articulate,T);
                low[node] = min(low[node], low[ad]);
                
                if(low[ad]>=tin[node] && par!=-1){
                    articulate.push_back(node);
                }
            }
        }
        
        if(par==-1 && child>1){
            articulate.push_back(node);
        }
    }
    
    
    bool canReachEnd(vector<vector<int>> &mat){
        int n = mat.size(), m = mat[0].size();
        queue<pair<int,int>> q;
        vector<vector<bool>> vis(n, vector<bool>(m));
        vis[0][0] = 1;
        q.push({0,0});
        
        while(!q.empty()){
            auto [x,y] = q.front(); q.pop();
            for(auto dir: dirs){
                int nx = x + dir[0], ny = y + dir[1];
                if(nx<0 || nx>=n || ny<0 || ny>=m || vis[nx][ny] || mat[nx][ny])
                    continue;
                if(nx==n-1 && ny==m-1) return true;
                vis[nx][ny] = 1;
                q.push({nx,ny});
            }
        }
        return false;
    }
};

int solve(vector<vector<int>>& matrix) {
    Solution sol; return sol.solve(matrix);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    return 0;
}