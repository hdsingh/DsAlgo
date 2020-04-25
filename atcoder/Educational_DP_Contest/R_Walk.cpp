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

ll n,k;

int mul(int a, int b){
    return (ll) a*b % mod;
}

vvi matmul(vvi &a, vvi &b){
    vvi res(n, vi(n));
    
    forn(i,n)
        forn(j,n)
            forn(k,n)
                add_self(res[i][j], mul(a[i][k], b[k][j]));
    return res;
}

vvi matPow(vvi &a, ll p){
    vvi res(n, vi(n));
    forn(i,n)
        res[i][i] = 1;
    
    while(p){
        if(p&1)
            res = matmul(res,a);
        a = matmul(a,a);
        p>>=1;
    }
    return res;
}

int main(){
    
    while(cin>>n>>k){
        vvi can(n, vi(n));
        forn(i,n)
            forn(j,n) 
                cin>>can[i][j];

        can = matPow(can,k);

        int ans = 0;
        forn(i,n)
            forn(j,n)
                add_self(ans, can[i][j]);
        
        cout<<ans<<endl;

        // vi dp(n,1);
        // for(ll steps =0; steps<k; ++steps){
        //     vi ndp(n);
        //     forn(i,n){
        //         forn(j,n){
        //             if(can[i][j])
        //                 add_self(ndp[j], dp[i]);
        //         }
        //     }
        //     dp = ndp;
        // }

        // int ans = 0;
        // for(auto x: dp)
        //     add_self(ans,x);
        // cout<<ans<<endl;
    
    }
    return 0;
}