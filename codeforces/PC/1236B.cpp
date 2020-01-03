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

// No. of ways to fill m boxes(by 1 obj) :  2^m - 1
// No. of ways to fill m boxes(by n obj) : (2^m - 1)^n
// Bec each filling of box by each obj is independent of the other
const int mod = 1e9+7;
 
ll powMod(ll n, ll p, ll mod) {
	ll res = 1;
	while (p) {
		if (p & 1) (res *= n) %= mod;
		(n *= n) %= mod;
		p >>= 1;
	}
	return res;
}

int main(){
    ll n, m;
    while(cin>>n>>m){
        int ans = (powMod(2, m, mod) - 1 + mod) % mod;
        ans = powMod(ans, n, mod);

        printf("%d\n", ans);
    }
    
    return 0;
}