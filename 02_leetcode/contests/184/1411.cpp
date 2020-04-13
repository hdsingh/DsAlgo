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

class Solution0 {
public:
    int numOfWays(int n) {
        ll dp[5005][3][3][3];
        memset(dp,0, sizeof(dp));
        // # of ways to color till nth pos, row1, row2, row3

        forn(i,3)
            forn(j,3)
                forn(k,3)
                    if(i!=j && j!=k)
                        dp[1][i][j][k] = 1;

        fore(row,2,n+1)
            forn(i,3)   
                forn(j,3)
                    forn(k,3)
                        forn(pi,3)
                            forn(pj,3)
                                forn(pk,3)
                                    if(i!=j && j!=k && pi!=i && pj!=j && pk!=k)
                                        add_self(dp[row][i][j][k], dp[row-1][pi][pj][pk]);

        ll ans = 0;
        forn(i,3)
            forn(j,3)
                forn(k,3)
                    // if(i!=j && j!=k)
                    add_self(ans, dp[n][i][j][k]);

        return ans;
    }
};


// Ref: https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/discuss/574923/JavaC%2B%2BPython-DP-O(1)-Space
class Solution {
    const int mod = 1e9 + 7;
public:
    int numOfWays(int n) {
       ll a123 = 6;
       ll a121 = 6;

       for(int i=2; i<=n; ++i){
           ll n121 = (3*a121 + 2*a123)%mod;
           ll n123 = (2*a121 + 2*a123)%mod;
           a121 = n121; a123 = n123;
       }          
       return (a121 + a123)%mod;
    }
};

int main(){
    Solution sol; int n, out;
    fore(i,1,8){
        out = sol.numOfWays(i);
        deb(out);
    }
    out = sol.numOfWays(5000);
    deb(out);

    return 0;
}