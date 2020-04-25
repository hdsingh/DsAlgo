#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define pb push_back
#define deb(x) cout<<#x<<" "<<x<<endl;
#define deb2(x, y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define deb3(x, y, z) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<bool> vb;

template <typename T>void print(T v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<v.size(); i++)cout<<setw(w)<<i<<" ";cout<<endl;}for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(w)<<*i<<" ";cout<<endl;}
template <typename T>void print_vv(T v){if(v.size()==0) {cout<<"Empty"<<endl; return;} int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}

// Refer: https://cp-algorithms.com/graph/strongly-connected-components.html
// Lets say in a graph we have two SCCs
// 5->4->3->2->1->0, and 6->7->8
// First find an order to visit the nodes,
// This order will ensure that we visit 5 and 6 (i.e  starting node of a SCC)
// before visiting any other node.
// Function dfs1 fills the list order with vertices in increasing order of their exit times (actually, it is making a topological sort)

int n;
int nax = 15;
vvi adj(nax);
vb used(nax);
vi component, order;

// Find order
void dfs1(int x){
    used[x] = true;
    for(auto ad: adj[x])
        if(!used[ad])
            dfs1(ad);

    order.pb(x);
}

// visit and store components
void dfs2(int x){
    used[x] = true;
    component.pb(x);
    for(auto ad: adj[x])
        if(!used[ad])
            dfs2(ad);
}


void find_sccs(){
    used.assign(nax, false);
    forn(i,n)
        if(!used[i])
            dfs1(i);
    
    used.assign(nax, false);
    forn(i,n){
        int v = order[n-1-i];
        if(!used[v]){

            dfs2(v);
            print(component);
        
            component.clear();
        }
    }
}

int main(){
    n = 10;
    vvi edges = {{5,4},{4,3},{3,2},{2,1},{1,0},
                 {6,7},{7,8},{8,9},
                };
    for(auto ed: edges)
        adj[ed[0]].pb(ed[1]);

    find_sccs();  
    
    
    return 0;
}
