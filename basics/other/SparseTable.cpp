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

const int nax = 1e5 + 10;
const int maxlog = 20;
int n;
int logs[nax];
vi a(nax);
vvi table(maxlog, vi(nax));
// ans in range 2^i, starting at index j

void computeLogs(){
    for(int i=2; i<nax; ++i)
        logs[i] = logs[i/2] + 1;
}

void buildSparseTable(){
    computeLogs();
    for(int i=0; i<=logs[n]; ++i){
        int curlen = 1<<i;
        for(int j=0; j + curlen<=n; ++j){
            if(curlen==1)
                table[i][j] = a[j];
            else 
                table[i][j] = min(table[i-1][j], table[i-1][j + (curlen/2)]);
        }
    }
}

int getMin(int l, int r){
    int p = logs[r-l+1];
    int plen = (1<<p);
    return min(table[p][l], table[p][r - plen + 1]);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    forn(j,n) cin>>a[j];
    buildSparseTable();
    int q; cin>>q;
    while(q--){
        int l, r; cin>>l>>r;
        cout<<getMin(l,r)<<"\n";
    }
    return 0;
}

// http://www.spoj.com/problems/RMQSQ/
// https://www.spoj.com/problems/THRBL/