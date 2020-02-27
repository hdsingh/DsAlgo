/*
 * @lc app=leetcode id=413 lang=cpp
 *
 * [413] Arithmetic Slices
 *
 * https://leetcode.com/problems/arithmetic-slices/description/
 *
 * algorithms
 * Medium (56.95%)
 * Likes:    768
 * Dislikes: 148
 * Total Accepted:    75.8K
 * Total Submissions: 133.2K
 * Testcase Example:  '[1,2,3,4]'
 *
 * A sequence of number is called arithmetic if it consists of at least three
 * elements and if the difference between any two consecutive elements is the
 * same.
 * 
 * For example, these are arithmetic sequence:
 * 1, 3, 5, 7, 9
 * 7, 7, 7, 7
 * 3, -1, -5, -9
 * 
 * The following sequence is not arithmetic. 1, 1, 2, 5, 7 
 * 
 * 
 * A zero-indexed array A consisting of N numbers is given. A slice of that
 * array is any pair of integers (P, Q) such that 0 
 * 
 * A slice (P, Q) of array A is called arithmetic if the sequence:
 * ⁠   A[P], A[p + 1], ..., A[Q - 1], A[Q] is arithmetic. In particular, this
 * means that P + 1 < Q.
 * 
 * The function should return the number of arithmetic slices in the array
 * A. 
 * 
 * 
 * Example:
 * 
 * A = [1, 2, 3, 4]
 * 
 * return: 3, for 3 arithmetic slices in A: [1, 2, 3], [2, 3, 4] and [1, 2, 3,
 * 4] itself.
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
template <typename T>void print_vv(T v){int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}
template <class T, class U> void print_m(map<T,U> m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}


class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& a) {
		int n = a.size();
		if(n<3) return 0;
		
		vi dp(n); // number of seq with a[i] as end
        
        // if A[i] forms AP, then it will be appended to all
        // APs formed by i-1, also a new AP will be formed [A[i-2], A[i-1], A[i]]

		for(int i=2; i<n; ++i){
			if(a[i] - a[i-1] == a[i-1] - a[i-2])
				dp[i] = dp[i-1] + 1;
		}

		// print(dp);
		return accumulate(all(dp), 0);
    }

    int BruteForce_numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        
        auto is_am = [&](int beg, int end){
            int d = A[beg+1] - A[beg];
            for(int x=beg+2; x<=end; x++)
                if(A[x] - A[x-1]!=d)
                    return false; 
            return true;
        };

        int cnt = 0;
        for(int len = 3; len<=n; len++){
            for(int beg=0; beg+len-1<n; beg++){
                int end = beg + len-1;
                if(is_am(beg, end)) ++cnt;
            }
        }
        // deb(cnt);
        return cnt;
    }
};
// @lc code=end


int main(){
    Solution sol;
    vi A;
    A = {};
    fore(i,1, 15){
        int out = sol.numberOfArithmeticSlices(A);
        deb2(A.size(), out);
        A.pb(i);
    }

    return 0;
}
