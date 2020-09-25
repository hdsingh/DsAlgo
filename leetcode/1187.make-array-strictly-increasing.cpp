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
class Solution {
    vi a, b;
    int n, m;
    vvi dp;
public:
    int makeArrayIncreasing(vector<int>& a, vector<int>& b) {
        n = sz(a), m = sz(b);
        map<int,int> seen;
        for(auto x: a) seen[x] = 1; 
        for(auto x: b) seen[x] = 1;
        int N = 1;
        for(auto &p: seen)
            p.second = N++;
        
        for(auto &x: a) x = seen[x];
        for(auto &x: b) x = seen[x];
        sort(all(b));
        this->a = a, this->b = b;
        // print(a); print(b);
        dp.clear(); dp.assign(n+1,vi(N+1,-1));

        int ans = dfs(0,0);
        if(ans>=inf) return -1;
        return ans;
    }
    
    // cost to make a strictly inc if last seen element is last
    int dfs(int pos, int last){
        if(pos>=n) return 0;
        int &ans = dp[pos][last];
        if(~ans) return ans;
        ans = inf;
        
        // if already greater use it.
        if(a[pos]>last)
            min_self(ans, dfs(pos+1, a[pos]));
        
        // also try the nearest greater element than last
        auto loc = upper_bound(all(b),last);
        if(loc!=b.end()){
            min_self(ans, 1 + dfs(pos+1, *loc));
        }
             
        return ans;
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    Solution sol; vi a, b; int out;
    a = {1,5,3,6,7}, b = {1,3,2,4};
    out = sol.makeArrayIncreasing(a, b); deb(out);
    a = {1,5,3,6,7}, b = {4,3,1};
    out = sol.makeArrayIncreasing(a, b); deb(out);
    a = {1,5,3,6,7}, b = {1,6,3,3};
    out = sol.makeArrayIncreasing(a, b); deb(out);

    return 0;
}