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

const int inf = 1e3;
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& adj) {
        int n = adj.size();
        vvi sp(n, vi(n,inf)); // all pair shortest path
        for(int i=0; i<n; ++i)
            for(auto ad: adj[i])
                sp[i][ad] = sp[ad][i] = 1;

        for(int k=0; k<n; ++k)  
            for(int i=0; i<n; ++i)
                for(int j=0; j<n; ++j)
                    min_self(sp[i][j], sp[i][k] + sp[k][j]);
        
        // print_vv(sp);
        
        vvi dp(1<<n, vi(n,inf));
        // min dist covering the group of nodes which have been visited, and 
        // last visited node is j

        for(int i=0; i<n; ++i)
            dp[1<<i][i] = 0;
        
        for(int grp=0; grp<(1<<n); ++grp){
            for(int u=0; u<n; ++u){ // last vis node
                for(int v=0; v<n; ++v){ // node to vis next
                    int pos_u = (1<<u), pos_v = (1<<v);
                    if((grp & pos_u) && !(grp & pos_v)){
                        min_self(dp[grp|pos_v][v], dp[grp][u] + sp[u][v]);
                    }
                }
            }
        }

        int full = (1<<n) - 1;
        int ans = inf;
        for(int last=0; last<n; ++last)
            min_self(ans, dp[full][last]);
    
        return ans;
        
    }
};

int main(){
    Solution sol;
    vector<vvi> adjs = {
        {{1,2,3},{0},{0},{0}},
        {{1},{0,2,4},{1,3,4},{2},{1,2}},
    };
    for(auto adj: adjs){
        int out = sol.shortestPathLength(adj); deb(out);
    } 
    return 0;
}