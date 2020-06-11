#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)

typedef long long ll;
typedef vector<ll> vl;
const int mod = 1e9 + 7;


ll powmod(ll A, ll p, ll MOD = mod){
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

ll solve(int n){
    if(n<=0) return 0;
    if(n==1) return 9;
    if(n==2) return 99;

    ll sum = 0;
    ll t = (n+1)/2 - 2;
    ll times = powmod(9,t);

    for(int pos = 1; pos<=n; ++pos){
        for(int i=1; i<=9; ++i){
            sum+= (i%mod * powmod(10, pos-1) * times%mod);
            sum%=mod;
        }
    }

    return sum;
}

int main(){
    ll sum = solve(1e5);
    cout<<sum<<endl;

    forn(i,10){
        sum =  solve(i);
        cout<<i<<" "<<sum<<endl;
    }

    return 0;
}

// Found using brute force 
// i 1 sum 9
// i 2 sum 99
// i 3 sum 4995
// i 4 sum 49995
// i 5 sum 4499955
// i 6 sum 44999955
// i 7 sum 49999567
// i 8 sum 499999315
// i 9 sum 999970847

