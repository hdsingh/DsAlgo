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

int n = 3;
vvi adj;
vi color, par;
int cycle_start, cycle_end;

// has cycle
// "void" dfs works better, setting and restting has_cycle globally.
// ex: 711D
bool dfs(int x){
    color[x] = 1;
    for(auto ad: adj[x]){
        if(color[ad]==0){
            par[ad] = x;
            if(dfs(ad)) 
                return true;
        }else if(color[ad]==1){
            cycle_start = ad;
            cycle_end = x;
            return true;
        }
    }
    color[x] = 2;
    return false;
}

vb vis;

// Undirectd Graph 
bool dfs1(int x, int p){
    vis[x] = 1;
    par[x] = p;
    for(auto ad: adj[x]){
        if(vis[ad]==0){
            if(dfs1(ad, x)) 
                return true;
        }else if(ad!=par[x]){
            return true;
        }
    }
    return false;
}


void find_cycle(){
    color.assign(n,0);
    par.assign(n,-1);
    cycle_start = -1;
    // vis.assign(0); // undirected
    forn(v,n){
        if(color[v]==0 && dfs(v))
            break;
    }

    if(cycle_start==-1)
        cout<<"Acyclic"<<endl;
    else{
        vi cycle;
        cycle.pb(cycle_start);
        for(int v = cycle_end; v!=cycle_start; v = par[v])
            cycle.pb(v);
        cycle.pb(cycle_start);
        reverse(all(cycle));

        cout<<"Cycle found: ";
        print(cycle);
    }
}



int main(){
    // adj = {{1},{2},{}}; // 0->1->2 // acyclic
    adj = {{1},{2},{0}}; // 0->1->2->0
    find_cycle();
    return 0;
}

// https://codeforces.com/problemset/problem/1027/D


// https://codeforces.com/problemset/problem/698/B
const int nax = 2e5+10;
int n, root, grp,ans;
vi grps(nax), par(nax);

void dfs1(int x){
    ++grp;
    while(grps[x]==0){
        grps[x] = grp;
        x = par[x];
    }

    if(grps[x]==grp){
        // is a cycle , do handling
        
        if(!root){
            root = x;
        }
        if(par[x]!=root){
            par[x] = root;
            ++ans;
        }
    }
}

// https://codeforces.com/contest/1205/problem/B
// Brute force but required in some cases.
// Disconnect the edge bw i and j, and find the dist 
// bw them. if the dist is non-inf, the cycle len is dist+1;

const int inf = 1e9;
vi dist;
int find_dist(int src, int ed){
    forn(i,n) dist[i] = inf;

    dist[src] = 0;
    queue<int> q;
    q.push(src);

    while(size(q)){
        auto top = q.front(); q.pop();
        for(auto ad: adj[top]){
            if(top==src && ad==ed) continue; // disconnection.
            
            if(dist[ad]>dist[top]+1){
                dist[ad] = dist[top]+1;
                q.push(ad);
            }
        }
    }

    return dist[ed];
}

// forn(i,n){
//     fore(j,i+1,n){
//         if(connected){
//                 min_self(min_clen, find_dist(i,j)+1);
//         }
//     }
// }

// https://leetcode.com/problems/find-eventual-safe-states/