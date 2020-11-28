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

class RMQ{
    int n;
    vi logs;
    vvi table;
public:
    RMQ(vi &a){
        n = a.size();
        logs.assign(n+1,0);
        for(int i=2; i<=n; ++i)
            logs[i] = logs[i/2]+1;
    
        table.assign(logs[n]+1, vi(n));

        for(int i=0; i<=logs[n]; ++i){
            int curLen = 1<<i;
            for(int j=0; j+curLen<=n; ++j){
                if(curLen==1)
                    table[i][j] = a[j];
                else 
                    table[i][j] = min(table[i-1][j], table[i-1][j + curLen/2]);
            }
        }
    }

    int query(int l, int r){
        int p = logs[r-l+1];
        int plen = 1<<p;
        return min(table[p][l], table[p][r-plen+1]);
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin>>n;
    vi a(n); forn(i,n) cin>>a[i];
    RMQ rmq(a);
    int q; cin>>q;
    while(q--){
        int l, r; cin>>l>>r;
        cout<<rmq.query(l,r)<<"\n";
    }
    return 0;
}

// http://www.spoj.com/problems/RMQSQ/
// https://www.spoj.com/problems/THRBL/