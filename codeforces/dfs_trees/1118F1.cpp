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

vi color, reds, blues;
vvi graph;
int good = 0;

// Re-rooting Technique
void dfs1(int node, int par = -1){
    for(auto ad: graph[node]){
        if(ad==par) continue;
        dfs1(ad, node);
        reds[node]+=reds[ad];
        blues[node]+=blues[ad];
    }
    if(color[node]==1) reds[node]++;
    else if(color[node]==2) blues[node]++;
}

void dfs2(int node, int par = -1){
    for(auto ad: graph[node]){
        if(ad==par) continue;
        reds[node]-=reds[ad]; blues[node]-=blues[ad];
        // find good since disconnected
        if((!reds[node] || !blues[node]) && (!reds[ad] || !blues[ad])) good++;

        reds[ad]+=reds[node]; blues[ad]+=blues[node];

        dfs2(ad, node);

        reds[ad]-=reds[node]; blues[ad]-=blues[node];
        reds[node]+=reds[ad]; blues[node]+=blues[ad];
    }
}

int main(){
    int n,x,y;
    while(cin>>n){
        good = 0;
        color.clear(), color.resize(n);
        graph.clear(), graph.resize(n);
        reds.clear(), reds.resize(n);
        blues.clear(), blues.resize(n);
        
        forn(i,n) cin>>color[i];

        forn(i,n-1){
            cin>>x>>y;
            --x,--y;
            graph[x].pb(y), graph[y].pb(x);
        }

        dfs1(0);
        // print(blues);
        // print(reds);
        // cout<<endl;

        dfs2(0);
        cout<<good<<endl;

    }
    return 0;
}