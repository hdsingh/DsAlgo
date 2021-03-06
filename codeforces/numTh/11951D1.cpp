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
const int mod = 998244353;
template<class T, class U> inline void add_self(T &a, U b){a += b;if (a >= mod) a -= mod;if (a < 0) a += mod;}
template<class T, class U> inline void min_self(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void max_self(T &x, U y) { if (y > x) x = y; }

template <typename T>void print_vv(T v){int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}
template <typename T>void print(T v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<v.size(); i++)cout<<setw(w)<<i<<" ";}cout<<endl;for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(w)<<*i<<" ";cout<<endl;}

vi pw10(30);

int add(int a, int b){
    a+=b;
    if(a>mod) a-=mod;
    if(a<0)a+=mod;
    return a;
}

int mul(int a, int b){
    return a * 1ll * b % mod;
}

int f(int a, int b){
    int ans = 0;
    
    int pos = 0;
    while(a || b){
        if(b){
            ans = add(mul(b%10, pw10[pos++]), ans);
            b/=10;
        }
        if(a){
            ans = add(mul(a%10, pw10[pos++]), ans);
            a/=10; 
        }
    }

    return ans;
}

int main(){
    pw10[0] = 1;
    fore(i, 1, 30)
        pw10[i] = mul(pw10[i-1], 10);

    int n;
    while(cin>>n){
        vi a(n);
        forn(i,n)   
            cin>>a[i];

        ll ans = 0;
        forn(i, n){
            add_self(ans, mul(n, f(a[i], a[i])));
        }

        cout<<ans<<endl;        
    }
    
    return 0;
}