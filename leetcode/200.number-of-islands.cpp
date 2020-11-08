#include <bits/stdc++.h>
using namespace std;

class DSU{
	int n; 
	vector<int> par, rank;
public:
	DSU(int N){
		n = N;
		par.resize(n);
		for(int i=0; i<n; ++i)
			par[i] = i;
		rank.assign(n,0);
	}

	int find_par(int node){
		if(node==par[node]) return node;
		return par[node] = find_par(par[node]);
	}
		
	void unite(int a, int b){
		a = find_par(a);
		b = find_par(b);
		if(a==b) return;
		if(rank[a]<rank[b])
			swap(a,b);
		par[b] = a;
		if(rank[a]==rank[b])
			rank[a]++;	
	}	
};

class Solution {
	const vector<vector<int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}};
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(); if(!n) return 0;
		int m = grid[0].size(); if(!m) return 0;
		
		DSU ds(n*m);
		for(int i=0; i<n; ++i){
			for(int j=0; j<m; ++j){
				if(grid[i][j]=='1'){
					int id = i*m + j;
					for(auto &dir: dirs){
						int nx = i + dir[0], ny = j + dir[1];
						if(nx<0 || nx>=n || ny<0 || ny>=m || grid[nx][ny]!='1') continue;
						int adj_id = nx*m + ny;
						ds.unite(id, adj_id); 
					}									
				}
			}	
		}
		
		int comps = 0;
		for(int i=0; i<n; ++i){
			for(int j=0; j<m; ++j){
				if(grid[i][j]=='1'){
					int id = i*m + j;
					if(ds.find_par(id)==id)
						++comps;
				}
			}		
		}
		
		return comps;
    }
};


// DFS + BFS
class Solution0 {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(); if(!n) return 0;
		int m = grid[0].size(); if(!m) return 0;
		
		int comps = 0;
		
		// for(int i=0; i<n; ++i){
		// 	for(int j=0; j<m; ++j){
		// 		if(grid[i][j]=='1'){
		// 			dfs(i,j,grid,n,m);
		// 			++comps;
		// 		}	
		// 	}
		// }		

		for(int i=0; i<n; ++i){
			for(int j=0; j<m; ++j){
				if(grid[i][j]=='1'){
					++comps;
					queue<pair<int,int>> q;
					grid[i][j] = '2';
					q.push({i,j});
					
					while(!q.empty()){
						auto [x,y] = q.front(); q.pop();

						if(x+1<n && grid[x+1][y]=='1'){
							grid[x+1][y] = '2';
							q.push({x+1,y});
						}	
						
						if(y+1<m && grid[x][y+1]=='1'){
							grid[x][y+1] = '2';
							q.push({x,y+1});
						}	
						
						if(x-1>=0 && grid[x-1][y]=='1'){
							grid[x-1][y] = '2';
							q.push({x-1,y});
						}	
						
						if(y-1>=0 && grid[x][y-1]=='1'){
							grid[x][y-1] = '2';
							q.push({x,y-1});
						}			
					}					
				}	
			}
		}
		
		for(int i=0; i<n; ++i){
			for(int j=0; j<m; ++j){
				if(grid[i][j]=='2')
					grid[i][j] = '1';
			}
		}	

		return comps;
    }

	void dfs(int x, int y, vector<vector<char>> &grid, int &n, int &m){
		if(x<0 || x>=n || y<0 || y>=m || grid[x][y]!='1') return;
		grid[x][y] = '2'; // mark as visited

		dfs(x+1,y,grid,n,m);
		dfs(x,y+1,grid,n,m);
		dfs(x-1,y,grid,n,m);
		dfs(x,y-1,grid,n,m);
	}
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    return 0;
}