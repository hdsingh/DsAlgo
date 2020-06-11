// Find the sum of all the N digit palindromic numbers which are divisible by 9 and contain no zeros in their decimal representation. 
// Print the sum modulo 1e7.

// Ex: the palindromic numbers of length N = 3, which are divisible by 9 and contian no zeros are:
// [171,252,333,414,585,666,747,828,999]

// Constraints: 1<=N<=1e5
// Time Limit: 5secs

// N = 1, ans = 9,
// N = 2, ans = 495
// N = 3, ans = 4995

#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define pb push_back
#define deb(x) cout<<#x<<" "<<x<<endl;
#define deb2(x, y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define deb3(x, y, z) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
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

template <typename T>void print(T v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<v.size(); i++)cout<<setw(w)<<i<<" ";cout<<endl;}for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(w)<<*i<<" ";cout<<endl;}
template <typename T>void print_vv(T v){if(v.size()==0) {cout<<"Empty"<<endl; return;} int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}
template <class T, class U> void print_m(map<T,U> m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"), ";cout<<endl;}


bool is_pal(ll n){
    ll div = 1;
    while(n/div>=10)
        div*=10;
    
    while(n){
        int trail = n%10;
        int lead = n/div;
        
        if(trail!=lead) return false;

        n = (n%div)/10;

        div/=100;
    }
    return true;
}

bool no_zero(ll n){
    while(n){
        if(n%10==0) return false;
        n/=10;
    }
    return true;
}

void count(vl &a){
    int sz = 1;
    ll c = a[0];
    // c/=10;
    while(c) 
        c/=10, ++sz;

    vector<map<int,int>> m(sz+1); //pos, digit
    for(auto &x: a){
        int pos = 1;
        while(x){
            m[pos][x%10]++;
            x/=10;
            ++pos;
        }
    }

    fore(pos, 1, sz){
        cout<<pos<<" ";
        print_m(m[pos]);
    }
}


// brute force
ll solve1(int n){
    vl a;
    ll sum = 0;

    ll beg = 1;
    forn(i,n-1) beg*=10;
    ll end = beg*10;

    for(ll i=beg; i<end; ++i){
        if(i%9==0 && is_pal(i) && no_zero(i)){
            sum+=i;
            sum%=mod;
            a.push_back(i);
        }
    }

    // print(a);
    // count(a);
    return sum;
}

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


ll solve2(int n){
    if(n<=0) return 0;
    if(n==1) return 9;
    if(n==2) return 99;

    ll sum = 0;
    ll t = (n+1)/2 - 2;
    // deb(t);
    ll times = powmod(9,t);
    // deb(times);

    for(int pos = 1; pos<=n; ++pos){
        for(int i=1; i<=9; ++i){
            sum+= (i%mod * powmod(10, pos-1) * times%mod);
            sum%=mod;
        }
    }

    return sum;
}

// Explanation: 
// Using by creating the possiblities or using Combinatrics
// We can see that, for num = N,
// for each position:
//    for each digit:
//         the digit appears , T times
// here t = pow(9, (n+1)/2 - 2) (ex: 1 for (3,4), 9 for (5,6), 81 for(7,8) ..)
// So for each pos we find the sum of digits and add it to sum
// here pow(10, pos-1) is done to represent the respective pos in the number

int main(){
    ll sum = solve2(1e5);
    deb(sum);

    forn(i,10){
        sum =  solve2(i);
        deb2(i,sum);
    }

    return 0;
}

// i 1 sum 9
// i 2 sum 99
// i 3 sum 4995
// i 4 sum 49995
// i 5 sum 4499955
// i 6 sum 44999955
// i 7 sum 49999567
// i 8 sum 499999315
// i 9 sum 999970847

// Using brute force
// 1
// 1 (9: 1), 
// i 1 sum 9


// 2
// 1 (9: 1), 
// 2 (9: 1), 
// i 2 sum 99


// 3
// 1 (1: 1), (2: 1), (3: 1), (4: 1), (5: 1), (6: 1), (7: 1), (8: 1), (9: 1), 
// 2 (1: 1), (2: 1), (3: 1), (4: 1), (5: 1), (6: 1), (7: 1), (8: 1), (9: 1), 
// 3 (1: 1), (2: 1), (3: 1), (4: 1), (5: 1), (6: 1), (7: 1), (8: 1), (9: 1), 
// i 3 sum 4995


// 4
// 1 (1: 1), (2: 1), (3: 1), (4: 1), (5: 1), (6: 1), (7: 1), (8: 1), (9: 1), 
// 2 (1: 1), (2: 1), (3: 1), (4: 1), (5: 1), (6: 1), (7: 1), (8: 1), (9: 1), 
// 3 (1: 1), (2: 1), (3: 1), (4: 1), (5: 1), (6: 1), (7: 1), (8: 1), (9: 1), 
// 4 (1: 1), (2: 1), (3: 1), (4: 1), (5: 1), (6: 1), (7: 1), (8: 1), (9: 1), 
// i 4 sum 49995


// 5
// 1 (1: 9), (2: 9), (3: 9), (4: 9), (5: 9), (6: 9), (7: 9), (8: 9), (9: 9), 
// 2 (1: 9), (2: 9), (3: 9), (4: 9), (5: 9), (6: 9), (7: 9), (8: 9), (9: 9), 
// 3 (1: 9), (2: 9), (3: 9), (4: 9), (5: 9), (6: 9), (7: 9), (8: 9), (9: 9), 
// 4 (1: 9), (2: 9), (3: 9), (4: 9), (5: 9), (6: 9), (7: 9), (8: 9), (9: 9), 
// 5 (1: 9), (2: 9), (3: 9), (4: 9), (5: 9), (6: 9), (7: 9), (8: 9), (9: 9), 
// i 5 sum 4499955


// 6
// 1 (1: 9), (2: 9), (3: 9), (4: 9), (5: 9), (6: 9), (7: 9), (8: 9), (9: 9), 
// 2 (1: 9), (2: 9), (3: 9), (4: 9), (5: 9), (6: 9), (7: 9), (8: 9), (9: 9), 
// 3 (1: 9), (2: 9), (3: 9), (4: 9), (5: 9), (6: 9), (7: 9), (8: 9), (9: 9), 
// 4 (1: 9), (2: 9), (3: 9), (4: 9), (5: 9), (6: 9), (7: 9), (8: 9), (9: 9), 
// 5 (1: 9), (2: 9), (3: 9), (4: 9), (5: 9), (6: 9), (7: 9), (8: 9), (9: 9), 
// 6 (1: 9), (2: 9), (3: 9), (4: 9), (5: 9), (6: 9), (7: 9), (8: 9), (9: 9), 
// i 6 sum 44999955


// 7
// 1 (1: 81), (2: 81), (3: 81), (4: 81), (5: 81), (6: 81), (7: 81), (8: 81), (9: 81), 
// 2 (1: 81), (2: 81), (3: 81), (4: 81), (5: 81), (6: 81), (7: 81), (8: 81), (9: 81), 
// 3 (1: 81), (2: 81), (3: 81), (4: 81), (5: 81), (6: 81), (7: 81), (8: 81), (9: 81), 
// 4 (1: 81), (2: 81), (3: 81), (4: 81), (5: 81), (6: 81), (7: 81), (8: 81), (9: 81), 
// 5 (1: 81), (2: 81), (3: 81), (4: 81), (5: 81), (6: 81), (7: 81), (8: 81), (9: 81), 
// 6 (1: 81), (2: 81), (3: 81), (4: 81), (5: 81), (6: 81), (7: 81), (8: 81), (9: 81), 
// 7 (1: 81), (2: 81), (3: 81), (4: 81), (5: 81), (6: 81), (7: 81), (8: 81), (9: 81), 
// i 7 sum 49999567


// 8
// 1 (1: 81), (2: 81), (3: 81), (4: 81), (5: 81), (6: 81), (7: 81), (8: 81), (9: 81), 
// 2 (1: 81), (2: 81), (3: 81), (4: 81), (5: 81), (6: 81), (7: 81), (8: 81), (9: 81), 
// 3 (1: 81), (2: 81), (3: 81), (4: 81), (5: 81), (6: 81), (7: 81), (8: 81), (9: 81), 
// 4 (1: 81), (2: 81), (3: 81), (4: 81), (5: 81), (6: 81), (7: 81), (8: 81), (9: 81), 
// 5 (1: 81), (2: 81), (3: 81), (4: 81), (5: 81), (6: 81), (7: 81), (8: 81), (9: 81), 
// 6 (1: 81), (2: 81), (3: 81), (4: 81), (5: 81), (6: 81), (7: 81), (8: 81), (9: 81), 
// 7 (1: 81), (2: 81), (3: 81), (4: 81), (5: 81), (6: 81), (7: 81), (8: 81), (9: 81), 
// 8 (1: 81), (2: 81), (3: 81), (4: 81), (5: 81), (6: 81), (7: 81), (8: 81), (9: 81), 
// i 8 sum 499999315


// 9
// 1 (1: 729), (2: 729), (3: 729), (4: 729), (5: 729), (6: 729), (7: 729), (8: 729), (9: 729), 
// 2 (1: 729), (2: 729), (3: 729), (4: 729), (5: 729), (6: 729), (7: 729), (8: 729), (9: 729), 
// 3 (1: 729), (2: 729), (3: 729), (4: 729), (5: 729), (6: 729), (7: 729), (8: 729), (9: 729), 
// 4 (1: 729), (2: 729), (3: 729), (4: 729), (5: 729), (6: 729), (7: 729), (8: 729), (9: 729), 
// 5 (1: 729), (2: 729), (3: 729), (4: 729), (5: 729), (6: 729), (7: 729), (8: 729), (9: 729), 
// 6 (1: 729), (2: 729), (3: 729), (4: 729), (5: 729), (6: 729), (7: 729), (8: 729), (9: 729), 
// 7 (1: 729), (2: 729), (3: 729), (4: 729), (5: 729), (6: 729), (7: 729), (8: 729), (9: 729), 
// 8 (1: 729), (2: 729), (3: 729), (4: 729), (5: 729), (6: 729), (7: 729), (8: 729), (9: 729), 
// 9 (1: 729), (2: 729), (3: 729), (4: 729), (5: 729), (6: 729), (7: 729), (8: 729), (9: 729), 
// i 9 sum 999970847


// 10
// 1 (1: 729), (2: 729), (3: 729), (4: 729), (5: 729), (6: 729), (7: 729), (8: 729), (9: 729), 
// 2 (1: 729), (2: 729), (3: 729), (4: 729), (5: 729), (6: 729), (7: 729), (8: 729), (9: 729), 
// 3 (1: 729), (2: 729), (3: 729), (4: 729), (5: 729), (6: 729), (7: 729), (8: 729), (9: 729), 
// 4 (1: 729), (2: 729), (3: 729), (4: 729), (5: 729), (6: 729), (7: 729), (8: 729), (9: 729), 
// 5 (1: 729), (2: 729), (3: 729), (4: 729), (5: 729), (6: 729), (7: 729), (8: 729), (9: 729), 
// 6 (1: 729), (2: 729), (3: 729), (4: 729), (5: 729), (6: 729), (7: 729), (8: 729), (9: 729), 
// 7 (1: 729), (2: 729), (3: 729), (4: 729), (5: 729), (6: 729), (7: 729), (8: 729), (9: 729), 
// 8 (1: 729), (2: 729), (3: 729), (4: 729), (5: 729), (6: 729), (7: 729), (8: 729), (9: 729), 
// 9 (1: 729), (2: 729), (3: 729), (4: 729), (5: 729), (6: 729), (7: 729), (8: 729), (9: 729), 
// 10 (1: 729), (2: 729), (3: 729), (4: 729), (5: 729), (6: 729), (7: 729), (8: 729), (9: 729), 
// i 10 sum 999741212