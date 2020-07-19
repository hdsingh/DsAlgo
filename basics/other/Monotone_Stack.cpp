#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define pb push_back
#define deb(x) cout<<#x<<" "<<x<<endl;
#define deb2(x, y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define deb3(x, y, z) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define all(x) x.begin(), x.end()
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

template <typename T>void print(T v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<v.size(); i++)cout<<setw(w)<<i<<" ";cout<<endl;}for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(w)<<*i<<" ";cout<<endl;}
template <typename T>void print_vv(T v){if(v.size()==0) {cout<<"Empty"<<endl; return;} int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}
template <class T, class U> void print_m(map<T,U> m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}

int main(){
	vi a = {11,11,12,12};
	int n = a.size();
	stack<int> stk_p, stk_n;
	vi next_less(n);
	vi prev_less(n);

	for(int i=0; i<n; i++){
		while(stk_p.size() && a[stk_p.top()]>=a[i]) // >= here or below(only at one place)
			stk_p.pop();
		prev_less[i] = stk_p.size() ? stk_p.top() : -1;
		stk_p.push(i);
	}

	for(int i=n-1; i>=0; --i){
		while(stk_n.size() && a[stk_n.top()]>a[i])
			stk_n.pop();
		next_less[i] = stk_n.size() ? stk_n.top() : n;
		stk_n.push(i);
	}

	print(a);
	print(prev_less);
	print(next_less);
	
	return 0;
}

// 1. [239. Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum/)
// 2. [1425. Constrained Subset Sum](https://leetcode.com/problems/constrained-subset-sum/)
// 3. [862. Shortest Subarray with Sum at Least K](https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/)
// 4. [C2. Skyscrapers](https://codeforces.com/contest/1313/problem/C2)
// 5. [B. Mike and Feet](https://codeforces.com/problemset/problem/547/B)
