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

// Bad Solution : O(n^3)
const int inf = INT_MAX;
class Solution0 {
public:
    int mctFromLeafValues(vector<int>& a) {
        int n = a.size();
        vvi leaf(n, vi(n));
        for(int l=n-1; l>=0; --l){
            leaf[l][l] = a[l];
            for(int r=l+1; r<n; ++r){
                max_self(leaf[l][r], max(leaf[l+1][r], leaf[l][r-1]));
            }
        }

        vvi dp(n, vi(n));
        for(int l=n-1; l>=0; --l){
            for(int r=l+1; r<n; ++r){
                dp[l][r] = inf;
                for(int k=l; k<r; ++k){
                    min_self(dp[l][r], leaf[l][k] * leaf[k+1][r] + dp[l][k] + dp[k+1][r]);
                }
            }
        }        

        return dp[0][n-1];
    }
};

// Since we are maximizing the leaf values, the min value node will never be used again
// So it is equivalent to removal of min node,
// a*b + dp[l][k] + dp[k+1][r]
// here one min node is constant (a), and for b, we must use a value greater than it
// since a will be removed by a value greater than it
// there are 2 possible options:
// 1. greater to left of a, 
// 2. greater to right of a
// hence use min value of both
class Solution {
public:
    int mctFromLeafValues(vector<int>& a) {
        int n = a.size();
        vi stk = {INT_MAX};

        int res = 0;
        for(auto x: a){
            if(sz(stk) && stk.back()<=x){
                int mid = stk.back(); stk.pop_back();
                res += mid * min(stk.back(), x);         
            }
            stk.push_back(x);
        }
        
        for(int i=2; i<sz(stk); ++i)
            res+=stk[i]*stk[i-1];
        return res;
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    Solution sol; vi a = {6,2,4,5,8,20}; int out;
    out = sol.mctFromLeafValues(a); deb(out);
    return 0;
}