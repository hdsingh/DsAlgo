/*
 * @lc app=leetcode id=678 lang=cpp
 *
 * [678] Valid Parenthesis String
 *
 * https://leetcode.com/problems/valid-parenthesis-string/description/
 *
 * algorithms
 * Medium (34.11%)
 * Likes:    1144
 * Dislikes: 33
 * Total Accepted:    54.2K
 * Total Submissions: 169.3K
 * Testcase Example:  '"()"'
 *
 * 
 * Given a string containing only three types of characters: '(', ')' and '*',
 * write a function to check whether this string is valid. We define the
 * validity of a string by these rules:
 * 
 * Any left parenthesis '(' must have a corresponding right parenthesis ')'.
 * Any right parenthesis ')' must have a corresponding left parenthesis '('.
 * Left parenthesis '(' must go before the corresponding right parenthesis ')'.
 * '*' could be treated as a single right parenthesis ')' or a single left
 * parenthesis '(' or an empty string.
 * An empty string is also valid.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: "()"
 * Output: True
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: "(*)"
 * Output: True
 * 
 * 
 * 
 * Example 3:
 * 
 * Input: "(*))"
 * Output: True
 * 
 * 
 * 
 * Note:
 * 
 * The string size will be in the range [1, 100].
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

class Solution {
public:
    bool checkValidString(string s) {
        int minBal = 0, maxBal = 0;
        
        for(auto x: s){
            if(x=='(') ++minBal, ++maxBal;
            else if(x==')') --minBal, --maxBal;
            else{
                --minBal;
                ++maxBal;
            }
            
            if(minBal<0) minBal = 0;
            if(maxBal<0) return false;
            
        }
        
        return minBal==0;
    }
};

class Solution1 {
public:
    bool checkValidString(string s) {
        int bal = 0, ex = 0;
        for(int i=0; i<s.size(); ++i){
            if(s[i]=='(') ++bal;
            else if(s[i]==')') --bal;
            else ++ex;
            
            if(bal<0){
                if(ex>0) ++bal, --ex;
                else return false;
            }
        }
        
        bal = 0, ex = 0;
        for(int i=s.size()-1; i>=0; --i){
            if(s[i]==')') ++bal;
            else if(s[i]=='(') --bal;
            else ++ex;
            
            if(bal<0){
                if(ex>0) --ex, ++bal;
                else return false;
            }
        }
        return true;
    }
};

// @lc code=end

int main(){
    Solution sol;  vs ss;
    ss = {
        "()",
        "(*)",
        ")(*))",
        "(*()((*",
    };

    for(auto s: ss){
        bool out = sol.checkValidString(s);
        deb(out);
    }
    return 0;
}
