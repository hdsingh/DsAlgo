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

const int nax = 5000 + 10;
int n,m,s,u,v,cnt;
vb vis(nax), good(nax);
vvi adj(nax);

void dfs1(int src){
    good[src] = true;
    for(auto ad: adj[src]){
        if(!good[ad]){
            dfs1(ad);
        }
    }
};

void dfs2(int src){
    vis[src] = true;
    ++cnt;
    for(auto ad: adj[src]){
        if(!good[ad] && !vis[ad])
            dfs2(ad);
    }
}

// ans = # of SCC with indeg 0;
// 0. simple connected comps wont work bec, 
//   1->2->3->4->5->6 so if lets say we visit node 4 before visiting 1, then we will get comps 
//   size as 2+ however the actual size is 1, hence we need a specific order.
//   i.e visit the head, whcih will have the max bad nodes count
// 1. Find the good edges (reachabel from the src)
// 2. for each bad edge count the number of bad nodes reachable from it
// 3. Sort and Pick nodes based on max bad nodes unreachable, do it till all have been visited

int main(){
    cin>>n>>m>>s;
    forn(i,m){
        cin>>u>>v;
        adj[u].pb(v);
    }
    
    dfs1(s);

    // Count the bad nodes reachable from a bad node

    vector<pii> badList;
    fore(i,1,n+1){
        if(!good[i]){
            cnt = 0;
            vis.assign(nax,false);
            dfs2(i);
            badList.pb({cnt,i});
        }
    }

    sort(all(badList));
    reverse(all(badList));

    int ans = 0;
    for(auto p: badList){
        if(!good[p.second]){
            ++ans;
            dfs1(p.second);
        }
    }

    cout<<ans<<endl;

    return 0;
}