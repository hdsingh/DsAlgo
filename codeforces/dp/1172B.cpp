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
const int mod = 998244353;
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

void mul_self(ll &a, int b){
    a*=b;
    a%=mod;
}

int n;
int root = 1;
const int nax = 2e5+10;
vvi adj;
vl fact(nax);

void precalc(){
    fact[0] = 1;
    fore(i, 1, nax)
        fact[i] = fact[i-1] * i % mod;
}

ll dfs(int x, int p){
    int childs = sz(adj[x]);
    ll cf = fact[childs];
    for(auto ad: adj[x]){
        if(ad==p) continue;
        mul_self(cf, dfs(ad, x));
    }

    return cf;
}

// f[v]  = and for a node
// If a node has c child,
//  if it is a root(1): there are c! ways to choose pos for its children, (root is fixed)
//  if it is not a root: there are (c+1)! ways to choose pos (+1 since it is not fixed)
// # of children of root(1) = sz(adj[1])
// # of children of node + 1 =    sz(adj[node]) (+1 for parent)
// In the end we can make any node as root by ans*n

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    precalc();
    while(cin>>n){
        adj.clear(); adj.resize(nax);

        int u,v;
        forn(i,n-1){
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }

        ll ans = n*dfs(1,0);
        ans%=mod;

        cout<<ans<<endl;
    }
    return 0;
}