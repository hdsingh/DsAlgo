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

ll n,x,y, a,b;
vvi adj;
vi sz;
vb has_x_as_sub;

int dfs(int cur, int par){
    int cur_sz = 1;
    if(cur==x)
        has_x_as_sub[cur] = true;

    for(auto ad: adj[cur]){
        if(ad==par) continue;
        cur_sz+=dfs(ad, cur);
        has_x_as_sub[cur] = (has_x_as_sub[cur] | has_x_as_sub[ad]);
    }

    return sz[cur] = cur_sz;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    while(cin>>n>>x>>y){
        --x,--y;
        adj.clear(); adj.resize(n);
        sz.clear(); sz.resize(n);
        has_x_as_sub.clear(); has_x_as_sub.resize(n);

        forn(i,n-1){
            cin>>a>>b;
            --a, --b;
            adj[a].pb(b), adj[b].pb(a);
        }

        // print_vv(adj);
        // deb(y);
    
        dfs(y, -1);

        ll res = 1;
        
        ll z_sz = 0;
        for(auto ad: adj[y]){
            if(has_x_as_sub[ad]){
                z_sz = sz[y] - sz[ad];
                break;
            }
        }

        res = (n*(n-1)) - sz[x] * (z_sz);
    
        
        cout<<res<<endl;
    }    
    return 0;
}