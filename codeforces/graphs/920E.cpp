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

const int nax = 2e5+10;
int n,m,u,v;
vector<set<int>> adj(nax);
set<int> nodes;
int sz;

void dfs(int x){
    ++sz;
    nodes.erase(x);
    int next = 0;
    
    while(!nodes.empty()){
        auto it = nodes.upper_bound(next);
        if(it==nodes.end()) break;

        next = *it;
        if(adj[x].count(next)==0){ // means a path exists since complement
            dfs(next);
        }
    }
}

int main(){
    cin>>n>>m;
    forn(i,m){
        cin>>u>>v;
        adj[u].insert(v); adj[v].insert(u);
    }

    fore(i,1,n+1)
        nodes.insert(i);
    
    vi out; // list of sizes
    fore(i,1,n+1){
        // if it exists in set, delete it and all its connected components
        if(nodes.count(i)){
            sz = 0;
            dfs(i);
            out.pb(sz);
        }
    }

    sort(all(out));
    cout<<(int)out.size()<<endl;
    for(auto x: out) cout<<x<<" "; cout<<endl;

    return 0;
}