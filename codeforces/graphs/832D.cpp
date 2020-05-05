#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define pb push_back
#define deb(x) cout<<#x<<" "<<x<<endl;
#define deb2(x, y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define deb3(x, y, z) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
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

template <typename T>void print(T v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<v.size(); i++)cout<<setw(w)<<i<<" ";cout<<endl;}for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(w)<<*i<<" ";cout<<endl;}
template <typename T>void print_vv(T v){if(v.size()==0) {cout<<"Empty"<<endl; return;} int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}
template <class T, class U> void print_m(map<T,U> m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}


const int nax = 1e5+10;
int n;
vvi adj(nax);

int timer;
const int LG = log2(nax)+1;
vvi parent(LG, vi(nax+1)); // par[i][j] is 2^i th par of j
vi level(nax), tin(nax), tout(nax);

void dfs(int node, int par, int lvl){
    tin[node] = ++timer;
    parent[0][node] = par;
    level[node] = lvl;
    for(auto ad: adj[node]){
        if(ad==par) continue;
        dfs(ad, node, lvl+1);
    }
    tout[node] = ++timer;
}

void init(){
    dfs(1,0,0); 
    
    // precompute lca parent array
    for(int i=1; i<LG; ++i)
        for(int j=1; j<=n; ++j)
            if(parent[i-1][j])
                parent[i][j] = parent[i-1][parent[i-1][j]];
}

int lca(int u, int v){
    // u to be deeper
    if(level[u]<level[v])
        swap(u,v);
    
    int dif = level[u] - level[v];
    // move it up by dif, using its bin representation
    for(int i=LG-1; i>=0; --i)
        if((dif>>i) & 1)
            u = parent[i][u];
    
    // now both u and v are same level
    if(u==v) return u;

    // check what is the max height that we can move up, such that par's are different
    for(int i=LG-1; i>=0; --i){
        if(parent[i][u] && parent[i][u]!=parent[i][v]){
            u = parent[i][u];
            v = parent[i][v];
        }
    }

    return parent[0][u];
}

// move u above by h
int walk(int u, int h){
    for(int i=LG-1; i>=0; --i)
        if((h>>i) & 1)
            u = parent[i][u];
    return u;
}

int dist(int u, int v){
    return level[u] + level[v] - 2*level[lca(u,v)];
}

bool is_ancestor(int u, int v){
    return tin[u]<=tin[v] && tout[u]>=tout[v];
}

ll calc(int s, int f, int t) {
	return (dist(s,f)+dist(t,f)-dist(s,t)+1)/2;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int p,a,b,c,q;
    cin>>n>>q;
    fore(i,2,n+1){
        cin>>p;
        adj[p].pb(i); adj[i].pb(p);
    }

    init();

    while(q--){
        cin>>a>>b>>c;
        vvi ops = {{a,b,c},{b,a,c},{a,c,b}};
        ll mx = 0;
        for(auto op: ops){
            mx =  max(mx, calc(op[0],op[1],op[2]));
        }
        cout<<mx+1<<endl;
    }

    return 0;
}