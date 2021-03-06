/*
 * @lc app=leetcode id=921 lang=cpp
 *
 * [921] Minimum Add to Make Parentheses Valid
 *
 * https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/description/
 *
 * algorithms
 * Medium (71.74%)
 * Likes:    490
 * Dislikes: 36
 * Total Accepted:    48.3K
 * Total Submissions: 67.4K
 * Testcase Example:  '"())"'
 *
 * Given a string S of '(' and ')' parentheses, we add the minimum number of
 * parentheses ( '(' or ')', and in any positions ) so that the resulting
 * parentheses string is valid.
 * 
 * Formally, a parentheses string is valid if and only if:
 * 
 * 
 * It is the empty string, or
 * It can be written as AB (A concatenated with B), where A and B are valid
 * strings, or
 * It can be written as (A), where A is a valid string.
 * 
 * 
 * Given a parentheses string, return the minimum number of parentheses we must
 * add to make the resulting string valid.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "())"
 * Output: 1
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "((("
 * Output: 3
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "()"
 * Output: 0
 * 
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: "()))(("
 * Output: 4
 * 
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * S.length <= 1000
 * S only consists of '(' and ')' characters.
 * 
 * 
 * 
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

// In order for a par to be valid, it the bal(or tot), must
// always remain positive, if it becomes neg, i.e more "))" than "(",
// then we must insert "(", somewhere earlier, to make it neutral
class Solution {
public:
    int minAddToMakeValid(string s) {
        int tot = 0;
        int cur = 0;
        for(auto &c: s){
            cur += c=='(' ? 1 : -1;
            if(cur<0){
                ++tot;
                cur = 0;
            }
        }
        tot+=cur;

        return tot;
    }
};
// @lc code=end

int main(){
    Solution sol; int out;
    vs ss = {"())","(((","()", "()))((",")("};
    for(auto &s: ss){
        out =  sol.minAddToMakeValid(s); deb(out);
    }
    return 0;
}
