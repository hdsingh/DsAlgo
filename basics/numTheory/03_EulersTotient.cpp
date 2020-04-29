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

int phi(int n){
    int result = n;
    for(int i=2; i*i<=n; i++){
        if(n%i==0){
            while(n%i==0)
                n/=i;
            result-= result/i;
        }
    }
    if(n>1)
        result-=result/n;
    return result;
}

// more efficient way, similar to Seive
vi phi_1_to_n(int n){
    vi phi(n+1);
    phi[0] = 0;
    phi[1] = 1;
    for(int i=2; i<=n; ++i)
        phi[i] = i; // mark all as prime

    for(int i=2; i<=n; ++i){
        if(phi[i]==i){ // if prime, remove it from its multiples
            for(int j=i; j<=n; j+=i)
                phi[j]-=phi[j]/i;
        }
    }
    return phi;
}

int main(){
    deb(phi(6));
    deb(phi(12));
    deb(phi(23));
    return 0;
}

// Usage: 
// https://codeforces.com/contest/1295/problem/D