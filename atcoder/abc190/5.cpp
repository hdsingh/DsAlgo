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
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7;
template<class T, class U> inline void add_self(T &a, U b){a += b;if (a >= mod) a -= mod;if (a < 0) a += mod;}
template<class T, class U> inline void min_self(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void max_self(T &x, U y) { if (y > x) x = y; }

#define _deb(x) cout<<x;
void _print() {cerr << "]\n";} template <typename T, typename... V>void _print(T t, V... v) {_deb(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#define deb(x...) cerr << "[" << #x << "] = ["; _print(x)
template <class T, class U> void print_m(const map<T,U> &m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}
template<class T, class U>void debp(const pair<T, U> &pr, bool end_line=1){cout<<"{"<<pr.first<<" "<<pr.second<<"}"; cout<<(end_line ? "\n" : ", ");}
template <class T> void print_vp(const T &vp, int sep_line=0){if(vp.empty()){cout<<"Empty"<<endl; return;}if(!sep_line) cout<<"{ ";for(auto x: vp) debp(x,sep_line);if(!sep_line) cout<<"}\n";cout<<endl;}
template <typename T>void print(const T &v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<sz(v); i++)cout<<setw(w)<<i<<" ";cout<<endl;}for(auto &el: v) cout<<setw(w)<<el<<" ";cout<<endl;}
template <typename T>void print_vv(const T &vv){if(sz(vv)==0) {cout<<"Empty"<<endl; return;} int w = 3;cout<<setw(w)<<" ";for(int j=0; j<sz(*vv.begin()); j++)cout<<setw(w)<<j<<" ";cout<<endl;int i = 0;for(auto &v: vv){cout<<i++<<" {";for(auto &el: v) cout<<setw(w)<<el<<" ";cout<<"},\n";}cout<<endl;}
template <typename T> ostream& operator<<(ostream &os, const vector<T> &v){print(v); return os;};
template <typename T> ostream& operator<<(ostream &os, const vector<vector<T>> &vv){print_vv(vv); return os;};
template <class T, class U> ostream& operator<<(ostream &os, const map<T,U>  &m){print_m(m); return os;};
template <class T, class U> ostream& operator<<(ostream &os, const pair<T, U> &pr){debp(pr); return os;};
template <class T, class U> ostream& operator<<(ostream &os, const vector<pair<T, U>> &vp){ print_vp(vp); return os;};

const int inf = 1e9+10;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    while(cin>>n>>m){
        vvi adj(n+1);
        forn(i,m){
            int x, y; cin>>x>>y;
            adj[x].pb(y); adj[y].pb(x);
        }
        int K; cin>>K;
        vi C(K); forn(i,K) cin>>C[i];
        
        auto findDist = [&](int node){
            vi dist(n+1,inf);
            dist[node] = 0;
            queue<int> q;
            q.push(node);

            while(!q.empty()){
                auto top = q.front(); q.pop();

                for(auto ad: adj[top]){
                    if(dist[ad]==inf){
                        dist[ad] = dist[top] + 1;
                        q.push(ad);
                    }
                }
            }
            return dist;
        };

        unordered_map<int,int> idx;
        int I = 0;
        for(auto x: C){
            idx[x] = I++;
        }

        vvi dist(K, vi(K));
        for(auto x: C){
            auto tempDist = findDist(x);
            for(auto y: C){
                dist[idx[x]][idx[y]] = tempDist[y];
            }
        }

        vector<vector<int>> dp(1<<K,vector<int>(K,inf));
        // shotest length of path covering subset s, if the last vis node is x.
        for(int i=0; i<K; ++i) dp[1<<i][i] = 0;
        
        for(int mask=0; mask<(1<<K); ++mask){
            for(int last=0; last<K; ++last){
                if( !((mask>>last)&1) || dp[mask][last]>=inf) continue;
                for(int next=0; next<K; ++next){
                    if(next==last || ((mask>>next)&1)) continue;
                    min_self(dp[mask|(1<<next)][next],  dp[mask][last] + dist[last][next]); 
                }
            }
        }
        int ans = inf;
        forn(last,K){
            min_self(ans, dp[(1<<K)-1][last]+1);
        }
        if(ans>=inf) ans = -1;
        cout<<ans<<"\n";
    }
    return 0;
}