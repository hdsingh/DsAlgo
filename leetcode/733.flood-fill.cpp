/*
 * @lc app=leetcode id=733 lang=cpp
 *
 * [733] Flood Fill
 *
 * https://leetcode.com/problems/flood-fill/description/
 *
 * algorithms
 * Easy (53.07%)
 * Likes:    780
 * Dislikes: 152
 * Total Accepted:    91K
 * Total Submissions: 171.4K
 * Testcase Example:  '[[1,1,1],[1,1,0],[1,0,1]]\n1\n1\n2'
 *
 * 
 * An image is represented by a 2-D array of integers, each integer
 * representing the pixel value of the image (from 0 to 65535).
 * 
 * Given a coordinate (sr, sc) representing the starting pixel (row and column)
 * of the flood fill, and a pixel value newColor, "flood fill" the image.
 * 
 * To perform a "flood fill", consider the starting pixel, plus any pixels
 * connected 4-directionally to the starting pixel of the same color as the
 * starting pixel, plus any pixels connected 4-directionally to those pixels
 * (also with the same color as the starting pixel), and so on.  Replace the
 * color of all of the aforementioned pixels with the newColor.
 * 
 * At the end, return the modified image.
 * 
 * Example 1:
 * 
 * Input: 
 * image = [[1,1,1],[1,1,0],[1,0,1]]
 * sr = 1, sc = 1, newColor = 2
 * Output: [[2,2,2],[2,2,0],[2,0,1]]
 * Explanation: 
 * From the center of the image (with position (sr, sc) = (1, 1)), all pixels
 * connected 
 * by a path of the same color as the starting pixel are colored with the new
 * color.
 * Note the bottom corner is not colored 2, because it is not 4-directionally
 * connected
 * to the starting pixel.
 * 
 * 
 * 
 * Note:
 * The length of image and image[0] will be in the range [1, 50].
 * The given starting pixel will satisfy 0  and 0 .
 * The value of each color in image[i][j] and newColor will be an integer in
 * [0, 65535].
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

// DFS
class Solution0 {
    int nc,n,m, oc;
    vvi dirs = {{1,0},{-1,0},{0,1},{0,-1}};
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int _newColor) {
       nc = _newColor; 
       oc = image[sr][sc];
       if(oc==nc) return image;
       n = image.size(); m = image[0].size();
       dfs(image, sr, sc);

       return image;
    }

    void dfs(vvi &image, int r, int c){
        if(r<0 || r>=n || c<0 || c>=m || image[r][c]!=oc) return;
        image[r][c] = nc;
        for(auto dir: dirs){
            dfs(image, r+dir[0], c+dir[1]);
        }
    }
};

// BFS
class Solution {
    vvi dirs = {{1,0},{-1,0},{0,1},{0,-1}};
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int nc) {
       int oc = image[sr][sc];
       int n = image.size(), m = image[0].size();
       if(oc==nc) return image;
       queue<vi> q;
       vi cur = {sr,sc};
       image[sr][sc] = nc;
       q.push(cur);

       while(!q.empty()){
            cur = q.front(); q.pop();
            for(auto dir: dirs){
                int rr = cur[0] + dir[0];
                int cc = cur[1] + dir[1];
                if(rr>=0 && rr<n && cc>=0 && cc<m && image[rr][cc]==oc){
                    image[rr][cc] = nc;
                    q.push({rr,cc});
                }
            }
       }

       return image;
    }
};
// @lc code=end


int main(){
    Solution sol;
    vvi image = {{1,1,1},{1,1,0},{1,0,1}};
    int sr = 1, sc = 1, newColor = 2;
    vvi out = sol.floodFill(image,sr,sc,newColor); print_vv(out);
    image = {{0,0,0},
             {0,1,1}};
    out = sol.floodFill(image,1,1,1); print_vv(out);

    return 0;
}