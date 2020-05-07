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

// https://www.youtube.com/watch?v=khCze6j1vXg
// GCD Sum
// Question: 
// Calc gcd(i,N) (for i=1 to N);
// for N = 12 
// GCD(1, 12 ) = 1
// GCD(2, 12 ) = 2
// GCD(3, 12 ) = 3
// GCD(4, 12 ) = 4
// GCD(5, 12 ) = 1
// GCD(6, 12 ) = 6
// GCD(7, 12 ) = 1
// GCD(8, 12 ) = 4
// GCD(9, 12 ) = 3
// GCD(10, 12 ) = 2
// GCD(11, 12 ) = 1
// GCD(12, 12 ) = 12

// We know that the result of gcd(x,12) = some divisor of 12
// So lets count how many times a divisor appears
// (1: 4),
// (2: 2),
// (3: 2),
// (4: 2),
// (6: 1),
// (12: 1),
// We know GCD(x,N) = d,  1<=x<=N
// so      GCD(x/d, N/d) = 1,  1<=x/d<=N/d
// i.e # of ints having gcd as d, with N == # of ints that are co-prime to N/d,
// i.e # of ints having gcd as d = phi(N/d)
// So 
// (1: phi(12/1)),
// (2: phi(12/2)),
// (3: phi(12/3)),
// (4: phi(12/4)),
// (6: phi(12/6)),
// (12: phi(12/12)),
// This also verifies Divisor sum property
// i.e summation of phi(d) = N, (for all divs of N)
// Because each phi(N/d), represents number the number of times it has appeared

vi find_divs(int x){
    vi out;
    for(int i=1; i*i<=x; ++i){
        if(x%i==0){
            int d1 = i;
            int d2 = x/i;
            out.push_back(d1);
            if(d1!=d2) out.push_back(d2);
        }
    }
    return out;
}

int main(){
    vi phi = phi_1_to_n(1000);
    int n = 75;
    vi divs = find_divs(n);
    int ans = 0;
    for(auto d: divs){
        ans+=d*phi[n/d];
    }
    deb(ans);
    
    // Brute force
    // int n = 75;
	// int ans = 0;
	// fore(i,1,n+1){
	// 	ans+=__gcd(i,n);
	// }
	// deb(ans);
    return 0;
}

// Usage: 
// https://codeforces.com/contest/1295/problem/D