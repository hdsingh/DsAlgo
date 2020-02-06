/*
 * @lc app=leetcode id=1314 lang=cpp
 *
 * [1314] Matrix Block Sum
 *
 * https://leetcode.com/problems/matrix-block-sum/description/
 *
 * algorithms
 * Medium (71.73%)
 * Likes:    87
 * Dislikes: 16
 * Total Accepted:    4.9K
 * Total Submissions: 6.8K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]\n1'
 *
 * Given a m * n matrix mat and an integer K, return a matrix answer where each
 * answer[i][j] is the sum of all elements mat[r][c] for i - K <= r <= i + K, j
 * - K <= c <= j + K, and (r, c) is a valid position in the matrix.
 * 
 * Example 1:
 * 
 * 
 * Input: mat = [[1,2,3],
 *               [4,5,6],
 *               [7,8,9]], 
 *        K = 1
 * Output: [[12,21,16],
 *          [27,45,33],
 *          [24,39,28]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: mat = [[1,2,3],
 *               [4,5,6],
 *               [7,8,9]],  
 *      K = 2
 * Output: [[45,45,45],
 *          [45,45,45],
 *          [45,45,45]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == mat.length
 * n == mat[i].length
 * 1 <= m, n, K <= 100
 * 1 <= mat[i][j] <= 100
 * 
 */
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

// @lc code=start
class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        int n = mat.size();
        int m = mat[0].size();

        vvi dp(n, vi(m)); // sum of area till i,j
        forn(i, n){
            forn(j, m){
                dp[i][j] = (i-1>=0 ? dp[i-1][j] : 0) + (j-1>=0 ? dp[i][j-1] : 0) - (i-1>=0 && j-1>=0 ? dp[i-1][j-1] : 0) + mat[i][j];
            }
        }
        // print_vv(mat);
        // print_vv(dp);

        auto get_area = [&](int x2, int y2, int x1, int y1){
            // return dp[x2][y2] - dp[x1-1][y2] - dp[x2][y1-1] + dp[x1-1][y1-1];
            return dp[x2][y2] - (x1-1>=0 ? dp[x1-1][y2] : 0) - (y1-1>=0 ? dp[x2][y1-1] : 0) + (x1-1>=0 && y1-1>=0 ? dp[x1-1][y1-1] : 0);
        };

        vvi out(n, vi(m));
        forn(i, n){
            forn(j, m){
                int x2 = min(i+K, n-1);
                int y2 = min(j+K, m-1);
                int x1 = max(i-K, 0);
                int y1 = max(j-K, 0);
                out[i][j] = get_area(x2, y2, x1, y1);
            }
        }
        // print_vv(out);

        return out;
    }
};
// @lc code=end


int main(){
    Solution sol;
    vvi mat = {{1,2,3}, 
               {4,5,6},
               {7,8,9}};
    int  k = 2;
    vvi out;
    out = sol.matrixBlockSum(mat, k);
    print_vv(out);
    mat = { { 67,64,78 },{ 99,98,38 },{ 82,46,46 },{ 6,52,55 },{ 55,99,45 } };
    k = 3;
    out = sol.matrixBlockSum(mat, k);
    print_vv(out);
    return 0;
}