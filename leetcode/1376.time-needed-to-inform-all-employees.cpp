/*
 * @lc app=leetcode id=1376 lang=cpp
 *
 * [1376] Time Needed to Inform All Employees
 *
 * https://leetcode.com/problems/time-needed-to-inform-all-employees/description/
 *
 * algorithms
 * Medium (54.69%)
 * Likes:    67
 * Dislikes: 8
 * Total Accepted:    5.9K
 * Total Submissions: 10.8K
 * Testcase Example:  '1\n0\n[-1]\n[0]'
 *
 * A company has n employees with a unique ID for each employee from 0 to n -
 * 1. The head of the company has is the one with headID.
 * 
 * Each employee has one direct manager given in the manager array where
 * manager[i] is the direct manager of the i-th employee, manager[headID] = -1.
 * Also it's guaranteed that the subordination relationships have a tree
 * structure.
 * 
 * The head of the company wants to inform all the employees of the company of
 * an urgent piece of news. He will inform his direct subordinates and they
 * will inform their subordinates and so on until all employees know about the
 * urgent news.
 * 
 * The i-th employee needs informTime[i] minutes to inform all of his direct
 * subordinates (i.e After informTime[i] minutes, all his direct subordinates
 * can start spreading the news).
 * 
 * Return the number of minutes needed to inform all the employees about the
 * urgent news.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 1, headID = 0, manager = [-1], informTime = [0]
 * Output: 0
 * Explanation: The head of the company is the only employee in the company.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 6, headID = 2, manager = [2,2,-1,2,2,2], informTime =
 * [0,0,1,0,0,0]
 * Output: 1
 * Explanation: The head of the company with id = 2 is the direct manager of
 * all the employees in the company and needs 1 minute to inform them all.
 * The tree structure of the employees in the company is shown.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: n = 7, headID = 6, manager = [1,2,3,4,5,6,-1], informTime =
 * [0,6,5,4,3,2,1]
 * Output: 21
 * Explanation: The head has id = 6. He will inform employee with id = 5 in 1
 * minute.
 * The employee with id = 5 will inform the employee with id = 4 in 2 minutes.
 * The employee with id = 4 will inform the employee with id = 3 in 3 minutes.
 * The employee with id = 3 will inform the employee with id = 2 in 4 minutes.
 * The employee with id = 2 will inform the employee with id = 1 in 5 minutes.
 * The employee with id = 1 will inform the employee with id = 0 in 6 minutes.
 * Needed time = 1 + 2 + 3 + 4 + 5 + 6 = 21.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: n = 15, headID = 0, manager = [-1,0,0,1,1,2,2,3,3,4,4,5,5,6,6],
 * informTime = [1,1,1,1,1,1,1,0,0,0,0,0,0,0,0]
 * Output: 3
 * Explanation: The first minute the head will inform employees 1 and 2.
 * The second minute they will inform employees 3, 4, 5 and 6.
 * The third minute they will inform the rest of employees.
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: n = 4, headID = 2, manager = [3,3,-1,2], informTime = [0,0,162,914]
 * Output: 1076
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 10^5
 * 0 <= headID < n
 * manager.length == n
 * 0 <= manager[i] < n
 * manager[headID] == -1
 * informTime.length == n
 * 0 <= informTime[i] <= 1000
 * informTime[i] == 0 if employee i has no subordinates.
 * It is guaranteed that all the employees can be informed.
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

// sub: subordinates
// BFS
// Find the path with maxTime(weight)
class Solution0 {
    vvi adj;
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        adj.clear(); adj.resize(n);
        for(int i=0; i<n; ++i){
            if(manager[i]!=-1)
                adj[manager[i]].push_back(i);
        }

        // print_vv(adj);
    
        queue<pii> q; // index, time req to reach till this node
        int curIndex = headID;
        int prevTime = 0;
        q.push({curIndex, prevTime});
        int maxTime = 0;

        while(!q.empty()){
            int breadth = q.size();
            for(int i=0; i<breadth; ++i){
                curIndex = q.front().first; prevTime = q.front().second; q.pop();
                maxTime = max(maxTime, prevTime);
                for(auto sub: adj[curIndex])
                    q.push({sub, prevTime + informTime[curIndex]});
            }
        }

        return maxTime;
    }
};

// DFS
class Solution1 {
    vvi adj;
    int maxTime = 0;
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        adj.clear(); adj.resize(n);
        for(int i=0; i<n; ++i){
            if(manager[i]!=-1)
                adj[manager[i]].push_back(i);
        }
        
        return dfs(headID, informTime);
    }

    int dfs(int cur, vi &informTime){
        int time = 0;
        for(int &sub: adj[cur])
            time = max(dfs(sub,informTime), time);
        return time + informTime[cur];
    }
};

// Using stack 
class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vvi adj;
        int maxTime = 0;

        adj.clear(); adj.resize(n);
        for(int i=0; i<n; ++i){
            if(manager[i]!=-1)
                adj[manager[i]].push_back(i);
        } 

        stack<pii> stk;
        pii cur = {headID, informTime[headID]};
        stk.push(cur);

        while(!stk.empty()){
            int curIndex = stk.top().first; int time = stk.top().second; stk.pop();
            maxTime = max(maxTime, time);

            for(auto &sub: adj[curIndex]){
                stk.push({sub, time + informTime[sub]});
            }
        }

        return maxTime;
    }
};
// @lc code=end

int main(){
    Solution sol;
    int n; int headID; vector<int> manager,informTime; int out;

    n = 1, headID = 0, manager = {-1}, informTime = {0};
    out = sol.numOfMinutes(n,headID,manager,informTime); deb(out);    

    n = 6, headID = 2, manager = {2,2,-1,2,2,2}, informTime = {0,0,1,0,0,0};
    out = sol.numOfMinutes(n,headID,manager,informTime); deb(out);    

    n = 7, headID = 6, manager = {1,2,3,4,5,6,-1}, informTime = {0,6,5,4,3,2,1};
    out = sol.numOfMinutes(n,headID,manager,informTime); deb(out);    

    n = 15, headID = 0, manager = {-1,0,0,1,1,2,2,3,3,4,4,5,5,6,6}, informTime = {1,1,1,1,1,1,1,0,0,0,0,0,0,0,0};
    out = sol.numOfMinutes(n,headID,manager,informTime); deb(out);    

    n = 4, headID = 2, manager = {3,3,-1,2}, informTime = {0,0,162,914};
    out = sol.numOfMinutes(n,headID,manager,informTime); deb(out);    

    n = 11, headID =4, manager = {5,9,6,10,-1,8,9,1,9,3,4}, informTime = {0,213,0,253,686,170,975,0,261,309,337};
    out = sol.numOfMinutes(n,headID,manager,informTime); deb(out);    

    return 0;
}
