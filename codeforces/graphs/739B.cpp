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
template <typename T> ostream& operator<<(ostream &os, const vector<T> &v){print(v); return os;};
template <typename T> ostream& operator<<(ostream &os, const vector<vector<T>> &vv){print_vv(vv); return os;};
template <class T, class U> ostream& operator<<(ostream &os, const map<T,U>  &m){print_m(m); return os;};
template <class T, class U> ostream& operator<<(ostream &os, const pair<T, U> &pr){debp(pr); return os;};
template <class T, class U> ostream& operator<<(ostream &os, const vector<pair<T, U>> &vp){ print_vp(vp); return os;};
typedef pair<ll,ll> pll;

const int nax = 2e5+10;
const int lg = log2(nax) + 1;
int n;
vl a, dist;
vl cnt;
vvl par; // ith par of jth node
vector<vector<pll>> adj; // {ad, wt}

void dfs1(int node, int p, ll d){
    par[0][node] = p;
    dist[node] = d;
    for(auto [ad, wt]: adj[node]){
        dfs1(ad,node, wt+d);
    }
}

void dfs2(int node){
    for(auto [ad, wt]: adj[node]){
        dfs2(ad);
        cnt[node]+=cnt[ad];
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    while(cin>>n){
        a.resize(n+1,0);
        adj.assign(n+1,{});
        par.assign(lg,vl(n+1));
        dist.assign(n+1,0);
        cnt.assign(n+1,0);

        fore(i,1,n+1) cin>>a[i];

        fore(i,2,n+1){
            int p, wt; cin>>p>>wt;
            adj[p].pb({i,wt});
        }

        dfs1(1,0,0);

        for(int i=1; i<lg; ++i){
            for(int node=1; node<=n; ++node){
                if(par[i-1][node])
                    par[i][node] = par[i-1][par[i-1][node]];
            }
        }

        for(int node=1; node<=n; ++node){
            int p = node;
            for(int j=lg-1; j>=0; --j){
                if(par[j][p] && dist[node] - dist[par[j][p]]<=a[node])
                    p = par[j][p];
            }
    
            cnt[par[0][node]]++;
            cnt[par[0][p]]--;
        }
        
        dfs2(1);

        fore(i,1,n+1) cout<<cnt[i]<<" ";
        cout<<"\n";
    }
    return 0;
}