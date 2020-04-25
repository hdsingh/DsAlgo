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

const int inf = 1e9;
vector<vector<pii>> adj;

void dijkstra(int src, int dest, vi &dist, vi &par){
    int n = adj.size();
    vb visited(n);
    dist.assign(n, inf);
    par.assign(n, -1);

    dist[src] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0,src});

    while(!q.empty()){
        int d = q.top().first;
        int v = q.top().second;
        q.pop();
        visited[v] = true;
        
        // We already found a better path before we got to
        // processing this node so we can ignore it.
        if(dist[v] < d) continue;

        for(auto edge: adj[v]){
            int to = edge.first;
            int len = edge.second;

            // You cannot get a shorter path by revisiting
            // a node you have already visited before.
            if(visited[to]) continue;

            if(dist[v] + len < dist[to]){
                dist[to] = dist[v] + len;
                par[to] = v;
                q.push({dist[to], to});
            }
        }

        // If we know the end, we can break when end is found
        if(v==dest) break;
    }

    if(!visited[dest]){
        cout<<-1<<endl; return;
    }

	vi path;
    for(int v = dest; v!=src; v = par[v])
        path.push_back(v);
    path.push_back(src);

    reverse(all(path));
    print(path);
}

int main(){
    
    return 0;
}