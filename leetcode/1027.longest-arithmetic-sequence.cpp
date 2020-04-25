/*
 * @lc app=leetcode id=1027 lang=cpp
 *
 * [1027] Longest Arithmetic Sequence
 *
 * https://leetcode.com/problems/longest-arithmetic-sequence/description/
 *
 * algorithms
 * Medium (52.99%)
 * Likes:    453
 * Dislikes: 27
 * Total Accepted:    26.8K
 * Total Submissions: 50.6K
 * Testcase Example:  '[3,6,9,12]'
 *
 * Given an array A of integers, return the length of the longest arithmetic
 * subsequence in A.
 * 
 * Recall that a subsequence of A is a list A[i_1], A[i_2], ..., A[i_k] with 0
 * <= i_1 < i_2 < ... < i_k <= A.length - 1, and that a sequence B is
 * arithmetic if B[i+1] - B[i] are all the same value (for 0 <= i < B.length -
 * 1).
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [3,6,9,12]
 * Output: 4
 * Explanation: 
 * The whole array is an arithmetic sequence with steps of length = 3.
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [9,4,7,2,10]
 * Output: 3
 * Explanation: 
 * The longest arithmetic subsequence is [4,7,10].
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [20,1,15,3,10,5,8]
 * Output: 4
 * Explanation: 
 * The longest arithmetic subsequence is [20,15,10,5].
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 2 <= A.length <= 2000
 * 0 <= A[i] <= 10000
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
template <typename T>void print_vv(T v){int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}
template <class T, class U> void print_m(map<T,U> m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}

class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        int n = A.size();
        int md = 1e4 + 1e4 + 1; // to support neg indexes
        vvi dp(n, vi(md));

        int mx = 0 ;
        for(int i=1; i<n; i++){
            for(int j=i-1; j>=0; j--){
                int d = A[i] - A[j] + 1e4;
                max_self(dp[i][d], (dp[j][d] ? dp[j][d] + 1 : 2) );
                max_self(mx, dp[i][d]);
            }
        }

        return mx;
    }

    int longestArithSeqLength1(vector<int>& A) {
        int n = A.size();
        unordered_map<int, unordered_map<int, int>> dp(n);
        // dp[i][d] represents the max len of seq before i taking diff as d

        // depends upon the max len of elements before j + 1, for i
        int mx = 0;
        for(int i=1; i<n; i++){
            for(int j=i-1; j>=0; j--){
                int d = A[i] - A[j];
                max_self(dp[i][d], (dp[j][d] ? dp[j][d] + 1  : 2) );
                max_self(mx, dp[i][d]);
            }
        }

        // for(auto m: dp)
        //     print_m(m);

        return mx;
    }
};
// @lc code=end

int main(){
    Solution sol;
    vi A; int out;
    A = {3,6,9,12};
    out = sol.longestArithSeqLength(A);
    deb(out)

    A = {9,4,7,2,10};
    out = sol.longestArithSeqLength(A);
    deb(out)

    A = {20,1,15,3,10,5,8};
    out = sol.longestArithSeqLength(A);
    deb(out)

    return 0;
}

