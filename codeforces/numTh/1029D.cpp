#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define pb push_back
#define deb(x) cout<<#x<<" "<<x<<endl;
#define deb2(x, y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define deb3(x, y, z) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
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

template <typename T>void print(const T &v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<sz(v); i++)cout<<setw(w)<<i<<" ";cout<<endl;}for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(w)<<*i<<" ";cout<<endl;}
template <typename T>void print_vv(const T &v){if(sz(v)==0) {cout<<"Empty"<<endl; return;} int w = 3;cout<<setw(w)<<" ";for(int j=0; j<sz(v[0]); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<sz(v); i++){cout<<i<<" {";for(auto j = 0; j!=sz(v[i]); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}
template <class T, class U> void print_m(const map<T,U> &m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}

int len(ll x){
    int cnt =0;
    while(x)
        x/=10, ++cnt;
    return cnt;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,k;
    while(cin>>n>>k){
        ll p = 1;
        vl p10(18);
        forn(i,18){
            p%=k;
            p10[i] = p;
            p*=10;
        }
    
        ll ans = 0;
        vl a(n); forn(i,n) cin>>a[i];

        // vvl dp(11, vl(k)); // wont work bec nax = 1e9;
        map<int, map<ll,ll>> dp;
        // better method is to store for each len, the remainders separately
        // and then binary search using upperand lower bound

        // i is len of 1st word, k is its rem
        // dp stores for a num, its mod with respect to its len

        for(auto x: a){
            int rem = x%k;
            dp[len(x)][rem]++;
        }

        // // place second int x : x+prev
        for(auto x: a){
            for(int l=1; l<=10; ++l){
                int rem = (x*p10[l])%k;
                int req = (k-rem)%k;
                ans+= dp[l][req];
            }
        }

        for(auto x: a){
            int rem = (p10[len(x)]*x%k) + x%k;
            rem%=k;
            if(rem==0) --ans;
        }

        cout<<ans<<endl;
    }
    return 0;
}