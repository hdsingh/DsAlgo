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

// @lc code=start

// Method 1 : DFS Coloring
class Solution1 {
    int n;
    vvi adj;
    vi colors;
    bool has_cycle;
public:
    bool canFinish(int N, vector<vector<int>>& pre) {
        n = N;
        adj.clear(); adj.resize(n);
        colors.clear(); colors.resize(n);
        for(auto p: pre)
            adj[p[0]].push_back(p[1]);

        has_cycle = false;

        for(int i=0; i<n; ++i){
            if(colors[i]==0)
                dfs(i);

            if(has_cycle) return false;
        }

        return !has_cycle;
    }

    void dfs(int x){
        colors[x] = 1;
        for(auto ad: adj[x]){
            if(colors[ad]==0)
                dfs(ad);
            else if(colors[ad]==1)
                has_cycle = true;
        }
        colors[x] = 2;
    }
};

// Method 2: Khans algo
class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vvi adj(n);
        vi indeg(n);
        for(auto p: pre){
            adj[p[0]].push_back(p[1]);
            indeg[p[1]]++;
        }

        queue<int> q;
        for(int i=0;i<n; ++i)
            if(indeg[i]==0)
                q.push(i);
        
        int cnt = 0;
        while(!q.empty()){
            int cur = q.front(); q.pop();
            ++cnt;

            for(auto ad: adj[cur]){
                indeg[ad]--;
                if(indeg[ad]==0)
                    q.push(ad);
            }
        }

        return cnt==n;        
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
