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

// Ways in which a pal can be extended
// 1. if a[i]==a[i+1] then reduce (a[i], a[i+1]) + reduce remaining
// 2. ...l..k......r
// if a[l]==a[k] (l+1<k<=r) it could be reduced along with the palindrome
// inside. (remember in case of no preper palindrome, a char of len 1 is always a pal)
// along with which a[l](pal)a[r]  (pal could be single c) can be reduce without any cost
// + cost of reducing the remaining seq from a[k+1] to a[r].

// Important step:
// while minimising of collapsing from i to j
// if i and some position k have same value,
// the steps required will be
// dp[i][j] =  dp[i+1][k-1] + dp[k+1][j] + (nothing)
// we will not add +1 here because of this example
// 1 2 3 1 : the steps required here are 2, not 3
// bec remove 3 -> 1 2 1 . (2 steps)
const int inf = 1e8;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    while(cin>>n){
        vi a(n+1); fore(i,1,n+1) cin>>a[i];
        vvi dp(n+2, vi(n+2));

        for(int l=n; l>=1; --l){
            dp[l][l] = 1;
            for(int r=l+1; r<=n; ++r){
                dp[l][r] = inf;
                min_self(dp[l][r], 1 + dp[l+1][r]);

                if(a[l]==a[l+1]) 
                    min_self(dp[l][r], dp[l+2][r] + 1);
                
                for(int k=l+2; k<=r; ++k){
                    if(a[l]==a[k])
                        min_self(dp[l][r], dp[l+1][k-1] + dp[k+1][r]);
                }
            }
        }

        // print_vv(dp);
        cout<<dp[1][n]<<"\n";
    }
    
    return 0;
}