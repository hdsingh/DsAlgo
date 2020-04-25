/*
 * @lc app=leetcode id=1278 lang=cpp
 *
 * [1278] Palindrome Partitioning III
 *
 * https://leetcode.com/problems/palindrome-partitioning-iii/description/
 *
 * algorithms
 * Hard (56.01%)
 * Likes:    71
 * Dislikes: 2
 * Total Accepted:    2.2K
 * Total Submissions: 4K
 * Testcase Example:  '"abc"\n2'
 *
 * You are given a string s containing lowercase letters and an integer k. You
 * need to :
 * 
 * 
 * First, change some characters of s to other lowercase English letters.
 * Then divide s into k non-empty disjoint substrings such that each substring
 * is palindrome.
 * 
 * 
 * Return the minimal number of characters that you need to change to divide
 * the string.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "abc", k = 2
 * Output: 1
 * Explanation: You can split the string into "ab" and "c", and change 1
 * character in "ab" to make it palindrome.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "aabbc", k = 3
 * Output: 0
 * Explanation: You can split the string into "aa", "bb" and "c", all of them
 * are palindrome.
 * 
 * Example 3:
 * 
 * 
 * Input: s = "leetcode", k = 8
 * Output: 0
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= k <= s.length <= 100.
 * s only contains lowercase English letters.
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

class Solution {
public:
    int palindromePartition(string s, int K) {
        int n = s.size();
        if(!n) return 0;

        auto calcCost = [&](int l, int r){
            int changes = 0;
            while(l<=r){
                if(s[l++]!=s[r--])
                    ++changes;
            }
            return changes;
        };

        vvi cost(n+1, vi(n+1));
        for(int i=0; i<n; ++i){
            for(int j=i; j<n; ++j){
                cost[i][j] = calcCost(i,j);
            }
        }

        vvi dp(n, vi(K+1, n));
        // cost of conversion till pos i, in k parts
        for(int i=0; i<n; ++i)
            dp[i][1] = cost[0][i];
        // cost till i in 1 part is cost of change from 0 to i

        for(int k=2; k<=K; ++k){
            for(int r=0; r<n; ++r){
                for(int l=0; l<=r; ++l){
                    min_self(dp[r][k], dp[l][k-1] + cost[l+1][r]);
                }
            }
        }

        return dp[n-1][K];
    }
};
// @lc code=end

int main(){
    Solution sol; string s; int k,out;
    s = "abc", k = 2;
    out = sol.palindromePartition(s,k); deb(out);
    s = "aabbc", k = 3;
    out = sol.palindromePartition(s,k); deb(out);
    s = "leetcode", k = 8;
    out = sol.palindromePartition(s,k); deb(out);
    return 0;
}

