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

template <typename T>void print(T v){ for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(2)<<*i<<" ";cout<<endl; }
template <typename T>void print_vv(T v, bool same_line=true){for(auto i= 0; i<v.size(); i++){cout<<"{";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(3)<<v[i][j]<<",";}cout<<"},";if(same_line) cout<<endl;}cout<<endl;}

const int mod = 1e9+7;
inline ll fpow(ll n, ll k, int p = mod) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
inline void addmod(int& a, int val, int p = mod) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = mod) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = mod) {return (ll) a * b % p;}
// inline int inv(int a, int p = mod) {return fpow(a, p - 2, p);}


const int MAXN = 20;
vl fact(MAXN), inv(MAXN), finv(MAXN);

void precalc(){
    int n = MAXN;
    
    fact[0] = finv[0] = inv[1] = 1;

    fore(i, 2, n)
        inv[i] = (mod - (mod/i) * inv[mod%i] % mod) % mod;

    fore(i, 1, n){
        fact[i] = fact[i-1] * i % mod;
        finv[i] = finv[i-1] * inv[i] % mod;
    }
    
}

ll C(int n, int r){
    if(n<r || r<0) return 0;
    return fact[n] * finv[r]%mod * finv[n-r]%mod;
}

// ll powMod(ll n, ll p, ll mod)
ll powMod(ll n, ll p) { 
	ll res = 1;
	while (p) {
		if (p & 1) (res *= n) %= mod;
		(n *= n) %= mod;
		p >>= 1;
	}
	return res;
}

ll powmod1(ll A, ll p, ll MOD = mod){
    A%=MOD;
    ll res  = 1;
    while(p){
        if(p&1)
            res = ((__int128)res*A)%MOD;
        
        A = ((__int128)A*A)%MOD;
        p>>=1;
    }

    return res;
}

int main(){
    precalc();
    cout<<C(10,8)<<endl;
    
    return 0;
}

// https://atcoder.jp/contests/abc172/tasks/abc172_e
// https://atcoder.jp/contests/abc171/tasks/abc171_f
