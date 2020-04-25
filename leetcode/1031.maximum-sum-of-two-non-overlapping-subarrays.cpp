/*
 * @lc app=leetcode id=1031 lang=cpp
 *
 * [1031] Maximum Sum of Two Non-Overlapping Subarrays
 *
 * https://leetcode.com/problems/maximum-sum-of-two-non-overlapping-subarrays/description/
 *
 * algorithms
 * Medium (56.02%)
 * Likes:    387
 * Dislikes: 22
 * Total Accepted:    13.7K
 * Total Submissions: 24.5K
 * Testcase Example:  '[0,6,5,2,2,5,1,9,4]\n1\n2'
 *
 * Given an array A of non-negative integers, return the maximum sum of
 * elements in two non-overlapping (contiguous) subarrays, which have lengths L
 * and M.  (For clarification, the L-length subarray could occur before or
 * after the M-length subarray.)
 * 
 * Formally, return the largest V for which V = (A[i] + A[i+1] + ... +
 * A[i+L-1]) + (A[j] + A[j+1] + ... + A[j+M-1]) and either:
 * 
 * 
 * 0 <= i < i + L - 1 < j < j + M - 1 < A.length, or
 * 0 <= j < j + M - 1 < i < i + L - 1 < A.length.
 * 
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
 * Input: A = [0,6,5,2,2,5,1,9,4], L = 1, M = 2
 * Output: 20
 * Explanation: One choice of subarrays is [9] with length 1, and [6,5] with
 * length 2.
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: A = [3,8,1,3,2,1,8,9,0], L = 3, M = 2
 * Output: 29
 * Explanation: One choice of subarrays is [3,8,1] with length 3, and [8,9]
 * with length 2.
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: A = [2,1,5,6,0,9,5,0,3,8], L = 4, M = 3
 * Output: 31
 * Explanation: One choice of subarrays is [5,6,0,9] with length 4, and [3,8]
 * with length 3.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * L >= 1
 * M >= 1
 * L + M <= A.length <= 1000
 * 0 <= A[i] <= 1000
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
template <typename T>void print_vv(T v){int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}
template <class T, class U> void print_m(map<T,U> m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}

class Solution1 {
public:
    int maxSumTwoNoOverlap(vi& a, int l, int m) {
        int n = a.size(); 
        vi pre(n);
        pre[0] = a[0];
        for(int i=1; i<n; i++)
            pre[i] = pre[i-1] + a[i];

        int mx = 0;
        for(int i=0; i+l+m<=n; i++){
           int lsum = pre[i+l-1] - (i-1>=0 ? pre[i-1] : 0);
           for(int j=i+l; j+m<=n; j++){
               int msum = pre[j+m-1] - (j-1>=0 ? pre[j-1] : 0);
               mx = max(mx, lsum+msum);
           }
        }

        swap(l,m);
        for(int i=0; i+l+m<=n; i++){
           int lsum = pre[i+l-1] - (i-1>=0 ? pre[i-1] : 0);
           for(int j=i+l; j+m<=n; j++){
               int msum = pre[j+m-1] - (j-1>=0 ? pre[j-1] : 0);
               mx = max(mx, lsum+msum);
           }
        }

        return mx;
    }
};

class Solution {
public:
    int maxSumTwoNoOverlap(vi& a, int l, int m) {
        int n = a.size(); 
        vi pre(n);
        pre[0] = a[0];
        for(int i=1; i<n; i++)
            pre[i] = pre[i-1] + a[i];

        int res = pre[l+m-1];
        int lmax = pre[l-1];
        int mmax = pre[m-1];
        for(int i=l+m; i<n; i++){
            // 0....l...m...i(l+m)
            lmax = max(lmax, pre[i-m] - pre[i-l-m]);

            // 0...m...l...i
            mmax = max(mmax, pre[i-l] - pre[i-l-m]);

            res = max({res, lmax + pre[i] - pre[i-m], mmax + pre[i] - pre[i-l]});          
        }

        return res;
    }
};
// @lc code=end

int main(){
    Solution sol; vi A; int L, M, out;
    A = { 0,6,5,2,2,5,1,9,4 }, L = 1, M = 2;
    out = sol.maxSumTwoNoOverlap(A, L, M); deb(out); 
    A = { 3,8,1,3,2,1,8,9,0 }, L = 3, M = 2;
    out = sol.maxSumTwoNoOverlap(A, L, M); deb(out); 
    A = { 2,1,5,6,0,9,5,0,3,8 }, L = 4, M = 3;
    out = sol.maxSumTwoNoOverlap(A, L, M); deb(out); 
    return 0;
}
