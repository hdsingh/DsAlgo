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

const int nax = 2e5+10;
int n;
vvi adj(nax);
vi dp(nax);

void dfs(int x, int p){
    for(auto ad: adj[x]){
        if(ad==p) continue;
        dfs(ad,x);
        dp[x]+=dp[ad];
    }
    dp[x]++;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    fore(i,2,n+1){
        int p; cin>>p;
        adj[p].pb(i), adj[i].pb(p);
    }
    dfs(1,0);
    fore(i,1,n+1) cout<<dp[i]-1<<" ";
    return 0;
}