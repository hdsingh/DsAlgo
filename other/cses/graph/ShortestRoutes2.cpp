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

const ll inf = 1e18L;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, q;
    cin>>n>>m>>q;
    vvl dist(n+1, vl(n+1,inf));
    forn(i,n+1) dist[i][i] = 0; // imp
    
    forn(i,m){
        int x, y, c; cin>>x>>y>>c;
        min_self(dist[x][y], c); 
        min_self(dist[y][x], c);
    }

    fore(k,1,n+1)
        fore(i,1,n+1)
            fore(j,1,n+1)
                min_self(dist[i][j], dist[i][k] + dist[k][j]);

    forn(i,q){
        int x, y; cin>>x>>y;
        ll d = dist[x][y];
        if(d>=inf) d=-1;
        cout<<d<<"\n";
    }
    return 0;
}