/*
 * @lc app=leetcode id=1147 lang=cpp
 *
 * [1147] Longest Chunked Palindrome Decomposition
 *
 * https://leetcode.com/problems/longest-chunked-palindrome-decomposition/description/
 *
 * algorithms
 * Hard (57.86%)
 * Likes:    131
 * Dislikes: 11
 * Total Accepted:    7.4K
 * Total Submissions: 12.7K
 * Testcase Example:  '"ghiabcdefhelloadamhelloabcdefghi"'
 *
 * Return the largest possible k such that there exists a_1, a_2, ..., a_k such
 * that:
 * 
 * 
 * Each a_i is a non-empty string;
 * Their concatenation a_1 + a_2 + ... + a_k is equal to text;
 * For all 1 <= i <= k,  a_i = a_{k+1 - i}.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: text = "ghiabcdefhelloadamhelloabcdefghi"
 * Output: 7
 * Explanation: We can split the string on
 * "(ghi)(abcdef)(hello)(adam)(hello)(abcdef)(ghi)".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: text = "merchant"
 * Output: 1
 * Explanation: We can split the string on "(merchant)".
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: text = "antaprezatepzapreanta"
 * Output: 11
 * Explanation: We can split the string on
 * "(a)(nt)(a)(pre)(za)(tpe)(za)(pre)(a)(nt)(a)".
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: text = "aaa"
 * Output: 3
 * Explanation: We can split the string on "(a)(a)(a)".
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * text consists only of lowercase English characters.
 * 1 <= text.length <= 1000
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

// Form front and back strong usong pointers and compare
// When front==back, we found 2 parts of palindrome
class Solution {
public:
    int longestDecomposition(string text) {
        int n = text.size();
        if(n<=1) return n;
        int out = 0;

        string front,back;
        int f=0, b=n-1;

        while(f<=b){
            front += text[f++];
            back = text[b--] + back;
            if(front==back){
                // size 1 and both same ex: central a in "aaa"
                if(f==b && front.size()){
                    out+=1;
                }else
                    out+=2;
                front.clear();
                back.clear();
            }
        }
        // If the word in middle is single
        if(front!=back)
            out++;

        return out;
    }
};
// @lc code=end

int main(){
    Solution sol; vs texts; int out;
    texts = {
        "ghiabcdefhelloadamhelloabcdefghi",
        "merchant",
        "antaprezatepzapreanta",
        "aaa",
        "bbbb",
        "sd"
    };
    for(auto text: texts){
        out = sol.longestDecomposition(text); deb(out);
    }
    return 0;
}
