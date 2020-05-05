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

vi tail;
const int nax = 2e5+20;
vi a(nax), ans(nax);
vvi adj(nax);
int n,u,v;

// int LIS1(vi &a){
//     vi tail;
//     for(auto x: a){
//         auto it = lower_bound(all(tail), x);
//         if(it==tail.end())
//             tail.push_back(x);
//         else 
//             *it = x;
//     }
//     print(tail);
//     return tail.size();
// }

void dfs(int x, int par){
    int prev = -1;
    auto it = lower_bound(all(tail), a[x]);
    int idx = it - tail.begin();
    if(it==tail.end()){
        tail.push_back(a[x]);
    }
    else{
        prev = *it;
        *it = a[x];
    }

    ans[x] = (int)tail.size();

    for(auto ad: adj[x]){
        if(ad==par) continue;
        dfs(ad, x);
    }

    if(prev==-1)
        tail.pop_back();
    else{
        tail[idx] = prev;
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    fore(i,1,n+1)
        cin>>a[i];
    
    forn(i,n-1){
        cin>>u>>v;
        adj[u].pb(v), adj[v].pb(u);
    }

    dfs(1,-1);

    fore(i,1,n+1)
        cout<<ans[i]<<"\n";

    return 0;
}
