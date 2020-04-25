/*
 * @lc app=leetcode id=673 lang=cpp
 *
 * [673] Number of Longest Increasing Subsequence
 *
 * https://leetcode.com/problems/number-of-longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (34.82%)
 * Likes:    1070
 * Dislikes: 71
 * Total Accepted:    41.1K
 * Total Submissions: 117.9K
 * Testcase Example:  '[1,3,5,4,7]'
 *
 * 
 * Given an unsorted array of integers, find the number of longest increasing
 * subsequence.
 * 
 * 
 * Example 1:
 * 
 * Input: [1,3,5,4,7]
 * Output: 2
 * Explanation: The two longest increasing subsequence are [1, 3, 4, 7] and [1,
 * 3, 5, 7].
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [2,2,2,2,2]
 * Output: 5
 * Explanation: The length of longest continuous increasing subsequence is 1,
 * and there are 5 subsequences' length is 1, so output 5.
 * 
 * 
 * 
 * Note:
 * Length of the given array will be not exceed 2000 and the answer is
 * guaranteed to be fit in 32-bit signed int.
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
template <class T, class U> void print_m(map<T,U> m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x[0]<<": "<<x[1]<<"),"<<endl;cout<<endl;}

class Solution {
public:
    int findNumberOfLIS(vector<int>& a) {
        int n = a.size();
        vvi dp(n, vi{1,1});
        // till ith pos, (longest_len, cnt);
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(a[j]<a[i]){ // if we find a num less
                    if(dp[i][0]<dp[j][0]+1){   // if found a sub seq with more len
                        dp[i][0] = dp[j][0]+1; // len of prev+1
                        dp[i][1] = dp[j][1];   // cnt will remain same as prev
                    }else if(dp[i][0]==dp[j][0]+1){ // new seq of same len found
                        dp[i][1]+=dp[j][1];    // add prev cnt;
                    }
                }
            }
        }
        // print_vv(dp);

        // find the longest len, and its cnt;
        int mxLen = 0; int cnt = 0;
        for(int i=0; i<n; i++)
            mxLen = max(mxLen, dp[i][0]);
        
        for(int i=0; i<n; i++)
            if(dp[i][0]==mxLen)
                cnt+=dp[i][1];

        return cnt;
        // return max of all first lens;        
    }
};
// @lc code=end

int main(){
    Solution sol; vi a; int out;
    a = {1,3,5,4,7};
    out = sol.findNumberOfLIS(a); deb(out);
    a = {2,2,2,2,2};
    out = sol.findNumberOfLIS(a); deb(out);
    a = {1,2,4,3,5,4,7,2};
    out = sol.findNumberOfLIS(a); deb(out);
    a = {1,1,1,2,2,2,3,3,3};
    out = sol.findNumberOfLIS(a); deb(out);
    return 0;
}


// [1,2,4,3,5,4,7,2]

// [1,2,4, ,5, ,7,]

// [1,2, ,3,5, ,7,]
// [1,2, ,3, ,4,7,]

