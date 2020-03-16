/*
 * @lc app=leetcode id=1383 lang=cpp
 *
 * [1383] Maximum Performance of a Team
 *
 * https://leetcode.com/problems/maximum-performance-of-a-team/description/
 *
 * algorithms
 * Hard (27.55%)
 * Likes:    120
 * Dislikes: 9
 * Total Accepted:    3.2K
 * Total Submissions: 11.6K
 * Testcase Example:  '6\n[2,10,3,1,5,8]\n[5,4,3,9,7,2]\n2'
 *
 * There are n engineers numbered from 1 to n and two arrays: speed and
 * efficiency, where speed[i] and efficiency[i] represent the speed and
 * efficiency for the i-th engineer respectively. Return the maximum
 * performance of a team composed of at most k engineers, since the answer can
 * be a huge number, return this modulo 10^9 + 7.
 * 
 * The performance of a team is the sum of their engineers' speeds multiplied
 * by the minimum efficiency among their engineers. 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 2
 * Output: 60
 * Explanation: 
 * We have the maximum performance of the team by selecting engineer 2 (with
 * speed=10 and efficiency=4) and engineer 5 (with speed=5 and efficiency=7).
 * That is, performance = (10 + 5) * min(4, 7) = 60.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 3
 * Output: 68
 * Explanation:
 * This is the same example as the first but k = 3. We can select engineer 1,
 * engineer 2 and engineer 5 to get the maximum performance of the team. That
 * is, performance = (2 + 10 + 5) * min(5, 4, 7) = 68.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 4
 * Output: 72
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 10^5
 * speed.length == n
 * efficiency.length == n
 * 1 <= speed[i] <= 10^5
 * 1 <= efficiency[i] <= 10^8
 * 1 <= k <= n
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

template <typename T>void print(T v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<v.size(); i++)cout<<setw(w)<<i<<" ";cout<<endl;}for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(w)<<*i<<" ";cout<<endl;}
template <typename T>void print_vv(T v){if(v.size()==0) {cout<<"Empty"<<endl; return;} int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}
template <class T, class U> void print_m(map<T,U> m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}

// 1. Sort the pairs on the basis of efficiency
//  speed =      [2,10,3,1,5,8], 
//  efficiency = [5,4,3,9,7,2]  will be:
//  spe = [1,5,2,10,3,8]
//  eff = [9,7,5,4,3,2]
// will act as a pair
//  Start from the left, and keep on adding elements in the PQ
// At each time the size must remain K
// Also maintain Sum of elements in the Q
// Same as hint: 
// Keep track of the engineers by their efficiency in decreasing order.
// For each engineer's efficiency take the K highest speeds among the engineers previously tracked.
const int mod = 1e9 + 7;
class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& eff, int k) {
        vector<pii> comb;
        for(int i=0; i<n; ++i){
            comb.push_back({speed[i], eff[i]});
        }

        sort(all(comb),[&](pii &p1, pii &p2){
            return p1.second>p2.second;
        });

        // for(auto &p: comb)
            // cout<<p.first<<" "<<p.second<<endl;

        long long sum = 0;
        long long maxPerf = 0;

        priority_queue<int, vector<int>, greater<int>> pq; //min pq
        
        for(auto &p: comb){
            sum+=p.first;
            int cur_eff = p.second;

            pq.push(p.first);
            if(pq.size()>k){
                sum-=pq.top(); pq.pop();
            }

            maxPerf = max(maxPerf, sum*cur_eff);
        }

        return maxPerf%mod;
    }
};
// @lc code=end

int main(){
    Solution sol;
    int n; vi speed, efficiency; int k, out;
    n = 6, speed = {2,10,3,1,5,8}, efficiency = {5,4,3,9,7,2}, k = 2;
    out = sol.maxPerformance(n,speed,efficiency,k);deb(out);

    n = 6, speed = {2,10,3,1,5,8}, efficiency = {5,4,3,9,7,2}, k = 3;
    out = sol.maxPerformance(n,speed,efficiency,k);deb(out);

    n = 6, speed = {2,10,3,1,5,8}, efficiency = {5,4,3,9,7,2}, k = 4;    
    out = sol.maxPerformance(n,speed,efficiency,k);deb(out);
    
    return 0;
}
