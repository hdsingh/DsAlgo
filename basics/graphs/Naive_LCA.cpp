#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

// Ref: https://www.youtube.com/watch?v=g48iAXLt5XU
int N;
vi level;
vi par;
// int LG = log2(N) + 1; // max height of tree

int lca(int u, int v){
    // we suppose the u is deeper
    if(level[u]<level[v])
        swap(u,v);
    int dif = level[u] - level[v];
    // use this dif to bring them to same level
    while(dif>0){
        v = par[v];
        --dif;
    }

    if(u==v) return u;
    while(par[u]!=par[v])
        u = par[u], v = par[v];
    
    return par[u];
}

int main(){
    
    return 0;
}