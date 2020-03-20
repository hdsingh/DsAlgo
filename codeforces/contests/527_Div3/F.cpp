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

template <typename T>void print(T v, bool show_index = false, int inc = 0){int w = 2;if(show_index){for(int i=0; i<v.size(); i++)cout<<setw(w)<<i+inc<<" ";cout<<endl;}for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(w)<<*i<<" ";cout<<endl;}
template <typename T>void print_vv(T v){if(v.size()==0) {cout<<"Empty"<<endl; return;} int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}
template <class T, class U> void print_m(map<T,U> m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}

int n;
vvi graph;
vi a;
vl sum;
ll res, ans;
// sum: sum of all values in a tree/subtree
// tot1: used in dfs1 wrt v, calculates correct answer for v
// tot2: final answer formed after rooting

void dfs1(int node, int depth = 0, int par = -1){
    res+=a[node]* 1ll * depth;
    sum[node]=a[node];

    for(auto ad: graph[node]){
        if(ad==par) continue;
        dfs1(ad, depth+1, node);
        sum[node]+=sum[ad];
    }
}

// each time depth increases by 1, the sum of values in subtree of child
// get incremented by sum of subtree
// Refer editorial for more details
void dfs2(int node, int par = -1){
    ans = max(res, ans);
    for(auto ad: graph[node]){
        if(ad==par) continue;

        res-=sum[ad];
        sum[node]-=sum[ad];
        res+=sum[node];
        sum[ad]+=sum[node];
        
        dfs2(ad,node);

        // reversing by maintaining the same order
        sum[ad]-=sum[node];
        res-=sum[node];
        sum[node]+=sum[ad];
        res+=sum[ad];
    }
}


int main(){
    while(cin>>n){
        graph.clear(); graph.resize(n);
        a.clear(); a.resize(n);        
        sum.clear(); sum.resize(n);
        res=0, ans =0;

        forn(i,n) cin>>a[i];

        int x,y;
        forn(i,n-1){
            cin>>x>>y;
            --x;--y;
            graph[x].pb(y); graph[y].pb(x);
        }

        dfs1(0);
        dfs2(0);

        cout<<ans<<endl;


    }

    return 0;
}