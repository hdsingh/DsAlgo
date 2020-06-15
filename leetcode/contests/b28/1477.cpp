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
public:
    int minSumOfLengths(vector<int>& a, int X) {
        int n = a.size();
        vector<pii> good;
        map<int,int> seen;
        seen[0] = -1;
        int sum = 0;

        for(int i=0; i<n; ++i){
            sum+=a[i];
            if(seen.count(sum-X)){
                good.push_back({seen[sum-X]+1, i});
            }
            seen[sum] = i;
        }
        // print_vp(good);
    
        if(good.size()<2) return -1;
        vi pre(n+1,inf), suf(n+1,inf);
        // pre: min_len of subarray that ends at i,
        // suf min_len of subarray that starts at i
        for(auto x: good){
            int len = x.second - x.first + 1;
            pre[x.second] = len;
            suf[x.first] = len;                        
        }
        for(int i=1; i<=n; ++i)
            pre[i] = min(pre[i], pre[i-1]);
        
        for(int i=n-1; i>=0; --i)
            suf[i] = min(suf[i+1], suf[i]);
        
        // print(pre,1);
        // print(suf);

        int ans = inf;
        for(int i=0; i<n; ++i){
            ans = min(ans, pre[i] + suf[i+1]);            
        }

        return ans==inf ? -1 : ans;
    }
};

int main(){
    Solution sol;
    vi arr; int target, out;

    arr = {3,2,2,4,3}, target = 3;
    // arr = {1,6,1}; target = 7;
    out = sol.minSumOfLengths(arr,target); deb(out);
    arr = {7,3,4,7}, target = 7;
    out = sol.minSumOfLengths(arr,target); deb(out);
    arr = {4,3,2,6,2,3,4}, target = 6;
    out = sol.minSumOfLengths(arr,target); deb(out);
    arr = {5,5,4,4,5}, target = 3;
    out = sol.minSumOfLengths(arr,target); deb(out);
    arr = {3,1,1,1,5,1,2,1}, target = 3;
    out = sol.minSumOfLengths(arr,target); deb(out);

    return 0;
}