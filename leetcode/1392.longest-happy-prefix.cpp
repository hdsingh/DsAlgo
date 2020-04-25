/*
 * @lc app=leetcode id=1392 lang=cpp
 *
 * [1392] Longest Happy Prefix
 *
 * https://leetcode.com/problems/longest-happy-prefix/description/
 *
 * algorithms
 * Hard (38.88%)
 * Likes:    159
 * Dislikes: 12
 * Total Accepted:    6.8K
 * Total Submissions: 17.5K
 * Testcase Example:  '"level"'
 *
 * A string is called a happy prefix if is a non-empty prefix which is also a
 * suffix (excluding itself).
 * 
 * Given a string s. Return the longest happy prefix of s .
 * 
 * Return an empty string if no such prefix exists.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "level"
 * Output: "l"
 * Explanation: s contains 4 prefix excluding itself ("l", "le", "lev",
 * "leve"), and suffix ("l", "el", "vel", "evel"). The largest prefix which is
 * also suffix is given by "l".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "ababab"
 * Output: "abab"
 * Explanation: "abab" is the largest prefix which is also suffix. They can
 * overlap in the original string.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "leetcodeleet"
 * Output: "leet"
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: s = "a"
 * Output: ""
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 10^5
 * s contains only lowercase English letters.
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

// Using KMP prefix function
class Solution {
public:
    string longestPrefix(string s) {
        int m = s.size();
        vi pi(m);
        for(int i=1; i<m; ++i){
            int len = pi[i-1];
            while(len>0 && s[i]!=s[len])
                len = pi[len-1];
            if(s[i]==s[len])
                ++len;

            pi[i] = len;
        }
        int len = pi[m-1];
        return s.substr(m-len,len);
    }
};
// @lc code=end

int main(){
    Solution sol; vs ss;
    ss = {
        "level",
        "ababab",
        "leetcodeleet",
        "a",
        "",
    };
    for(auto s: ss){
        string out =  sol.longestPrefix(s);
        deb(out);
    }
    return 0;
}
