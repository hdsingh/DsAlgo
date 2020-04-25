/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 *
 * https://leetcode.com/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (32.68%)
 * Likes:    1778
 * Dislikes: 495
 * Total Accepted:    314.9K
 * Total Submissions: 963.2K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given a matrix of m x n elements (m rows, n columns), return all elements of
 * the matrix in spiral order.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 4, 5, 6 ],
 * ⁠[ 7, 8, 9 ]
 * ]
 * Output: [1,2,3,6,9,8,7,4,5]
 * 
 * 
 * Example 2:
 * 
 * Input:
 * [
 * ⁠ [1, 2, 3, 4],
 * ⁠ [5, 6, 7, 8],
 * ⁠ [9,10,11,12]
 * ]
 * Output: [1,2,3,4,8,12,11,10,9,5,6,7]
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

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& a) {
        int oth = INT_MIN + 12;
        vvi dirs = {{0,1}, {0,-1}, {1,0},{-1,0}};
        int n = a.size();
        if(n==0) return {};
        int m = a[0].size();
        if(m==0) return {};

        vi out(m*n);
        out[0] = a[0][0];
        a[0][0] = oth;
        vi inc(2); inc[0] = 0; inc[1] = 1;
        int x =0; int y = 1;
        int i = 1;
        while(i<m*n){
            while(0<=x && x<n && 0<=y && y<m && a[x][y]!=oth){
                out[i] = a[x][y];
                a[x][y] = oth;
                x+=inc[0]; y+=inc[1];
                ++i;
            }

            // Undo last move
            x-=inc[0]; y-=inc[1];

            for(auto dir: dirs){
                int nx = x+dir[0];
                int ny = y+dir[1];
                if(0<=nx && nx<n && 0<=ny && ny<m && a[nx][ny]!=oth){
                    inc = dir;
                    break;
                }
            }

            x+=inc[0]; y+=inc[1];
        }
        return out;
    }
};
// @lc code=end

int main(){
    Solution sol; vvi a; vi out;
    a = {
            { 1, 2, 3 },
            { 4, 5, 6 },
            { 7, 8, 9 }
           };
    out = sol.spiralOrder(a); print(out);

    a = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9,10,11,12}
        };
    out = sol.spiralOrder(a); print(out);
    a = {{1},{3},{5}};
    out = sol.spiralOrder(a); print(out);
    a ={{2,5},
        {8,4},
        {0,-1}};
    out = sol.spiralOrder(a); print(out);
    return 0;
}
