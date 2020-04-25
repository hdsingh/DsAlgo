/*
 * @lc app=leetcode id=903 lang=cpp
 *
 * [903] Valid Permutations for DI Sequence
 *
 * https://leetcode.com/problems/valid-permutations-for-di-sequence/description/
 *
 * algorithms
 * Hard (48.36%)
 * Likes:    239
 * Dislikes: 28
 * Total Accepted:    4.9K
 * Total Submissions: 10.1K
 * Testcase Example:  '"DID"'
 *
 * We are given S, a length n string of characters from the set {'D', 'I'}.
 * (These letters stand for "decreasing" and "increasing".)
 * 
 * A valid permutation is a permutation P[0], P[1], ..., P[n] of integers {0,
 * 1, ..., n}, such that for all i:
 * 
 * 
 * If S[i] == 'D', then P[i] > P[i+1], and;
 * If S[i] == 'I', then P[i] < P[i+1].
 * 
 * 
 * How many valid permutations are there?  Since the answer may be large,
 * return your answer modulo 10^9 + 7.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "DID"
 * Output: 5
 * Explanation: 
 * The 5 valid permutations of (0, 1, 2, 3) are:
 * (1, 0, 3, 2)
 * (2, 0, 3, 1)
 * (2, 1, 3, 0)
 * (3, 0, 2, 1)
 * (3, 1, 2, 0)
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= S.length <= 200
 * S consists only of characters from the set {'D', 'I'}.
 * 
 * 
 * 
 * 
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


// Simple observation: any sequence can be extended easily to new seq,
// maintaining the prev property.
// foreample: 1032 is DID
// Let find DIDI
// here last is 2, so possible options are 3,4
// For 3: 1032 -> 1042_3  (inc all elements >=3)
// For 4: 1032 -> 1032_4 
// To make DIDD
// possible options are 0,1,2
// 1032 -> 2143_0  (inc >=0)
// 1032 -> 2043_1 (inc >=1)
// 1032 -> 1043_2 (inc >=2)
// So here dp[i][j] will repreent the #of seq with having len i (upto i digit are used as a result)
// and last digit as j
// So if the last digit is at j is 2, in order to extend "D", I can use # of 2,3,4 as j till prev pos (2_2(last), 3_2, 4_2(last))
// (2_2) accoring to rule will become 3_2, so is valid
// 2, in order to extend "I", I can use 0,1,( 0_2, 1_2)

// Yet to optimize to O(n^2)
class Solution {
public:
    int numPermsDISequence(string s) {
        int n = s.size();
        vvi dp(n+1, vi(n+1));

        dp[0][0] = 1; //only seq 0
        // dp[i][j], represents seq till i digits used having j as its last digit
        // ex: 201, last digit j =1, and i=2
        for(int i=1; i<=n; ++i)
            for(int j=0; j<=i; ++j)
                if(s[i-1]=='D') 
                    for(int k=j; k<=i-1; ++k) // ex: if j=2, 2_2, 3_2,.. i-1_2, will be considered
                        add_self(dp[i][j], dp[i-1][k]);
                else 
                    for(int k=0; k<=j-1; ++k)
                        add_self(dp[i][j], dp[i-1][k]);

        int res = 0;
        for(int j=0; j<=n; ++j)
            add_self(res, dp[n][j]);
        return res;
    }
};
// @lc code=end

int main(){
    Solution sol; int out;
    vs ss = {
        "DID",
        "DIDI",
        "DIDD",
    };
    for(auto s: ss)
        out = sol.numPermsDISequence(s),deb(out);
    return 0;
}
