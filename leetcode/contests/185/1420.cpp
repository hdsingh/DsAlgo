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

int mul(ll a, int b){
    a*=b;
    a%=mod;
    return a;
}

class Solution {
public:
    int numOfArrays(int n, int m, int K) {
        int dp[n][m+1][K+1]; // pos, mx_so_far, cost
        memset(dp, 0, sizeof(dp));
        for(int mx=1; mx<=m; ++mx)
            dp[0][mx][1] = 1;
        
        for(int pos=1; pos<n; ++pos){
            for(int mx=1; mx<=m; ++mx){
                for(int k=1; k<=K; ++k){
                    // if we have found the max, we can use any of {1,2,3....mx} elements hence having mx choices
                    add_self(dp[pos][mx][k], mul(mx, dp[pos-1][mx][k]));

                    // if we have a new mx, then prev_mx will be less than it
                    for(int prev_mx=1; prev_mx<mx; ++prev_mx){
                        add_self(dp[pos][mx][k], dp[pos-1][prev_mx][k-1]);
                    }
                }
            }
        }
        
        int ans = 0;
        for(int mx=1; mx<=m; ++mx)
            add_self(ans, dp[n-1][mx][K]);

        return ans;

    }
};

int main(){
    Solution sol; 
    vvi vin = {
        // n,m.k
        {2,3,1},
        {5,2,3},
        {9,1,1},
        {50,100,25},
        {37,17,7},
    };
    for(auto p: vin){
        int out = sol.numOfArrays(p[0],p[1],p[2]); deb(out);
    }
    return 0;
}