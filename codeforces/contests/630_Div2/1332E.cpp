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
const int mod = 998244353;
template<class T, class U> inline void add_self(T &a, U b){a += b;if (a >= mod) a -= mod;if (a < 0) a += mod;}
template<class T, class U> inline void min_self(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void max_self(T &x, U y) { if (y > x) x = y; }

template <typename T>void print(T v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<v.size(); i++)cout<<setw(w)<<i<<" ";cout<<endl;}for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(w)<<*i<<" ";cout<<endl;}
template <typename T>void print_vv(T v){if(v.size()==0) {cout<<"Empty"<<endl; return;} int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}
template <class T, class U> void print_m(map<T,U> m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}

ll powMod(ll n, ll p) { 
	ll res = 1;
	while (p) {
		if (p & 1) (res *= n) %= mod;
		(n *= n) %= mod;
		p >>= 1;
	}
	return res;
}

// Ref: https://www.youtube.com/watch?v=5J1qfcgT4LQ&list=PLl4Y2XuUavmtZVNTojhNwzYkr3fQZirYp
int main(){
    ll n,m,l,r;
    while(cin>>n>>m>>l>>r){
        
        if((n*m)&1){
            cout<<powMod(r-l+1, n*m)<<endl;
        }else{
            ll tot = r-l+1;
            ll e = r/2 - (l-1)/2;
            ll o = tot - e;
            ll sub = (powMod(e+o, n*m) - powMod(abs(e-o), n*m) + mod)%mod;
            sub = (sub * powMod(2, mod-2))%mod;  // sub =sub/2
            ll ans = (powMod(tot, n*m) - sub + mod)%mod;
            cout<<ans<<endl;
        }
    }
    return 0;
}