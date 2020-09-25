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

//  a seq of len l can be extended to form additional [0 to len] pairs
// ex [1,2,3] 
// can [_,1,_,2_,3_] form additional
//      3  2   1  0 pairs
// This is true for all permutations of len n.
class Solution0 {
public:
    int kInversePairs(int n, int K) {
        vvi dp(n+1, vi(2*K+10));
        // cnt of inv pairs of len 1, having k pairs

        // brute force
        // dp[1][0] = 1;
        // for(int i=1; i<n; ++i){
        //     // max pairs possible at i = (i*(i-1))/2
        //     for(int k=0; k<=min((i*(i-1))/2, K); ++k){
        //         // extend all these pairs
        //         for(int nk=0; nk<=min(i,K-k); ++nk){
        //             add_self(dp[i+1][nk+k], dp[i][k]);
        //         }
        //     }
        // }

        // 2d optimised
        dp[1][0] = 1;
        for(int i=1; i<n; ++i){
            for(int k=0; k<=min((i*(i-1)/2), K); ++k){
                int st = k, ed = min(i,K-k)+k; 
                add_self(dp[i+1][st], dp[i][k]);
                add_self(dp[i+1][ed+1], -dp[i][k]);
            }
            for(int k=1; k<=K; ++k){
                add_self(dp[i+1][k], dp[i+1][k-1]);
            }
        }

        // print_vv(dp);
        return (dp[n][K]%mod + mod)%mod;
    }
};

// 1d
class Solution {
public:
    int kInversePairs(int n, int K) {
        vi dp(2*K+1);

        dp[0] = 1;
        for(int i=1; i<n; ++i){
            vi ndp(2*K+1);
            for(int k=0; k<=min((i*(i-1)/2), K); ++k){
                int st = k, ed = min(i,K-k)+k; 
                add_self(ndp[st], dp[k]);
                add_self(ndp[ed+1], -dp[k]);
            }
            for(int k=1; k<=K; ++k){
                add_self(ndp[k], ndp[k-1]);
            }
            dp = ndp;
        }

        // print_vv(dp);
        return (dp[K]%mod + mod)%mod;
    }
};


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    Solution sol; int n, k, out;
    n = 3, k = 0;
    out = sol.kInversePairs(n,k); deb(out);
    n = 20, k = 100;
    out = sol.kInversePairs(n,k); deb(out);
    return 0;
}