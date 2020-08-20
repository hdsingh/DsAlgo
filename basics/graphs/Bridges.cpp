#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define pb push_back
#define deb(x) cout<<#x<<" "<<x<<endl;
#define all(x) x.begin(), x.end()
#define sz(a) int((a).size())
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

template <typename T>void print(T v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<v.size(); i++)cout<<setw(w)<<i<<" ";cout<<endl;}for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(w)<<*i<<" ";cout<<endl;}
template <typename T>void print_vv(T v){if(v.size()==0) {cout<<"Empty"<<endl; return;} int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}

// Ref: https://www.youtube.com/watch?v=ECKTyseo2H8 + CpAlgo
const int nax = 5;
vvi adj(nax);
vi tin(nax), low(nax), vis(nax);
// low: lowest ancestor 's time that can be reached directly from this node
int timer;

void dfs1(int x, int par){
    vis[x] = 1;
    tin[x] = low[x] = timer++;

    for(auto ad: adj[x]){
        if(ad==par) continue;
        if(vis[ad]){ // back edge, ad is ancestor of x
            // back edge can't be a bridge
            low[x] = min(low[x], tin[ad]);
        }else{ // forward edge
            dfs1(ad, x); // go ahead and let ad discover its low time
            if(low[ad]>tin[x]) // is not connected to any ancestor
                cout<<x<<"->"<<ad<<" is a bridge \n";

            low[x] = min(low[x], low[ad]);
            // If a child can reach the low ancestor, the par also can via child 

        }
    }
}

// concise
void dfs(int node, int p){
    tin[node] = low[node] = timer++;
    vis[node] = 1;
    for(auto ad: adj[node]){
        if(ad==p) continue;
        if(vis[ad]){ // back edge
            low[node] = min(low[node], tin[ad]);
        }else{
            dfs(ad, node);
            low[node] = min(low[node], low[ad]);

            if(low[ad]>tin[node]){ // no back edge found
                cout<<ad<<"->"<<node<<" is a bridge\n";
            }
        }
    }
}

int main(){
    int n,m,x,y;
    vvi edges = {{1,2},{2,3},{3,4},{2,4}};
    // edges = {{1,2},{1,3},{1,4}};
    for(auto e: edges){
        adj[e[0]].pb(e[1]), adj[e[1]].pb(e[0]);
    }

    dfs(1,-1);

    print(tin,1);
    print(low);

    return 0;
}

// Usage:
// https://codeforces.com/problemset/problem/118/E
// https://leetcode.com/problems/critical-connections-in-a-network/