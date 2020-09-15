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

#define x first
#define y second

// 3 Cases:
// 1. Has Cycle (formed by connecting a node with its ancestor)
//   a. has 2 pars: (remove the latest edge of incoming edges to node having 2 pars)
//   b. no 2 pars: this is formed when edge from a node is connected to root.
//      here removing any node(latest) present in cycle will result in a valid tree.
// 2. Has 2 pars: remove latest`
class Solution {
    set<int> incycle;
    int n;
    vvi edges;
    vector<vector<pii>> adj, pars; // {par, precedence}
    vi cols;
    int two_pars, has_cyc; 
    vector<pii> par; // for cyc detect
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& E) {
        edges = E;
        n = sz(edges);
        two_pars = 0, has_cyc = 0;
        pars.clear(); pars.resize(n+1);
        adj.clear(); adj.resize(n+1);
        cols.assign(n+1,0);
        par.assign(n+1,{-1,-1});
        incycle.clear();
        
        forn(i,n){
            adj[edges[i][0]].pb({edges[i][1], i}); //{ad, precedence}
            edges[i].pb(i);
            pars[edges[i][1]].pb({edges[i][0],i});
            if(sz(pars[edges[i][1]])==2) two_pars = edges[i][1];
        }
        
        // // detect cyc
        fore(i,1,n+1){
            if(cols[i]==0 && dfs(i)){
                has_cyc = 1;
                break;
            }
        }

        vi e;
        if(has_cyc){ // cycle present
            if(!two_pars){ // remove latest incycle.
                e =  edges[*incycle.rbegin()];
            }else{
                // remove latest
                int p1 = pars[two_pars][0].y, p2 = pars[two_pars][1].y;
                e = incycle.count(p1) ? edges[p1] : edges[p2];
            }
        }else{ // 2 pars
            // remove latest
            if(pars[two_pars][0].y>pars[two_pars][1].y){
                e = edges[pars[two_pars][0].y];
            }else 
                e = edges[pars[two_pars][1].y];
        }


        return {e[0], e[1]};
    }

    // cycle detection.
    bool dfs(int node){
        cols[node] = 1;

        for(auto ad: adj[node]){
            if(!cols[ad.x]){
                par[ad.x] = {node, ad.y};
                if(dfs(ad.x)) return 1;
            }else if(cols[ad.x]==1){
                incycle.insert(ad.y);
                pii cur = par[node];
                while(cur.x!=ad.x){
                    cur = par[cur.x]; 
                    incycle.insert(cur.y);                   
                }
                return 1;
            }
        }
    
        cols[node] = 2;
        return 0;
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    Solution sol; vvi E; vi out;
    E = {{1,2}, {1,3}, {2,3}};
    out = sol.findRedundantDirectedConnection(E); print(out);
    E = {{1,2}, {2,3}, {3,4}, {4,1}, {1,5}};
    out = sol.findRedundantDirectedConnection(E); print(out);
    return 0;
}