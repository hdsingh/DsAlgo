#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define pb push_back
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

int n;
const int nax = 2e5+10;
vvi adj(nax);

// farthest node, dist
pii bfs(int x){
    int far = x;
    vi dist(n+1,-1);
    dist[x] = 0;
    queue<int> q;
    q.push(x);

    while(sz(q)){
        int top = q.front(); q.pop();
        far = top;
        for(auto ad: adj[top]){
            if(~dist[ad]) continue;
            dist[ad] = dist[top]+1;
            q.push(ad);
        }
    }
    return {far, dist[far]};
}

// 1. select a node and find the farthest node from it (A);
// 2. from A find the distance to the farthest node.
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    forn(i,n-1){
        int x, y; cin>>x>>y;
        adj[x].pb(y), adj[y].pb(x);
    }

    pii p1 = bfs(1);
    pii p2 = bfs(p1.first);
    cout<<p2.second<<"\n";

    return 0;
}