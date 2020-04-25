/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 *
 * https://leetcode.com/problems/spiral-matrix-ii/description/
 *
 * algorithms
 * Medium (51.15%)
 * Likes:    768
 * Dislikes: 100
 * Total Accepted:    172.5K
 * Total Submissions: 337.2K
 * Testcase Example:  '3'
 *
 * Given a positive integer n, generate a square matrix filled with elements
 * from 1 to n^2 in spiral order.
 * 
 * Example:
 * 
 * 
 * Input: 3
 * Output:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 8, 9, 4 ],
 * ⁠[ 7, 6, 5 ]
 * ]
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

// Keep on moving forward, incrementing in hte selected dir
// till it is allowed(x,y exists ans not occupied)
// upon hitting an end, change the direction
// There would always be only one possible valid dir.
// Think of this process like a snake moving spirally
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vvi dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        vvi a(n, vi(n));
        a[0][0] = 1;
        vi inc(2);
        inc[0] = 0; inc[1] = 1;
        int x, y; x = 0; y = 1;
        int i = 2;
        while(i<=n*n){
            while(x>=0 && x<n && y>=0 && y<n && a[x][y]==0){
                a[x][y] = i;
                x+=inc[0]; y+=inc[1];
                i++;
            }
            
            x-=inc[0]; y-=inc[1];

            // change direction of increment
            for(auto dir: dirs){
                int nx = x + dir[0];
                int ny = y + dir[1];
                if(0<=nx && nx<n && 0<=ny && ny<n && a[nx][ny]==0){
                    inc = dir;
                    break;
                }
               
            }
            x+=inc[0]; y+=inc[1];
        }

        return a;
    }
};
// @lc code=end

int main(){
    Solution sol; int n; vvi out;
    fore(i, 1, 10){
        n = i;
        out = sol.generateMatrix(n); print_vv(out);
    }
    return 0;
}
