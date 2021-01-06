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

// Remove all the leaf nodes so that only cycles remain.
// since for the leaves we can't revisit them, we will propagate thier extra value above
// in the end take sum of all remaining nodes in cycle + 1 extra.
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    while(cin>>n>>m){
        vl ws(n+1); fore(i,1,n+1) cin>>ws[i];
        vvi adj(n+1);
        vi deg(n+1);
        forn(i,m){
            int x, y; cin>>x>>y;
            adj[x].pb(y); adj[y].pb(x);
            deg[x]++; deg[y]++;
        }
        int st; cin>>st;
        queue<int> q;
        vi par(n+1);
        vb vis(n+1);
        
        function<void(int,int)> dfs = [&](int node, int p){
            vis[node] = 1;
            par[node] = p;
            for(auto ad: adj[node]){
                if(!vis[ad]){
                    dfs(ad, node);
                }
            }
        };

        dfs(st,0);

        // add all leafs to q except s, and keep on eleiminating the leaves
        // till we have only the cycles left, which can't be removed 
        // almost same logic as in Kahn's algo
        fore(i,1,n+1){
            if(deg[i]==1 && i!=st){
                q.push(i);
                // deb(i);
            }
        }    

        vl extra(n+1);
        while(!q.empty()){
            auto top = q.front(); q.pop();
            --deg[top];
            // deb(top);
            int p = par[top];
            max_self(extra[p], extra[top] + ws[top]);
            if(--deg[p]==1 && p!=st){
                q.push(p);
                // deb(p);
            }
        }
        // print(par,1);
        // print(deg);
        ll mx = *max_element(all(extra));
        ll ans = 0;
        fore(i,1,n+1){
            if(i!=st){ // st could be a leaf since it is start.
                if(deg[i]==1){
                    deb(i);
                }
                assert(deg[i]!=1); // there is no other leaf now.
            }
        
            if(deg[i]>=2 || i==st){ // in cycle
                ans+=ws[i];
            }
        }
        cout<<ans+mx<<"\n";
    }
    return 0;
}