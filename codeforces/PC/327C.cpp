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
inline int inv(int a, int p = mod) {return fpow(a, p - 2, p);}

int main(){
    string s; 
    int k;
    while(cin>>s){
        cin>>k;
        int n = s.size();

        int ans = 0;
        for(int i=0; i<n; i++){
            if(s[i]=='0' || s[i]=='5'){
                addmod(ans, fpow(2, i));
            }
        }
        ans = mult(ans, fpow(2, (ll) n*k % (mod-1)) -1);
        ans = mult(ans, inv( fpow(2, n) - 1));

        cout<<ans<<endl;
    }
    return 0;
}