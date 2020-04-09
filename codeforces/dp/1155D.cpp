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
template <class T, class U> void print_m(map<T,U> m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}

// We cant use simple kadane here so lets modify it
// We have to find the max subarray sum of 
//  1 1 1 1 1   x x x x  1 1 1 1 
//  a a a a a  a a a a  a a a a 
//  i          j        k     l
// After multiplying a selected elements by x, find the subarray sum
// so it has 3 parts
// max_sum of part1,2,3 = best1,2,3 
// best1 = max_sum[i:j-1]
// best2 = max_sum[j:k-1]
// best3 = max_sum[k:l]
// However best1 will be computed 1st, then best2 and then best3

int main(){
    int n, x;
    while(cin>>n>>x){
        ll best1(0), best2(0), best3(0);
        vl a(n); forn(i,n) cin>>a[i];

        ll ans = 0;
        for(auto e: a){
            best3 = max({0LL, best2 + e, best3+e});
            best2 = max({0LL, best1 + e*x, best2 + e*x});
            best1 = max({0LL, e, best1+e});
            ans = max({ans, best1, best2, best3});
        }
        cout<<ans<<endl;
        
    }
    return 0;
}

// reverse order to compute best1 first and then use it in best2, 
// similarly, compute best2 first and use it in best3 later

// 3. extend the prev best2 by adding simple e(start of simple seq) or keep on extending the prev started best seq
// best3 = max({0LL, best2 + e, best3+e});

// 2. extend the best1 by adding e*x (start of x seq), or keep on extending the prev best2 seq by adding e*x
// best2 = max({0LL, best1 + e*x, best2 + e*x});

// 1. 0, sinlge e or extend the prev best by adding single e
// best1 = max({0LL, e, best1+e});



// ans = max({best1, best2, best3});

