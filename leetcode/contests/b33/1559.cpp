#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(a) int((a).size())
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

#define _deb(x) cout<<x;
void _print() {cerr << "]\n";} template <typename T, typename... V>void _print(T t, V... v) {_deb(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#define deb(x...) cerr << "[" << #x << "] = ["; _print(x)
template <class T, class U> void print_m(const map<T,U> &m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}
template<class T, class U>void debp(const pair<T, U> &pr, bool end_line=1){cout<<"{"<<pr.first<<" "<<pr.second<<"}"; cout<<(end_line ? "\n" : ", ");}
template <class T> void print_vp(const T &vp, int sep_line=0){if(vp.empty()){cout<<"Empty"<<endl; return;}if(!sep_line) cout<<"{ ";for(auto x: vp) debp(x,sep_line);if(!sep_line) cout<<"}\n";cout<<endl;}
template <typename T>void print(const T &v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<sz(v); i++)cout<<setw(w)<<i<<" ";cout<<endl;}for(auto &el: v) cout<<setw(w)<<el<<" ";cout<<endl;}
template <typename T>void print_vv(const T &vv){if(sz(vv)==0) {cout<<"Empty"<<endl; return;} int w = 3;cout<<setw(w)<<" ";for(int j=0; j<sz(*vv.begin()); j++)cout<<setw(w)<<j<<" ";cout<<endl;int i = 0;for(auto &v: vv){cout<<i++<<" {";for(auto &el: v) cout<<setw(w)<<el<<" ";cout<<"},\n";}cout<<endl;}

class Solution {
public:
    int n, m;
    vector<vector<char>> grid;
    vector<vector<bool>> vis;
    const vi N = {0,-1}, S = {0,1}, E = {1,0}, W = {-1,0};
    vvi dirs = {N,E, W, S};
    bool containsCycle(vector<vector<char>>& grid) {
        this->grid = grid;
        n = grid.size(), m = grid[0].size();
        vis.assign(n, vb(m,0));
    
        forn(i,n){
            forn(j,m){
                if(!vis[i][j]){
                    if(dfs(i,j,-1,-1))  
                        return true;
                }
            }
        }

        return false;
    }

    bool dfs(int x, int y, int px, int py){
        vis[x][y] = 1;
        for(auto dir: dirs){
            int nx = x + dir[0], ny = y + dir[1];
            if(nx==px && ny==py) continue;
            
            if(nx<0 || nx>=n || ny<0 || ny>=m || grid[nx][ny]!=grid[x][y]) continue;
            if(vis[nx][ny]) return 1;
            if(dfs(nx,ny, x,y)) return 1;
        }
        return 0;
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<vector<char>> grid; bool out;
    Solution sol;
    grid = {{'a','b','b'},{'b','z','b'},{'b','b','a'}};
    grid = {{'b'},{'b'}};
    // print_vv(grid);
    out = sol.containsCycle(grid); deb(out);
    // print_vv(sol.vis);
    
    return 0;
}