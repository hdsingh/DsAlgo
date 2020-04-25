/*
 * @lc app=leetcode id=1397 lang=cpp
 *
 * [1397] Find All Good Strings
 *
 * https://leetcode.com/problems/find-all-good-strings/description/
 *
 * algorithms
 * Hard (35.10%)
 * Likes:    95
 * Dislikes: 68
 * Total Accepted:    1.7K
 * Total Submissions: 4.7K
 * Testcase Example:  '2\n"aa"\n"da"\n"b"'
 *
 * Given the strings s1 and s2 of size n, and the string evil. Return the
 * number of good strings.
 * 
 * A good string has size n, it is alphabetically greater than or equal to s1,
 * it is alphabetically smaller than or equal to s2, and it does not contain
 * the string evil as a substring. Since the answer can be a huge number,
 * return this modulo 10^9 + 7.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 2, s1 = "aa", s2 = "da", evil = "b"
 * Output: 51 
 * Explanation: There are 25 good strings starting with 'a':
 * "aa","ac","ad",...,"az". Then there are 25 good strings starting with 'c':
 * "ca","cc","cd",...,"cz" and finally there is one good string starting with
 * 'd': "da". 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 8, s1 = "leetcode", s2 = "leetgoes", evil = "leet"
 * Output: 0 
 * Explanation: All strings greater than or equal to s1 and smaller than or
 * equal to s2 start with the prefix "leet", therefore, there is not any good
 * string.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: n = 2, s1 = "gx", s2 = "gz", evil = "x"
 * Output: 2
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * s1.length == n
 * s2.length == n
 * s1 <= s2
 * 1 <= n <= 500
 * 1 <= evil.length <= 50
 * All strings consist of lowercase English letters.
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

// Ref: https://leetcode.com/problems/find-all-good-strings/discuss/555591/JavaC%2B%2B-Memoization-DFS-and-KMP-with-Picture-Clean-code-~-12ms
// KMP + Digit DP
class Solution {
    int dp[501][51][2][2] = {};
    int n,m; string s1, s2, evil;
    vi lps;
public:
    int findGoodStrings(int _n, string _s1, string _s2, string _evil) {
        memset(dp,0,sizeof(dp));
        n = _n, s1 = _s1, s2 = _s2, evil = _evil; 
        m = evil.size();
        lps = prefix_function(evil); // longest prefix that is also a suffix
        return dfs(0, 0, true, true);
    }   
                                       // is left bound,  is right bound                               
    int dfs(int pos, int evilMatched, int isLb, int isRb){
        if(evilMatched==m) return 0;
        if(pos==n) return 1;
        if(dp[pos][evilMatched][isLb][isRb]!=0) 
            return dp[pos][evilMatched][isLb][isRb];
        
        char from = isLb ? s1[pos] : 'a';
        char to = isRb ? s2[pos] : 'z';
        int res = 0;
        for(char c=from; c<=to; ++c){
            // kmp processing
            // j will refer to the pos in evil string till which is=t is matching
            // if it completely matches, i.e j==m, then ans for that state will be 0
            int j = evilMatched;
            while(j>0 && evil[j]!=c) j=lps[j-1];
            if(c==evil[j]) j++;
            //  digit dp
            res+=dfs(pos+1, j, isLb && (c==s1[pos]), isRb && (c==s2[pos]));
            res%=mod;
        }
        return dp[pos][evilMatched][isLb][isRb] = res;
    }

    // kmp 
    vi prefix_function(string &s){
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
        return pi;
    }
};
// @lc code=end

int main(){
    Solution sol; int n,out; string s1,s2,evil;
    n = 2, s1 = "aa", s2 = "da", evil = "b";
    out =  sol.findGoodStrings(n,s1,s2,evil); deb(out); 

    n = 8, s1 = "leetcode", s2 = "leetgoes", evil = "leet";
    out =  sol.findGoodStrings(n,s1,s2,evil); deb(out);    

    n = 2, s1 = "gx", s2 = "gz", evil = "x";
    out =  sol.findGoodStrings(n,s1,s2,evil); deb(out);    

    return 0;
}
