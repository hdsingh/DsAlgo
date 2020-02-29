/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 *
 * https://leetcode.com/problems/maximal-square/description/
 *
 * algorithms
 * Medium (34.02%)
 * Likes:    1658
 * Dislikes: 41
 * Total Accepted:    154.5K
 * Total Submissions: 450.9K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * Given a 2D binary matrix filled with 0's and 1's, find the largest square
 * containing only 1's and return its area.
 * 
 * Example:
 * 
 * 
 * Input: 
 * 
 * 1 0 1 0 0
 * 1 0 1 1 1
 * 1 1 1 1 1
 * 1 0 0 1 0
 * 
 * Output: 4
 * 
 */
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

// @lc code=start

// dp[i][j] represent the max side of square whose bottom corner is
// point (i,j). If mat[i][j] exists only then a sqaure can exist there
// Also we will extend the minimum of previous existing squares
class Solution1 {
public:
    int maximalSquare(vector<vector<char>>& mat) {
		int n = mat.size();
		if(!n) return 0;
		int m = mat[0].size();
		if(!m) return 0;

		vvi dp(n+1, vi(m+1));
		int max_side = 0;
		fore(i, 1, n+1){
			fore(j,1,m+1){
				if(mat[i-1][j-1]=='0') continue;
				dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]})+1;
				max_side = max(max_side, dp[i][j]);
			}
		}
		return max_side*max_side;
    }
};

// Since we are using only 1 prev row space optimisation is possible
class Solution {
public:
    int maximalSquare(vector<vector<char>>& mat) {
		int n = mat.size();
		if(!n) return 0;
		int m = mat[0].size();
		if(!m) return 0;

		vi dp(m+1);
		int max_side = 0;
		fore(i, 1, n+1){
            vi ndp(m+1);
			fore(j,1,m+1){
				if(mat[i-1][j-1]=='0') continue;
				ndp[j] = min({dp[j], ndp[j-1], dp[j-1]})+1;
				max_side = max(max_side, ndp[j]);
			}
            dp = ndp;
		}
		return max_side*max_side;
    }
};

// @lc code=end
int main(){
	Solution sol;
	vector<vector<char>> mat; int out;
	mat = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
	out = sol.maximalSquare(mat); deb(out);
	return 0;
}