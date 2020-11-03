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

// PQ
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& builds) {
        int n = builds.size();
        priority_queue<pair<int,int>> pq; // {ht, ed_pt};
		vector<vector<int>> out;
		set<int> pts;
		for(auto build: builds){
			pts.insert(build[0]);
			pts.insert(build[1]);
		}
		
		int prev_ht = 0;
		int i = 0;
		for(auto pt:pts){
			// remove old points
			while(!pq.empty() && pq.top().second<=pt) 
				pq.pop();

			// Add new buildings starting here.
			while(i<n && builds[i][0]<=pt){
				pq.push({builds[i][2], builds[i][1]});
				++i;
			}

			int cur_ht = pq.size() ? pq.top().first : 0;
			if(cur_ht!=prev_ht){
				out.push_back({pt, cur_ht});
				prev_ht = cur_ht;
			}
		}
		return out;
    }	
};

struct Node{
	int val = 0, lazy = 0;
};

class SegmentTree{
	int n;
	vector<Node> st;
public:
	SegmentTree(int N){
		n = N;
		st.resize(4*n);
	}
	
	void update(int pos, int sl, int sr, int l, int r, int val){
		propagate(pos, sl, sr);
		if(sr<l || r<sl) return;
		if(l<=sl && sr<=r){
			st[pos].lazy = val;
			propagate(pos, sl, sr);
			return;
		}
		int mid = (sl+sr)/2;
		update(2*pos, sl, mid, l, r, val);
		update(2*pos+1, mid+1, sr, l, r, val);
		st[pos].val = max(st[2*pos].val, st[2*pos+1].val);		
	}	
	
	int query(int pos, int sl, int sr, int idx){
		propagate(pos, sl, sr);
		if(sl==sr) return st[pos].val;
		int mid = (sl+sr)/2;
		if(idx<=mid)
			return query(2*pos, sl, mid, idx);
		return query(2*pos+1, mid+1, sr, idx);
	}
	
	void propagate(int pos, int sl, int sr){
		if(!st[pos].lazy) return;
		if(sl!=sr){
			st[2*pos].lazy = max(st[2*pos].lazy, st[pos].lazy);
			st[2*pos+1].lazy = max(st[2*pos+1].lazy, st[pos].lazy);
		}
		st[pos].val = max(st[pos].val, st[pos].lazy);
		st[pos].lazy = 0;
	}
		
	int query(int idx){
		return query(1,0,n-1,idx);
	}
		
	void update(int lt, int rt, int ht){
		update(1,0,n-1,lt,rt,ht);
	}
};

// Coordinate compression + Range Max (point query, range update + Lazy Prop)
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& builds) {
        map<int,int> locs;
		for(auto build: builds)
			locs[build[0]], locs[build[1]], locs[build[1]-1]; // insert in map
		int tot = 0;
		for(auto &p: locs)
			p.second = tot++;

		SegmentTree st(tot);
		for(auto build: builds){
			int lt = build[0], rt = build[1]-1, ht = build[2];
			st.update(locs[lt], locs[rt], ht);
		}	

		vector<vector<int>> out;
        int prev_ht = 0;
		for(auto p: locs){
            int ht = st.query(p.second);
            if(prev_ht==ht) continue;
            out.push_back({p.first, ht});
            prev_ht = ht;
        }
		return out;
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    Solution sol; vvi a, out;
    a = {{2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8}};
    out = sol.getSkyline(a); cout<<out;
    return 0;
}
