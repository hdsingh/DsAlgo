#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define pb push_back
#define deb(x) cout<<#x<<" "<<x<<endl;
#define deb2(x, y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define deb3(x, y, z) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define all(x) x.begin(), x.end()
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

template <typename T>void print(T v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<v.size(); i++)cout<<setw(w)<<i<<" ";cout<<endl;}for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(w)<<*i<<" ";cout<<endl;}
template <typename T>void print_vv(T v){if(v.size()==0) {cout<<"Empty"<<endl; return;} int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}
template <class T, class U> void print_m(map<T,U> m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}

// Ref: https://www.youtube.com/watch?v=ytOManO7GO0
int main(){
    int n;
    while(cin>>n){
        vi a(n);
        int dp[n][n]; // represents the value formed in l to r
        memset(dp, 0, sizeof(dp));

        forn(i,n){
            cin>>a[i];
            dp[i][i] = a[i];
        }

        for(int l=n-2; ~l; --l){
            for(int r=l+1; r<n; ++r){
                dp[l][r] = -1; // not possible
                for(int k=l; k<r; ++k){
                    // if possible and value is same
                    if(~dp[l][k] && dp[l][k]== dp[k+1][r]){
                        dp[l][r] = dp[l][k] + 1;
                    }
                }
            }
        }

        int dp2[n+1];
        memset(dp2, 0, sizeof(dp2));
    
        for(int i=1; i<=n; ++i){
            dp2[i] = 1e9;
            for(int j=0; j<i; ++j){
                if(~dp[j][i-1]){
                    dp2[i] = min(dp2[i], dp2[j] + 1);
                }
            }
        }        

        cout<<dp2[n]<<endl;

    }
    return 0;
}