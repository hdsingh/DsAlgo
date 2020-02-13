/*
 * @lc app=leetcode id=1318 lang=cpp
 *
 * [1318] Minimum Flips to Make a OR b Equal to c
 *
 * https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/description/
 *
 * algorithms
 * Medium (60.55%)
 * Likes:    55
 * Dislikes: 7
 * Total Accepted:    7.2K
 * Total Submissions: 11.7K
 * Testcase Example:  '2\n6\n5'
 *
 * Given 3 positives numbers a, b and c. Return the minimum flips required in
 * some bits of a and b to make ( a OR b == c ). (bitwise OR operation).
 * Flip operation consists of change any single bit 1 to 0 or change the bit 0
 * to 1 in their binary representation.
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: a = 2, b = 6, c = 5
 * Output: 3
 * Explanation: After flips a = 1 , b = 4 , c = 5 such that (a OR b == c)
 * 
 * Example 2:
 * 
 * 
 * Input: a = 4, b = 2, c = 7
 * Output: 1
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: a = 1, b = 2, c = 3
 * Output: 0
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= a <= 10^9
 * 1 <= b <= 10^9
 * 1 <= c <= 10^9
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
template <typename T>void print_vv(T v){int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}
template <class T, class U> void print_m(map<T,U> m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}

class Solution1 {
public:
    int minFlips(int a, int b, int c) {
        if(a==b && b==c)
            return 0;
        
        int x = (a|b)^c;
        x = __builtin_popcount(x); // repreents places where diff
        // but it misses case 1 1 0
        // so we will add 1 for each such case
        int _and = a&b;
        for(int i=0; i<32; i++){
            if((1<<i & _and) && ((1<<i & c)^1) )
                x++;
        }

        return x;    
    }
};

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int x = (a|b)^c;
        x = __builtin_popcount(x); // repreents places where diff
        // but it misses case 1 1 0
        // so we will add 1 for each such case

        // int y = (a&b) & ((a|b)^c);
        // if a_i and b_i are both 1 (&), but only at place where
        // we are having different c_i and if c_i is 1   ,  (1 1 0)
        int y = a & b & ~c;
        y = __builtin_popcount(y);

        return x+y;    
    }
};
// @lc code=end

int main(){
    Solution sol; int out,a,b,c;
    a = 2, b = 6, c = 5;
    out = sol.minFlips(a,b,c); deb(out);
    a = 4, b = 2, c = 7;
    out = sol.minFlips(a,b,c); deb(out);
    a = 4, b = 4, c = 3;
    out = sol.minFlips(a,b,c); deb(out);
    a = 7, b = 3, c = 9;
    out = sol.minFlips(a,b,c); deb(out);
    return 0;
}