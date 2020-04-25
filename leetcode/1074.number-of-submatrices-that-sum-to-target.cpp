/*
 * @lc app=leetcode id=1074 lang=cpp
 *
 * [1074] Number of Submatrices That Sum to Target
 *
 * https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/description/
 *
 * algorithms
 * Hard (60.36%)
 * Likes:    312
 * Dislikes: 12
 * Total Accepted:    9.7K
 * Total Submissions: 16.1K
 * Testcase Example:  '[[0,1,0],[1,1,1],[0,1,0]]\n0'
 *
 * Given a matrix, and a target, return the number of non-empty submatrices
 * that sum to target.
 * 
 * A submatrix x1, y1, x2, y2 is the set of all cells matrix[x][y] with x1 <= x
 * <= x2 and y1 <= y <= y2.
 * 
 * Two submatrices (x1, y1, x2, y2) and (x1', y1', x2', y2') are different if
 * they have some coordinate that is different: for example, if x1 != x1'.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: matrix = [[0,1,0],[1,1,1],[0,1,0]], target = 0
 * Output: 4
 * Explanation: The four 1x1 submatrices that only contain 0.
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: matrix = [[1,-1],[-1,1]], target = 0
 * Output: 5
 * Explanation: The two 1x2 submatrices, plus the two 2x1 submatrices, plus the
 * 2x2 submatrix.
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= matrix.length <= 300
 * 1 <= matrix[0].length <= 300
 * -1000 <= matrix[i] <= 1000
 * -10^8 <= target <= 10^8
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
#define deb4(x, y, z, u) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<" "<<#u<<" "<<u<<endl;
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

// Brute Force
class Solution0 {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& mat, int T) {
        int n = mat.size();
        if(!n) return 0;
        int m = mat[0].size();
        if(!m) return 0;

        vvi area(n+1, vi(m+1));
        fore(i, 1, n+1)
            fore(j, 1, m+1)
                area[i][j] = area[i-1][j] + area[i][j-1] - area[i-1][j-1] + mat[i-1][j-1];

        int cnt = 0;
        fore(i1, 1, n+1)
            fore(j1, 1, m+1)
                fore(i2, i1, n+1)
                    fore(j2, j1, m+1){
                        int cur = area[i2][j2] - area[i1-1][j2] - area[i2][j1-1] + area[i1-1][j1-1];
                        if(cur==T) ++cnt;
                    }


        return cnt;
    }
};

// O(n^4) - > O(n^3)
// Using the same idea in find/Count subarray with target Sum (LC 560)
// Approach 1: Iterate over all possiblities of rows, 
// by fixing row_start and row_end
// In each combination, find the sum of numbers in every column of a row and form array
// Use the Count Subarray idea on this array. This allows us to iterate on
// different combinations of columns in O(n) rather than O(n^2), hence reducing 
// complexity to O(n^3)
class Solution1 {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& mat, int T) {
        int rows = mat.size();
        if(!rows) return 0;
        int cols = mat[0].size();
        if(!cols) return 0;
        int cnt = 0;

        // PreFix sum Column wise
        vvi pre(rows+1, vi(cols));
        for(int row=0; row<rows; ++row){
            for(int col=0; col<cols; ++col){
                pre[row+1][col] = pre[row][col] + mat[row][col];
            }
        }
        
        unordered_map<int,int> m;
        for(int rowStart=0; rowStart<rows; ++rowStart){
            for(int row=rowStart; row<rows; ++row){
                m.clear(); m[0] = 1;
                int sum=0;
                for(int col=0; col<cols; ++col){
                    // pre[row][col] - pre[rowStart-1][col] , but this way since using pre[row+1](shifted by 1)
                    // Subtracting rowStart to restrict prev rows
                    sum+=pre[row+1][col] - pre[rowStart][col];
                    if(m.find(sum-T)!=m.end()){
                        cnt+=m[sum-T];
                    }
                    m[sum]++;
                }
            }
        }        
        return cnt;
    }
};

// Same idea as above, just fixing columns instead of rows
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& mat, int T) {
        int rows = mat.size();
        if(!rows) return 0;
        int cols = mat[0].size();
        if(!cols) return 0;
        int cnt = 0;

        // Along column for a particular row
        vvi pre(rows, vi(cols+1));
        for(int row=0; row<rows; ++row){
            for(int col=0; col<cols; ++col){
                pre[row][col+1] = pre[row][col] + mat[row][col];
            }
        }

        unordered_map<int,int> difCnt;
        for(int colStart=0; colStart<cols; ++colStart){
            for(int col=colStart; col<cols; ++col){
                difCnt.clear();
                difCnt[0] = 1;

                int sum=0;
                for(int row=0; row<rows; ++row){
                    sum+= pre[row][col+1] - pre[row][colStart];
                    if(difCnt.find(sum-T)!=difCnt.end()){
                        cnt+=difCnt[sum-T];
                    }
                    difCnt[sum]++;
                }
            }
        }
        
        return cnt;
    }
};


// @lc code=end

int main(){
    Solution sol; vvi matrix; int target, out;
    matrix = {{0,1,0},
              {1,1,1},
              {0,1,0}}, target = 0;
    out = sol.numSubmatrixSumTarget(matrix,target); deb(out); 
    matrix = {{1,-1},{-1,1}}, target = 0;
    out = sol.numSubmatrixSumTarget(matrix,target); deb(out); 
    return 0;
}
