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

// 6 18
// 5 6 1 10 12 2
// Looking at the example, we see possible ways to make sum =18
// are {5,1,10,2}, {6,12}
// Now out of these 2 subsets, we can form more subsets sums
// ex: 5+1, 5+1+2, ... , and from {6,12}  as 6,12,18
// Hence the 3 cases:
// 1. don't incluse it in subset
// 2. Include it in subset
//    1. dont include it in subsets of subsets
//    2. Inculde it in subsets of subsets

// dp[i][j][k] = is true only if till ith pos, subset having sum j,
// can have a subset with sum k
// In the end ans is dp[n][k][check the values]
const int nax = 505;
bool dp[2][nax][nax];

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,k;
    while(cin>>n>>k){
        memset(dp, 0, sizeof(dp));

        dp[0][0][0] = 1;
        vi a(n+1);
        fore(i,1,n+1) cin>>a[i];

        fore(i,1,n+1){
            int now = i%2;
            int last = 1-now;

            int x = a[i];

            forn(j,k+1){
                for(int cur_sum=0; cur_sum<=k; ++cur_sum){
                    // dont include:
                    dp[now][j][cur_sum] = dp[last][j][cur_sum];
                    
                    // include in this subset
                    if(j>=x){
                        dp[now][j][cur_sum] |= dp[last][j-x][cur_sum];

                        // include it in sum of subset
                        if(cur_sum>=x)
                            dp[now][j][cur_sum] |= dp[last][j-x][cur_sum-x];
                    }
                }
            }
        }

        vi res;
        fore(y,0,k+1){
            if(dp[n%2][k][y])
                res.pb(y);
        }
        cout<<sz(res)<<endl;
        print(res);

    }
    return 0;
}