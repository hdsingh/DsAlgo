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

template <typename T>void print(T v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<v.size(); i++)cout<<setw(w)<<i<<" ";cout<<endl;}for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(w)<<*i<<" ";cout<<endl;}
template <typename T>void print_vv(T v){if(v.size()==0) {cout<<"Empty"<<endl; return;} int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}
template <class T, class U> void print_m(map<T,U> m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}

int n,m,d,u,v;
vvi adj, nadj;
vb vis;
set<int> connected;

void dfs(int x){
    vis[x] = 1;
    for(auto ad: adj[x]){
        if(vis[ad]) continue;
        dfs(ad);
    }
}


void bfs(int x){
    queue<int> q;
    vis[x] = 1;
    q.push(x);
    vis[1] = 0;

    while(!q.empty()){
        int top = q.front(); q.pop();
        for(auto ad: adj[top]){
            if(vis[ad]) continue;
            vis[ad] = 1;
            nadj[ad].pb(top), nadj[top].pb(ad);

            if(ad==1)
                connected.insert(top);

            if(ad!=1)
                q.push(ad);
        }
    }
}

void bfs2(int x){
    queue<int> q;
    vis[x] = 1;
    q.push(x);

    while(!q.empty()){
        int top = q.front(); q.pop();
        for(auto ad: nadj[top]){
            if(vis[ad]) continue;
            vis[ad] = 1;
            q.push(ad);

            cout<<ad<<" "<<top<<endl;
        }
    }

}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    while(cin>>n>>m>>d){
        adj.clear(); adj.resize(n+1);
        nadj.clear(); nadj.resize(n+1);
        vis.clear(); vis.resize(n+1);
        
        forn(i,m)
            cin>>u>>v, adj[u].pb(v), adj[v].pb(u);

        int cc = 0;
        vis[1] = 1;

        fore(i,2,n+1){
            if(vis[i]) continue;
            dfs(i);
            ++cc;
        }

        // deb(cc);
        if(d<cc || d>(int)adj[1].size()){
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;

        vis.assign(n+1,false);

        fore(i,2,n+1){
            if(vis[i]) continue;
            bfs(i); 
            // add edges to new graph from connected component
        }


        vis.assign(n+1,false);

        int rem = d - cc;
        for(auto x: adj[1]){
            if(rem<=0) break;
            if(connected.count(x)==0){
                nadj[x].pb(1), nadj[1].pb(x);
                --rem;
            }
        }

        bfs2(1);

    }
    return 0;
}