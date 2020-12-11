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
template <typename T> ostream& operator<<(ostream &os, const vector<T> &v){print(v); return os;};
template <typename T> ostream& operator<<(ostream &os, const vector<vector<T>> &vv){print_vv(vv); return os;};
template <class T, class U> ostream& operator<<(ostream &os, const map<T,U>  &m){print_m(m); return os;};
template <class T, class U> ostream& operator<<(ostream &os, const pair<T, U> &pr){debp(pr); return os;};
template <class T, class U> ostream& operator<<(ostream &os, const vector<pair<T, U>> &vp){ print_vp(vp); return os;};

class Solution {
public:
    int minimumIncompatibility(vector<int>& nums, int K) {
        int n = nums.size();
        int len = n/K;
        // Precalculate by iterating over each valid mask
        vector<int> pre(1<<n,-1);
        for(int mask=0; mask<(1<<n); ++mask){
            if(__builtin_popcount(mask)!=len) continue;
            bool good = true;
            int mn = INT_MAX, mx = INT_MIN;
            int vis = 0;
            for(int i=0; i<n; ++i){
                if( !( (mask>>i)&1 ) ) continue;
                if(vis&(1<<nums[i])){
                    good = false;
                    break;
                }
                vis|=(1<<nums[i]);
                mn = min(mn, nums[i]);
                mx = max(mx, nums[i]);
            }
            if(good){
                pre[mask] = mx-mn;
            }
        }

        // find the ans for a mask if its len%K==0;
        // iterate over all its masks, ans minimize it by using their complements.
        vector<int> dp(1<<n, -1);
        dp[0] = 0;
        for(int mask=0; mask<(1<<n); ++mask){
            if(__builtin_popcount(mask)%len) continue;
            for(int sub=mask; sub; sub = (sub-1)&mask){
                if(pre[sub]==-1 || dp[mask^sub]==-1) continue;
                if(dp[mask]==-1)
                    dp[mask] = pre[sub] + dp[mask^sub];
                else 
                    dp[mask] = min(dp[mask], pre[sub] + dp[mask^sub]);
            }
        }

        return dp[(1<<n)-1];
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    Solution sol; int K; vi nums; int out;
    nums = {1,2,1,4}, K = 2;
    nums = {6,3,8,1,3,1,2,2}, K = 4; 
    out = sol.minimumIncompatibility(nums, K); deb(out);
    return 0;
}