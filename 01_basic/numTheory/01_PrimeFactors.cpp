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

vvi primeFactorsEachN(int N){
    vvi fact(N+1); //prime factors

    for(int i=2; i<=N; i++){
        if(fact[i].empty()){
            for(int j=i; j<=N; j+=i)
                fact[j].push_back(i);
        }
    };

    return fact;
}

vl primeFactorizationSimple(ll n){
    vl fact;

    for(ll d=2; d*d<=n; d++){
        while(n%d==0){
            fact.pb(d);
            n/=d;
        }
    }
    if(n>1)
        fact.pb(n);
    return fact;
}

// Wheel factorisation
// Optimized : If a number is not divisibel by 2, it will not be divisible
// by any multiple of 2(even number), so instead of incrementing by 1, we 
// should increment by 2;
// Similarly for        7, 11, 13, 17, 19, 23, 29, 31, 37,
// increment pattern is  4   2   4   2   4   6   2   4  ....
vl primeFactorization(ll n){
    vl fact;
    
    for(int d: {2,3,5}){
        while(n%d == 0){
            fact.pb(d);
            n/=d;
        }
    }
    static const vi increment = {4, 2, 4, 2, 4, 6, 2, 6};
    int i = 0;
    for(ll d = 7; d*d<=n; d+=increment[i++]){
        while(n%d == 0){
            fact.pb(d);
            n/=d;
        }
        if(i==8) i =0;
    }

    if(n>1)
        fact.pb(n);
    
    return fact;
}

int main(){
    // vvi fact = primeFactorsEachN(100);
    // print_vv(fact);
    
    vl factsOfN = primeFactorization(199191);
    print(factsOfN);
}

