/*
 * @lc app=leetcode id=1235 lang=cpp
 *
 * [1235] Maximum Profit in Job Scheduling
 *
 * https://leetcode.com/problems/maximum-profit-in-job-scheduling/description/
 *
 * algorithms
 * Hard (43.89%)
 * Likes:    274
 * Dislikes: 4
 * Total Accepted:    7.3K
 * Total Submissions: 16.7K
 * Testcase Example:  '[1,2,3,3]\n[3,4,5,6]\n[50,10,40,70]'
 *
 * We have n jobs, where every job is scheduled to be done from startTime[i] to
 * endTime[i], obtaining a profit of profit[i].
 * 
 * You're given the startTime , endTime and profit arrays, you need to output
 * the maximum profit you can take such that there are no 2 jobs in the subset
 * with overlapping time range.
 * 
 * If you choose a job that ends at time X you will be able to start another
 * job that starts at time X.
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
 * Output: 120
 * Explanation: The subset chosen is the first and fourth job. 
 * Time range [1-3]+[3-6] , we get profit of 120 = 50 + 70.
 * 
 * 
 * Example 2:
 * 
 * ⁠
 * 
 * 
 * 
 * Input: startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], profit =
 * [20,20,100,70,60]
 * Output: 150
 * Explanation: The subset chosen is the first, fourth and fifth job. 
 * Profit obtained 150 = 20 + 70 + 60.
 * 
 * 
 * Example 3:
 * 
 * 
 * 
 * 
 * Input: startTime = [1,1,1], endTime = [2,3,4], profit = [5,6,4]
 * Output: 6
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= startTime.length == endTime.length == profit.length <= 5 * 10^4
 * 1 <= startTime[i] < endTime[i] <= 10^9
 * 1 <= profit[i] <= 10^4
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
template <typename T>void print_vv(T v){if(v.size()==0) {cout<<"Empty"<<endl; return;} int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}
template <class T, class U> void print_m(map<T,U> m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}


// Approach: 
// 1. Sort the jobs on the basis of time
// 2. Now start from the end(max possible endtime of a job) and keep
// on decreasing time
// 2.1 Copy the profit from prev position
// 3. If a job's start time is present at cur_time, process it. (while loop for multiple jobs at same index)
// 4. maxProfit[i] = max(maxProfit[i+1], maxProfit[at cur jobs end] + cur_job's_profit)

const int st = 0;
const int ed = 1;
const int pr = 2;

class Solution0 {
public:
    int jobScheduling(vector<int>& stime, vector<int>& etime, vector<int>& profit) {
        int maxEnd = 0;
        int n = stime.size();
        vvi jobs(n);
        for(int i=0; i<n; ++i){
            jobs[i] = {stime[i], etime[i], profit[i]};
            maxEnd = max(maxEnd, etime[i]);
        }

        sort(all(jobs)); // on the basis of start time
        // print_vv(jobs);

        vi maxP(maxEnd+2);
        int i = n-1;
        for(int pos =maxEnd; pos>=0; --pos){
            maxP[pos] = maxP[pos+1];
            while(i>=0 && jobs[i][st]==pos){
                int cur_end = jobs[i][ed];
                int cur_pr = jobs[i][pr];
                maxP[pos] = max(maxP[pos], maxP[cur_end] + cur_pr);
                --i;
            }
        }

        return maxP[0];
    }
};

// binary search could be used to optimise the searching process
// There is no need to maintain and copy prev_profit for the entire array,
// The only thing we need is the prev_startime, equal or greater than cur's end time
// So binary search using lower_bound seems a better option.
// Also use map instead of array
class Solution1 {
public:
    int jobScheduling(vector<int>& stime, vector<int>& etime, vector<int>& profit) {
        int n = stime.size();
        vvi jobs(n);
        for(int i=0; i<n; ++i)
            jobs[i] = {stime[i], etime[i], profit[i]};
        
        sort(all(jobs)); // on the basis of start time
        // print_vv(jobs);
        
        map<int,int> dp; // startime, maxProfit
        int maxP = 0; // running maxProfit
        for(int i=n-1; i>=0; --i){
            int cur_st = jobs[i][st];
            int cur_ed = jobs[i][ed];
            int cur_pr = jobs[i][pr];
            
            auto it = dp.lower_bound(cur_ed);
            int prevProfit = it==dp.end() ? 0 : it->second; 
            maxP = max(maxP, cur_pr + prevProfit);
            dp[cur_st] = maxP;
        }

        return maxP;
    }
};

// Instead of copying the data in jobs array and then sorting, we can just create an
// index array and sort ti on the basis of stime
class Solution {
public:
    int jobScheduling(vector<int>& stime, vector<int>& etime, vector<int>& profit) {
        int n = stime.size();
        vi idx(n); 
        iota(all(idx),0);
        sort(all(idx), [&](int i, int j){
            return stime[i]<stime[j];
        });

        map<int,int> dp; // startime, maxProfit
        int maxP = 0; // running maxProfit
        for(int i=n-1; i>=0; --i){
            int cur_st = stime[idx[i]];
            int cur_ed = etime[idx[i]];
            int cur_pr = profit[idx[i]];
            
            auto it = dp.lower_bound(cur_ed);
            int prevProfit = it==dp.end() ? 0 : it->second; 
            maxP = max(maxP, cur_pr + prevProfit);
            dp[cur_st] = maxP;
        }

        return maxP;
    }
};

// @lc code=end

int main(){
    Solution sol; vi startTime, endTime, profit; int out;
    startTime = {1,2,3,3}, endTime = {3,4,5,6}, profit = {50,10,40,70};
    out =  sol.jobScheduling(startTime, endTime, profit); deb(out);

    startTime = {1,2,3,4,6}, endTime = {3,5,10,6,9}, profit = {20,20,100,70,60};
    out =  sol.jobScheduling(startTime, endTime, profit); deb(out);

    startTime = {1,1,1}, endTime = {2,3,4}, profit = {5,6,4};
    out =  sol.jobScheduling(startTime, endTime, profit); deb(out);

    return 0;
}
