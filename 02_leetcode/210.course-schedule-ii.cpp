/*
 * @lc app=leetcode id=210 lang=cpp
 *
 * [210] Course Schedule II
 *
 * https://leetcode.com/problems/course-schedule-ii/description/
 *
 * algorithms
 * Medium (36.21%)
 * Likes:    1302
 * Dislikes: 92
 * Total Accepted:    182.7K
 * Total Submissions: 496.9K
 * Testcase Example:  '2\n[[1,0]]'
 *
 * There are a total of n courses you have to take, labeled from 0 to n-1.
 * 
 * Some courses may have prerequisites, for example to take course 0 you have
 * to first take course 1, which is expressed as a pair: [0,1]
 * 
 * Given the total number of courses and a list of prerequisite pairs, return
 * the ordering of courses you should take to finish all courses.
 * 
 * There may be multiple correct orders, you just need to return one of them.
 * If it is impossible to finish all courses, return an empty array.
 * 
 * Example 1:
 * 
 * 
 * Input: 2, [[1,0]] 
 * Output: [0,1]
 * Explanation: There are a total of 2 courses to take. To take course 1 you
 * should have finished   
 * course 0. So the correct course order is [0,1] .
 * 
 * Example 2:
 * 
 * 
 * Input: 4, [[1,0],[2,0],[3,1],[3,2]]
 * Output: [0,1,2,3] or [0,2,1,3]
 * Explanation: There are a total of 4 courses to take. To take course 3 you
 * should have finished both     
 * ⁠            courses 1 and 2. Both courses 1 and 2 should be taken after you
 * finished course 0. 
 * So one correct course order is [0,1,2,3]. Another correct ordering is
 * [0,2,1,3] .
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
        //kahn's algo
    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        vvi adj(n);
        vi indeg(n, 0);
        vi order;

        // Create adj matrix
        for(const auto &e: edges){
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
            order.push_back(u);

            // dec indeg of all adj vertices of u
            for(const int &v: adj[u]){
                indeg[v]--;
                if(indeg[v]==0)
                    q.push(v);
            }

            cnt++;
        }

        // if cnt!=n cycle is present
        // here is cycle is present return false so
        if (cnt!=n) return {};
        
        reverse(order.begin(), order.end());
        return order;
    }
};



// @lc code=end
int main(){
    Solution s;
    vvi courses; int nc;
    courses = {{1,0}}; nc = 2;
    print(s.findOrder(nc, courses));

    courses = {{1,0}, {2,0}, {3,1}, {3,2}}; nc=4;
    print(s.findOrder(nc, courses)); 
}
