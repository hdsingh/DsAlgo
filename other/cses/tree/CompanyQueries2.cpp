#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define pb push_back
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

#define _deb(x) cout<<x;
void _print() {cerr << "]\n";} template <typename T, typename... V>void _print(T t, V... v) {_deb(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#define deb(x...) cerr << "[" << #x << "] = ["; _print(x)
template <class T, class U> void print_m(const map<T,U> &m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}
template<class T, class U>void debp(const pair<T, U> &pr, bool end_line=1){cout<<"{"<<pr.first<<" "<<pr.second<<"}"; cout<<(end_line ? "\n" : ", ");}
template <class T> void print_vp(const T &vp, int sep_line=0){if(vp.empty()){cout<<"Empty"<<endl; return;}if(!sep_line) cout<<"{ ";for(auto x: vp) debp(x,sep_line);if(!sep_line) cout<<"}\n";cout<<endl;}
template <typename T>void print(const T &v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<sz(v); i++)cout<<setw(w)<<i<<" ";cout<<endl;}for(auto &el: v) cout<<setw(w)<<el<<" ";cout<<endl;}
template <typename T>void print_vv(const T &vv){if(sz(vv)==0) {cout<<"Empty"<<endl; return;} int w = 3;cout<<setw(w)<<" ";for(int j=0; j<sz(*vv.begin()); j++)cout<<setw(w)<<j<<" ";cout<<endl;int i = 0;for(auto &v: vv){cout<<i++<<" {";for(auto &el: v) cout<<setw(w)<<el<<" ";cout<<"},\n";}cout<<endl;}

const int maxlg = 20;
const int nax = 2e5+10;
vvi dp(maxlg, vi(nax)); // 2^i th ancestor of node j
int n, m;
vvi adj(nax);
vi lev(nax), tin(nax), tout(nax);
int T;

void dfs(int x, int p, int l){
    tin[x] = T++;
    dp[0][x] = p;
    lev[x] = l;
    for(auto ad: adj[x]){
        if(ad==p) continue;
        dfs(ad, x,l+1);
    }
    tout[x] = T++;
}

void precalc(){
    for(int i=1; i<maxlg; ++i){
        fore(j,1,n+1){
            if(dp[i-1][j])
                dp[i][j] = dp[i-1][dp[i-1][j]];
        }
    }
}

bool is_ancestor(int x, int y){
    return (tin[x]<=tin[y] && tout[y]<=tout[x]);
}

int walk(int x, int k){
    for(int i=maxlg-1; i>=0; --i){
        if((k>>i)&1){
            x = dp[i][x];
        }
    }
    if(x==0) return -1;
    return x;
}

int lca(int x, int y){
    if(lev[x]>lev[y]) swap(x,y);
    if(is_ancestor(x,y)) return x;
    int dif = lev[y] - lev[x];
    y = walk(y,dif);

    if(x==y) return x;

    for(int i=maxlg-1; i>=0; --i){
        if(dp[i][y] && dp[i][y]!=dp[i][x]){
            y = dp[i][y];
            x = dp[i][x];
        }
    }

    return dp[0][x];
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    fore(i,2,n+1){
        int p; cin>>p;
        adj[i].pb(p); adj[p].pb(i);
    }
    dfs(1,0,0);
    precalc();
    while(m--){
        int x, y; cin>>x>>y;
        cout<<lca(x,y)<<"\n";
    }
    return 0;
}