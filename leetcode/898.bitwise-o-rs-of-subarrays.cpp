/*
 * @lc app=leetcode id=898 lang=cpp
 *
 * [898] Bitwise ORs of Subarrays
 *
 * https://leetcode.com/problems/bitwise-ors-of-subarrays/description/
 *
 * algorithms
 * Medium (35.31%)
 * Likes:    304
 * Dislikes: 63
 * Total Accepted:    10.4K
 * Total Submissions: 29.1K
 * Testcase Example:  '[0]'
 *
 * We have an array A of non-negative integers.
 * 
 * For every (contiguous) subarray B = [A[i], A[i+1], ..., A[j]] (with i <= j),
 * we take the bitwise OR of all the elements in B, obtaining a result A[i] |
 * A[i+1] | ... | A[j].
 * 
 * Return the number of possible results.  (Results that occur more than once
 * are only counted once in the final answer.)
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [0]
 * Output: 1
 * Explanation: 
 * There is only one possible result: 0.
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1,1,2]
 * Output: 3
 * Explanation: 
 * The possible subarrays are [1], [1], [2], [1, 1], [1, 2], [1, 1, 2].
 * These yield the results 1, 1, 2, 1, 3, 3.
 * There are 3 unique values, so the answer is 3.
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [1,2,4]
 * Output: 6
 * Explanation: 
 * The possible results are 1, 2, 3, 4, 6, and 7.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= A.length <= 50000
 * 0 <= A[i] <= 10^9
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
template <typename T>void print_vv(T v){int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}
template <class T, class U> void print_m(map<T,U> m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}

// To better understand just try out the procedure with [1,2,3]
// Although this looks like O(n^2), but since we are doing a OR, 
// the total size of ans will be limited due to number of max
// bit positions, upto 32.
// The approach is same as using DP, increasing len in each step,
// but due to use of sets, this works efficiently.
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& a) {
        int n = a.size();
        set<int> ans;
        set<int> cur;

        for(int x: a){
            set<int> cur2;
            for(int c: cur)
                cur2.insert(c|x);
            cur2.insert(x);
            cur = cur2;

            ans.insert(cur.begin(), cur.end());
        }

        return ans.size();
    }
};
// @lc code=end

int main(){
    Solution sol; vi a; int out;
    a = {0};
    out = sol.subarrayBitwiseORs(a); deb(out);

    a = {1,1,2};
    out = sol.subarrayBitwiseORs(a); deb(out);

    a = {1,2,4};
    out = sol.subarrayBitwiseORs(a); deb(out);

    return 0;
}