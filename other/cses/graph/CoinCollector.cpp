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

const int nax = 1e5;
int n,m; 
vi indeg(nax), ord, comp_id(nax);
vvi adj(nax), radj(nax);
vb vis(nax);
vl compsum, dp, ks(nax);
vector<set<int>> nadj, nradj; // SCC graph
int id = 0;

void dfs(int node){
    vis[node] = 1;
    for(auto ad: adj[node]){
        if(!vis[ad])
            dfs(ad);
    }
    ord.pb(node);
}

void dfs2(int node){
    vis[node] = 1;
    comp_id[node] = id;
    for(auto ad: radj[node]){
        if(!vis[ad])
            dfs2(ad);
    }
}

void dfs3(int node){
    vis[node] = 1;
    for(auto ad: nadj[node]){
        if(!vis[ad])
            dfs3(ad);
    }
    ord.pb(node);
}

void solve(int node){
    if(dp[node]) return;
    for(auto ad: nadj[node]){
        solve(ad);
        max_self(dp[node], dp[ad]);
    }   
    dp[node]+=compsum[node];
}

// Idea: Find and label all the SCCs, since in a SCC we can move freely anywhere.
// Treat all the nodes of a SCC as a single node and find the sum of a SCC.
// Create a new graph (this will be a DAG).
// To calu
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    fore(i,1,n+1) cin>>ks[i];
    forn(i,m){
        int a, b; cin>>a>>b;
        adj[a].pb(b);
        radj[b].pb(a);
    }

    fore(i,1,n+1)
        if(!vis[i])
            dfs(i);
    vis.assign(n+1,0);
    reverse(all(ord));
    for(auto x: ord){
        if(!vis[x]){
            ++id;
            dfs2(x);
        }
    }

    compsum.resize(id+1);
    nadj.resize(id+1);
    nradj.resize(id+1);
    dp.resize(id+1);

    fore(i,1,n+1) compsum[comp_id[i]]+=ks[i];

    fore(i,1,n+1){
        for(auto ad: adj[i]){
            int a = comp_id[i], b = comp_id[ad];
            if(a==b) continue;
            nadj[a].insert(b);
            nradj[b].insert(a);
        }
    }
    // print_vv(nadj);
    ord.clear();
    vis.assign(id+1,0);
    // deb(id);
    // fore(i,1,n+1) cout<<comp_id[i]<<" ";
    // cout<<"\n";

    // dp represent max sum that can be obtained by starting at that node
    // Approach 1: Do topsort and calculate dp, according to the order in which nodes will
    // be visited 
    
    // fore(i,1,id+1)
    //     if(!vis[i])
    //         dfs3(i);
    
    // reverse(all(ord));
    // // print(ord);

    // for(auto node: ord){
    //     for(auto ad: nradj[node]){
    //         max_self(dp[node], dp[ad]);
    //     }
    //     dp[node]+=compsum[node];
    // }

    // Approach 2: A simple dfs
    fore(i,1,id+1)  
        if(!dp[i])
            solve(i);
            

    ll ans = *max_element(all(dp));
    cout<<ans<<"\n";

    return 0;
}