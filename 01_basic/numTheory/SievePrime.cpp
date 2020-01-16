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

template <typename T>void print(T v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<v.size(); i++)cout<<setw(w)<<i<<" ";}cout<<endl;for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(w)<<*i<<" ";cout<<endl;}
template <typename T>void print_vv(T v){int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}

vb naivePrime(int n){
    vb isPrime(n+1, true);
    isPrime[0] = isPrime[1] = false;
    for(int i=2; i<=n; i++){
        if(isPrime[i]){
            for(int j=i+i; j<=n; j+=i){
                isPrime[j] = false;
            }
        }
    }
    return isPrime;
}

// instead of starting from pos i, we should start marking not prime from
// i*i because the previous positions have already been marked as composite
//  by smaller primes. ex: 5x2, 5x3, 5x4(by 2), so start from 5x5.
vb seivePrime1(int n){
    vb isPrime(n+1, true);
    isPrime[0] = isPrime[1] = false;
    for(int i=2; i<=n; i++){
        if(isPrime[i]){
            for(int j=i*i; j<=n; j+=i){
                isPrime[j] = false;
            }
        }
    }
    return isPrime;
}

// till root
vb seivePrime(int n){
    vb isPrime(n+1, true);
    isPrime[0] = isPrime[1] = false;
    for(int i=2; i*i<=n; i++)
        if(isPrime[i])
            for(int j = i*i; j<=n; j+=i)
                isPrime[j] = false;
    return isPrime;
}

int main(){
    int n = 10000;
    vb isPr = seivePrime(n);
    forn(i, n){
        if(isPr[i])
            cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}