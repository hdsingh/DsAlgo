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
typedef pair<ll, ll> pll;

int n, m;
const int nax = 1e5+10;
// int nax = 6;
const ll inf = 1e18l;
vector<vector<pll>> adj(nax);
vb vis(nax);
vl dist(nax,inf);
vi paths(nax), mn_nodes(nax, nax), mx_nodes(nax);

// If we are able to find new lesser distance for a to vertex,
// then use the values of par (reset)
// else if the distance remains same(the min possible till now)
// add_paths, minmise and maximise nodes. (update)
void dijkstra(int src){
    dist[src] = mx_nodes[src] = mn_nodes[src] =  0; 
    paths[src] = 1; 
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, src});

    while(sz(pq)){
        auto [d, node] = pq.top(); pq.pop();
        vis[node] = 1;
        if(d>dist[node]) continue;

        for(auto ad: adj[node]){
            auto [w, to] = ad;
            if(vis[to]) continue;

            if(dist[to]>dist[node] + w){
                dist[to] = dist[node] + w;
                pq.push({dist[to], to});
                paths[to] = paths[node];
                mn_nodes[to] = mn_nodes[node] + 1;
                mx_nodes[to] = mx_nodes[node] + 1;
            }else if(dist[to]==dist[node] + w){
                add_self(paths[to], paths[node]);
                min_self(mn_nodes[to], mn_nodes[node] + 1);
                max_self(mx_nodes[to], mx_nodes[node] + 1);
            }
        }
        if(node==n) break;
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    forn(i,m){
        int x, y, w; cin>>x>>y>>w;
        adj[x].pb({w,y});
    }
    dijkstra(1);

    cout<<dist[n]<<" "<<paths[n]<<" "<<mn_nodes[n]<<" "<<mx_nodes[n]<<"\n";
    
    return 0;
}