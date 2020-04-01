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
const int mod = 998244353;
template<class T, class U> inline void add_self(T &a, U b){a += b;if (a >= mod) a -= mod;if (a < 0) a += mod;}
template<class T, class U> inline void min_self(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void max_self(T &x, U y) { if (y > x) x = y; }

template <typename T>void print(T v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<v.size(); i++)cout<<setw(w)<<i<<" ";cout<<endl;}for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(w)<<*i<<" ";cout<<endl;}
template <typename T>void print_vv(T v){if(v.size()==0) {cout<<"Empty"<<endl; return;} int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}
template <class T, class U> void print_m(map<T,U> m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}

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

// Lets check if graph is bipartite
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--){
        cin>>n>>m;
        adj.clear(); adj.resize(n);

        forn(i,m){
            cin>>u>>v;
            --u, --v;
            adj[u].pb(v); adj[v].pb(u);
        }

        vi cols(n,-1);
        bool is_bipartite = true;
        ll res = 1;

        for(int i=0; i<n; ++i){
            if(cols[i]!=-1) continue;
            
            vi cnt(2);

            cols[i] = 0;
            queue<int> q;
            q.push(i);

            while(q.size()){
                int cur = q.front(); q.pop();
                cnt[cols[cur]]++;

                for(auto ad: adj[cur]){
                    if(cols[ad]==-1){
                        cols[ad] = cols[cur] ^ 1;
                        q.push(ad);
                    }else{
                        is_bipartite &= (cols[ad]!=cols[cur]);
                    }
                }
            }

            if(!is_bipartite) break;

            ll out = powMod(2, cnt[0]) + powMod(2, cnt[1]);
            res = (res*out)%mod;
        }

        if(!is_bipartite){
            cout<<0<<endl;
        }else{
            cout<<res<<endl;
        }


    }
    
    return 0;
}