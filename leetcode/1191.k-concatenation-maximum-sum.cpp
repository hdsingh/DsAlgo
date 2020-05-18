/*
 * @lc app=leetcode id=1191 lang=cpp
 *
 * [1191] K-Concatenation Maximum Sum
 *
 * https://leetcode.com/problems/k-concatenation-maximum-sum/description/
 *
 * algorithms
 * Medium (25.74%)
 * Likes:    194
 * Dislikes: 21
 * Total Accepted:    8.2K
 * Total Submissions: 31.8K
 * Testcase Example:  '[1,2]\n3'
 *
 * Given an integer array arr and an integer k, modify the array by repeating
 * it k times.
 * 
 * For example, if arr = [1, 2] and k = 3 then the modified array will be [1,
 * 2, 1, 2, 1, 2].
 * 
 * Return the maximum sub-array sum in the modified array. Note that the length
 * of the sub-array can be 0 and its sum in that case is 0.
 * 
 * As the answer can be very large, return the answer modulo 10^9 + 7.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: arr = [1,2], k = 3
 * Output: 9
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: arr = [1,-2,1], k = 5
 * Output: 2
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: arr = [-1,-2], k = 7
 * Output: 0
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= arr.length <= 10^5
 * 1 <= k <= 10^5
 * -10^4 <= arr[i] <= 10^4
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


// The answer is the maximum between, 
// the answer for k=1, the sum of the whole array multiplied by k, 
// or the maximum suffix sum plus the maximum prefix sum 
// plus (k-2) multiplied by the whole array sum for k > 1.
class Solution {
public:
    int kConcatenationMaxSum(vector<int>& a, int k) {
        int a_sum = 0, m_sum = 0, n = a.size();
        a_sum = accumulate(all(a), 0);

        for(int i=0, cur_sum=0; i<min(k, 2)*n; i++){
            cur_sum = max(cur_sum + a[i%n],a[i%n]);
            m_sum = max(cur_sum, m_sum);
        }

        while(a_sum>0 && --k>=2){
            add_self(m_sum, a_sum);
        }
        return m_sum;
    }
};
// @lc code=end


int main(){
    Solution sol; vi a; int out, out1, k;
    a = {1,2}; k = 3;
    out1 = sol.kConcatenationMaxSum(a, k); deb(out1);

    a =  {1,-2,1}; k=5;
    out1 = sol.kConcatenationMaxSum(a, k); deb(out1);
    
    a = {-1, -2}; k=7;
    out1 = sol.kConcatenationMaxSum(a, k); deb(out1);

    return 0;
}
