/*
 * @lc app=leetcode id=1319 lang=cpp
 *
 * [1319] Number of Operations to Make Network Connected
 *
 * https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/
 *
 * algorithms
 * Medium (50.49%)
 * Likes:    197
 * Dislikes: 3
 * Total Accepted:    8.9K
 * Total Submissions: 17.5K
 * Testcase Example:  '4\n[[0,1],[0,2],[1,2]]'
 *
 * There are n computers numbered from 0 to n-1 connected by ethernet cables
 * connections forming a network where connections[i] = [a, b] represents a
 * connection between computers a and b. Any computer can reach any other
 * computer directly or indirectly through the network.
 * 
 * Given an initial computer network connections. You can extract certain
 * cables between two directly connected computers, and place them between any
 * pair of disconnected computers to make them directly connected. Return the
 * minimum number of times you need to do this in order to make all the
 * computers connected. If it's not possible, return -1. 
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: n = 4, connections = [[0,1],[0,2],[1,2]]
 * Output: 1
 * Explanation: Remove cable between computer 1 and 2 and place between
 * computers 1 and 3.
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
 * Output: 2
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]
 * Output: -1
 * Explanation: There are not enough cables.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: n = 5, connections = [[0,1],[0,2],[3,4],[2,3]]
 * Output: 0
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 10^5
 * 1 <= connections.length <= min(n*(n-1)/2, 10^5)
 * connections[i].length == 2
 * 0 <= connections[i][0], connections[i][1] < n
 * connections[i][0] != connections[i][1]
 * There are no repeated connections.
 * No two computers are connected by more than one cable.
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
class Solution {
    int n;
    unordered_map<int,bool> visited;
    vvi adj;
public:
    int makeConnected(int _n, vector<vector<int>>& cons) {
        n = _n;
        if(n-1 > cons.size()) return -1;
        visited.clear();
        adj.clear();
        adj.resize(n);

        for(auto con: cons){
            adj[con[0]].push_back(con[1]);
            adj[con[1]].push_back(con[0]);
        }

        int groups = 0;
        forn(i,n){
            if(!visited[i]){
                ++groups;
                dfs(i);
            }
        }

        return groups -1;
    }

    void dfs(const int &x){
        visited[x] = true;
        for(auto &ad: adj[x])
            if(!visited[ad])
                dfs(ad);
    }
};
// @lc code=end

int main(){
    Solution sol; int n; vvi connections; int out;
    n = 4, connections = {{0,1},{0,2},{1,2}};
    out = sol.makeConnected(n,connections); deb(out);

    n = 6, connections = {{0,1},{0,2},{0,3},{1,2},{1,3}};
    out = sol.makeConnected(n,connections); deb(out);

    n = 6, connections = {{0,1},{0,2},{0,3},{1,2}};
    out = sol.makeConnected(n,connections); deb(out);

    n = 5, connections = {{0,1},{0,2},{3,4},{2,3}};
    out = sol.makeConnected(n,connections); deb(out);

    n = 11, connections = {{1,4},{0,3},{1,3},{3,7},{2,7},{0,1},{2,4},{3,6},{5,6},{6,7},{4,7},{0,7},{5,7}};    
    out = sol.makeConnected(n,connections); deb(out);

    // for(auto con: connections)
    //     cout<<con[0]<<" "<<con[1]<<endl;
    return 0;
}
