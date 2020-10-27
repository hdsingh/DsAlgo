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
template <typename T> ostream& operator<<(ostream &os, const vector<T> &v){print(v); return os;};
template <typename T> ostream& operator<<(ostream &os, const vector<vector<T>> &vv){print_vv(vv); return os;};
template <class T, class U> ostream& operator<<(ostream &os, const map<T,U>  &m){print_m(m); return os;};
template <class T, class U> ostream& operator<<(ostream &os, const pair<T, U> &pr){debp(pr); return os;};
template <class T, class U> ostream& operator<<(ostream &os, const vector<pair<T, U>> &vp){ print_vp(vp); return os;};

int LG;// = log2(nax)+1;
int n, Q, R;
int timer;
vector<vector<pii>> adj; // {w,x}
vvi parent; // par[i][j] is 2^i th par of j
vi level, tin, tout;
vl dp;

void dfs(int node, int par, int lvl, ll sum){
    tin[node] = ++timer;
    parent[0][node] = par;
    level[node] = lvl;
    dp[node] = sum;
    for(auto adp: adj[node]){
        // auto [ad,wt] = adp;
        int ad = adp.first, wt = adp.second;
        if(ad==par) continue;
        dfs(ad, node, lvl+1, sum+wt);
    }
    tout[node] = ++timer;
}

void init(){
    dfs(R,0,0,0); 
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

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        cin>>n>>Q>>R;
        LG = log2(n+1)+1;
        timer = 0;
        adj.assign(n+1,{}); // {v,w}
        parent.assign(LG, vi(n+1));
        level.assign(n+1,0); tin.assign(n+1,0), tout.assign(n+1,0);
        dp.assign(n+1,0);

        forn(i,n-1){
            int x, y, w; cin>>x>>y>>w;
            adj[x].pb({y,w});
            adj[y].pb({x,w});
        }
        init();

        while(Q--){
            int x, y; cin>>x>>y;
            // I want level[x]<level[y]

            if(level[x]>level[y]) 
                swap(x,y);
            if(is_ancestor(x,y)){
                ll ans = dp[y] - dp[x];
                cout<<ans<<"\n";
            }else{
                int lc = lca(x,y);
                ll ans = dp[x] + dp[y] - 2*dp[lc];
                cout<<ans<<"\n"; 
            }
        }
    }
    return 0;
}