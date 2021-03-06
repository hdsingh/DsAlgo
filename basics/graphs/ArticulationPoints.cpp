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

// Ref: https://www.youtube.com/watch?v=iGGolqb6gDE, cpalgos

const int nax = 10;
vvi adj(nax);
vi in(nax), low(nax), vis(nax);
int timer;

void dfs(int x, int par){
    vis[x] = 1;
    in[x] = low[x] = timer++;

    int child = 0;
    for(auto ad: adj[x]){
        if(ad==par) continue;
        if(vis[ad]){ // back_edge
            low[x] = min(low[x], in[ad]);
        }else{ // forward edge
            // go and try decrement the low time of ad, by checking if it connects to some ancestor
            dfs(ad,x); 
            low[x] = min(low[x], low[ad]);

            // we are not succesful in finding a better low time for ad, i.e
            // some ancestor was not found, then this is cut point, 
            // except root, (since it always satifies this condition)
            if(low[ad]>=in[x] && par!=-1)
                cout<<x<<" is a cut point \n";
            
            ++child;
        }
    }   

    if(par==-1 && child>1)
        cout<<x<<" is a cut point \n";
}

int main(){
    vvi edges = {{1,2},{1,3},{1,4}};
    edges = {{1,2},{2,3},{3,1},{1,4}};
    for(auto e: edges)
        adj[e[0]].pb(e[1]) , adj[e[1]].pb(e[0]);
    dfs(1,-1);
    return 0;
}

// Usage: 
// https://www.spoj.com/problems/SUBMERGE/