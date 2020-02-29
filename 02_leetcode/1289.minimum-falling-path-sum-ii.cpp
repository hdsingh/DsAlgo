/*
 * @lc app=leetcode id=1289 lang=cpp
 *
 * [1289] Minimum Falling Path Sum II
 *
 * https://leetcode.com/problems/minimum-falling-path-sum-ii/description/
 *
 * algorithms
 * Hard (57.90%)
 * Likes:    83
 * Dislikes: 10
 * Total Accepted:    4.8K
 * Total Submissions: 8.1K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given a square grid of integers arr, a falling path with non-zero shifts is
 * a choice of exactly one element from each row of arr, such that no two
 * elements chosen in adjacent rows are in the same column.
 * 
 * Return the minimum sum of a falling path with non-zero shifts.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: arr = [[1,2,3],[4,5,6],[7,8,9]]
 * Output: 13
 * Explanation: 
 * The possible falling paths are:
 * [1,5,9], [1,5,7], [1,6,7], [1,6,8],
 * [2,4,8], [2,4,9], [2,6,7], [2,6,8],
 * [3,4,8], [3,4,9], [3,5,7], [3,5,9]
 * The falling path with the smallest sum is [1,5,7], so the answer is 13.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= arr.length == arr[i].length <= 200
 * -99 <= arr[i][j] <= 99
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

class Solution1 {
public:
    int minFallingPathSum(vector<vector<int>>& a) {
        int n = a.size();
        if(!n) return 0;
        int m = a[0].size();
        if(!m) return 0;

        vvi dp(n+1, vi(m, 1e9));
        dp[0] = vi(m,0);
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                for(int p=0; p<m; ++p){
                    if(p==j) continue;
                    min_self(dp[i+1][j], dp[i][p] + a[i][j]);
                }
            }
        }

        // print_vv(dp);

        return *min_element(all(dp[n]));

    }
};

// inplace
class Solution2 {
public:
    int minFallingPathSum(vector<vector<int>>& a) {
        int n = a.size();
        if(!n) return 0;
        int m = a[0].size();
        if(!m) return 0;

        for(int i=1; i<n; ++i){
            for(int j=0; j<m; ++j){
                int best = INT_MAX;
                for(int k=0; k<m; ++k)
                    if(k!=j) best = min(a[i-1][k], best);
                a[i][j]+=best;
            }
        }

        // print_vv(a);

        return *min_element(all(a.back()));
    }
};

// In every row, we need to keep trac of two min elements and their index
// if the minimum most(m1)'s pos==j then we use m2
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& a) {
        int n = a.size();
        int fm=0, sm=0, pos=-1;
        
        for(int i=0; i<n; ++i){
            int fm2=INT_MAX, sm2 =INT_MAX, pos2 = -1;
            for(int j=0; j<n; ++j){
                auto mn = j != pos ? fm : sm;

                if(a[i][j] + mn<fm2){
                    sm2 = fm2;
                    fm2 = a[i][j] + mn;
                    pos2 = j;
                }else{
                    sm2 = min(sm2, a[i][j] + mn);
                }
            }

            fm = fm2, sm = sm2, pos = pos2;
        }
        return fm;        
    }
};

// @lc code=end

int main(){
    Solution sol; vvi a; int out;
    a = {{1,2,3},
         {4,5,6},
         {7,8,9}};
    a = {{1,2,3},
         {4,9,9},
         {7,10,9}};
    out = sol.minFallingPathSum(a); deb(out);
    return 0;
}

