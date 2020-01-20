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
const int mod = 1e9 + 7;
template<class T, class U> inline void add_self(T &a, U b){a += b;if (a >= mod) a -= mod;if (a < 0) a += mod;}
template<class T, class U> inline void min_self(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void max_self(T &x, U y) { if (y > x) x = y; }

template <typename T>void print(T v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<v.size(); i++)cout<<setw(w)<<i<<" ";}cout<<endl;for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(w)<<*i<<" ";cout<<endl;}
template <typename T>void print_vv(T v){int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}
template<class T, class U> void print_m(map<T,U> m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}

// Q: Find the trailing 0s in B-ary representation of n!
// If B = 10 , then depends upon the highest pow of 10;
// if B = x, then x will be represented as 10 in B-ary representation,
// So it reduces to find the highest pow of B in n!

// exp = n/x + n/(x^2) + n/(x^3)
ll ExpOfXinFact(ll n, ll x){
    ll exp = 0;
    
    while(n){
        n/=x;
        exp+=n;
    }

    return exp;
}

map<ll,ll> primeFact(ll n){
    map<ll, ll> m;
    for(ll d=2; d*d<=n; d++){
        if(n%d==0){
            while(n%d==0){
                m[d]++;
                n/=d;
            }
        }
    }

    if(n>1)    
        m[n]++;

    return m;
} 

int main(){
    ll n, b;
    while(cin>>n>>b){
        auto primes_b = primeFact(b);
    
        ll ans = LONG_LONG_MAX;
        for(auto pc: primes_b){
            ll p = pc.first;
            ll c = pc.second;
            ll exp = ExpOfXinFact(n, p);
            exp/=c;
            ans = min(ans, exp);
        }

        cout<<ans<<endl;
    }

    return 0;
}