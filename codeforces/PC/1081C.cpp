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
const int mod = 998244353;

// if there are K bircks with color different from the prev brick,
// There will be K+1 blocks, (each block having same color and size atleast 1);
// So we can color the first block in m colors and each next in (m-1)( since cant be same as prev)
// hence s1 + s2 + s3 .. s_(k+1) = n
// Since s1>=1, s2>=1, .... s_(k+1)>=1  -> (s1' + 1)>=1
// acc to stars and bars : s1' + s2' + s3'  .... s(k+1)' = n - k;
// hence ways to resize are C(n+k-1 - (k),k) -> C(n-1, k)
// Total  = C(n-1, k) * m* (m-1)^k

const int MAXN = 2000;
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

ll powMod(ll n, ll p) {
    assert(p>=0);
    ll res = 1;
    while (p) {
        if (p & 1) (res *= n) %= mod;
          (n *= n) %= mod;
        p >>= 1;
    }
    return res;
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    precalc();
    ll n,m,k;
    while(cin>>n>>m>>k){
        ll ans = C(n-1,k)%mod * m%mod * powMod(m-1,k)%mod;
        ans%=mod;
        
        cout<<ans<<endl;
    }
    return 0;
}

