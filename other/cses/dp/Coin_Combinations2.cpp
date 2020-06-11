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

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,X;
    while(cin>>n>>X){
        vi coins(n); forn(i,n) cin>>coins[i];

        vi dp(X+1);
        dp[0] = 1;
        // # of distinct ways to produce sum x, using first i coins
        // This is unlike the previous task, where we considered every coin at all times.
    
        // for(auto c: coins){
        //     for(int amt=c; amt<=X; ++amt){
        //         add_self(dp[amt], dp[amt-c]);
        //     }
        // }

        for(auto c: coins){
            for(int amt=0; amt+c<=X; ++amt){
                add_self(dp[amt+c], dp[amt]);
            }
        }

        cout<<dp[X]<<endl;


        // 2D dp
        // vvi dp(n+1, vi(X+1));
        // dp[0][0] = 1;
        // // # of ways to form sum j using first i coins

        // for(int c=1; c<=n; ++c){
        //     for(int amt=0; amt<=X; ++amt){
        //         dp[c][amt] = dp[c-1][amt];
        //         if(amt-coins[c-1]>=0)
        //         (dp[c][amt] += dp[c][amt-coins[c-1]])%=mod;
        //     }
        // }

        // cout<<dp[n][X]<<endl;

    }
    return 0;
}