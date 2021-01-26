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
typedef pair<ll, ll> pll;
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


// Just focus on connect each group of left side, with any grp on right
// in the end, all the points on left will be connected,
// however some on right might not be,
// for these connect them with any point on left with min cost repectively.
class Solution {
    const int inf = 1e8;
    int n, m, full;
    vvi dp;
    vi save; // mask representing min cost for the unconnected points of right side

    int on(int mask, int bit){
        return ((mask>>bit)&1);
    }
public:
    int connectTwoGroups(vector<vector<int>>& a) {
        n = a.size(), m = a[0].size();
        full = (1<<m)-1;
        vi mn(m);
        forn(j,m){
            mn[j] = INT_MAX;
            forn(i,n) 
                min_self(mn[j], a[i][j]);
        }
        dp.assign(n, vi(1<<m,-1));
        save.assign(1<<m,0);
        for(int mask=0; mask<(1<<m); ++mask){
            int cost = 0;
            for(int j=0; j<m; ++j){
                if(on(mask,j)) cost+=mn[j];
            }
            save[mask] = cost;
        }
        
        return dfs(0,0,a);
    }

    int dfs(int pos, int used, vvi &a){
        if(pos==n){
            int rem = (~used)&full;
            return save[rem];
        };

        int &ans = dp[pos][used];
        if(~ans) return ans;
        ans = inf;

        for(int j=0; j<m; ++j){
            min_self(ans, a[pos][j] + dfs(pos+1,used|(1<<j),a));
        }
        return ans;
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    Solution sol; vvi cost; int out;
    cost = {{15, 96}, {36, 2}};
    cost = {{1, 3, 5}, 
            {4, 1, 1}, 
            {1, 5, 3}};
    cost = {{2, 5, 1}, {3, 4, 7}, {8, 1, 2}, {6, 2, 4}, {3, 8, 8}};
    out = sol.connectTwoGroups(cost); deb(out);
    return 0;
}