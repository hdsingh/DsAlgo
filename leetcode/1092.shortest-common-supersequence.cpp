/*
 * @lc app=leetcode id=1092 lang=cpp
 *
 * [1092] Shortest Common Supersequence 
 *
 * https://leetcode.com/problems/shortest-common-supersequence/description/
 *
 * algorithms
 * Hard (50.49%)
 * Likes:    275
 * Dislikes: 9
 * Total Accepted:    7.7K
 * Total Submissions: 15.3K
 * Testcase Example:  '"abac"\n"cab"'
 *
 * Given two strings str1 and str2, return the shortest string that has both
 * str1 and str2 as subsequences.  If multiple answers exist, you may return
 * any of them.
 * 
 * (A string S is a subsequence of string T if deleting some number of
 * characters from T (possibly 0, and the characters are chosen anywhere from
 * T) results in the string S.)
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: str1 = "abac", str2 = "cab"
 * Output: "cabac"
 * Explanation: 
 * str1 = "abac" is a subsequence of "cabac" because we can delete the first
 * "c".
 * str2 = "cab" is a subsequence of "cabac" because we can delete the last
 * "ac".
 * The answer provided is the shortest such string that satisfies these
 * properties.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= str1.length, str2.length <= 1000
 * str1 and str2 consist of lowercase English letters.
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

// 1. Find LCS dp table
// 2. Use it to find LCS
// 3. use LCS to find superseq
class Solution {
public:
    string shortestCommonSupersequence(string a, string b) {
        int n = sz(a), m = sz(b);
        vvi dp(n+1, vi(m+1));
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=m; ++j){
                if(a[i-1]==b[j-1])
                    max_self(dp[i][j], dp[i-1][j-1] + 1);
                else 
                    max_self(dp[i][j], max(dp[i-1][j], dp[i][j-1]));
            }
        }
        
        string lcs;
        int ap = n, bp = m; // a's pointer, b's pointer
        while(ap && bp){
            if(a[ap-1]==b[bp-1]){
                lcs+=a[ap-1];
                --ap, --bp;
            }else if(dp[ap-1][bp]>dp[ap][bp-1]){
                --ap;
            }else --bp;
        }
        reverse(all(lcs));
    
        string res;
        ap = 0, bp = 0;
        for(auto x: lcs){
            while(ap<n && a[ap]!=x) 
                res+=a[ap++];
            while(bp<m && b[bp]!=x)
                res+=b[bp++];
            res+=x; ++ap, ++bp;
        }

        return res + a.substr(ap) + b.substr(bp);
    }
};

// @lc code=end

int main(){
    Solution sol; string str1, str2, out;
    // str1 = "bac", str2 = "bcab";
    str1 = "cab", str2 = "abac";
    out = sol.shortestCommonSupersequence(str1, str2); deb(out);
    return 0;
}
