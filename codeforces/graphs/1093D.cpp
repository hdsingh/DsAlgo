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

const int mod = 998244353;
const int N = 3e5 + 10;

ll powMod(ll n, ll p) { 
	ll res = 1;
	while (p) {
		if (p & 1) (res *= n) %= mod;
		(n *= n) %= mod;
		p >>= 1;
	}
	return res;
}

int t,n,m,u,v;
vvi adj;
vi cnt(2);
vi cols;
vi p2(N);
bool is_bipartite;

void dfs(int cur, int c){
    cols[cur] = c;
    cnt[c]++;

    for(auto ad: adj[cur]){
        if(cols[ad]==-1){
            dfs(ad, 1-c);
        }else{
            is_bipartite &= (cols[cur]!=cols[ad]);
        }
    }
}

// Lets check if graph is bipartite
// Here imp pt to keep in mind is that graph may be disconnected,
// So process accordingly
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    p2[0] = 1;
    for(int i = 1; i < N; ++i)
    	p2[i] = (2 * p2[i - 1]) % mod;

    cin>>t;
    while(t--){
        cin>>n>>m;
        adj.clear(); adj.resize(n);
        cols.assign(n,-1);
        is_bipartite = true;

        forn(i,m){
            cin>>u>>v;
            --u, --v;
            adj[u].pb(v); adj[v].pb(u);
        }

        ll res = 1;
        forn(i,n){
            if(cols[i]!=-1) continue;
            cnt[0] = cnt[1] = 0;
            dfs(i,0);
            if(!is_bipartite) break;
            ll sum = powMod(2, cnt[0]) + powMod(2, cnt[1]);
            res = (res * sum)%mod;
        }

        if(!is_bipartite)
            cout<<0<<endl;
        else{
           cout<<res<<endl; 
        }

    }
    
    return 0;
}