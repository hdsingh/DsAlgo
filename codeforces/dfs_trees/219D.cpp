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

int n;
const int nax = 2e5+10;
// int nax = 6;
vector<vector<pii>> adj(nax);
vi dp(nax);
vvi ans(nax);

void dfs1(int x, int p){
    for(auto ad: adj[x]){
        if(ad.first==p) continue;
        dfs1(ad.first,x);
        dp[x]+=dp[ad.first] + !(ad.second);
    }
}

void dfs2(int x, int p){
    ans[dp[x]].pb(x);
    // deb(x,dp[x]);
    for(auto ad: adj[x]){
        int child = ad.first, starts_x = ad.second;
        if(child==p) continue;

        dp[x]-=(dp[child]+!starts_x);
        dp[child]+=(dp[x] + starts_x);

        dfs2(child,x);

        dp[child]-=(dp[x] + starts_x);
        dp[x]+=(dp[child]+!starts_x);
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;    
    int u,v;
    forn(i,n-1){
        cin>>u>>v;
        adj[u].pb({v,1}), adj[v].pb({u,0});
    }
    dfs1(1,0);
    // print(dp,1);

    dfs2(1,0);
    
    forn(i,nax){
        if(sz(ans[i])){
            cout<<i<<"\n";
            sort(all(ans[i]));
            print(ans[i]);
            break;
        }
    }

    return 0;
}