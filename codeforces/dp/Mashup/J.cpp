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


// Think in terms of creating a new node and combining each child with it.
ll dp[100010][3][11];
const int ls = 0, eq = 1, gr = 2;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, m;
    while(cin>>n>>m){
        vvi adj(n+1); 
        forn(i,n-1){
            int x, y; cin>>x>>y;
            adj[x].pb(y); adj[y].pb(x);
        }
        ll sec, most; cin>>sec>>most;
        memset(dp, 0, sizeof(dp));

        function<void(int,int)> dfs = [&](int node, int p){
            dp[node][eq][1] = 1; dp[node][ls][0] = (sec-1); dp[node][gr][0] = (m-sec);

            for(auto ad: adj[node]){
                if(ad==p) continue;
                dfs(ad,node);
                ll ndp[3][11] = {0};

                forn(ps,most+1){ // prev sum
                    forn(cs,most+1){ // cur sum
                        if(ps+cs>most) break;
                        ndp[ls][ps+cs] += dp[node][ls][ps] * ((dp[ad][ls][cs] + dp[ad][eq][cs] + dp[ad][gr][cs])%mod)%mod;
                        ndp[ls][ps+cs]%=mod;

                        ndp[eq][ps+cs] += dp[node][eq][ps] * ( dp[ad][ls][cs]) %mod;
                        ndp[eq][ps+cs]%=mod;

                        ndp[gr][ps+cs] += dp[node][gr][ps] * ((dp[ad][gr][cs] + dp[ad][ls][cs])%mod) %mod;
                        ndp[gr][ps+cs]%=mod;
                    }
                }

                memcpy(dp[node], ndp, sizeof(ndp));
            }
        };

        dfs(1,0);
        ll ans = 0;
        forn(k,most+1){
            add_self(ans, (dp[1][ls][k] + dp[1][eq][k] + dp[1][gr][k])%mod);
        }
        cout<<ans<<"\n";
    }
    return 0;
}