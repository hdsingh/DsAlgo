/*
 * @lc app=leetcode id=1335 lang=cpp
 *
 * [1335] Minimum Difficulty of a Job Schedule
 *
 * https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/description/
 *
 * algorithms
 * Hard (55.20%)
 * Likes:    109
 * Dislikes: 3
 * Total Accepted:    4.1K
 * Total Submissions: 7.5K
 * Testcase Example:  '[6,5,4,3,2,1]\n2'
 *
 * You want to schedule a list of jobs in d days. Jobs are dependent (i.e To
 * work on the i-th job, you have to finish all the jobs j where 0 <= j < i).
 * 
 * You have to finish at least one task every day. The difficulty of a job
 * schedule is the sum of difficulties of each day of the d days. The
 * difficulty of a day is the maximum difficulty of a job done in that day.
 * 
 * Given an array of integers jobDifficulty and an integer d. The difficulty of
 * the i-th job is jobDifficulty[i].
 * 
 * Return the minimum difficulty of a job schedule. If you cannot find a
 * schedule for the jobs return -1.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: jobDifficulty = [6,5,4,3,2,1], d = 2
 * Output: 7
 * Explanation: First day you can finish the first 5 jobs, total difficulty =
 * 6.
 * Second day you can finish the last job, total difficulty = 1.
 * The difficulty of the schedule = 6 + 1 = 7 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: jobDifficulty = [9,9,9], d = 4
 * Output: -1
 * Explanation: If you finish a job per day you will still have a free day. you
 * cannot find a schedule for the given jobs.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: jobDifficulty = [1,1,1], d = 3
 * Output: 3
 * Explanation: The schedule is one job per day. total difficulty will be 3.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: jobDifficulty = [7,1,7,1,7,1], d = 3
 * Output: 15
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: jobDifficulty = [11,111,22,222,33,333,44,444], d = 6
 * Output: 843
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= jobDifficulty.length <= 300
 * 0 <= jobDifficulty[i] <= 1000
 * 1 <= d <= 10
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


class Solution {
    const int inf = 1e9;
public:
    int minDifficulty(vector<int>& jd, int D) {
        int n = jd.size();
        if(D>n) return -1;
        vvi dp(D+1, vi(n+1));
        // min difficult of completing till jth job on day d

        for(int i=1; i<=n; ++i)
            dp[1][i] = max(dp[1][i-1], jd[i-1]);

        for(int d=2; d<=D; ++d){
            for(int j=d; j<=n; ++j){
                dp[d][j] = inf;
                int curmax = 0;
                for(int beg=j; beg>=d; --beg){
                    curmax = max(curmax, jd[beg-1]);
                    min_self(dp[d][j], dp[d-1][beg-1] + curmax);
                }
            }
        }

        // print_vv(dp);
        
        return dp[D][n];
    }
};

// @lc code=end

int main(){
    Solution sol; vi jobDifficulty; int d, out; 
    jobDifficulty = {6,5,4,3,2,1}, d = 2;
    out =  sol.minDifficulty(jobDifficulty, d); deb(out);

    jobDifficulty = {9,9,9}, d = 4;
    out =  sol.minDifficulty(jobDifficulty, d); deb(out);

    jobDifficulty = {1,1,1}, d = 3;
    out =  sol.minDifficulty(jobDifficulty, d); deb(out);

    jobDifficulty = {7,1,7,1,7,1}, d = 3;
    out =  sol.minDifficulty(jobDifficulty, d); deb(out);

    jobDifficulty = {11,111,22,222,33,333,44,444}, d = 6;
    out =  sol.minDifficulty(jobDifficulty, d); deb(out);
    return 0;
}

