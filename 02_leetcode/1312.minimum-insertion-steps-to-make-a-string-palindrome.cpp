/*
 * @lc app=leetcode id=1312 lang=cpp
 *
 * [1312] Minimum Insertion Steps to Make a String Palindrome
 *
 * https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/description/
 *
 * algorithms
 * Hard (55.14%)
 * Likes:    154
 * Dislikes: 5
 * Total Accepted:    6K
 * Total Submissions: 10.9K
 * Testcase Example:  '"zzazz"'
 *
 * Given a string s. In one step you can insert any character at any index of
 * the string.
 * 
 * Return the minimum number of steps to make s palindrome.
 * 
 * A Palindrome String is one that reads the same backward as well as
 * forward.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "zzazz"
 * Output: 0
 * Explanation: The string "zzazz" is already palindrome we don't need any
 * insertions.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "mbadm"
 * Output: 2
 * Explanation: String can be "mbdadbm" or "mdbabdm".
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "leetcode"
 * Output: 5
 * Explanation: Inserting 5 characters the string becomes "leetcodocteel".
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: s = "g"
 * Output: 0
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: s = "no"
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 500
 * All characters of s are lower case English letters.
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

// Start comparing from l to r;(++l,--r) (-->  <--)
// when s[l]!=s[r], we have 2 possible choices:
// 1. move l to -> dir, keeping r fixed, since 
// we assume the char has been inserted at after r
// 2. move r to <-- dir, keeping l fixed
// ex:  |  |        | | 
//     abcda:  a b c d b a  (l moved, r fixed)
class Solution0 {
    string s;
    int n;
public:
    int minInsertions(string S) {
        s = S;
        int n = s.size();
        return dfs(0,n-1);        
    }

    int dfs(int l, int r){
        while(l<=r && s[l]==s[r]){
            ++l; --r;
        }
        if(l>r) return 0;
        
        return 1 + min(dfs(l+1, r), dfs(l, r-1));
    }
};


class Solution1 {
public:
    int minInsertions(string s) {
        int n = s.size();
        vvi dp(n+2, vi(n+2));
        for(int l=n; l>0; --l){
            for(int r=l; r<=n; ++r){
                if(s[l-1]==s[r-1])
                    dp[l][r] = dp[l+1][r-1];
                else 
                    dp[l][r] = 1 + min(dp[l+1][r], dp[l][r-1]);
            }
        }

        return dp[1][n];        
    }
};

class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        vvi dp(n+2, vi(n+2));

        for(int r=1; r<=n; ++r){
            for(int l=r; l>0; --l){
                if(s[l-1]==s[r-1])
                    dp[l][r] = dp[l+1][r-1];
                else 
                    dp[l][r] = 1 + min(dp[l+1][r], dp[l][r-1]);
            }
        }
        
        return dp[1][n];        
    }
};


// @lc code=end

int main(){
    Solution1 sol; vs ss; int out;
    ss = {
        "zzazz",
        "mbadm",
        "leetcode",
        "g",
        "no",
    };
    for(auto s: ss){
        out = sol.minInsertions(s); deb2(out, s);
    }
    return 0;
}
