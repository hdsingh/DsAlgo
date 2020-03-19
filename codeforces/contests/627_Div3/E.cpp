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

const int inf = 1e9;
int main(){
    int n,H,l,r;
    cin>>n>>H>>l>>r;
    vi a(n);
    forn(i,n) cin>>a[i];

    auto is_good = [&](const int x){
        return l<=x && x<=r;
    };

    vvi dp(n+1, vi(H, -inf)); // max good segments that can be obtained
    // till ith day, on h_th hour
    dp[0][(a[0]-1) %H ]  = is_good((a[0]-1)%H);
    dp[0][(a[0]) %H ]    = is_good((a[0])%H);

    fore(i,1,n){
        int cur_h = a[i] - 1;
        // if sleeps for a[i] - 1 hrs
        forn(h,H)
            max_self(dp[i][(cur_h+h)%H] , dp[i-1][h] + is_good((cur_h+h)%H));     
        
        // if sleeps for a[i] hrs
        cur_h = a[i];
        forn(h,H)
            max_self(dp[i][(cur_h+h)%H] , dp[i-1][h] + is_good((cur_h+h)%H));
    }

    // print_vv(dp);
    int out = *max_element(all(dp[n-1]));
    cout<<out<<endl;

    return 0;
}