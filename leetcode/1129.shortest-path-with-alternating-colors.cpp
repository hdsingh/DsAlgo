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
    const int inf = 1e9;
    vvi radj, badj;
    vi dist;
    int n;
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        this->n = n;
        radj.assign(n,{}), badj.assign(n,{});
        dist.assign(n,inf);
        for(auto ed: red_edges)
            radj[ed[0]].pb(ed[1]);
        for(auto ed: blue_edges){
            badj[ed[0]].pb(ed[1]);
        }
        dist[0] = 0;
        bfs(0);
        bfs(1);
        for(auto &x: dist) if(x>=inf) x = -1;
        return dist;
    }

    void bfs(int next_red){
        vvi dis(n, vi(2,inf));
        dis[0][next_red] = 0;
        queue<int> q;
        q.push(0);

        while(sz(q)){
            int len = sz(q);
            while(len--){
                int top = q.front(); q.pop();
                if(next_red){
                    for(auto ad: radj[top]){
                        if(dis[ad][next_red^1]!=inf) continue;
                        dis[ad][next_red^1] = dis[top][next_red]+1;
                        q.push(ad);
                    }
                }else{
                    for(auto ad: badj[top]){
                        if(dis[ad][next_red^1]!=inf) continue;
                        dis[ad][next_red^1] = dis[top][next_red]+1;
                        q.push(ad);
                    }
                }
            }
            next_red^=1;
        }
        
        for(int i=0; i<n; ++i){
            min_self(dist[i], min(dis[i][0], dis[i][1]));
        }
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    Solution sol;
    int n; vvi red_edges, blue_edges; vi out;
    n= 3, red_edges = {{0,1},{1,2}}, blue_edges = {};
    out = sol.shortestAlternatingPaths(n,red_edges, blue_edges); print(out);
    n = 3, red_edges = {{0,1}}, blue_edges = {{2,1}};
    out = sol.shortestAlternatingPaths(n,red_edges, blue_edges); print(out);
    n = 3, red_edges = {{1,0}}, blue_edges = {{2,1}};
    out = sol.shortestAlternatingPaths(n,red_edges, blue_edges); print(out);
    n = 3, red_edges = {{0,1}}, blue_edges = {{1,2}};
    out = sol.shortestAlternatingPaths(n,red_edges, blue_edges); print(out);
    n = 3, red_edges = {{0,1},{0,2}}, blue_edges = {{1,0}};
    out = sol.shortestAlternatingPaths(n,red_edges, blue_edges); print(out);
    n = 5, red_edges = {{0,1},{2,3}}; blue_edges = {{1,2},{3,4}};
    out = sol.shortestAlternatingPaths(n,red_edges, blue_edges); print(out);
    n = 5, red_edges = {{0,1},{1,2},{2,3},{3,4}}, blue_edges = {{1,2},{2,3},{3,1}};
    out = sol.shortestAlternatingPaths(n,red_edges, blue_edges); print(out);
    return 0;
}