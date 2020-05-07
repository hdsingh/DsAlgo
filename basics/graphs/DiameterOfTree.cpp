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

template <typename T>void print(const T &v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<sz(v); i++)cout<<setw(w)<<i<<" ";cout<<endl;}for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(w)<<*i<<" ";cout<<endl;}
template <typename T>void print_vv(const T &v){if(sz(v)==0) {cout<<"Empty"<<endl; return;} int w = 3;cout<<setw(w)<<" ";for(int j=0; j<sz(v[0]); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<sz(v); i++){cout<<i<<" {";for(auto j = 0; j!=sz(v[i]); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}
template <class T, class U> void print_m(const map<T,U> &m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}


int n,u,v;
const int nax = 2e5+10;
vvi adj(nax);
vi parent(nax);

// {dist, far}
pii dfs(int x, int par, int dist){
    parent[x] = par;
    pii res = {dist, x};
    for(auto ad: adj[x]){
        if(ad==par) continue;
        res = max(res, dfs(ad, x, dist+1));
    }
    return res;
}

// Start from any node and find the farthest node (far1);
// start from far1 and find the farthest far2, the ends of dimater's path
int main(){
    cin>>n;
    forn(i,n-1){
        cin>>u>>v;
        adj[u].pb(v), adj[v].pb(u);
    }

    // {dist, far}
    pii far1 = dfs(1,-1,0);
    pii far2 = dfs(far1.second,-1,0);

    // deb2(far1.second, far2.second);
    vi dia;
    int v = far2.second;
    while(v!=far1.second){
        dia.push_back(v);
        v = parent[v];
    }
    dia.push_back(far1.second);
    print(dia);
    
    int dia_sz = sz(dia)-1;
    deb(dia_sz);


    return 0;
}

// Usage:
// https://codeforces.com/contest/1294/problem/F

// Try:
// 8
// 1 2
// 2 3
// 3 4
// 4 5
// 4 6
// 3 7
// 3 8
// Ans: 
//  1  2  3  4  6 
// dia_sz 4
