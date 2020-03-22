/*
 * @lc app=leetcode id=1388 lang=cpp
 *
 * [1388] Pizza With 3n Slices
 *
 * https://leetcode.com/problems/pizza-with-3n-a/description/
 *
 * algorithms
 * Hard (31.43%)
 * Likes:    59
 * Dislikes: 2
 * Total Accepted:    740
 * Total Submissions: 2.4K
 * Testcase Example:  '[1,2,3,4,5,6]'
 *
 * There is a pizza with 3n a of varying size, you and your friends will
 * take a of pizza as follows:
 * 
 * 
 * You will pick any pizza slice.
 * Your friend Alice will pick next slice in anti clockwise direction of your
 * pick. 
 * Your friend Bob will pick next slice in clockwise direction of your
 * pick.
 * Repeat until there are no more a of pizzas.
 * 
 * 
 * Sizes of Pizza a is represented by circular array a in clockwise
 * direction.
 * 
 * Return the maximum possible sum of slice sizes which you can have.
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: a = [1,2,3,4,5,6]
 * Output: 10
 * Explanation: Pick pizza slice of size 4, Alice and Bob will pick a with
 * size 3 and 5 respectively. Then Pick a with size 6, finally Alice and
 * Bob will pick slice of size 2 and 1 respectively. Total = 4 + 6.
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input: a = [8,9,8,6,1,1]
 * Output: 16
 * Output: Pick pizza slice of size 8 in each turn. If you pick slice with size
 * 9 your partners will pick a of size 8.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: a = [4,1,2,5,8,3,1,9,7]
 * Output: 21
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: a = [3,1,2]
 * Output: 3
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= a.length <= 500
 * a.length % 3 == 0
 * 1 <= a[i] <= 1000
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

// Observation: We can pick at most N pizzas, such that no 2 
// of them are adjacent, hence simplified version
// Given an array what is the maximum sum you can obtain such that 
// no 2 of them are adjacent
// Due to cycle, we can either pick the first or the last
// so max 0 to n-2 or 1 to n-1,
// Similar to house robber 2
// dp[i-2][j-1] + a[i] ; till i-2 pos, having j-1 slices(because we will add 1 now)
// dp[i-1][j], prev pos, same slices
class Solution {
public:
    int maxSizeSlices(vector<int>& a) {
        int n = a.size();
        int m = n/3; // slices to pick
        int r1(0), r2(0);

        vvi dp(n, vi(m+1));
        // max sum till ith pos, picking m slices
        for(int i=0; i<n-1; ++i){
            for(int j=1; j<=m; ++j){
                // dp[i][j] = max(dp[i-2][j-1] + a[i],  dp[i-1][j]);
                dp[i][j] = max((i-2>=0 && j ? dp[i-2][j-1] : 0) + a[i],  (i ? dp[i-1][j] : 0));
            }
        }
        r1 = dp[n-2][m]; // till n-2 eating m slices
        
        dp.clear(); dp.resize(n, vi(m+1));
        // 1 to n-1
        for(int i=1; i<n; ++i){
            for(int j=1; j<=m; ++j){
                // dp[i][j] = max(dp[i-2][j-1] + a[i],  dp[i-1][j]);
                dp[i][j] = max((i-2>=0 && j ? dp[i-2][j-1] : 0) + a[i],  (i ? dp[i-1][j] : 0));
            }
        } 
        r2 = dp[n-1][m];

        return max(r1,r2);
    }
};
// @lc code=end

int main(){
    Solution sol; int out;
    vvi slices = {
        {1,2,3,4,5,6},
        {8,9,8,6,1,1},
        {4,1,2,5,8,3,1,9,7},
        {3,1,2},
    };
    for(auto s: slices)
        out = sol.maxSizeSlices(s), deb(out);
    return 0;
}
