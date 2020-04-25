#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define pb push_back
#define deb(x) cout<<#x<<" "<<x<<endl;
#define deb2(x, y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define deb3(x, y, z) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int, int> pii;
const int mod = 1e9 + 7;
template<class T, class U> inline void add_self(T &a, U b){a += b;if (a >= mod) a -= mod;if (a < 0) a += mod;}
template<class T, class U> inline void min_self(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void max_self(T &x, U y) { if (y > x) x = y; }

template <typename T>void print(T v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<v.size(); i++)cout<<setw(w)<<i<<" ";cout<<endl;}for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(w)<<*i<<" ";cout<<endl;}
template <typename T>void print_vv(T v){if(v.size()==0) {cout<<"Empty"<<endl; return;} int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}
template <class T, class U> void print_m(map<T,U> m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}

class Solution {
    int n,m,N,M;
    vvi grid;
    vvi dirs = {{0,1},{0,-1},{1,0},{-1,0}};
    unordered_map<int, vvi> turns = {
            {1, {{1,0},{1,2}}},
            {2, {{0,1},{2,1}}},
            {3, {{1,0},{2,1}}},
            {4, {{2,1},{1,2}}},
            {5, {{1,0},{0,1}}},
            {6, {{0,1},{1,2}}}
        };
public:
    bool hasValidPath(vector<vector<int>>& G) {
        N = G.size(), M = G[0].size();

        n = 3*N, m = 3*M;
        
        grid.clear();
        grid.resize(n, vi(m));
        for(int i=0; i<N; ++i){
            for(int j=0; j<M; ++j){
                mark(3*i, 3*j, G[i][j]);
            }
        }



        queue<pii> q;
        for(int i=0; i<3; ++i)
            for(int j=0; j<3; ++j){
                if(grid[i][j]==1){
                    grid[i][j]=2;
                    q.push({i,j});
                }
            }

        while(q.size()){
            int breadth  = q.size();
            for(int i=0; i<breadth; ++i){
                int x = q.front().first, y = q.front().second;
                q.pop();
                if(x/3==N-1 && y/3==M-1) return true;
                for(auto &dir: dirs){
                    int nx = x+dir[0];
                    int ny = y+dir[1];
                    if(is_valid(nx,ny)){
                        grid[nx][ny] = 2;
                        q.push({nx,ny});
                    }
                }
            }
        }

        return false;

    }

    bool is_valid(int x, int y){
        return (x>=0 && x<n && y>=0 && y<m && grid[x][y]==1);
    }
    
    void mark(int x, int y, int dir){
        grid[x+1][y+1] = 1;

        for(auto turn: turns[dir])
            grid[x+turn[0]][y+turn[1]] = 1;
    }
};

int main(){
    Solution sol; bool out;
    vector<vvi> grids = {
        {{2,4,3},{6,5,2}},

        {{1,2,1},{1,2,1}},

        {{1,1,2}},

        {{1,1,1,1,1,1,3}},

         {{2},{2},{2},{2},{2},{2},{6}},

         {{4,1},{6,1}},
    };

    for(auto grid: grids)
        out = sol.hasValidPath(grid), deb(out);

    return 0;
}