/*
 * @lc app=leetcode id=785 lang=cpp
 *
 * [785] Is Graph Bipartite?
 *
 * https://leetcode.com/problems/is-graph-bipartite/description/
 *
 * algorithms
 * Medium (44.55%)
 * Likes:    842
 * Dislikes: 107
 * Total Accepted:    65K
 * Total Submissions: 144.2K
 * Testcase Example:  '[[1,3],[0,2],[1,3],[0,2]]'
 *
 * Given an undirected graph, return true if and only if it is bipartite.
 * 
 * Recall that a graph is bipartite if we can split it's set of nodes into two
 * independent subsets A and B such that every edge in the graph has one node
 * in A and another node in B.
 * 
 * The graph is given in the following form: graph[i] is a list of indexes j
 * for which the edge between nodes i and j exists.  Each node is an integer
 * between 0 and graph.length - 1.  There are no self edges or parallel edges:
 * graph[i] does not contain i, and it doesn't contain any element twice.
 * 
 * 
 * Example 1:
 * Input: [[1,3], [0,2], [1,3], [0,2]]
 * Output: true
 * Explanation: 
 * The graph looks like this:
 * 0----1
 * |    |
 * |    |
 * 3----2
 * We can divide the vertices into two colors: {0, 2} and {1, 3}.
 * 
 * 
 * 
 * Example 2:
 * Input: [[1,2,3], [0,2], [0,1,3], [0,2]]
 * Output: false
 * Explanation: 
 * The graph looks like this:
 * 0----1
 * | \  |
 * |  \ |
 * 3----2
 * We cannot find a way to divide the set of nodes into two independent
 * subsets.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * graph will have length in range [1, 100].
 * graph[i] will contain integers in range [0, graph.length - 1].
 * graph[i] will not contain i or duplicate values.
 * The graph is undirected: if any element j is in graph[i], then i will be in
 * graph[j].
 * 
 * 
 */
#include "cpp.h"
#include "extra.h"
using namespace std;

// @lc code=start
class Solution {
public:
    // BFS
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        queue<int> q;
        vi colors(n, 0);
        
        for(int i=0; i<n; i++){
            if(colors[i]==0){
                colors[i]=1;
                q.push(i);

                while(!q.empty()){
                    int u = q.front(); q.pop();
                    
                    for(int v: graph[u]){
                        if(colors[v]==0){
                            colors[v]= -colors[u];
                            q.push(v);
                        }
                        else if(colors[v]!=-colors[u]) 
                            return false;
                        
                    }
                }
            }
        }
        return true;
    }

    // DFS1
    bool isBipartite1(vector<vector<int>>& graph) {
        int n = graph.size();
        vi color(n, 0); //if not visited then 0
        // colors: -1, 1
        
        for(int i=0; i<n; i++)
            if(color[i]==0 && !dfs(i, 1, color, graph)) 
                return false;
        
        return true;
    }

    bool dfs(int u, int c, vi &color,  vvi &graph){
        if(color[u]!=0) return color[u] == c;
        color[u] = c;
        
        for(int v: graph[u]){
            if(!dfs(v, -c, color, graph))
                return false;
            }

        return true;
    }
};

// @lc code=end
int main(){
    Solution s;
    vector<vvi> graphs;
    graphs = { {{1,3},{0,2},{1,3},{0,2}},
               {{1,2,3},{0,2},{0,1,3},{0,2}},
             };
            
    for(auto graph: graphs){
        bool out = s.isBipartite(graph);
        cout<<out;
    }
    

}
