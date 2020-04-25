/*
 * @lc app=leetcode id=1036 lang=cpp
 *
 * [1036] Escape a Large Maze
 *
 * https://leetcode.com/problems/escape-a-large-maze/description/
 *
 * algorithms
 * Hard (35.58%)
 * Likes:    174
 * Dislikes: 95
 * Total Accepted:    8.2K
 * Total Submissions: 23K
 * Testcase Example:  '[[0,1],[1,0]]\n[0,0]\n[0,2]'
 *
 * In a 1 million by 1 million grid, the coordinates of each grid square are
 * (x, y) with 0 <= x, y < 10^6.
 * 
 * We start at the source square and want to reach the target square.  Each
 * move, we can walk to a 4-directionally adjacent square in the grid that
 * isn't in the given list of blocked squares.
 * 
 * Return true if and only if it is possible to reach the target square through
 * a sequence of moves.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: blocked = [[0,1],[1,0]], source = [0,0], target = [0,2]
 * Output: false
 * Explanation: 
 * The target square is inaccessible starting from the source square, because
 * we can't walk outside the grid.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: blocked = [], source = [0,0], target = [999999,999999]
 * Output: true
 * Explanation: 
 * Because there are no blocked cells, it's possible to reach the target
 * square.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 0 <= blocked.length <= 200
 * blocked[i].length == 2
 * 0 <= blocked[i][j] < 10^6
 * source.length == target.length == 2
 * 0 <= source[i][j], target[i][j] < 10^6
 * source != target
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

// Ref: https://leetcode.com/problems/escape-a-large-maze/discuss/282860/C%2B%2B-Limited-BFS-28-ms
// Since the grid is too large and obstacles are very less,
// The only way it is possible is if the souce is covered by obstacles
// Or the target is. So we check around both and see, if we are able to go atleast 50 in all
// the directions around
// Do two BFS, one from src->tar, and tar->src
// 2. Simple optimization, if our wave size (imagine BFS wave from src to out)
// if the size of the blocks in wave is more than the blocked, it definitely could not be contained(limited)
class Solution {
    const vvi dirs = {{0,1},{0,-1},{1,0},{-1,0}};
    int blocked_size;
public:
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& src, vector<int>& tar) {
        blocked_size = blocked.size();
        unordered_set<ll> vis;
        for(auto b: blocked)
            vis.insert( ((ll)b[0]<<32) + b[1] );
        return bfs(src, tar, vis) && bfs(tar, src, vis);
    }

    bool bfs(vi src, vi tar, unordered_set<ll> vis){
        queue<pii> q;
        q.push({src[0], src[1]});

        int dist = -1;
        while(!q.empty() && dist< 200){
            ++dist;
            int sz = q.size();
            if(sz>blocked_size) return true;            

            while(sz--){
                pii top = q.front(); q.pop();

                for(auto dir: dirs){
                    int nx = top.first + dir[0];
                    int ny = top.second + dir[1];
                    if(nx<0 || nx>=1e6 || ny<0 || ny>=1e6) continue;
                    if(nx==tar[0] && ny==tar[1]) return true;
                    
                    ll hash = ((ll)nx<<32) + ny;
                    if(vis.insert(hash).second)
                        q.push({nx,ny});
                    
                    // Replaced
                    // if(!vis.count(hash)){
                    //     vis.insert(hash);
                    //     q.push({nx,ny});
                    // }
                }

            }
        }

        return !q.empty();
    }
};
// @lc code=end

int main(){
    vvi blocked; vi source, target; bool out;
    Solution sol;

    blocked = {{0,1},{1,0}}, source = {0,0}, target = {0,2};
    out = sol.isEscapePossible(blocked, source, target); deb(out);

    blocked = {}, source = {0,0}, target = {999999,999999};
    out = sol.isEscapePossible(blocked, source, target); deb(out);

    blocked = {{100059,100063},{100060,100064},
        {100061,100065},{100062,100066},{100063,100067},
        {100064,100068},{100065,100069},{100066,100070},
        {100067,100071},{100068,100072},{100069,100073},
        {100070,100074},{100071,100075},{100072,100076},
        {100073,100077},{100074,100078},{100075,100079},
        {100076,100080},{100077,100081},{100078,100082},
        {100079,100083},{100080,100082},{100081,100081},
        {100082,100080},{100083,100079},{100084,100078},
        {100085,100077},{100086,100076},{100087,100075},
        {100088,100074},{100089,100073},{100090,100072},
        {100091,100071},{100092,100070},{100093,100069},
        {100094,100068},{100095,100067},{100096,100066},
        {100097,100065},{100098,100064},{100099,100063},
        {100098,100062},{100097,100061},{100096,100060},
        {100095,100059},{100094,100058},{100093,100057},
        {100092,100056},{100091,100055},{100090,100054},
        {100089,100053},{100088,100052},{100087,100051},
        {100086,100050},{100085,100049},{100084,100048},
        {100083,100047},{100082,100046},{100081,100045},
        {100080,100044},{100079,100043},{100078,100044},
        {100077,100045},{100076,100046},{100075,100047},
        {100074,100048},{100073,100049},{100072,100050},
        {100071,100051},{100070,100052},{100069,100053},
        {100068,100054},{100067,100055},{100066,100056},
        {100065,100057},{100064,100058},{100063,100059},
        {100062,100060},{100061,100061},{100060,100062}};
       source = {100079,100063}; target = {999948,999967};

    out = sol.isEscapePossible(blocked, source, target); deb(out);
    return 0;
}
