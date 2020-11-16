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

// Time Complexity of Prims: O(E+ V log V)
// Time Complexity of Kruskal: O(E log E + E)
// Hence Kruskal takes more time on dense graphs.

class DSU{
public:
	vector<int> par, ranks;

	DSU(int n){
		par.assign(n+1,0);
		ranks.assign(n+1,0);
		// ranks.assign(n+1,1); // to merge by size
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
		if(ranks[a]==ranks[b])
			ranks[a]++;
        
        // To merge by size
        // ranks[a]+=ranks[b];

		return true;
	};

	int find_set(int a){
		if(a==par[a]) return a;
		return par[a] = find_set(par[a]);
	}
};

typedef tuple<ll,int,int> tii;
// typedef tuple<int,int,int> tii;

// dsu  + make heap
class Solution1 {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = sz(points);
        vector<tii> edges;
        forn(i,n){
            fore(j,i+1, n){
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({dist, i,j});
            }
        }
        
        DSU ds(n);
        int cost = 0;
        int added = 0;
        make_heap(edges.begin(), edges.end(), greater<tii>());
        while(!edges.empty()){
            pop_heap(edges.begin(), edges.end(), greater<tii>());
            auto [w, x, y] = edges.back();
            edges.pop_back();

            if(ds.union_sets(x,y)){
                cost+=w;
                if(++added==n-1) break;
            }

        }
        return cost;
    }
};

// dsu  + priority queue
class Solution2 {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = sz(points);
        priority_queue<tii, vector<tii>, greater<tii>> edges;
        forn(i,n){
            fore(j,i+1, n){
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push({dist, i,j});
            }
        }
        
        DSU ds(n);
        int cost = 0;
        int added = 0;
        while(!edges.empty()){
            auto [w, x, y] = edges.top(); edges.pop();
            
            if(ds.union_sets(x,y)){
                cost+=w;
                if(++added==n-1) break;
            }

        }
        return cost;
    }
};


typedef pair<ll,ll> pll;
const ll inf = 1e18L;

// Prims
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = sz(points);
        vvl wt(n, vl(n));
        forn(i,n){
            vector<tii> cur;
            fore(j,i+1, n){
                int d = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                wt[i][j] = wt[j][i] = d;
            }
        }

        vb vis(n);
        vl dist(n, inf);
        
        set<pll> q;
        q.insert({0,0});
        dist[0] = 0;

        forn(i,n){
            auto [d, node] = *q.begin();
            q.erase(*q.begin());
            vis[node] = 1;

            forn(ad,n){
                if(vis[ad]) continue;
                
                if(wt[node][ad] < dist[ad]){
                    q.erase({dist[ad], ad});
                    dist[ad] = wt[node][ad];
                    q.insert({dist[ad], ad});
                }
            }
        }
        
        int ans = accumulate(all(dist),0);
        return ans;
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    return 0;
}