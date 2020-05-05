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
typedef pair<ll, int> pli;
const int mod = 1e9 + 7;
template<class T, class U> inline void add_self(T &a, U b){a += b;if (a >= mod) a -= mod;if (a < 0) a += mod;}
template<class T, class U> inline void min_self(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void max_self(T &x, U y) { if (y > x) x = y; }

template <typename T>void print(const T &v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<sz(v); i++)cout<<setw(w)<<i<<" ";cout<<endl;}for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(w)<<*i<<" ";cout<<endl;}
template <typename T>void print_vv(const T &v){if(sz(v)==0) {cout<<"Empty"<<endl; return;} int w = 3;cout<<setw(w)<<" ";for(int j=0; j<sz(v[0]); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<sz(v); i++){cout<<i<<" {";for(auto j = 0; j!=sz(v[i]); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}
template <class T, class U> void print_m(const map<T,U> &m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}

const ll inf = 1e18;
const int nax = 3e5 + 10;
vector<pair<int,pii>> adj[nax];

// do k steps of dijkstra
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m,k,x,y,w;
    cin>>n>>m>>k;
    fore(i,1,m+1){
        cin>>x>>y>>w;
        adj[x].push_back({y,{w,i}});
        adj[y].push_back({x,{w,i}});
    }

    vi ans;

    priority_queue<pli, vector<pli>, greater<pli>> q;
    vl dist(n+1,inf);
    vl par(n+1,-1); // saves edge id
    vb visited(n+1);
    int src = 1;
    dist[src] = 0;
    q.push({0,src});

    int cnt = 0;

    while(!q.empty() && cnt<k){
        ll d = q.top().first;
        int v = q.top().second;

        q.pop();
        visited[v] = true;

        // We already found a better path before we got to
        // processing this node so we can ignore it.
        if(dist[v] < d) continue;

        if(par[v]!=-1){
            ++cnt;
            ans.push_back(par[v]);
        }

        for(auto edge: adj[v]){
            int to = edge.first;
            int len = edge.second.first;
            int id = edge.second.second;

            // You cannot get a shorter path by revisiting
            // a node you have already visited before.
            if(visited[to]) continue;

            if(dist[v] + len < dist[to]){
                dist[to] = dist[v] + len;
                par[to] = id;
                q.push({dist[to], to});
            }
        }
    }

    cout<<sz(ans)<<endl;
    print(ans);

    return 0;
}