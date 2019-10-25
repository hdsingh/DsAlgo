/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 *
 * https://leetcode.com/problems/course-schedule/description/
 *
 * algorithms
 * Medium (39.19%)
 * Likes:    2330
 * Dislikes: 113
 * Total Accepted:    273.8K
 * Total Submissions: 689.7K
 * Testcase Example:  '2\n[[1,0]]'
 *
 * There are a total of n courses you have to take, labeled from 0 to n-1.
 * 
 * Some courses may have prerequisites, for example to take course 0 you have
 * to first take course 1, which is expressed as a pair: [0,1]
 * 
 * Given the total number of courses and a list of prerequisite pairs, is it
 * possible for you to finish all courses?
 * 
 * Example 1:
 * 
 * 
 * Input: 2, [[1,0]] 
 * Output: true
 * Explanation: There are a total of 2 courses to take. 
 * To take course 1 you should have finished course 0. So it is possible.
 * 
 * Example 2:
 * 
 * 
 * Input: 2, [[1,0],[0,1]]
 * Output: false
 * Explanation: There are a total of 2 courses to take. 
 * To take course 1 you should have finished course 0, and to take course 0 you
 * should
 * also have finished course 1. So it is impossible.
 * 
 * 
 * Note:
 * 
 * 
 * The input prerequisites is a graph represented by a list of edges, not
 * adjacency matrices. Read more about how a graph is represented.
 * You may assume that there are no duplicate edges in the input
 * prerequisites.
 * 
 * 
 */
#include "cpp.h"
#include "extra.h"
using namespace std;

// @lc code=start
class Solution {
public:
    // using kahn's algo
    bool canFinish(int n, vector<vector<int>>& edges) {
        vvi adj(n);
        vi indeg(n, 0);

        // Create adj matrix
        for(auto e: edges){
            adj[e[0]].push_back(e[1]);
            indeg[e[1]]++;
        }

        queue<int> q;
        int cnt = 0;

        // push all the indeg=0 vertices into q
        for(int i=0; i<n; i++)
            if(indeg[i]==0)
                q.push(i);
        
        while(!q.empty()){
            int u = q.front(); q.pop();

            // dec indeg of all adj vertices of u
            for(int v: adj[u]){
                indeg[v]--;
                if(indeg[v]==0)
                    q.push(v);
            }

            cnt++;
        }

        // if cnt!=n cycle is present
        // here is cycle is present return false so
        return cnt==n;
    }

    // 3 color method
    bool canFinish1(int n, vector<vector<int>>& edges) {
        vvi adj(n);

        for(auto e: edges){
            adj[e[0]].push_back(e[1]);
        }

        vi color(n, 1); //all white(1)

        for(int i=0; i<n; i++){
            if(color[i]==1)
                if(dfs_color(i, color, adj)) return false;
                // return false if cycle exists, else true
        }
        return true;
    }

    bool dfs_color(int u, vi &color, vvi &adj){
        color[u]=2;

        for(int v: adj[u]){
            if(color[v]==3) continue;

            if(color[v]==2) return true;

            if(color[v]==1)
                if(dfs_color(v, color, adj)) return true;
        }

        color[u]=3;
        return false;
    }
};
// @lc code=end
int main(){
    Solution s;
    vvi courses; int nc;
    courses = {{1,0}};
    cout<<s.canFinish(nc, courses)<<endl;

    courses = {{1,0},{0,1}};
    cout<<s.canFinish(nc, courses)<<endl;    
}
