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
typedef pair<ll,ll> pll;
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

int n, m;
const ll inf = 1e18l;

void SPFA(){
    cin>>n>>m;
    vector<vector<pll>> adj(n+1); // {to, w}
    forn(i,m){
        int x, y, w; cin>>x>>y>>w;
        adj[x].pb({y,w});
    }
    vl dist(n+1, -inf);
    vb inq(n+1); vi cnt(n+1), par(n+1, -1);
    queue<int> q;
    int src = 1;
    dist[src] = 0;
    q.push(src);

    int x; // vertex in cycle
    bool has_cycle = 0;
    while(sz(q)){
        if(has_cycle) break;
        int top = q.front(); q.pop();
        inq[top] = 0;

        for(auto ad: adj[top]){
            auto [to, len] = ad;
            if(dist[top]+len> dist[to]){
                dist[to] = dist[top] + len;
                par[to] = top;
                if(!inq[to]){
                    q.push(to);
                    inq[to] = 1;
                    cnt[to]++;
                    if(cnt[to]>=n){
                        x = to;
                        has_cycle = 1;
                        break;
                    }
                }
            }
        }
    }

    if(!has_cycle){
        cout<<dist[n]<<"\n";
    }else{
        // find a node present in cycle
        forn(i,n) x = par[x]; // since it is in cycle
        // if from this node present in cycle
        // it is possible to reach n(dest) then we can
        // get arbitrarily large val

        vb vis(n+1);
        queue<int> q;
        vis[x] = 1;
        q.push(x);

        while(sz(q)){
            int top = q.front(); q.pop();
            for(auto ad: adj[top]){
                int to = ad.first;
                if(vis[to]) continue;
                vis[to] = 1;
                q.push(to);
            }
        }
        cout<<(vis[n] ? -1 : dist[n])<<"\n";
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    SPFA();
    return 0;
}