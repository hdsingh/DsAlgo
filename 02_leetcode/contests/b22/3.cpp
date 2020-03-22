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
    vi dp;
    int getKth(int lo, int hi, int k) {
        compute();

        vector<pair<int,int>> a;
        for(auto i=lo; i<=hi; ++i)
            a.push_back({dp[i],i});
        
        sort(a.begin(), a.end());

        return a[k-1].second;
    }

    void compute(){
        if(dp.empty())
            dp.resize(1e6);
        else return;

        dp[2] = 1;
        for(int i=2; i<=1000; ++i)
            if(dp[i]==0)
                dfs(i);
    }

    int dfs(int x){
        if(dp[x]) return dp[x];
        int cnt = 1;
        if(x&1) 
            cnt+=dfs(3*x+1);
        else 
            cnt+=dfs(x/2);
    
        return dp[x] = cnt;
    }
};

int main(){
    Solution sol; 
    int lo,hi,k, out;
    lo = 12, hi = 15, k = 2;
    out = sol.getKth(lo,hi,k); deb(out);

    lo = 1, hi = 1, k = 1;
    out = sol.getKth(lo,hi,k); deb(out);
    lo = 7, hi = 11, k = 4;
    out = sol.getKth(lo,hi,k); deb(out);
    lo = 10, hi = 20, k = 5;
    out = sol.getKth(lo,hi,k); deb(out);
    lo = 1, hi = 1000, k = 777;
    out = sol.getKth(lo,hi,k); deb(out);

    return 0;
}