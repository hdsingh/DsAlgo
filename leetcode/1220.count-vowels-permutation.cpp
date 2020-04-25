/*
 * @lc app=leetcode id=1220 lang=cpp
 *
 * [1220] Count Vowels Permutation
 *
 * https://leetcode.com/problems/count-vowels-permutation/description/
 *
 * algorithms
 * Hard (52.41%)
 * Likes:    104
 * Dislikes: 30
 * Total Accepted:    7.3K
 * Total Submissions: 13.8K
 * Testcase Example:  '1'
 *
 * Given an integer n, your task is to count how many strings of length n can
 * be formed under the following rules:
 * 
 * 
 * Each character is a lower case vowel ('a', 'e', 'i', 'o', 'u')
 * Each vowel 'a' may only be followed by an 'e'.
 * Each vowel 'e' may only be followed by an 'a' or an 'i'.
 * Each vowel 'i' may not be followed by another 'i'.
 * Each vowel 'o' may only be followed by an 'i' or a 'u'.
 * Each vowel 'u' may only be followed by an 'a'.
 * 
 * 
 * Since the answer may be too large, return it modulo 10^9 + 7.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 1
 * Output: 5
 * Explanation: All possible strings are: "a", "e", "i" , "o" and "u".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 2
 * Output: 10
 * Explanation: All possible strings are: "ae", "ea", "ei", "ia", "ie", "io",
 * "iu", "oi", "ou" and "ua".
 * 
 * 
 * Example 3: 
 * 
 * 
 * Input: n = 5
 * Output: 68
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 2 * 10^4
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
    unordered_map<char, string> m{
        {'a',"e"},
        {'e',"ai"},
        {'i',"aeou"},
        {'o',"iu"},
        {'u',"a"}
    };
public:
    int countVowelPermutation(int n) {
        vector<string> out;
        out = {"a","e","i","o","u"};
        for(int i=2; i<=n; ++i){
            vs nout;
            for(auto x: out){
                char bk = x.back();
                for(auto c: m[bk]){
                    nout.push_back(x+c);
                }
            }
            out =  nout;
        }
        // unique(all(out));
        return out.size();
    }
};

// Using unordered map and string
class Solution1 {
    unordered_map<char, string> m{
        {'a',"e"},
        {'e',"ai"},
        {'i',"aeou"},
        {'o',"iu"},
        {'u',"a"}
    };
public:
    int countVowelPermutation(int n) {
        unordered_map<char, int> dp;
        string s = "aeiou";
        for(auto x: s)
            dp[x] = 1;
        
        for(int i=2; i<=n; ++i){
            unordered_map<char, int> ndp;
            for(auto x: s){
                for(auto nxt: m[x]){
                    add_self(ndp[nxt], dp[x]);
                }
            }
            dp = ndp;
        }

        int tot = 0;
        for(auto x: s)
            add_self(tot, dp[x]);
        return tot;
    }
};

// converted into int and vi
// Could be further optimised by directly writing the recurrence relations, 
// instead of using for loops
class Solution {
    vvi m;
public:
    int countVowelPermutation(int n) {
        m = {
            {1},
            {0,2},
            {0,1,3,4},
            {2,4},
            {0}
        };
        vi dp(5,1);

        for(int times=2; times<=n; ++times){
            vi ndp(5);
            for(int w=0; w<5; ++w){
                for(int nxt: m[w]){
                    add_self(ndp[nxt], dp[w]);
                }
            }
            dp = ndp;
        }

        int tot = 0;
        for(int w=0; w<5; ++w)
            add_self(tot, dp[w]);
        return tot;
    }
};

// @lc code=end

int main(){
    Solution sol; int out;
    out = sol.countVowelPermutation(2e4); deb(out);
    fore(i, 1, 6){
        out = sol.countVowelPermutation(i);
        deb2(i, out);
    }

    return 0;
}

