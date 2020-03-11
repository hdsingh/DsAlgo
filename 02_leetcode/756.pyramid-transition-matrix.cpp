/*
 * @lc app=leetcode id=756 lang=cpp
 *
 * [756] Pyramid Transition Matrix
 *
 * https://leetcode.com/problems/pyramid-transition-matrix/description/
 *
 * algorithms
 * Medium (52.60%)
 * Likes:    214
 * Dislikes: 290
 * Total Accepted:    16.4K
 * Total Submissions: 31.1K
 * Testcase Example:  '"ABC"\n["ABD","BCE","DEF","FFF"]'
 *
 * We are stacking blocks to form a pyramid. Each block has a color which is a
 * one letter string.
 * 
 * We are allowed to place any color block C on top of two adjacent blocks of
 * colors A and B, if and only if ABC is an allowed triple.
 * 
 * We start with a bottom row of bottom, represented as a single string. We
 * also start with a list of allowed triples allowed. Each allowed triple is
 * represented as a string of length 3.
 * 
 * Return true if we can build the pyramid all the way to the top, otherwise
 * false.
 * 
 * Example 1:
 * 
 * 
 * Input: bottom = "BCD", allowed = ["BCG", "CDE", "GEA", "FFF"]
 * Output: true
 * Explanation:
 * We can stack the pyramid like this:
 * ⁠   A
 * ⁠  / \
 * ⁠ G   E
 * ⁠/ \ / \
 * B   C   D
 * 
 * We are allowed to place G on top of B and C because BCG is an allowed
 * triple.  Similarly, we can place E on top of C and D, then A on top of G and
 * E.
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: bottom = "AABA", allowed = ["AAA", "AAB", "ABA", "ABB", "BAC"]
 * Output: false
 * Explanation:
 * We can't stack the pyramid to the top.
 * Note that there could be allowed triples (A, B, C) and (A, B, D) with C !=
 * D.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * bottom will be a string with length in range [2, 8].
 * allowed will have length in range [0, 200].
 * Letters in all strings will be chosen from the set {'A', 'B', 'C', 'D', 'E',
 * 'F', 'G'}.
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

// Brute Force
// Problem: check if top can be formed, by generating diff combinations
class Solution0 {
    unordered_map<string, bool> is_valid;
    string top;
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        top.clear(); is_valid.clear();
        for(auto a: allowed)
            is_valid[a] = true;

        dfs(0,"",bottom, (int)bottom.size() -1);
        deb(top);
        return (int)top.size();
    }

    void dfs(int pos, string cur, const string &bottom, int n){
        if(n==0){
            top = bottom; return;
        }
        if(pos==n){
            dfs(0,"",cur,n-1);
            return;
        }

        string ab = bottom.substr(pos,2); 
        for(auto c: "ABCDEFG"){
            ab.push_back(c);
            if(is_valid[ab]){
                cur.push_back(c);
                dfs(pos+1,cur,bottom,n);
                cur.pop_back();
            }
            ab.pop_back();
        }
    }
};

// Use only valid combinations to move up
class Solution {
    unordered_map<string, string> valid;
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        valid.clear(); 
        for(auto a: allowed)
            valid[a.substr(0,2)] += a[2];

        return dfs(0, "", bottom, (int)bottom.size()-1); 
    }

    bool dfs(int pos, string cur, const string &bottom, int n){ // n represents size of "cur" level
        if(n==0) return true;
        if(pos==n) return dfs(0,"",cur,n-1); // n-1 decrease the level
        
        // string ab = bottom.substr(pos,2);
        for(auto c: valid[bottom.substr(pos,2)])
            if(dfs(pos+1,cur+c,bottom, n)) return true;

        return false;        
    }
};

int main(){
    Solution sol; bool out; string bottom; vs allowed;
    bottom = "BCD", allowed = { "BCG", "CDE", "GEA", "FFF" };
    out =  sol.pyramidTransition(bottom,allowed); deb(out);

    bottom = "AABA", allowed = { "AAA", "AAB", "ABA", "ABB", "BAC" };
    out =  sol.pyramidTransition(bottom,allowed); deb(out);

    bottom = "BDBBAA";
    allowed = { "ACB","ACA","AAA","ACD","BCD","BAA","BCB","BCC","BAD","BAB","BAC","CAB","CCD","CAA","CCA","CCC","CAD","DAD","DAA","DAC","DCD","DCC","DCA","DDD","BDD","ABB","ABC","ABD","BDB","BBD","BBC","BBA","ADD","ADC","ADA","DDC","DDB","DDA","CDA","CDD","CBA","CDB","CBD","DBA","DBC","DBD","BDA" };
    out =  sol.pyramidTransition(bottom,allowed); deb(out);

    return 0;
}
