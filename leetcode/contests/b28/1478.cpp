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

const int inf = 1e8;
class Solution {
    vi a;
    int n;
    vvi dp;
    vvi diff;
public:
    int minDistance(vector<int>& A, int K) {
        a = A;
        sort(a.begin(), a.end());
        n = a.size();
        dp.clear();
        dp.resize(n+1, vi(K+1,-1));
        // calc();
        // if(K==n) return a[(n-1)/2];
        int ans = solve(0,K);
        return ans;
    }

    // void calc(){
    //     diff.resize(n+1, vi());

    // }

    int solve(int beg, int k){
        if(beg==n){
            if(k==0) return 0;
            return inf;
        }
        if(k==0) return inf;
        if(dp[beg][k]!=-1) return dp[beg][k];
        // if(~dp[beg][k]) return dp[beg][k];


        int ans = inf;

        for(int l=beg; l<n; ++l){
            int mid = beg + (l-beg)/2;
            int dif = 0;
            for(int i=beg; i<=l; ++i){
                dif+=abs(a[mid]-a[i]);
            }

            int cur = dif + solve(l+1,k-1);
            ans = min(ans,cur);
        }

        // deb(beg,k,ans);
        return dp[beg][k] = ans;
        return ans;
    }
};

int main(){
    Solution sol; vi houses; int k, out;
    houses = {1,4,8,10,20}, k = 3;
    out = sol.minDistance(houses,k); deb(out);
    houses = {2,3,5,12,18}, k = 2;
    out = sol.minDistance(houses,k); deb(out);
    houses = {7,4,6,1}, k = 1;
    out = sol.minDistance(houses,k); deb(out);
    houses = {3,6,14,10}, k = 4;
    out = sol.minDistance(houses,k); deb(out);

    return 0;
}