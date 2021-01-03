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
        vi sub(n+1);
        vi flat, idx(n+1), lev(n+1);
        vi deg(n+1);
        vvi adj(n+1);
        vector<pii> edges;
        forn(i,n-1){
            int x,y; cin>>x>>y;
            adj[x].pb(y); adj[y].pb(x);
            edges.pb({x,y});
            deg[x]++; deg[y]++;
        }

        function<void(int, int, int)> dfs = [&](int node, int p, int l){
            idx[node] = sz(flat);
            lev[node] = l;

            flat.pb(node);
            for(auto ad: adj[node]){
                if(ad==p) continue;
                dfs(ad, node,l+1);
                sub[node]+=sub[ad];
            }
            sub[node]++;
        };

        int root = 0;
        fore(i,1,n+1){
            if(deg[i]==1){
                root = i;
                break;
            }
        }
        // deb(root);

        assert(root);
        dfs(root,0,0);
        vl ans(n+10);
        // print(flat,1);
        // cout<<"\n";
        // print(idx,1);
        // print(sub);

        auto add = [&](int l, int r, ll val){
            ans[l]+=val;
            ans[r+1]-=val;
        };

        int q; cin>>q;
        while(q--){
            int t, e,x; cin>>t>>e>>x;
            --e;
            int a = edges[e].first, b = edges[e].second;
            if(t==1){
                if(lev[a]<lev[b]){
                    add(0,n+2,x);
                    // remove from b
                    add(idx[b], idx[b] + sub[b]-1, -x);
                }else{
                    // only add in b
                    add(idx[a], idx[a] + sub[a]-1, x);
                }
            }else{
                if(lev[a]<lev[b]){
                    // only add in b
                    add(idx[b], idx[b] + sub[b]-1, x);
                }else{
                    add(0,n+2,x);
                    // remove from b
                    add(idx[a], idx[a] + sub[a]-1, -x);
                }

            }
            
        }
        partial_sum(all(ans), ans.begin());
        fore(i,1,n+1){
            cout<<ans[idx[i]]<<"\n";
        }
    }
    return 0;
}