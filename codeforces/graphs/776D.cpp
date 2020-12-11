#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define pb push_back
#define deb(x) cout<<#x<<" "<<x<<endl;
#define deb2(x, y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define deb3(x, y, z) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
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

template <typename T>void print(const T &v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<sz(v); i++)cout<<setw(w)<<i<<" ";cout<<endl;}for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(w)<<*i<<" ";cout<<endl;}
template <typename T>void print_vv(const T &v){if(sz(v)==0) {cout<<"Empty"<<endl; return;} int w = 3;cout<<setw(w)<<" ";for(int j=0; j<sz(v[0]); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<sz(v); i++){cout<<i<<" {";for(auto j = 0; j!=sz(v[i]); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}
template <class T, class U> void print_m(const map<T,U> &m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}

const int nax = 1e5+10;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m,x,y;
    while(cin>>n>>m){
        vi unlocked(nax);
        fore(i,1,n+1) cin>>unlocked[i];

        vvi edges(nax);
        // edge represent room, ith room is controlled by switch {a,b}
        fore(i,1,m+1){
            cin>>x; 
            forn(j,x){
                cin>>y;
                edges[y].pb(i);
            }
        }

        // print_vv(edges);
        vector<vector<pii>> adj(nax); // node: {edge_id, node}
        fore(i,1,m+1){
            // assert(sz(edges[i])==2);
            if(!sz(edges[i])) continue;
            adj[edges[i][0]].push_back({i, edges[i][1]});
            adj[edges[i][1]].push_back({i, edges[i][0]});
        }

        vector<int> color(nax,-1);
        queue<int> q;
        bool yes = true;

        fore(i,1,n+1){
            if(color[i]==-1){
                color[i] = 0;
                q.push(i);

                while(!q.empty()){
                    int v = q.front(); q.pop();
                    for(auto e: adj[v]){
                        int id = e.first;
                        int node = e.second;
                        // // if unlocked both must have same col
                        if(unlocked[id]){
                            if(color[node]==-1){
                                color[node] = color[v];
                                q.push(node);
                            }else{
                                yes &= color[node]==color[v];
                            }
                        }else{ // locked , both must have diff color
                            if(color[node]==-1){
                                color[node] = color[v]^1;
                                q.push(node);
                            }else{
                                yes &= color[node]!=color[v];
                            }
                        }
                    }
                }
            }
        }

        cout<<(yes ? "YES" : "NO")<<endl;

    }


    return 0;
}

// Form a graph, where doors are represented by edges, switch by nodes
// Check if such a graph is 2 colorable
// such that edges with val 0 have nodes with diff color 
int main1(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    while(cin>>n>>m){
        vi a(nax);
        fore(i,1,n+1){
            cin>>a[i];
        }

        vvi locs(nax);
        fore(i,1,m+1){
            int cnt; cin>>cnt;
            forn(j,cnt){
                int x; cin>>x;
                locs[x].pb(i);
            }
        }

        vector<vector<pii>> adj(nax); //{ad,p}
        fore(i,1,n+1){
            int p = a[i], x = locs[i][0], y = locs[i][1];
            adj[x].pb({y,p}); adj[y].pb({x,p});
        }

        bool good = 1;
        vector<int> cols(nax,-1);
        fore(node,1,m+1){
            if(cols[node]!=-1) continue;
            cols[node] = 1;
            queue<int> q;
            q.push(node);
        
            while(!q.empty()){
                auto top = q.front(); q.pop();
                for(auto [ad,p]: adj[top]){
                    if(cols[ad]==-1){
                        cols[ad] = (p==0 ? cols[top]^1 : cols[top]);
                        q.push(ad);
                    }else{
                        int req = (p==0 ? cols[top]^1 : cols[top]);
                        good&=(cols[ad]==req);
                    }
                }
            }
        }

        cout<<(good ? "YES\n" : "NO\n");   
    }
    return 0;
}