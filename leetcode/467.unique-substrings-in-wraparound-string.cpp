/*
 * @lc app=leetcode id=467 lang=cpp
 *
 * [467] Unique Substrings in Wraparound String
 *
 * https://leetcode.com/problems/unique-substrings-in-wraparound-string/description/
 *
 * algorithms
 * Medium (34.91%)
 * Likes:    485
 * Dislikes: 76
 * Total Accepted:    22.5K
 * Total Submissions: 64.3K
 * Testcase Example:  '"a"'
 *
 * Consider the string s to be the infinite wraparound string of
 * "abcdefghijklmnopqrstuvwxyz", so s will look like this:
 * "...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd....".
 * 
 * Now we have another string p. Your job is to find out how many unique
 * non-empty substrings of p are present in s. In particular, your input is the
 * string p and you need to output the number of different non-empty substrings
 * of p in the string s.
 * 
 * Note: p consists of only lowercase English letters and the size of p might
 * be over 10000.
 * 
 * Example 1:
 * 
 * Input: "a"
 * Output: 1
 * 
 * Explanation: Only the substring "a" of string "a" is in the string s.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: "cac"
 * Output: 2
 * Explanation: There are two substrings "a", "c" of string "cac" in the string
 * s.
 * 
 * 
 * 
 * Example 3:
 * 
 * Input: "zab"
 * Output: 6
 * Explanation: There are six substrings "z", "a", "b", "za", "ab", "zab" of
 * string "zab" in the string s.
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


// If we count starts with there is no end since s is infinite
// Instead of counting starts with, count ends with
// dp[c] represents the number of substring ending with c
// It is equal to the maxContinuous length
class Solution {
public:
    int findSubstringInWraproundString(string p) {
        int n = p.size();
        if(!n) return 0;
        
        vi dp(26+1);
        int maxContinuousLen = 1;
        dp[p[0]-'a'] = 1;
        for(int i=1; i<n; ++i){
            if(p[i]-p[i-1]==1 || p[i-1]-p[i]==25)
                ++maxContinuousLen;
            else 
                maxContinuousLen = 1;
            
            dp[p[i]-'a'] =  max(dp[p[i]-'a'] , maxContinuousLen);
        }
        // print(dp,1);
        return accumulate(all(dp), 0);
    }
};
// @lc code=end

// starting from any char, a string with len l will be unique 
// for unique len. hence we only need to know the max_len of 
// a valid string starting from a char
// example z, za, zab, zabc
///        1   2  3     4
// the len 4 covers all other prpev smaller strings.
class Solution {
    void max_self(int &a, int b){
        if(b>a) a = b;
    }
public:
    int findSubstringInWraproundString(string p) {
        int n = p.size();
        vector<int> len_ahead(26);
        
        for(int i=0; i<n; ++i){
            int j = i;
            while(j+1<n && (p[j+1]-p[j]==1 || (p[j+1]=='a' && p[j]=='z') ) )
                  ++j;
            
            for(int k=i; k<=j; ++k){
                max_self(len_ahead[p[k]-'a'], j-k+1);
            }  
            i = j;
        }
        
        int ans = 0;
        for(int i=0; i<26; ++i)
            ans+=len_ahead[i];
        return ans;
    }
};

int main(){
    Solution sol; int out;  vs ss;
    ss = {
        "a",
        "cac",
        "zab",
        // "abc",
        "",
    };

    for(auto s: ss){
        out = sol.findSubstringInWraproundString(s);deb(out);
    }
    return 0;
}

