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

class Solution {
    int n;
    vvi dp;
    vi locs;
    int E;
public:
    int countRoutes(vector<int>& _locs, int st, int ed, int fuel) {
        locs = _locs;
        n = sz(locs);
        st = locs[st], ed = locs[ed];
        sort(all(locs));
        st = find(all(locs), st) - locs.begin();
        ed = find(all(locs), ed) - locs.begin();
        E = ed;
        dp.clear();
        dp.resize(n+1, vi(fuel+1,-1));

        int ans = dfs(st,fuel); 
        return ans;     
    }

    int dfs(int st, int fuel){
        if(fuel<0) return 0;
        int &ans = dp[st][fuel];
        if(~ans) return ans;
        ans = 0;
        if(st==E){
            add_self(ans, 1);
        }

        for(int i=st-1; i>=0; --i){
            int dif = locs[st] - locs[i];
            if(dif<=fuel){
                add_self(ans, dfs(i, fuel-dif));
            }else break;
        }

        for(int i=st+1; i<n; ++i){
            int dif = locs[i] - locs[st];
            if(dif<=fuel){
                add_self(ans, dfs(i, fuel-dif));
            }else break;
        }

        return ans;
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    Solution sol;
    vi locations; int start, finish, fuel, out;
    locations = {2,3,6,8,4}, start = 1, finish = 3, fuel = 5;
    out = sol.countRoutes(locations,start, finish, fuel); deb(out);
    locations = {4,3,1}, start = 1, finish = 0, fuel = 6;
    out = sol.countRoutes(locations,start, finish, fuel); deb(out);
    locations = {5,2,1}, start = 0, finish = 2, fuel = 3;
    out = sol.countRoutes(locations,start, finish, fuel); deb(out);
    locations = {2,1,5}, start = 0, finish = 0, fuel = 3;
    out = sol.countRoutes(locations,start, finish, fuel); deb(out);
    locations = {1,2,3}, start = 0, finish = 2, fuel = 40;
    out = sol.countRoutes(locations,start, finish, fuel); deb(out);
    locations = {2,1,5}, start = 0, finish = 0, fuel = 3;
    out = sol.countRoutes(locations,start, finish, fuel); deb(out);
    return 0;
}