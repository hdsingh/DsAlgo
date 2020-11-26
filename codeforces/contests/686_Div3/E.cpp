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

int n;
vvi adj;
vb vis;
vi inCycle;
vi par;

bool dfs(int node, int p){
    par[node] = p;
    vis[node] = 1;
    for(auto ad: adj[node]){
        if(!vis[ad]){
            if(dfs(ad, node))
                return true;
        }else if(ad!=p){
            int x = node;
            while(x!=ad){
                inCycle.pb(x);
                x = par[x];
            }
            inCycle.pb(ad);
            return true;
        }
    }
    return false;
}



void dfs2(int node, int p, ll &comp){
    ++comp;
    vis[node] = 1;
    for(auto ad: adj[node]){
        if(!vis[ad]){
            dfs2(ad, node, comp);
        }
    }
}

// Find all the comps of nodes present in cycle
// Case 1: inside the comp : nc2
// Case 2: among 2 diff comps
// from A to others: A*(n-A); 
// Since it is a cycle there are 2 ways, 
// Now we are accounting only 1.
// The other will be noted when processing other comp.

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        adj.assign(n+1,{});    
        vis.assign(n+1,0); 
        par.assign(n+1,0);
        inCycle.clear();   
        forn(i,n){
            int x, y; cin>>x>>y;
            adj[x].pb(y); adj[y].pb(x);
        }

        fore(i,1,n+1){
            if(!vis[i]){
                dfs(i,0);
                if(inCycle.size()) break;
            }
        }
        vis.assign(n+1,0);
        for(auto x: inCycle) vis[x] = 1;

        ll ans = 0;
        for(auto x: inCycle){
            ll comp = 0;
            dfs2(x, 0, comp);
            ans+=(comp*(comp-1))/2;
            ans+=comp*(n-comp);
        }
        cout<<ans<<"\n";
    }
    return 0;
}