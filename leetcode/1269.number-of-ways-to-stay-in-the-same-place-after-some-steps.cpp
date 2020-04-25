/*
 * @lc app=leetcode id=1269 lang=cpp
 *
 * [1269] Number of Ways to Stay in the Same Place After Some Steps
 *
 * https://leetcode.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps/description/
 *
 * algorithms
 * Hard (35.83%)
 * Likes:    42
 * Dislikes: 3
 * Total Accepted:    1.8K
 * Total Submissions: 5.1K
 * Testcase Example:  '3\n2'
 *
 * You have a pointer at index 0 in an array of size arrLen. At each step, you
 * can move 1 position to the left, 1 position to the right in the array or
 * stay in the same place  (The pointer should not be placed outside the array
 * at any time).
 * 
 * Given two integers steps and arrLen, return the number of ways such that
 * your pointer still at index 0 after exactly steps steps.
 * 
 * Since the answer may be too large, return it modulo 10^9 + 7.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: steps = 3, arrLen = 2
 * Output: 4
 * Explanation: There are 4 differents ways to stay at index 0 after 3 steps.
 * Right, Left, Stay
 * Stay, Right, Left
 * Right, Stay, Left
 * Stay, Stay, Stay
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: steps = 2, arrLen = 4
 * Output: 2
 * Explanation: There are 2 differents ways to stay at index 0 after 2 steps
 * Right, Left
 * Stay, Stay
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: steps = 4, arrLen = 2
 * Output: 8
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= steps <= 500
 * 1 <= arrLen <= 10^6
 * 
 * 
 */

// @lc code=start
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

class Solution0 {
public:
    int numWays(int steps, int n) {
		n = min(n,500);
		vi dp(n+1);

		dp[0] = 1;
		for(int step=0; step<steps; ++step){
			vi ndp = dp;
			for(int pos=0; pos<n; ++pos){
				if(pos+1>=0 && pos+1<n)
					add_self(ndp[pos+1], dp[pos]);
				if(pos-1>=0 && pos-1<n)
					add_self(ndp[pos-1], dp[pos]);	
			}
			dp = ndp;
		}

		return dp[0];
    }
};

// Simple observation: since there are at max 500 steps we can never
// reach at a pos beyond, 500 so just limit the arreln to 500 to 
// save memory
// Also we can use the same dp table, because only 1 prev value is 
// needed so will save it before changing, ith stays same, i+1 th can be 
// referred since it has not been changed
class Solution {
public:
    int numWays(int steps, int n) {
		n = min(n, 500);
		vi dp(501); //+1 to avoid error in the end on pos+1

		int prev, cur;
		dp[0] = 1;
		for(int step=0; step<steps; ++step){
			prev = 0;
			for(int pos=0; pos<n; ++pos){
				cur = dp[pos];
				add_self(dp[pos], prev);
				add_self(dp[pos], dp[pos+1]);
				prev = cur;
			}
		}

		return dp[0];
    }
};


int main(){
	Solution0 sol; int steps, arrLen; int out;
	steps = 3, arrLen = 2;
	out = sol.numWays(steps,arrLen); deb(out);
	steps = 8, arrLen = 15;
	out = sol.numWays(steps,arrLen); deb(out);
	steps = 500, arrLen = 1e6;
	// steps = 4, arrLen = 2;
	out = sol.numWays(steps,arrLen); deb(out);
	cin>>out;
	return 0;
}
