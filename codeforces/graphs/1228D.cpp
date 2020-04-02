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

template <typename T>void print(T v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<v.size(); i++)cout<<setw(w)<<i<<" ";cout<<endl;}for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(w)<<*i<<" ";cout<<endl;}
template <typename T>void print_vv(T v){if(v.size()==0) {cout<<"Empty"<<endl; return;} int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}
template <class T, class U> void print_m(map<T,U> m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}

// Refer: https://codeforces.com/contest/1228/submission/61578861

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m,x,y;
    scanf("%d%d", &n, &m);
    vector<set<int>> edges(n+1);
    forn(i,m){
        scanf("%d%d", &x,&y);
        edges[x].insert(y),edges[y].insert(x);
    }

    // assign groups
    vi group(n+1, -1);
    forn(g,3){
        int first;
        for(first = 1; first<=n; ++first) if(group[first]==-1) break;
        if(first==n+1) { cout<<-1<<endl; return 0;}

        group[first] = g;
        fore(second, 1, n+1){
            if(first!=second && group[second]==-1 && edges[first].count(second)==0)
                group[second] = g;
        }
    }

    // all vertices should be in some group
    vvi groups(3);
    fore(i,1,n+1){
        if(group[i]==-1){cout<<-1<<endl; return 0;}
        groups[group[i]].pb(i);
    }

    // edge counting and completeness check
    // each edge from 1 set must be connected to each component of other set
    int found_edges = 0;
    for(int g1=0; g1<3; ++g1){
        for(int g2=g1+1; g2<3; ++g2){
            for(auto v1: groups[g1])
                for(auto v2: groups[g2]){
                    if(edges[v1].count(v2)==0){cout<<-1<<endl; return 0;}
                    ++found_edges;
                }
        }
    }

    // Edge validation
    if(found_edges!=m) {cout<<-1<<endl; return 0;}
    fore(i,1,n+1) cout<<group[i]+1<<" "; cout<<endl;

    return 0;
}