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

    bool isUnited(int a, int b){
        return (find_par(a)==find_par(b));
    }
};


class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int qlen = queries.size();
        for(int i=0; i<qlen; ++i){
            queries[i].push_back(i);
        }
        sort(queries.begin(), queries.end(), [&](vector<int> &v1, vector<int> &v2){
            return v1[2]<v2[2]; 
        }); 
        sort(edges.begin(), edges.end(), [&](vector<int> &v1, vector<int> &v2){
            return v1[2]<v2[2]; 
        });
        DSU ds(n);
        vector<bool> ans(qlen);
        int m = edges.size();
        int l = 0;
        for(int i=0; i<qlen; ++i){
            while(l<m && edges[l][2]<queries[i][2]){
                ds.unite(edges[l][0], edges[l][1]);
                ++l;
            }
            ans[queries[i][3]] = ds.isUnited(queries[i][0], queries[i][1]);
        }
        return ans;
    }
};


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    return 0;
}