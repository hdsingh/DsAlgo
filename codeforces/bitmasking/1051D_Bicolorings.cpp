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
const int mod = 998244353;
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

// cur, nx
const vvi cnt = {
    {0,1,1,1},
    {0,0,2,0},
    {0,2,0,0},
    {1,1,1,0},
};
const int N = 1002;
int dp[N][2*N][4];
// # of ways till ith pos, to have k comps if the last comp
// is of type t(0,1,2,3)
// 0 : 00, 1:01 : 2: 10, 3: 11
// we can see that 0 and 1 have only 1 comp
// and 2 and 3 have 2 comps

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, K;
    cin>>n>>K;

    memset(dp,0,sizeof(dp));

    dp[0][1][0] = dp[0][1][3] = 1;
    dp[0][2][1] = dp[0][2][2] = 1;

    forn(i,n-1){
        fore(k,1,K+1){
            forn(ct,4){
                forn(nt,4){
                    int inc = cnt[ct][nt];
                    add_self(dp[i+1][k+inc][nt], dp[i][k][ct]);
                }
            }
        }
    }

    ll ans = 0;
    forn(t,4)
        add_self(ans, dp[n-1][K][t]);
    
    cout<<ans<<endl;
    return 0;
}
