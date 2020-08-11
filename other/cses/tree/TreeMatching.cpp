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
const int mod = 1e9 + 7;
template<class T, class U> inline void add_self(T &a, U b){a += b;if (a >= mod) a -= mod;if (a < 0) a += mod;}
template<class T, class U> inline void min_self(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void max_self(T &x, U y) { if (y > x) x = y; }

int n;
const int nax = 2e5+10;
vvi adj(nax);
vi chsum(nax), sum(nax);

void dfs(int x, int p){
    for(auto ad: adj[x]){
        if(ad==p) continue;
        dfs(ad,x);
        chsum[x]+=sum[ad];
    }

    for(auto ad: adj[x]){
        if(ad==p) continue;
        max_self(sum[x], 1 + chsum[x] - sum[ad] + chsum[ad]);
    }
}

// For a particular node, find sum of all its ch.
// Now we can match this node with one of its child,
// hence that child instead of matching with its children, 
// will be matched with this node. So
// By finding the sum of matchings of all ch (chsum)
// we can easily check with which child should we match
// by 1 + chsum[x] - sum[ad] + chsum[ad], (+1 since new edge is created)
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    forn(i,n-1){
        int x, y; cin>>x>>y;
        adj[x].pb(y), adj[y].pb(x);
    }    
    dfs(1,0);
    cout<<sum[1]<<"\n";
    return 0;
}