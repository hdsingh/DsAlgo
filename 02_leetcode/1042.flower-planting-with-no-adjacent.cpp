/*
 * @lc app=leetcode id=1042 lang=cpp
 *
 * [1042] Flower Planting With No Adjacent
 *
 * https://leetcode.com/problems/flower-planting-with-no-adjacent/description/
 *
 * algorithms
 * Easy (47.87%)
 * Likes:    136
 * Dislikes: 165
 * Total Accepted:    12K
 * Total Submissions: 25.1K
 * Testcase Example:  '3\n[[1,2],[2,3],[3,1]]'
 *
 * You have N gardens, labelled 1 to N.  In each garden, you want to plant one
 * of 4 types of flowers.
 * 
 * paths[i] = [x, y] describes the existence of a bidirectional path from
 * garden x to garden y.
 * 
 * Also, there is no garden that has more than 3 paths coming into or leaving
 * it.
 * 
 * Your task is to choose a flower type for each garden such that, for any two
 * gardens connected by a path, they have different types of flowers.
 * 
 * Return any such a choice as an array answer, where answer[i] is the type of
 * flower planted in the (i+1)-th garden.  The flower types are denoted 1, 2,
 * 3, or 4.  It is guaranteed an answer exists.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: N = 3, paths = [[1,2],[2,3],[3,1]]
 * Output: [1,2,3]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: N = 4, paths = [[1,2],[3,4]]
 * Output: [1,2,1,2]
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: N = 4, paths = [[1,2],[2,3],[3,4],[4,1],[1,3],[2,4]]
 * Output: [1,2,3,4]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= N <= 10000
 * 0 <= paths.size <= 20000
 * No garden has 4 or more paths coming into or leaving it.
 * It is guaranteed an answer exists.
 * 
 * 
 * 
 * 
 */
#include "cpp.h"
#include "extra.h"
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vvi adj(N);
        vi res(N, 0);

        for(vi p: paths){
            adj[p[0]-1].push_back(p[1]-1);
            adj[p[1]-1].push_back(p[0]-1);            
        }

        // find the color which can't be used, since already used by neighbours
        for(int u=0; u<N; u++){
            vector<int> color_used(5, 0);

            for(int v: adj[u])
                color_used[res[v]] = 1;

            // if a color has not been used, use it and break
            for(int c=1; c<=4; c++){
                if(!color_used[c]){
                    res[u]=c;
                    break;
                }
            }
        }
        
        return res;        
    }
};
// @lc code=end

int main(){
    Solution s;
    vvi paths; int n; 
    paths = {{1,2}, {2,3}, {3,1}}; n=3;
    paths = {{1,2},{3,4}}; n=4;
    // paths = {{1,2},{2,3},{3,4},{4,1},{1,3},{2,4}}; n=4;
    // paths = {{4,1},{4,2},{4,3},{2,5},{1,2},{1,5}}; n=5;

    print(s.gardenNoAdj(n, paths));
}