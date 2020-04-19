/*
 * @lc app=leetcode id=85 lang=cpp
 *
 * [85] Maximal Rectangle
 *
 * https://leetcode.com/problems/maximal-rectangle/description/
 *
 * algorithms
 * Hard (35.07%)
 * Likes:    1873
 * Dislikes: 55
 * Total Accepted:    142.2K
 * Total Submissions: 405.1K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * Given a 2D binary mat filled with 0's and 1's, find the largest rectangle
 * containing only 1's and return its area.
 * 
 * Example:
 * 
 * 
 * Input:
 * [
 * ⁠ ["1","0","1","0","0"],
 * ⁠ ["1","0","1","1","1"],
 * ⁠ ["1","1","1","1","1"],
 * ⁠ ["1","0","0","1","0"]
 * ]
 * Output: 6
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

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& mat) {
        int n = mat.size(); int m = mat[0].size();
        vvi dp(n, vi(m+1)); 
        // the last element is 0 for the correct wooking of min stack
        for(int j=0; j<m; ++j) 
            dp[0][j] = mat[0][j]-'0';

        for(int i=1; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(mat[i][j]=='1')
                    dp[i][j] = dp[i-1][j] + (mat[i][j] - '0');
            }
        }
        // print_vv(dp);

        int area = 0;
        // using min stack as in LC 84
        for(int i=0; i<n; ++i){
            // area = max(area, largestRectangleArea(dp[i]));
            stack<int> stk; // will save indexes
            // j==m to include last element as 0
            for(int j=0; j<=m; ++j){
                while(stk.size() && dp[i][stk.top()]>dp[i][j]){
                    int h = dp[i][stk.top()]; stk.pop();
                    int l = stk.size() ? stk.top() : -1;
                    // l(left limit) is one less the cur min bec of the role of prev min in forming a larger rect
                    area = max(area, h*(j-l-1));
                }
                stk.push(j);
            }
        }
    
        return area;
    }
};



// @lc code=end

int main(){
    Solution sol;     
    vector<vector<char>> mat = {
  {'1','0','1','0','0'},
  {'1','0','1','1','1'},
  {'1','1','1','1','1'},
  {'1','0','0','1','0'}
};
    int out = sol.maximalRectangle(mat); deb(out);

    return 0;
}
