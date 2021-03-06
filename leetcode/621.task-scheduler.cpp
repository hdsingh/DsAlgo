/*
 * @lc app=leetcode id=621 lang=cpp
 *
 * [621] Task Scheduler
 *
 * https://leetcode.com/problems/task-scheduler/description/
 *
 * algorithms
 * Medium (47.53%)
 * Likes:    2414
 * Dislikes: 496
 * Total Accepted:    132.9K
 * Total Submissions: 279.6K
 * Testcase Example:  '["A","A","A","B","B","B"]\n2'
 *
 * Given a char array representing tasks CPU need to do. It contains capital
 * letters A to Z where different letters represent different tasks. Tasks
 * could be done without original order. Each task could be done in one
 * interval. For each interval, CPU could finish one task or just be idle.
 * 
 * However, there is a non-negative cooling interval n that means between two
 * same tasks, there must be at least n intervals that CPU are doing different
 * tasks or just be idle.
 * 
 * You need to return the least number of intervals the CPU will take to finish
 * all the given tasks.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: tasks = ["A","A","A","B","B","B"], n = 2
 * Output: 8
 * Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The number of tasks is in the range [1, 10000].
 * The integer n is in the range [0, 100].
 * 
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
template <typename T>void print_vv(T v){int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}
template <class T, class U> void print_m(map<T,U> m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}

// The least numeber of interval, depend upon the frequency 
// process occuring max times
// Ex if A occurs 4 times and skip =2 then
//  A . .  A . .   A . .   A
// |____| |_____| |_____|  
//   1       2      3      4
// so for (freq-1) intervals, we will have n+1 elements each
// ie. (freq-1)*(n+1)
// if more than 1 elements have same max freq, they will be placed in the end along with A
//  A . .  A . .   A . .   AB
// |____| |_____| |_____|  


// count the max freq and # of chars with max freq
// these form a grp.
// Count of all other chars is less than it so
// others can be placed in bw, or lets say before
// beginning of each grp 
// Example: K=4
// AB__AB__AB__
// here AB has max freq, any other char can be place before AB,
class Solution {
public:
    int leastInterval(vector<char>& tasks, int K) {
        vector<int> cnt(26);
        for(auto t: tasks)
            cnt[t-'A']++;
        
        int mx = 0, cnt_mx = 0;
        for(int i=0; i<26; ++i){
            if(cnt[i]>mx){
                mx = cnt[i];
                cnt_mx = 1;
            }else if(cnt[i]==mx){
                cnt_mx++;
            }
        }
        int ans = (K+1)*(mx-1) + (cnt_mx);
        return max(ans, (int)tasks.size());
    }
};

class Solution0 {
public:
    int leastInterval(vector<char>& tasks, int K) {
        if(!K) return tasks.size();
        map<char,int> cnt;
        for(auto t: tasks){
            cnt[t]++;
        } 

        priority_queue<pair<int, char>> pq; // count, char
        queue<pair<int,char>> q; // available at time, char

        for(auto &t: cnt){
            pq.push({t.second, t.first});
        }

        int time = 0;
        while(pq.size() || q.size()){
            if(q.size() && q.front().first<=time){
                char now = q.front().second; 
                q.pop();
                pq.push({cnt[now], now});
            }
            
            if(pq.size()){
                auto [c, now] = pq.top(); pq.pop();
                if(--cnt[now]>0){
                    q.push({time+1+K, now});
                }
            }
            
            ++time;
        }
        
        return time;
    }
};
// @lc code=end

int main(){
    Solution sol; vector<char> tasks; int n, out;
    tasks = {'A','A','A','B','B','B'}, n = 2;
    out = sol.leastInterval(tasks, n); deb(out);
    tasks = {'A','A','A','B','B','B'}, n=0;
    out = sol.leastInterval(tasks, n); deb(out);
    return 0;
}