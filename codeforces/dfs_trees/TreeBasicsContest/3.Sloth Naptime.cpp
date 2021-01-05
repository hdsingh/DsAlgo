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

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; 
    while(cin>>n){
        vvi adj(n+1);
        forn(i,n-1){
            int x, y; cin>>x>>y;
            adj[x].pb(y); adj[y].pb(x);
        }
        int LG = log2(n)+1;
        vvi par(LG, vi(n+1));
        vi level(n+1), tin(n+1), tout(n+1);
        int tim = 0;

        function<void(int,int,int)> dfs = [&](int node, int p, int lev){
            tin[node] = tim++;
            par[0][node] = p;
            level[node] = lev;

            for(auto ad: adj[node]){
                if(ad==p) continue;
                dfs(ad, node,lev+1);
            }
            tout[node] = tim++;
        };

        dfs(1,0,0);
        fore(j,1,LG){
            fore(i,1,n+1){
                if(par[j-1][i])
                    par[j][i] = (par[j-1][par[j-1][i]]);
            }
        }

        auto lca = [&](int a, int b){
            // a deeper 
            if(level[a]<level[b]) swap(a,b);
            int dif = level[a] - level[b];
            
            for(int i=LG-1; i>=0; --i){
                if((dif>>i)&1)
                    a = par[i][a];
            }
            
            if(a==b) return a;

            for(int i=LG-1; i>=0; --i){
                if(par[i][a] && par[i][a]!=par[i][b]){
                    a = par[i][a], b = par[i][b];
                }
            }
            return par[0][a];
        };  

        auto walk = [&](int node, int dist){
            for(int i=LG-1; i>=0; --i){
                if((dist>>i)&1) 
                    node = par[i][node];
            }
            return node;
        };

        auto dist = [&](int a, int b){
            return level[a] + level[b] - 2*level[lca(a,b)];
        };

        auto isAncestor = [&](int a, int b){
            return tin[a]<=tin[b] && tout[a]>=tout[b];
        };

        int q; cin>>q;
        while(q--){
            int a, b, c; cin>>a>>b>>c;
            // deb(a,b,c);
            int d = dist(a,b);
            if(isAncestor(a,b) && level[a]<=level[b]){
                c = min(c,d);
                cout<<walk(b,d-c)<<"\n";
            }else{
                int lc = lca(a,b);
                int alc = dist(a,lc); // a to lc
                int lcb = dist(lc,b); // lc to b
                if(c<=alc){
                    cout<<walk(a,c)<<"\n";
                }else if(c<alc+lcb){
                    // walk up from b the rem dist
                    cout<<walk(b, lcb - (c-alc))<<"\n";
                }else{
                    cout<<b<<"\n";
                }
            }
            // cout<<"\n";
        }
    }
    return 0;
}