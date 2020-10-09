#include <bits/stdc++.h>
using namespace std;

typedef tuple<int,int,int> tii; // {val, x,y}
const vector<vector<int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}};

class Solution {
    int mx, ans, n,m;
    priority_queue<tii, vector<tii>, greater<tii>> pq;
    vector<vector<int>> a, vis;
public:
    int trapRainWater(vector<vector<int>>& a) {
        n = a.size(), m = a[0].size();
        this->a = a;
        ans = 0;
        if(m==1 ||  n==1) return 0; 
        vis.assign(n, vector<int>(m,0));
        
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(i==0 || j==0 || i==n-1 || j==m-1){
                    pq.push({a[i][j], i, j});
                    vis[i][j] = 1;
                }
            }
        }
        
        while(pq.size()){
            auto [val, x, y] = pq.top(); pq.pop();
            mx = val;
            for(auto dir: dirs){
                int nx = x + dir[0], ny = y + dir[1];
                dfs(nx,ny);
            }
        }
        
        return ans;
    }
    
    void dfs(int x, int y){
        if(x<0 || x>=n || y<0 || y>=m || vis[x][y]) return;
        vis[x][y] = 1;
        if(a[x][y]<mx){
            ans+=(mx - a[x][y]);
            for(auto dir: dirs){
                int nx = x+ dir[0], ny = y + dir[1];
                dfs(nx,ny);
            }
        }else{
            pq.push({a[x][y], x,y});
        }
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    return 0;
}