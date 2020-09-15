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

// Refer: https://leetcode.com/problems/bricks-falling-when-hit/discuss/195781/Union-find-Logical-Thinking

vvi dirs = {{1,0},{0,1},{-1,0},{0,-1}};

class DSU{
public:
	vector<int> par, ranks;

	DSU(int n){
		par.assign(n+1,0);
		// ranks.assign(n+1,0);
		ranks.assign(n+1,1); // to merge by size
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
        
        // To merge by size
        ranks[a]+=ranks[b];

		return true;
	};

	int find_set(int a){
		if(a==par[a]) return a;
		return par[a] = find_set(par[a]);
	}
};

class Solution {
    int n, m;
    vvi grid;
public:
    vector<int> hitBricks(vector<vector<int>>& G, vector<vector<int>>& hits) {
        grid = G;
        n = sz(grid), m = sz(grid[0]);

        for(auto hit: hits){
            int x = hit[0], y =  hit[1];
            if(grid[x][y]==1) grid[x][y] = 2;
        }

        DSU ds(n*m+1);
        forn(i,n) forn(j,m) if(grid[i][j]==1) unite_around(i,j,ds);

        reverse(all(hits));

        vi ans;
        int connected = ds.ranks[ds.find_set(0)];
        for(auto hit: hits){
            int x = hit[0], y = hit[1];
            int now = 0;
            if(grid[x][y]==2){
                grid[x][y] = 1;
                unite_around(x,y,ds);
                int cur_connected = ds.ranks[ds.find_set(0)];
                now = max(cur_connected - connected - 1, 0);
                connected = cur_connected;
            }
            ans.pb(now);
        }
        reverse(all(ans));

        return ans;
    }

    void unite_around(int x, int y, DSU &ds){
        int cur_mark = mark(x,y);
        for(auto dir: dirs){
            int nx = x + dir[0], ny = y + dir[1];
            if(0<=nx && nx<n && 0<=ny && ny<m && grid[nx][ny]==1){
                ds.union_sets(cur_mark, mark(nx,ny));
            }
        }
        if(x==0) ds.union_sets(0,cur_mark);
    }

    int mark(int x, int y){
        return x*m + y + 1;
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    Solution sol; vvi grid, hits; vi out;
    
    grid = {{1,0,0,0},
            {1,1,1,0}};
    hits = {{1,0}};
    out = sol.hitBricks(grid, hits); print(out);

    grid = {{1,0,0,0},
            {1,1,0,0}};
    hits = {{1,1},{1,0}};
    out = sol.hitBricks(grid, hits); print(out);

    grid = {{1,1,1},
            {0,1,0},
            {0,0,0}};
    hits = {{0,2},{2,0},{0,1},{1,2}};
    out = sol.hitBricks(grid, hits); print(out);

    grid = {{1,1,1,0,1,1,1,1},
            {1,0,0,0,0,1,1,1},
            {1,1,1,0,0,0,1,1},
            {1,1,0,0,0,0,0,0},
            {1,0,0,0,0,0,0,0},
            {1,0,0,0,0,0,0,0}};

    hits = {{4,6},{3,0},{2,3},{2,6},{4,1},{5,2},{2,1}};
    out = sol.hitBricks(grid, hits); print(out);

    return 0;
}