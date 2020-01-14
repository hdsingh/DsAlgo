#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define pb push_back
#define deb(x) cout << #x <<  " " << x << endl;
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int, int> pii;
const int inf = 1e9 + 5;

template <typename T>void print(T v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<v.size(); i++)cout<<setw(w)<<i<<" ";}cout<<endl;for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(w)<<*i<<" ";cout<<endl;}
template <typename T>void print_vv(T v){int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}
template<class T, class U> inline void self_max(T &x, U y) { if (y > x) x = y; }
template<class T, class U> inline void self_min(T &x, U y) { if (y < x) x = y; }

// To do again
int main(){
    ll n,m,k;
    while(cin>>n>>m>>k){
        vl a(n), dp(n);
        forn(i, n)
            cin>>a[i];
        ll ans = 0;
        forn(i, n){
            dp[i] = a[i] - k;
            ll sum = a[i];

            for(int j=i-1; j>=0 && i-j<=m; j--){
                self_max(dp[i], dp[j] + sum - k);
                sum+=a[j];
            }
            if(i<m) self_max(dp[i], sum - k);
            self_max(dp[i], 0);
            self_max(ans, dp[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}