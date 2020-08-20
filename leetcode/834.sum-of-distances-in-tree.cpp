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
    vvi adj;
    int n;
    vi subs; // subtree size
    vi ans;
public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        n = N;
        adj.clear(); adj.resize(n); ans.resize(n); subs.resize(n);
        for(auto ed: edges){
            adj[ed[0]].pb(ed[1]), adj[ed[1]].pb(ed[0]);
        }
        int sum = dfs(0,-1, 0);
        dfs2(0,-1,sum);
        return ans;
    }

    int dfs(int x, int p, int d){
        int sum = d;
        subs[x] = 1;
        for(auto ad: adj[x]){
            if(ad==p) continue;
            sum+=dfs(ad,x,d+1);
            subs[x]+=subs[ad];
        }
        return sum;
    }

    void dfs2(int x, int p, int sum){
        ans[x] = sum;
        for(auto ad: adj[x]){
            if(ad==p) continue;
            subs[x]-=subs[ad];
            sum+=subs[x];
            sum-=subs[ad];
            subs[ad]+=subs[x];

            dfs2(ad,x,sum);

            subs[ad]-=subs[x];
            sum+=subs[ad];
            sum-=subs[x];
            subs[x]+=subs[ad];
        }

    }

};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    Solution sol; int N; vvi edges;
    N = 6, edges = {{0,1},{0,2},{2,3},{2,4},{2,5}};
    vi out = sol.sumOfDistancesInTree(N, edges); print(out);
    return 0;
}