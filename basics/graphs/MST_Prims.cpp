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

// Time Complexity of Prims: O(E+ V log V)
// Time Complexity of Kruskal: O(E log E + E)
// Hence Kruskal takes more time on dense graphs.
// Prim's algorithm (more efficient on dense graphs) 
// Kruskal's algorithm (more efficient on sparse graphs)

const int inf = 1e9;
vector<vector<pii>> adj;

void primMST(vi &dist, vi &par){
    int n = adj.size();
    dist.assign(n, inf);

    vb vis(n);
    par[0] = -1;
    dist[0] = 0;

    // Can also use pq, however set is faster
    set<pii> q;
    q.insert({0,0});

    forn(i,n){
        auto [d, node] = *q.begin();
        q.erase(*q.begin());
       
        vis[node] = true;

        for(auto adp: adj[node]){
            auto [wt, ad] = adp;

            if(vis[ad]) continue;

            if(wt < dist[ad]){
                q.erase({dist[ad], ad});
                dist[ad] = wt;
                q.insert({dist[ad], ad});
                par[ad] = node;
            }
        }
    }
}

int main(){
    
    return 0;
}

// https://codeforces.com/problemset/problem/1245/D