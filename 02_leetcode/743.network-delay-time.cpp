/*
 * @lc app=leetcode id=743 lang=cpp
 *
 * [743] Network Delay Time
 *
 * https://leetcode.com/problems/network-delay-time/description/
 *
 * algorithms
 * Medium (43.88%)
 * Likes:    825
 * Dislikes: 181
 * Total Accepted:    51.5K
 * Total Submissions: 116K
 * Testcase Example:  '[[2,1,1],[2,3,1],[3,4,1]]\n4\n2'
 *
 * There are N network nodes, labelled 1 to N.
 * 
 * Given times, a list of travel times as directed edges times[i] = (u, v, w),
 * where u is the source node, v is the target node, and w is the time it takes
 * for a signal to travel from source to target.
 * 
 * Now, we send a signal from a certain node K. How long will it take for all
 * nodes to receive the signal? If it is impossible, return -1.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: times = [[2,1,1],[2,3,1],[3,4,1]], N = 4, K = 2
 * Output: 2
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * N will be in the range [1, 100].
 * K will be in the range [1, N].
 * The length of times will be in the range [1, 6000].
 * All edges times[i] = (u, v, w) will have 1 <= u, v <= N and 0 <= w <= 100.
 * 
 * 
 */
#include "cpp.h"
#include "extra.h"
using namespace std;


// @lc code=start
typedef pair<int, int> pii;
// const int inf = 1e9;

class Solution {
public:
    // Dijkstras
    int networkDelayTime(vector<vector<int>>& edges, int V, int src) {
        vector<vector<pii> >adj(V+1);
        for(auto &e: edges){
            adj[e[0]].push_back({e[1], e[2]});
        }
        
        vector<int> dist(V+1, inf);
        dist[src]=0;
        priority_queue<pii, vector<pii>, greater<pii>> pq; //weight, v
        pq.push({0, src});

        int u, v, w;
        vector<bool> visited(V+1, false);

        while(!pq.empty()){
            pii p = pq.top(); pq.pop();
            u = p.second;

            if(visited[u]) continue;

            for(auto to: adj[u]){
                v = to.first, w = to.second;
                if(dist[u]+w < dist[v]){
                    dist[v] = dist[u]+w;
                    pq.push({dist[v], v});
                }
            }

        }

        int ans = *max_element(dist.begin()+1, dist.end());
        return ans==inf ? -1: ans;
    }

    // Bellman ford
    int networkDelayTime1(vector<vector<int>>& edges, int V, int src) {
        int E = edges.size(); //num of edges
        // V = num. of vertices

        // initialse dist to all vertices as int_max
        vector<int> dist(V+1, INT_MAX);
        dist[src] = 0;

        // relax all edges for V-1 times
        for(int count =0; count<V; count++){
            for(int j=0; j<E; j++){
                int u = edges[j][0], v = edges[j][1], w = edges[j][2];

                // if(dist[u]!=INT_MAX && dist[u] + w < dist[v]){
                //     dist[v] = dist[u] + w;
                // }
                dist[v] = min(dist[u] + w, dist[v]);
            }
        }
        
        // since starting from index 1;
        int time = *max_element(dist.begin()+1, dist.end());
        return time==INT_MAX ? -1 : time;
    }
};
// @lc code=end
int main(){
    Solution s;
    vvi edges = {{2,1,1}, {2,3,1}, {3,4,1}};
    cout<<s.networkDelayTime(edges, 4, 2)<<endl;    
}

