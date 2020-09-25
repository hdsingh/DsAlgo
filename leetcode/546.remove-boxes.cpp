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

// Trick: Attach the prev boxes together.

const int nax = 101;
class Solution {
    int dp[nax][nax][nax];
    int n; vi a;
public:
    int removeBoxes(vector<int>& boxes) {
        a = boxes; n = a.size();
        memset(dp,-1,sizeof(dp));
        return dfs(0,n-1,0);
    }

    // max sum that can be obtained from l to r,
    // if k extra boxes of same color as a[l] are attached with it.
    int dfs(int l, int r, int k){
        if(l>r) return 0;
        if(l==r) return (k+1)*(k+1);
        int &ans = dp[l][r][k];
        if(~ans) return ans;
        ans = 0;

        // optimisation in case the next continuous elements are same
        int j = l;
        while(j+1<r && a[l]==a[j+1]) ++j;
        k+=(j-l); l = j;

        // 1. remove here all the prev boxes attached and start a new seq
        max_self(ans, dfs(l,l,k) + dfs(l+1,r,0));

        // 2. skip some boxes in the middle if same color found
        // and attach prev boxes with this new one of same col.
        for(int m=l+1; m<=r; ++m){
            if(a[l]==a[m])
                max_self(ans, dfs(l+1,m-1,0) + dfs(m,r,k+1));
        } 

        return ans;
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    Solution sol; vi a; int out;
    a = {1,3,2,2,2,3,4,3,1};
    out = sol.removeBoxes(a); deb(out);
    return 0;
}