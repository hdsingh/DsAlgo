/*
 * @lc app=leetcode id=997 lang=cpp
 *
 * [997] Find the Town Judge
 *
 * https://leetcode.com/problems/find-the-town-judge/description/
 *
 * algorithms
 * Easy (49.53%)
 * Likes:    260
 * Dislikes: 38
 * Total Accepted:    31.7K
 * Total Submissions: 64.1K
 * Testcase Example:  '2\n[[1,2]]'
 *
 * In a town, there are N people labelled from 1 to N.  There is a rumor that
 * one of these people is secretly the town judge.
 * 
 * If the town judge exists, then:
 * 
 * 
 * The town judge trusts nobody.
 * Everybody (except for the town judge) trusts the town judge.
 * There is exactly one person that satisfies properties 1 and 2.
 * 
 * 
 * You are given trust, an array of pairs trust[i] = [a, b] representing that
 * the person labelled a trusts the person labelled b.
 * 
 * If the town judge exists and can be identified, return the label of the town
 * judge.  Otherwise, return -1.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: N = 2, trust = [[1,2]]
 * Output: 2
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: N = 3, trust = [[1,3],[2,3]]
 * Output: 3
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: N = 3, trust = [[1,3],[2,3],[3,1]]
 * Output: -1
 * 
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: N = 3, trust = [[1,2],[2,3]]
 * Output: -1
 * 
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: N = 4, trust = [[1,3],[1,4],[2,3],[2,4],[4,3]]
 * Output: 3
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= N <= 1000
 * trust.length <= 10000
 * trust[i] are all different
 * trust[i][0] != trust[i][1]
 * 1 <= trust[i][0], trust[i][1] <= N
 * 
 * 
 */
#include "cpp.h"
#include "extra.h"
using namespace std;

// @lc code=start
typedef std::vector<int> vi;
typedef std::vector<vector<int>> vvi;

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vi count(N+1, 0);
        for(vi t: trust){
            count[t[0]]--; //out
            count[t[1]]++; //in
        }

        for(int i=1; i<N+1; i++)
            if(count[i]==N-1) 
                return i;

        return -1;        
    }

    int findJudge2(int N, vector<vector<int>>& trust) {
        vi in(N+1); vi out(N+1);
        for(vi t: trust){
            out[t[0]]++; in[t[1]]++;
        }

        for(int i=1; i<N+1; i++)
            if(out[i]==0 && in[i]==N-1)
                return i;
        
        return -1;
    }

    // Aproach 1: Find in and out degree of all the vertices
    int findJudge1(int N, vector<vector<int>>& trust) {
        vector<set<int>> adj(N+1, set<int>{});

        vi in(N+1); 
        vi out(N+1);

        for(vi t: trust){
            adj[t[0]].insert(t[1]);
            out[t[0]]++;
        }

        for(int i=0; i<N+1; i++){
            set<int> t = adj[i];

            for(int j: t){
                in[j]++;
            }
        }

        // print(in);
        // print(out);

        for(int i=1; i<N+1; i++)
            if(out[i]==0 && in[i]==N-1)
                return i;

        return -1;             
    }
};
// @lc code=end
int main(){
    Solution s;
    vvi trust;
    int n;
    n = 2; trust = {{1,2}};
    // n = 3; trust = {{1,3}, {2,3}};
    // n = 3; trust = {{1,3},{2,3},{3,1}};
    // n = 3; trust = {{1,2},{2,3}};
    // n = 4; trust = {{1,3},{1,4},{2,3},{2,4},{4,3}};
    
    cout<<s.findJudge(n, trust)<<endl;
}
