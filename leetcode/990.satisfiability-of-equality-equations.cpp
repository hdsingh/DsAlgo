/*
 * @lc app=leetcode id=990 lang=cpp
 *
 * [990] Satisfiability of Equality Equations
 *
 * https://leetcode.com/problems/satisfiability-of-equality-equations/description/
 *
 * algorithms
 * Medium (42.68%)
 * Likes:    333
 * Dislikes: 4
 * Total Accepted:    13.8K
 * Total Submissions: 32.4K
 * Testcase Example:  '["a==b","b!=a"]'
 *
 * Given an array equations of strings that represent relationships between
 * variables, each string equations[i] has length 4 and takes one of two
 * different forms: "a==b" or "a!=b".  Here, a and b are lowercase letters (not
 * necessarily different) that represent one-letter variable names.
 * 
 * Return true if and only if it is possible to assign integers to variable
 * names so as to satisfy all the given equations.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: ["a==b","b!=a"]
 * Output: false
 * Explanation: If we assign say, a = 1 and b = 1, then the first equation is
 * satisfied, but not the second.  There is no way to assign the variables to
 * satisfy both equations.
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["b==a","a==b"]
 * Output: true
 * Explanation: We could assign a = 1 and b = 1 to satisfy both equations.
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: ["a==b","b==c","a==c"]
 * Output: true
 * 
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: ["a==b","b!=c","c==a"]
 * Output: false
 * 
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: ["c==c","b==d","x!=z"]
 * Output: true
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= equations.length <= 500
 * equations[i].length == 4
 * equations[i][0] and equations[i][3] are lowercase letters
 * equations[i][1] is either '=' or '!'
 * equations[i][2] is '='
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

// Could be done faster using int instead of chars, with vector instead of map
class Solution0 {
    map<char, char> par;
    map<char, int> rank;
public:
    bool equationsPossible(vector<string>& equations) {
        par.clear(); rank.clear();
        // make set
        for(char c='a'; c<='z'; ++c)
            par[c] = c;
        
        // pass 1 union for ==
        for(auto eq: equations)
            if(eq[1]=='=')
                unite(eq[0], eq[3]);
            
        // pass 1 to check != is correct
        for(auto eq: equations){
            if(eq[1]=='!'){
                char a = find_par(eq[0]);
                char b = find_par(eq[3]);
                if(a==b) return false;
            }
        }

        return true;
    }

    void unite(char a, char b){
        a = find_par(a);
        b = find_par(b);
        if(a!=b){
            if(rank[a]<rank[b])
                swap(a,b);
            if(rank[a]==rank[b])
                ++rank[a];
            par[a] = b;
        }
    }

    char find_par(char a){
        if(a==par[a]) return a;
        return par[a] = find_par(par[a]);
    }
};

class Solution {
    vector<int> par, rank;
public:
    bool equationsPossible(vector<string>& equations) {
        par.clear(); rank.clear();
        par.resize(26); rank.resize(26);

        iota(par.begin(), par.end(), 0);
        
        // pass 1 union for ==
        for(auto eq: equations)
            if(eq[1]=='=')
                unite(eq[0]-'a', eq[3]-'a');
            
        // pass 1 to check != is correct
        for(auto eq: equations){
            if(eq[1]=='!'){
                char a = find_par(eq[0]-'a');
                char b = find_par(eq[3]-'a');
                if(a==b) return false;
            }
        }

        return true;
    }

    void unite(int a, int b){
        a = find_par(a);
        b = find_par(b);
        if(a!=b){
            if(rank[a]<rank[b])
                swap(a,b);
            if(rank[a]==rank[b])
                ++rank[a];
            par[a] = b;
        }
    }

    int find_par(int a){
        if(a==par[a]) return a;
        return par[a] = find_par(par[a]);
    }
};
// @lc code=end

int main(){
    Solution sol;   
    vector<vs> eqss; bool out;
    eqss = {
        {"a==b","b!=a"},
        {"b==a","a==b"},
        {"a==b","b!=c","c==a"},
        {"c==c","b==d","x!=z"},
    };

    for(auto &eqs: eqss){
        out = sol.equationsPossible(eqs); deb(out);
    }
    
    return 0;
}
