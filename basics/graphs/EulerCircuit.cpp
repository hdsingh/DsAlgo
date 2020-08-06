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

#define x first
#define y second

template<int SZ, bool directed> struct Euler{
    int N, M; 
    // adj[from] : {to, edge_id}
    // used[i]: if ith edge has been used
    vector<pii> adj[SZ], circuit;
    int out[SZ], in[SZ], deg[SZ];
    bool used[SZ], bad;

    void clr(){
        forn(i,N) adj[i].clear();
        circuit.clear();
        forn(i,N) out[i] = in[i] = deg[i] = 0;
        forn(i,M) used[i] = 0;
        N = M = bad = 0;
    }

    void addEdge(int a, int b){
        if(directed){
            adj[a].pb({b, M});
            out[a]++, in[b]++;
        }else{
            adj[a].pb({b,M}), adj[b].pb({a,M});
            deg[a]++, deg[b]++;
        }
        M++;
    }

    void dfs(int pre, int cur){
        while(sz(adj[cur])){
            pii ad = adj[cur].back(); adj[cur].pop_back();
            if(used[ad.y]) continue; // edge has already been traversed
            used[ad.y] = 1;
            dfs(cur, ad.x);
        }
        if(sz(circuit) && circuit.back().x != cur) bad = 1;
        circuit.pb({pre, cur}); // generate circuit in reverse order
    }

    vi solve(int n){
        N = n;
        // Find start
        int start = 1;
        fore(i,1,n+1) if(deg[i]&1) return {};
        dfs(-1, start);

        if(sz(circuit) != M+1 || bad) return {};
        vi ans;
        reverse(all(circuit));
        forn(i,sz(circuit)) ans.pb(circuit[i].y);
        return ans;
    }
};

int n, m;
const int nax = 2e5 + 10;

Euler<nax, 0> euler;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;

    forn(i,m){
        int a, b; cin>>a>>b;
        euler.addEdge(a, b);
    }
    auto circuit = euler.solve(n);
    if(!sz(circuit))
        cout<<"IMPOSSIBLE\n";
    else{
        print(circuit);
    }
    return 0;
}

// https://cses.fi/problemset/task/1691 (Mail Delivery)
// https://cses.fi/problemset/task/1693/ (Teleporters Paths)
