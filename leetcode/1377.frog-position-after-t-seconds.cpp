/*
 * @lc app=leetcode id=1377 lang=cpp
 *
 * [1377] Frog Position After T Seconds
 *
 * https://leetcode.com/problems/frog-position-after-t-seconds/description/
 *
 * algorithms
 * Hard (32.59%)
 * Likes:    62
 * Dislikes: 35
 * Total Accepted:    5.4K
 * Total Submissions: 16.5K
 * Testcase Example:  '7\n[[1,2],[1,3],[1,7],[2,4],[2,6],[3,5]]\n2\n4'
 *
 * Given an undirected tree consisting of n vertices numbered from 1 to n. A
 * frog starts jumping from the vertex 1. In one second, the frog jumps from
 * its current vertex to another unvisited vertex if they are directly
 * connected. The frog can not jump back to a visited vertex. In case the frog
 * can jump to several vertices it jumps randomly to one of them with the same
 * probability, otherwise, when the frog can not jump to any unvisited vertex
 * it jumps forever on the same vertex. 
 * 
 * The edges of the undirected tree are given in the array edges, where
 * edges[i] = [fromi, toi] means that exists an edge connecting directly the
 * vertices fromi and toi.
 * 
 * Return the probability that after t seconds the frog is on the vertex
 * target.
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: n = 7, edges = [[1,2],[1,3],[1,7],[2,4],[2,6],[3,5]], t = 2, target =
 * 4
 * Output: 0.16666666666666666 
 * Explanation: The figure above shows the given graph. The frog starts at
 * vertex 1, jumping with 1/3 probability to the vertex 2 after second 1 and
 * then jumping with 1/2 probability to vertex 4 after second 2. Thus the
 * probability for the frog is on the vertex 4 after 2 seconds is 1/3 * 1/2 =
 * 1/6 = 0.16666666666666666. 
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input: n = 7, edges = [[1,2],[1,3],[1,7],[2,4],[2,6],[3,5]], t = 1, target =
 * 7
 * Output: 0.3333333333333333
 * Explanation: The figure above shows the given graph. The frog starts at
 * vertex 1, jumping with 1/3 = 0.3333333333333333 probability to the vertex 7
 * after second 1. 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: n = 7, edges = [[1,2],[1,3],[1,7],[2,4],[2,6],[3,5]], t = 20, target
 * = 6
 * Output: 0.16666666666666666
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 100
 * edges.length == n-1
 * edges[i].length == 2
 * 1 <= edges[i][0], edges[i][1] <= n
 * 1 <= t <= 50
 * 1 <= target <= n
 * Answers within 10^-5 of the actual value will be accepted as correct.
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

// Edge cases:
// When when either the node is somewhere in the middle and we reach that node but not in target time, we simply return 0.
// When it's a leaf node but the time is less than the required one, it'll simply jump until the goal time, thus we can return the same probablity.

class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vvi adj(n+1);
        vi visited(n+1);
        for(auto &ed: edges){
            adj[ed[0]].push_back(ed[1]);
            adj[ed[1]].push_back(ed[0]);
        }

        // find the adj and unvisited edges of a node x
        auto find_adj_cnt = [&](int x){
            int cnt = 0;
            for(auto ad: adj[x])
                if(!visited[ad])
                    ++cnt;
            return cnt;
        };

        queue<pair<int,double>> q;
        visited[1] = 1;
        double prob = 1;
        double ad_cnt = find_adj_cnt(1);
        // deb(ad_cnt);
        q.push({1,prob}); //node, next_prob
    
        int level = -1;
        while(q.size()){
            ++level;
            if(level>t) break;
            int breadth = q.size();
            for(int i=0; i<breadth; ++i){
                auto cur = q.front(); q.pop();
                int cur_node = cur.first; 
                double cur_prob = cur.second;
                // deb3(level, cur_node, cur_prob);
                ad_cnt = find_adj_cnt(cur_node);

                if(cur_node==target){
                    if(level==t) return cur_prob;
                    if(level<t){
                        if(ad_cnt) return 0;
                        return cur_prob;
                    }
                }

                for(auto ad: adj[cur_node]){
                    if(!visited[ad]){
                        visited[ad] = 1;
                        q.push({ad, cur_prob/ad_cnt});
                    }
                }
            }
        }

        return 0;
    }
};

// @lc code=end

int main(){
    Solution sol;
    int n,t,target; double out; vvi edges;

    n = 7, edges = {{1,2},{1,3},{1,7},{2,4},{2,6},{3,5}}, t = 2, target = 4;
    out = sol.frogPosition(n,edges,t,target); deb(out);

    n = 7, edges = {{1,2},{1,3},{1,7},{2,4},{2,6},{3,5}}, t = 1, target = 7;
    out = sol.frogPosition(n,edges,t,target); deb(out);

    n = 7, edges = {{1,2},{1,3},{1,7},{2,4},{2,6},{3,5}}, t = 20, target = 6;    
    out = sol.frogPosition(n,edges,t,target); deb(out);

    n = 3, edges = { { 2,1 },{ 3,2 } }, t = 1, target = 2;
    out = sol.frogPosition(n,edges,t,target); deb(out);

    n = 8, edges ={{2,1},{3,2},{4,1},{5,1},{6,4},{7,1},{8,7}}, t = 7, target=7;
    out = sol.frogPosition(n,edges,t,target); deb(out);

    return 0;
}
