/*
 * @lc app=leetcode id=1039 lang=cpp
 *
 * [1039] Minimum Score Triangulation of Polygon
 *
 * https://leetcode.com/problems/minimum-score-triangulation-of-polygon/description/
 *
 * algorithms
 * Medium (46.20%)
 * Likes:    271
 * Dislikes: 32
 * Total Accepted:    6.1K
 * Total Submissions: 13.1K
 * Testcase Example:  '[1,2,3]'
 *
 * Given N, consider a convex N-sided polygon with vertices labelled A[0],
 * A[i], ..., A[N-1] in clockwise order.
 * 
 * Suppose you triangulate the polygon into N-2 triangles.  For each triangle,
 * the value of that triangle is the product of the labels of the vertices, and
 * the total score of the triangulation is the sum of these values over all N-2
 * triangles in the triangulation.
 * 
 * Return the smallest possible total score that you can achieve with some
 * triangulation of the polygon.
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
 * Input: [1,2,3]
 * Output: 6
 * Explanation: The polygon is already triangulated, and the score of the only
 * triangle is 6.
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input: [3,7,4,5]
 * Output: 144
 * Explanation: There are two triangulations, with possible scores: 3*7*5 +
 * 4*5*7 = 245, or 3*4*5 + 3*4*7 = 144.  The minimum score is 144.
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [1,3,1,4,1,5]
 * Output: 13
 * Explanation: The minimum score triangulation has score 1*1*3 + 1*1*4 + 1*1*5
 * + 1*1*1 = 13.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 3 <= A.length <= 50
 * 1 <= A[i] <= 100
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

// dp[i][j] represent the minimum sum from i to j
// dp[i][j] = dp[i][k] + a[i]*a[j]*a[k]  + dp[k][j];
// for each polygon answer lies in choosing three points i,j,k
// such that i<k<j, here pts i->k->j->i form a triangle, the points 
// this will divide the triangle, mostly into three parts
// the min of left will be dp[i][k], and right will be dp[k][j];
class Solution {
public:
    int minScoreTriangulation(vector<int>& a) {
        int n = a.size();
    
        vvi dp(n, vi(n));
        for(int i=n-1; i>=0; i--){
            for(int k=i+1; k<n; k++){
                for(int j=k+1; j<n; j++){
                    dp[i][j] = (dp[i][j] ? dp[i][j] : INT_MAX);
                    min_self(dp[i][j], dp[i][k] + a[i]*a[k]*a[j] + dp[k][j]);
                }
            }
        } 

        // vvi dp(n, vi(n));
        // for(int i=n-1; i>=0; i--){
        //     for(int j=i+1; j<n; j++){
        //         for(int k=i+1; k<j; k++){
        //         dp[i][j] = (dp[i][j]==0 ? INT_MAX : dp[i][j]);
        //             min_self(dp[i][j], dp[i][k] + a[i]*a[k]*a[j] + dp[k][j]); 
        //         }
        //     }
        // }

        return dp[0][n-1];
    }
};
// @lc code=end

int main(){
    Solution sol; int out; vi a;
    a = {1,2,3};
    out = sol.minScoreTriangulation(a); deb(out);

    a = {1,3,1,4,1,5};
    out = sol.minScoreTriangulation(a); deb(out);
    return 0;
}

