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

int n,m,k,w;
const int nax = 1010;
vector<string> lev(nax);
vector<pair<int,pii>> edges; // wt, from to
vi par(nax);
vvi adj(nax);

int diff(int x, int y){
    int cost = 0;
    forn(i, (int)lev[x].size())
        cost+= (lev[x][i]!=lev[y][i]);
    return cost;
}

int find(int v){
    if(v==par[v]) return v;
    return par[v] = find(par[v]);
}

void unite(int u, int v){
    u = find(u); v = find(v);
    if(u!=v){
        par[u] = v;
    }
}

void dfs(int x, int p = -1){
    for(auto ad: adj[x]){
        if(ad==p) continue;
        cout<<ad<<" "<<x<<endl;
        dfs(ad,x);
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k>>w;
    fore(i,1,k+1){
        forn(j,n){
            string s; cin>>s;
            lev[i]+=s;
        }
    }

    fore(i,1,k+1){
        edges.push_back({n*m,{0,i}});
        fore(j,i+1,k+1){
            int cost = diff(i,j)*w;
            edges.push_back({cost, {i,j}});
        }
    }
    int tot = 0;
    sort(all(edges));
    iota(all(par),0); // make set
    for(auto &e: edges){
        int cost = e.first;
        int u = e.second.first;
        int v = e.second.second;
        if(find(u)!=find(v)){
            unite(u,v);
            tot+=cost;
            adj[u].push_back(v), adj[v].push_back(u);
        }
    }
    cout<<tot<<endl;
    dfs(0);

    return 0;
}