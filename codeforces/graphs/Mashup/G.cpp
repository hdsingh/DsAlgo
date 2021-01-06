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

class DSU{
public:
	vector<int> par, ranks;

	DSU(int n){
		par.assign(n+1,0);
		ranks.assign(n+1,0);
		// ranks.assign(n+1,1); // to merge by size
		iota(par.begin(),par.end(), 0); // make a node par of itself
	}

	bool unite(int a, int b){
		a = find_par(a);
		b = find_par(b);
		if(a==b) return false; // already united, since having same par

		if(ranks[a]<ranks[b])
			swap(a,b);
		par[b] = a;

        // to merge by rank
		if(ranks[a]==ranks[b])
			ranks[a]++;
        
        // To merge by size
        // ranks[a]+=ranks[b];

		return true;
	};

	int find_par(int a){
		if(a==par[a]) return a;
		return par[a] = find_par(par[a]);
	}

    bool connected(int a, int b){
        return find_par(a)==find_par(b);
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, D;
    while(cin>>n>>m>>D){
        set<int> adj1;
        vvi adj(n+1);
        forn(i,m){
            int x, y; cin>>x>>y;
            if(x>y) swap(x,y);
            if(x==1) adj1.insert(y);
            else{
                adj[x].pb(y); adj[y].pb(x);
            }
        }
        // cc<= D <= adj1
        if(sz(adj1)<D){
            cout<<"NO\n";
            continue;
        }
        vi comp;
        vb vis(n+1);
        vis[1] = 1; // ignore 1

        function<void(int)> dfs = [&](int node){
            vis[node] = 1;
            comp.pb(node);
            for(auto ad: adj[node]){
                if(!vis[ad]){
                    dfs(ad);
                }
            }
        };

        vvi comps;
        fore(i,2,n+1){
            if(!vis[i]){
                dfs(i);
                comps.pb(comp);
                comp.clear();
            }
        }
        
        if(sz(comps)>D){
            cout<<"NO\n";
            continue;
        }

        DSU ds(n+1);
        vector<pii> tree;
        // connect a single node from every comp.
        for(auto comp: comps){
            if(D<=0) break;
            for(auto c: comp){
                if(adj1.count(c)){
                    tree.pb({1,c});
                    ds.unite(1,c);
                    adj1.erase(c);
                    --D;
                    break;
                }
            }
        }
        // if D>0 connect from any comp
        for(auto ad: adj1){
            if(D<=0) break;
            ds.unite(1,ad);
            --D;
            tree.pb({1,ad});
        }

        fore(i,2,n+1){
            for(auto ad: adj[i]){
                if(!ds.connected(ad,i)){
                    ds.unite(i,ad);
                    tree.pb({i,ad});
                }
            }
        }
        
        if(sz(tree)==n-1){
            cout<<"YES\n";
            for(auto p: tree){
                cout<<p.first<<" "<<p.second<<"\n";
            }
        }else{
            cout<<"NO\n";
        }
    }
    return 0;
}