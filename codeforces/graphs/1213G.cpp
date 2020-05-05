#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define pb push_back
#define deb(x) cout<<#x<<" "<<x<<endl;
#define deb2(x, y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define deb3(x, y, z) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
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

template <typename T>void print(const T &v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<sz(v); i++)cout<<setw(w)<<i<<" ";cout<<endl;}for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(w)<<*i<<" ";cout<<endl;}
template <typename T>void print_vv(const T &v){if(sz(v)==0) {cout<<"Empty"<<endl; return;} int w = 3;cout<<setw(w)<<" ";for(int j=0; j<sz(v[0]); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<sz(v); i++){cout<<i<<" {";for(auto j = 0; j!=sz(v[i]); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}
template <class T, class U> void print_m(const map<T,U> &m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}

// Sort the edges and queries in increasing order of weight. 
// Process offline
// merge two components, by weight 1,2,3,4...
// When merging two components, of size s1 and s2, 
// In the new comp, we can choose 1 from s1, and one from s2,
// hence result will increase by s1+s2, or
// res = res - C(s1,2) - S(s2,2) + C(s1 + s2, 2),
// upon simplification
// res = res - s1*s2

ll res = 0;

class DisjointSet{
public: 
	vector<int> par, ranks;

	// for all the sets
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
		// 	ranks[a]++;

        res+=(ll)ranks[a]*(ll)ranks[b]; // we can choose 1 from both
        
        // To merge by size
        ranks[a]+=ranks[b];

		return true;
	};

	int find_set(int a){
		if(a==par[a]) return a;
		return par[a] = find_set(par[a]);
	}
};


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin>>n>>m;
    vvi adj(n-1, vi(3)); // {weight, u,v}
    forn(i,n-1){
        cin>>adj[i][1]>>adj[i][2]>>adj[i][0];
    }
    vvi qs(m, vi(2)); // {q, idx}
    forn(i,m){
        cin>>qs[i][0];
        qs[i][1] = i;
    }
    vl ans(m);

    sort(all(adj)); //based on wt
    sort(all(qs)); // based on wt

    DisjointSet ds;
    ds.make_sets(n+1);

    int i = 0;
    forn(j,m){
        // cur wt <= query wt
        while(i<n-1 && adj[i][0]<=qs[j][0]){
            int u = adj[i][1];
            int v = adj[i][2];
            ds.union_sets(u,v);
            ++i;
        }
        ans[qs[j][1]] = res;
    }

    print(ans);
    
    return 0;
}