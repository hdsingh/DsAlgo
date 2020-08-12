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

int n, m;
const int nax = 2e5+10;
const int logmax = 20;
vvi adj(nax), dp(logmax, vi(nax));
vi lev(nax), pre(nax);

void dfs(int x, int p, int l){
    lev[x] = l;
    dp[0][x] = p;
    for(auto ad: adj[x]){
        if(ad==p) continue;
        dfs(ad, x, l+1);
    }
}

void precalc(){
    fore(i,1,logmax)
        fore(j,1,n+1)
            if(dp[i-1][j])
                dp[i][j] = dp[i-1][dp[i-1][j]];
}

int walk(int x, int d){
    for(int i=logmax-1; i>=0; --i){
        if((d>>i)&1)
            x = dp[i][x];
    }
    return x;
}

int lca(int x, int y){
    if(lev[x]>lev[y]) swap(x,y);
    int dif = lev[y] - lev[x];

    y = walk(y,dif);

    if(x==y) return x;

    for(int i=logmax-1; i>=0; --i){
        if(dp[i][x] && dp[i][x]!=dp[i][y]){
            x = dp[i][x];
            y = dp[i][y];
        }
    }

    return dp[0][x];
}

void dfs2(int x, int p){
    for(auto ad: adj[x]){
        if(ad==p) continue;
        dfs2(ad, x);
        pre[x]+=pre[ad];
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    forn(i,n-1){
        int x, y; cin>>x>>y;
        adj[x].pb(y), adj[y].pb(x);
    }
    dfs(1,0,0);
    precalc();

    while(m--){
        int x, y; cin>>x>>y;
        pre[x]++;
        pre[y]++;
        int lc = lca(x, y);
        pre[lc]--;
        pre[dp[0][lc]]--;
    }
    dfs2(1,0);
    fore(i,1,n+1) cout<<pre[i]<<" ";
    return 0;
}