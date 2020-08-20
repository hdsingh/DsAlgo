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
    vvi edges;
    vi par;
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& E) {
        this->n = n;
        this->edges = E; // {u,v,wt,idx}
        par.resize(n);
        int m = sz(edges); 
        forn(i,m)
            edges[i].pb(i);
        sort(all(edges), [&](vi &v1, vi &v2){
            return v1[2]<v2[2];
        });
        
        vi critical, pseudo;
        int cost = kruskal();
        forn(i,m){
            // skip this edges
            int cur = kruskal(edges[i][3]);
            // if weight of mst increases then it is critical
            if(cur>cost)
                critical.pb(edges[i][3]);
            else{
                // add this edge and then form remaining tree
                cur = kruskal(-1,i);
                if(cur==cost) 
                    pseudo.pb(edges[i][3]);
            }
        }
        

        return {critical, pseudo};
    }

    int kruskal(int skip = -1, int use = -1){
        iota(all(par),0); 
        int cost = 0;
        int used = 0;
    
        if(~use){
            union_sets(edges[use][0], edges[use][1]);
            cost+=edges[use][2];
        }

        for(auto &ed: edges){
            if(skip==ed[3]) continue;
            if(union_sets(ed[0], ed[1])){
                cost+=ed[2];
                ++used;
            }
        }
        
        if(~skip){ // while skipping if we are not able to form a tree (n-1 nodes)
            if(used!=n-1) return INT_MAX; // then node is critical
        }

        return cost;        
    }

    bool union_sets(int a, int b){
        a = find_par(a); b = find_par(b);
        if(a==b) return false;
        par[b] = a;
        return 1;
    }

    int find_par(int a){
        if(a==par[a]) return a;
        return par[a] = find_par(par[a]);
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    Solution sol; vvi edges; int n; vvi out;
    n = 5, edges = {{0,1,1},{1,2,1},{2,3,2},{0,3,2},{0,4,3},{3,4,3},{1,4,6}};
    n = 6, edges = {{0,1,1},{1,2,1},{0,2,1},{2,3,4},{3,4,2},{3,5,2},{4,5,2}};
    out = sol.findCriticalAndPseudoCriticalEdges(n,edges);
    print_vv(out);
    return 0;
}