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

vvi graph;
vi weight;
vi dp; // for the 0th node, 
vi ans;

void dfs1(int v, int p=-1){
    dp[v] = weight[v];
    for(auto to: graph[v]){
        if(to==p) continue;
        dfs1(to, v);
        dp[v]+= max(0, dp[to]);
    }
}

// Max has been used here to avoid adding any negative weight from the subtree acc to q

void dfs2(int v, int p=-1){
    ans[v] = dp[v];
    for(auto to: graph[v]){
        if(to==p) continue;
        // reroot
        // aim: make v a child of to. (as of now v is parent of to)

        // since the cur node v has content from its child to,
        // so remove it
        dp[v] -= max(0,dp[to]);
        // if to wants to be a parent, it must have contents from its child v
        dp[to]+= max(0, dp[v]);

        dfs2(to, v);

        // reverse
        dp[to]-= max(0,dp[v]);
        dp[v]+= max(0,dp[to]); 
    }
}

// Tree Dp: Re-rooting Technique
int main(){
    int n;
    while(cin>>n){
        graph.clear(); graph.resize(n);
        weight.clear(); weight.resize(n);
        dp.clear(), dp.resize(n);
        ans.clear(), ans.resize(n);

        int c;
        forn(i,n){
            cin>>c;
            weight[i] = c==1 ? 1 : -1;
        }

        int u,v;
        forn(i,n-1){
            cin>>u>>v;
            --u,--v;
            graph[u].pb(v); graph[v].pb(u);
        }

        dfs1(0);
        dfs2(0);

        for(auto x: ans){
            cout<<x<<" ";
        }
        cout<<endl;
    }

    return 0;
}