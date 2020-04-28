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

int n,m,u,v;
const int nax = 1e5+10;
vvi adj(nax);
vi in(nax), low(nax), vis(nax);
int timer;
bool has_bridge;
vvi out;

void dfs(int x, int par){
    vis[x] = 1;
    in[x] = low[x] = timer++;

    for(auto ad: adj[x]){
        if(ad==par) continue;
        if(vis[ad]){    // back  edge
            low[x] = min(low[x], in[ad]);
            // need only from cur(x) to ancestor(ad)
            if(in[x] > in[ad])
                out.push_back({x,ad});
        }else{ // forward edge
            dfs(ad,x);
            if(low[ad]>in[x]){
                has_bridge = true;
                return;
            }
            low[x] = min(low[x], low[ad]);
            out.push_back({x,ad});
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    forn(i,m){
        cin>>u>>v;
        adj[u].pb(v), adj[v].pb(u);
    }

    dfs(1,-1);

    if(has_bridge){
        cout<<0<<endl;
    }else{
        for(auto x: out)
            cout<<x[0]<<" "<<x[1]<<endl;
    }

    return 0;
}