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

const int nax = 1e5+10;
vvi adj(nax);
vi leafs;
vi deg(nax), dist(nax);
int n,a,b, root;
int has_leaf_attached = 0;
bool odd = false, even = false;

void dfs(int x, int p, int d){
    dist[x] = d;
    bool has = 0;
    if(deg[x]==1){
        if(dist[x]&1) odd = true;
        else even = true;
    }

    for(auto ad: adj[x]){
        if(deg[ad]==1) has = 1;

        if(ad==p) continue;
        dfs(ad,x,d+1);
    }
    if(has) ++has_leaf_attached;
}

// min will be either 1 or 3
// If the distance bw all nodes is even then 1 else 3
// 1. In order to validate min=1, instead of comparing dist bw nodes
// check if parity of distance from each node to root is same
// ans = e - l + m
// edges - leafs + edges having atleast one leaf attached
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;


    forn(i,n-1){
        cin>>a>>b;
        adj[a].pb(b), adj[b].pb(a);
        deg[a]++; deg[b]++;
    }    


    fore(i,1,n+1)
        if(deg[i]==1) leafs.pb(i);
    assert((int)leafs.size());

    // set any leaf as root
    root = leafs.front();
    
    dfs(1,-1,0);
    // if parity differs
    int mn = (odd && even) ? 3 : 1;
    
    // edges - leafs - has_atleast_1_leaf_attached
    int edges = n-1;
    int l  = leafs.size();
    int mx = edges - l + has_leaf_attached;

    cout<<mn<<" "<<mx<<endl;

    return 0;
}