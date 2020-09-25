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

// for each node find ths dist to farthest node,
class Solution0 {
    int n;
    vvi adj;
    vi ans, far1, far2;
    int mn;
public:
    vector<int> findMinHeightTrees(int _n, vector<vector<int>>& edges) {
        n = _n;
        mn = n+1;
        adj.assign(n+1,{}); far1.assign(n+1,0); far2.assign(n+1,0);
        for(auto ed: edges){
            adj[ed[0]].pb(ed[1]), adj[ed[1]].pb(ed[0]);
        }
        dfs1(0,-1);
        dfs2(0,-1,0);
        return ans;
    }

    void dfs1(int node, int p){
        for(auto ad: adj[node]){
            if(ad==p) continue;
            dfs1(ad, node);
            int d = far1[ad]+1;
            if(d>far1[node]){
                far2[node] = far1[node];
                far1[node] = d;
            }else if(d>far2[node]){
                far2[node] = d;
            }
        }
    }

    void dfs2(int node, int p, int up){
        int ht = max(far1[node],up);
        if(ht<mn){
            mn = ht; ans = {node};
        }else if(ht==mn){
            ans.pb(node);
        }

        for(auto ad: adj[node]){
            if(ad==p) continue;
            int next = far1[node] + 1;
            if(far1[node]-1==far1[ad])
                next = far2[node] + 1;
            next = max(next, up+1);
            dfs2(ad,node,next);
        }
    }
};

// Idea: The leaves can't be have minHtTree.
// So lets remove them. Keep on removing level by lev and
// the last level left have minHt Tree
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vi deg(n);
        vvi adj(n);
        if(n==1) return {0};
        for(auto ed: edges){
            deg[ed[0]]++, deg[ed[1]]++;
            adj[ed[0]].pb(ed[1]); adj[ed[1]].pb(ed[0]);
        }

        queue<int> q;
        for(int i=0; i<n; ++i)
            if(deg[i]==1) 
                q.push(i), --deg[i];

        vi ans;

        while(sz(q)){
            int len = sz(q);
            ans.clear();
            while(len--){
                int top = q.front(); q.pop();
                ans.pb(top);
                for(auto ad: adj[top]){
                    if(--deg[ad]==1)
                        q.push(ad);
                }
            }
        }

        return ans;        
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    Solution0 sol; vvi edges; int n; vi out;
    n = 4, edges = {{1,0},{1,2},{1,3}};
    out = sol.findMinHeightTrees(n, edges); print(out);
    n = 6, edges = {{3,0},{3,1},{3,2},{3,4},{5,4}};
    out = sol.findMinHeightTrees(n, edges); print(out);
    n = 2, edges = {};
    out = sol.findMinHeightTrees(n, edges); print(out);
    n = 2, edges = {{0,1}};
    out = sol.findMinHeightTrees(n, edges); print(out);

    return 0;
}