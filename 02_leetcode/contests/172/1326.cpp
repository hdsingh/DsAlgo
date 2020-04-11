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

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        // cout<<endl;
        // print(ranges,1);
        vector<int> dp(n+1, n+2); // min taps required till ith pos

        dp[0] = 0;
        for(int i=0; i<=n; ++i){
            int l = max(0, i - ranges[i] + 1);
            int r = min(n, i + ranges[i]);
            int prev_taps = dp[max(0, i - ranges[i])];
            // deb3(i,l,r);
            for(int j=l; j<=r; ++j)
                min_self(dp[j], prev_taps + 1);
        }

        return dp[n]>=n+1 ? -1 : dp[n];
    }
};

int main(){
    Solution sol; int n; vi ranges; int out;

    n = 5, ranges = {3,4,1,1,0,0};
    out = sol.minTaps(n, ranges); deb(out);

    n = 3, ranges = {0,0,0,0};
    out = sol.minTaps(n, ranges); deb(out);

    n = 7, ranges = {1,2,1,0,2,1,0,1};
    out = sol.minTaps(n, ranges); deb(out);

    n = 8, ranges = {4,0,0,0,0,0,0,0,4};
    out = sol.minTaps(n, ranges); deb(out);

    n = 8, ranges = {4,0,0,0,4,0,0,0,4};
    out = sol.minTaps(n, ranges); deb(out);

    n = 35, ranges = { 1,0,4,0,4,1,4,3,1,1,1,2,1,4,0,3,0,3,0,3,0,5,3,0,0,1,2,1,2,4,3,0,1,0,5,2 };
    out = sol.minTaps(n, ranges); deb(out);


    return 0;
}