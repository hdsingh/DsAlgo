#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define pb push_back
#define deb(x) cout<<#x<<" "<<x<<endl;
#define deb2(x, y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define deb3(x, y, z) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define all(x) x.begin(), x.end()
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

template <typename T>void print(T v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<v.size(); i++)cout<<setw(w)<<i<<" ";cout<<endl;}for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(w)<<*i<<" ";cout<<endl;}
template <typename T>void print_vv(T v){if(v.size()==0) {cout<<"Empty"<<endl; return;} int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}
template <class T, class U> void print_m(map<T,U> m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}

const int inf = 1e9;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t,n,m,a,b,c,u,v;
    cin>>t;
    while(t--){
        cin>>n>>m>>a>>b>>c;
        // deb2(n,m); deb3(a,b,c);
        vl p(m); forn(i,m) cin>>p[i];
        sort(all(p));
        vl pre(m+1);
        forn(i,m)
            pre[i+1] = pre[i]+p[i];
        
        vvi adj(n+1);
        forn(i,m){
            cin>>u>>v;
            adj[u].pb(v), adj[v].pb(u);
        }

        // vvi dist(n+1,vi(3,inf)); // dist from x to (a,b,c)
        // auto bfs = [&](int node, int st){
        //     dist[node][st] = 0;
        //     queue<int> q;
        //     q.push(node);
        //     while(!q.empty()){
        //         int top = q.front(); q.pop();
        //         for(auto ad: adj[top]){
        //             if(dist[ad][st]==inf){
        //                 dist[ad][st] = dist[top][st] + 1;
        //                 q.push(ad);
        //             }
        //         }
        //     }
        // };

        vvl dist(n+1,vl(3,-1)); // dist from x to (a,b,c)
        auto bfs = [&](int node, int st){
            dist[node][st] = 0;
            queue<int> q;
            q.push(node);
            while(!q.empty()){
                int top = q.front(); q.pop();
                for(auto ad: adj[top]){
                    if(~dist[ad][st]) continue;
                    dist[ad][st] = dist[top][st] + 1;
                    q.push(ad);
                }
            }
        };


        bfs(a,0);
        bfs(b,1);
        bfs(c,2);

        // print_vv(dist);

        ll ans = 1e18;
        fore(i,1,n+1){
            if(dist[i][0] + dist[i][1] + dist[i][2]<=m){
                ll d = pre[dist[i][1]] + pre[dist[i][0] + dist[i][1] + dist[i][2]];
                ans = min(d, ans);
            }
        }
        cout<<ans<<endl;
        
    }
    return 0;
}