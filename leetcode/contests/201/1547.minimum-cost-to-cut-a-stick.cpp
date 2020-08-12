#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(a) int((a).size())
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

#define _deb(x) cout<<x;
void _print() {cerr << "]\n";} template <typename T, typename... V>void _print(T t, V... v) {_deb(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#define deb(x...) cerr << "[" << #x << "] = ["; _print(x)
template <class T, class U> void print_m(const map<T,U> &m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}
template<class T, class U>void debp(const pair<T, U> &pr, bool end_line=1){cout<<"{"<<pr.first<<" "<<pr.second<<"}"; cout<<(end_line ? "\n" : ", ");}
template <class T> void print_vp(const T &vp, int sep_line=0){if(vp.empty()){cout<<"Empty"<<endl; return;}if(!sep_line) cout<<"{ ";for(auto x: vp) debp(x,sep_line);if(!sep_line) cout<<"}\n";cout<<endl;}
template <typename T>void print(const T &v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<sz(v); i++)cout<<setw(w)<<i<<" ";cout<<endl;}for(auto &el: v) cout<<setw(w)<<el<<" ";cout<<endl;}
template <typename T>void print_vv(const T &vv){if(sz(vv)==0) {cout<<"Empty"<<endl; return;} int w = 3;cout<<setw(w)<<" ";for(int j=0; j<sz(*vv.begin()); j++)cout<<setw(w)<<j<<" ";cout<<endl;int i = 0;for(auto &v: vv){cout<<i++<<" {";for(auto &el: v) cout<<setw(w)<<el<<" ";cout<<"},\n";}cout<<endl;}

const int inf = 1e9;

class Solution0 {
    vi cuts;
    vvi dp;
public:
    int minCost(int n, vector<int>& C) {
        cuts = {0,n};
        dp.clear();
        dp.resize(110, vi(110,-1));
        for(auto x: C) cuts.pb(x);
        sort(all(cuts));
        return dfs(0,sz(cuts)-1);
    }

    int dfs(int l, int r){
        if(r-l<=1) return 0;
        if(dp[l][r]!=-1)  return dp[l][r];
        int mn = inf;
        for(int i=l+1; i<r; ++i){
            min_self(mn, dfs(l,i) + dfs(i, r));
        }
        return dp[l][r] = cuts[r] - cuts[l] + mn;
    }
};


class Solution {
public:
    int minCost(int N, vector<int>& cuts) {
        cuts.insert(cuts.begin(),0);
        sort(all(cuts));
        cuts.push_back(N);
        int n = cuts.size();
        print(cuts);

        vvi dp(n+1, vi(n+1, inf));

        for(int l=n-1; l>=0; --l){
            dp[l][l] = dp[l][l+1] = 0;
            for(int r=l+2; r<n; ++r){
                for(int mid=l+1; mid<r; ++mid){
                    min_self(dp[l][r], dp[l][mid] + dp[mid][r] + cuts[r] - cuts[l]);
                }
            }
        }

        return dp[0][n-1];
    }
};





int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; vi cuts; Solution sol; int out;
    n = 7, cuts = { 1,3,4,5 };
    out = sol.minCost(n,cuts); deb(out);
    n = 9, cuts = { 5,6,1,4,2 };
    out = sol.minCost(n,cuts); deb(out);
    n = 10, cuts = { 7,8,9,2,1 };
    out = sol.minCost(n,cuts); deb(out);
    return 0;
}