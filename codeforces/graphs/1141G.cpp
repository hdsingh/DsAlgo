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

const int nax = 2e5+10;
vector<vector<pii>> edges(nax);
vi col(nax);
int n, k, C,u,v;
map<int,int> deg;

void dfs(int x, int par, int pc){ // pc: prev color
    int color = 0;
    for(auto ed: edges[x]){
        if(ed.first==par) continue;
        if(color==pc){
            color = (color+1)%C;
        }
        col[ed.second] = color;
        dfs(ed.first,x,color);
        color = (color+1)%C;
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    forn(i,n-1){
        cin>>u>>v;
        edges[u].pb({v,i}); edges[v].push_back({u,i});
        deg[u]++; deg[v]++;
    }
    vi a;
    fore(i,1,n+1){
        a.pb(deg[i]);
    }
    sort(all(a));

    if(k>=n) C = 1;
    else{
        C = a[n-1-k];
    }
    
    dfs(1,-1,-1);

    cout<<C<<endl;
    forn(i,n-1)
        cout<<col[i]+1<<" ";
    cout<<endl;


    return 0;
}