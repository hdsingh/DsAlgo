/*
 * @lc app=leetcode id=873 lang=cpp
 *
 * [873] Length of Longest Fibonacci Subsequence
 *
 * https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/description/
 *
 * algorithms
 * Medium (47.51%)
 * Likes:    550
 * Dislikes: 26
 * Total Accepted:    23.3K
 * Total Submissions: 49K
 * Testcase Example:  '[1,2,3,4,5,6,7,8]'
 *
 * A sequence X_1, X_2, ..., X_n is fibonacci-like if:
 * 
 * 
 * n >= 3
 * X_i + X_{i+1} = X_{i+2} for all i + 2 <= n
 * 
 * 
 * Given a strictly increasing array A of positive integers forming a sequence,
 * find the length of the longest fibonacci-like subsequence of A.  If one does
 * not exist, return 0.
 * 
 * (Recall that a subsequence is derived from another sequence A by deleting
 * any number of elements (including none) from A, without changing the order
 * of the remaining elements.  For example, [3, 5, 8] is a subsequence of [3,
 * 4, 5, 6, 7, 8].)
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3,4,5,6,7,8]
 * Output: 5
 * Explanation:
 * The longest subsequence that is fibonacci-like: [1,2,3,5,8].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1,3,7,11,12,14,18]
 * Output: 3
 * Explanation:
 * The longest subsequence that is fibonacci-like:
 * [1,11,12], [3,11,14] or [7,11,18].
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 3 <= A.length <= 1000
 * 1 <= A[0] < A[1] < ... < A[A.length - 1] <= 10^9
 * (The time limit has been reduced by 50% for submissions in Java, C, and
 * C++.)
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
    int lenLongestFibSubseq(vector<int>& a) {
        int n = a.size();
        // print(a, 1);
        unordered_map<int, int> m;
        for(auto x: a)
            m[x] = 1;

        int mlen = 0;
        fore(i, 0, n){
            fore(j, i+1, n){
                int x = a[i];
                int y = a[j];
                int len = 2;
                while(m.count(x+y)){
                    int temp = y;
                    y = x+y;
                    x = temp;
                    ++len;
                }
                mlen = max(len, mlen);
            }
        }

        return mlen==2 ? 0 : mlen;
    }
};

// DP based
class Solution2 {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        int n = A.size();

        vvi dp(n, vi(n, 2));
        map<int, int> pos;
        forn(i, n)
            pos[A[i]] = i;

        int mlen = 0;
        for(int c=1; c<n; c++){
            for(int b=0; b<c; b++){
                int ai = A[c] - A[b];
                if(pos.count(ai) && pos[ai]<b){
                    max_self(dp[b][c], dp[pos[ai]][b]+1);
                    max_self(mlen, dp[b][c]);
                }
            }
        }
        return mlen;
    }
};

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        int n=A.size();
        vvi dp(n, vi(n, 2));
        unordered_map<int,int> m;
        forn(i, n)
            m[i] = i;

        int mlen = 2;
        fore(i, 0, n){
            fore(j, i, n){
                int ki = A[i] + A[j];
                if(m.count(ki)){
                    int k = m[ki];
                    max_self(dp[j][k], dp[i][j]+1);
                    max_self(mlen, dp[j][k]);
                }
            }
        }
        return mlen==2 ? 0 : mlen;
    }
};
// @lc code=end

int main(){
    Solution sol;
    vi A; int out;
    A = {1,2,3,4,5,6,7,8};
    out = sol.lenLongestFibSubseq(A); deb(out);
    A = {1,3,7,11,12,14,18};
    out = sol.lenLongestFibSubseq(A); deb(out);
    A = {2,4,7,8,9,10,14,15,18,23,32,50};
    out = sol.lenLongestFibSubseq(A); deb(out);

    return 0;
}