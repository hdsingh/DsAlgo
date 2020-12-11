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

struct edge{
    int wt,x,y, id;
    bool inMST = false;
    bool operator<(const edge &oth) {
        return wt<oth.wt;   
    }
};

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
};

const int nax = 2e5+10;
int n, m, T = 0;
const int LG = log2(nax)+1;
vector<vector<pii>> adj(nax); // {wt, ad}
vvi par(LG, vi(nax+1));
vvi dp(LG, vi(nax+1)); // 
vi level(nax), tin(nax), tout(nax);

void dfs(int node, int p, int lev, int edWt){
    tin[node] = ++T;
    par[0][node] = p;
    dp[0][node] = edWt;
    level[node] = lev;
    for(auto [wt, ad]: adj[node]){
        if(ad==p) continue;
        dfs(ad, node, lev+1, wt);
    }
    tout[node] =  ++T;
}

int lca(int a, int b){
    // a is deeper
    if(level[a]<level[b])
        swap(a,b);

    int dif = level[a] - level[b];
    for(int i=LG-1; i>=0; --i){
        if((dif>>i)&1)
            a = par[i][a];
    }

    if(a==b) return a;
    for(int i=LG-1; i>=0; --i){
        if(par[i][a] && par[i][a]!=par[i][b]){
            a = par[i][a];
            b = par[i][b];
        }
    }

    return par[0][a];
}

int dist(int a, int b){
    return level[a] + level[b] - 2*level[lca(a,b)];
}

bool is_ancestor(int u, int v){
    return tin[u]<=tin[v] && tout[u]>=tout[v];
}


// 1. Create a MST
// 2. If an edge is part of mst wt is same
// 3. Since the mst is a tree, for an edge e: (x,y)
// will always be a part of tree. So we should find the heaviest edge on the path bw x,y
// and remove it, since x,y would be connected by the new edge we are adding.
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    vector<edge> edges(m);
    forn(i,m){
        cin>>edges[i].x>>edges[i].y>>edges[i].wt;
        edges[i].inMST = 0, edges[i].id = i;
    }   

    sort(all(edges));

    DSU ds(n+1);
    ll mstWt = 0;
    
    for(auto &ed: edges){
        auto &[wt, x, y, id, inMST] = ed;
        if(ds.unite(x,y)){
            mstWt+=wt;
            adj[x].pb({wt,y});
            adj[y].pb({wt,x});
            inMST = 1;
        }
    }

    dfs(1,0,0,0);
    for(int i=1; i<LG; ++i){
        for(int j=1; j<=n; ++j){
            if(par[i-1][j]){
                par[i][j] = par[i-1][par[i-1][j]];
                dp[i][j] = max(dp[i-1][j], dp[i-1][par[i-1][j]]);
            }
        }
    }

    auto wtWalk = [&](int a, int d){
        ll ans = dp[0][a];
        for(int i=LG-1; i>=0; --i){
            if((d>>i)&1){
                ans = max(ans, (ll)dp[i][a]);
                a = par[i][a];
            }
        }
        return ans;
    };  


    function<ll(int,int)> getWt = [&](int a, int b){
        if(level[a]<level[b]) swap(a,b);
        if(is_ancestor(b,a)){
            int d = level[a] - level[b];
            return wtWalk(a, d);
        }
        int lc = lca(a,b);
        int d1 = level[a] - level[lc];
        int d2 = level[b] - level[lc];
        return max(wtWalk(a,d1), wtWalk(b,d2));
    };

    vl ans(m);
    for(auto ed: edges){
        if(ed.inMST){
            ans[ed.id] = mstWt;
        }else{
            ll maxWt = getWt(ed.x, ed.y);
            ans[ed.id] = mstWt + ed.wt - maxWt;
        }
    }

    print(ans);
    
    return 0;
}