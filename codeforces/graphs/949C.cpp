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

// In a SCC, I want to find a smallest comp, having no outgoing edge.
// SCC can be found using Kosaraju.
// If from a comp path to oth comp exists, then that comp is bad.
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, H;
    while(cin>>n>>m>>H){
        vi a(n+1); fore(i,1,n+1) cin>>a[i];
        vvi adj(n+1), radj(n+1);

        auto add = [&](int x, int y){
            adj[x].pb(y); radj[y].pb(x);
        };

        
        forn(i,m){
            int x, y; cin>>x>>y;
            if((a[x]+1)%H==a[y]) add(x,y);
            if((a[y]+1)%H==a[x]) add(y,x);
        }

        vb vis(n+1);
        vi order;
        function<void(int)> dfs1 = [&](int node){
            vis[node] = 1;
            for(auto ad: adj[node]){
                if(!vis[ad]) 
                    dfs1(ad);
            }       
            order.pb(node);
        };

        fore(i,1,n+1){
            if(!vis[i])
                dfs1(i);
        }

        reverse(all(order));

        vis.assign(n+1,0);
        vi comp;
        vvi comps; 
        vi color(n+1,-1);
        int C = 0;
    
        function<void(int)> dfs2 = [&](int node){
            vis[node] = 1;
            comp.pb(node);
            color[node] = C;
            for(auto ad: radj[node]){
                if(!vis[ad]){
                    dfs2(ad);
                }
            }
        };

        for(auto node: order){
            if(!vis[node]){
                comp.clear();
                dfs2(node);
                
                comps.pb(comp);
                ++C;
            }
        }

        vi bad(C);
        fore(node,1,n+1){
            for(auto ad: adj[node]){
                if(color[node]!=color[ad]){
                    bad[color[node]] = 1;
                }
            }
        }

        vi ans;
        forn(c,C){
            if(bad[c]) continue;
            if(ans.empty() || sz(comps[c])<sz(ans))
                ans = comps[c];
        }
        cout<<sz(ans)<<"\n";
        print(ans);
    }   
    return 0;
}