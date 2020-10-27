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

class Solution {
public:
    // brute
    int numberOfSets1(int n, int K) {
        vector<vector<int>> dp(n, vector<int>(K+1));
        // // number of seq before i having k segments

        dp[0][0] = 1;
        for(int lt=0; lt<n; ++lt){
            for(int k=0; k<=K; ++k){
                if(lt) add_self(dp[lt][k], dp[lt-1][k]);
                
                for(int rt=lt+1; rt<n; ++rt){
                    if(k+1<=K)
                        add_self(dp[rt][k+1], dp[lt][k]);
                }
            }
        }

        return dp[n-1][K];
    }

    // optim n*K
    int numberOfSets(int n, int K) {
        vector<vector<int>> dp(n, vector<int>(K+1));
        // // number of seq before i having k segments
        vector<int> add(K+2);
        dp[0][0] = 1;
        for(int lt=0; lt<n; ++lt){
            for(int k=min(lt,K); k>=0; --k){
                if(lt) add_self(dp[lt][k], dp[lt-1][k]);
                add_self(dp[lt][k], add[k]);

                add_self(add[k+1], dp[lt][k]);
            }
        }

        return dp[n-1][K];
    }

};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, K; Solution sol; int out;
    n = 4, K = 2;
    out = sol.numberOfSets1(n,K); deb(out);
    n = 3, K = 1;
    out = sol.numberOfSets(n,K); deb(out);
    n = 30, K = 7;
    out = sol.numberOfSets1(n,K); deb(out);
    n = 5, K = 3;
    out = sol.numberOfSets(n,K); deb(out);
    n = 3, K = 2;
    out = sol.numberOfSets(n,K); deb(out);
    return 0;
}