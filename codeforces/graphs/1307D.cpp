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
const int nax = 2e5 + 10;
vi spl;
vvi adj(nax), dist(2, vi(nax));
int n,m,k,u,v;

void bfs(vi &dis, int src){
    fill(all(dis),inf);
    dis[src] = 0;
    vi q; q.pb(src);

    while(!q.empty()){
        vi nq;
        for(auto cur: q){
            for(auto ad: adj[cur])
                if(dis[ad]==inf){
                    dis[ad] = dis[cur] + 1;
                    nq.pb(ad);
                }
        }
        swap(q,nq);
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    forn(i,k){
        cin>>u; --u;
        spl.pb(u);
    }    
    sort(all(spl));

    forn(i,m){
        cin>>u>>v;
        --u,--v;
        adj[u].pb(v), adj[v].pb(u);
    }

    bfs(dist[0],0);
    bfs(dist[1],n-1);

    vector<pii> data;
    for(auto x: spl){
        data.pb({dist[0][x] -dist[1][x], x});
    }
    sort(all(data));
    int best = 0;
    int mx = -inf;
    for(auto p: data){
        int a = p.second;
        best = max(best, mx + dist[1][a]);
        mx = max(mx, dist[0][a]);
    }

    cout<<min(dist[0][n-1], best + 1)<<endl;

    return 0;
}