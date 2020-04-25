/*
 * @lc app=leetcode id=1353 lang=cpp
 *
 * [1353] Maximum Number of Events That Can Be Attended
 *
 * https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/description/
 *
 * algorithms
 * Medium (32.41%)
 * Likes:    279
 * Dislikes: 38
 * Total Accepted:    8.7K
 * Total Submissions: 26.8K
 * Testcase Example:  '[[1,2],[2,3],[3,4]]'
 *
 * Given an array of events where events[i] = [startDayi, endDayi]. Every event
 * i starts at startDayi and ends at endDayi.
 * 
 * You can attend an event i at any day d where startTimei <= d <= endTimei.
 * Notice that you can only attend one event at any time d.
 * 
 * Return the maximum number of events you can attend.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: events = [[1,2],[2,3],[3,4]]
 * Output: 3
 * Explanation: You can attend all the three events.
 * One way to attend them all is as shown.
 * Attend the first event on day 1.
 * Attend the second event on day 2.
 * Attend the third event on day 3.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: events= [[1,2],[2,3],[3,4],[1,2]]
 * Output: 4
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: events = [[1,4],[4,4],[2,2],[3,4],[1,1]]
 * Output: 4
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: events = [[1,100000]]
 * Output: 1
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: events = [[1,1],[1,2],[1,3],[1,4],[1,5],[1,6],[1,7]]
 * Output: 7
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= events.length <= 10^5
 * events[i].length == 2
 * 1 <= events[i][0] <= events[i][1] <= 10^5
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
#define sz(a) int((a).size())
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

// On a particular day attend the events that have least further remaining time
// So sort the elements based on starting time.
// On each day add elements to pq and attend one with shortest further remaining time
// remove the unattended events of prev days;
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(), events.end());
        int ans = 0;

        priority_queue<int, vector<int>, greater<int>> pq; // end, start
        
        int i=0;
        int day = 1;
        while(day<=1e5){
            // remove old events (finish time yesterday)
            while(pq.size() && pq.top()<day)
                pq.pop();

            // add events starting today
            while(i<n && events[i][0]==day){
                pq.push(events[i][1]); // end start
                ++i;
            }
            
            if(pq.size() && pq.top()>=day){
                pq.pop();
                ++ans;
            }
            
            ++day;
        }

        return ans;
    }
};
// @lc code=end

int main(){
    Solution sol; vvi events; int out;
    events = {{1,2},{2,3},{3,4}};
    out = sol.maxEvents(events); deb(out);

    events= {{1,2},{2,3},{3,4},{1,2}};
    out = sol.maxEvents(events); deb(out);

    events = {{1,4},{4,4},{2,2},{3,4},{1,1}};
    out = sol.maxEvents(events); deb(out);

    events = {{1,100000}};
    out = sol.maxEvents(events); deb(out);

    events = {{1,1},{1,2},{1,3},{1,4},{1,5},{1,6},{1,7}};
    out = sol.maxEvents(events); deb(out);


    events = {{1,1},{1,2},{1,3},{1,4},{1,5},{1,6},{1,7}};
    out = sol.maxEvents(events); deb(out);

    return 0;
}
