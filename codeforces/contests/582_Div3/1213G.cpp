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

class DisjointSet{
public:
	vector<int> par, ranks;
	void make_sets(int n){
		par.clear(); par.resize(n);
		// ranks.clear(); ranks.resize(n);
		ranks.clear(); ranks.resize(n,1); // to merge by size
		iota(par.begin(),par.end(), 0); // make a node par of itself
	}

	bool union_sets(int a, int b){
		a = find_set(a);
		b = find_set(b);
		if(a==b) return false; // already united, since having same par

		if(ranks[a]<ranks[b])
			swap(a,b);
		par[b] = a;

        // to merge by rank
		// if(ranks[a]==ranks[b])
			// ranks[a]++;
        
        // To merge by size
        ranks[a]+=ranks[b];

		return true;
	};

	int find_set(int a){
		if(a==par[a]) return a;
		return par[a] = find_set(par[a]);
	}
};

const int nax = 2e5+10;
int n,m,u,v,w,q;
vector<pair<int,pii>> edges;
vl ans(nax);

ll nc2(ll s){
    if(s<2) return 0;
    return (s*(s-1))/2;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    forn(i,n-1){
        cin>>u>>v>>w;
        edges.push_back({w,{u,v}});
    }

    DisjointSet ds;
    ds.make_sets(nax);

    ll tot = 0;
    sort(all(edges));
    int i = 0;
    for( ; i<n-1; ++i){
        int j = i;
        while(j<n-1 && edges[i].first==edges[j].first){
            // deb(i,j,edges[j].first, edges[j].second.first, edges[j].second.second);
            int a = edges[j].second.first;
            int b = edges[j].second.second;
            a = ds.find_set(a), b = ds.find_set(b);
            ll old_a_sz = nc2(ds.ranks[a]);
            ll old_b_sz = nc2(ds.ranks[b]);
            ds.union_sets(a,b);
            int par = ds.find_set(a);
            ll new_sz_combined =  nc2(ds.ranks[par]);
            tot += new_sz_combined - old_a_sz - old_b_sz;
            ++j;
        }
        i = j-1;
        ans[edges[i].first] = tot;
    }    


    // print(ans,1);
    fore(i,1,n+1){
        if(!ans[i])
            ans[i] = ans[i-1];
    }
    
    forn(i,m){
        cin>>q;
        cout<<ans[q]<<" ";
    }
    cout<<endl;

    return 0;
}