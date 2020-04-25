/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 *
 * https://leetcode.com/problems/daily-temperatures/description/
 *
 * algorithms
 * Medium (61.95%)
 * Likes:    2095
 * Dislikes: 66
 * Total Accepted:    122.4K
 * Total Submissions: 197.7K
 * Testcase Example:  '[73,74,75,71,69,72,76,73]'
 *
 * 
 * Given a list of daily temperatures T, return a list such that, for each day
 * in the input, tells you how many days you would have to wait until a warmer
 * temperature.  If there is no future day for which this is possible, put 0
 * instead.
 * 
 * For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76,
 * 73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].
 * 
 * 
 * Note:
 * The length of temperatures will be in the range [1, 30000].
 * Each temperature will be an integer in the range [30, 100].
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

class Solution1 {
public:
    vector<int> dailyTemperatures(vector<int>& a) {
        int n = a.size();
        vi lastPos(101, INT_MAX);

        lastPos[a[n-1]] = n-1;
        a[n-1] = 0;
        for(int i=n-2; i>=0; i--){
            int temp = a[i];
            int daysPos = INT_MAX;
            for(int t=temp+1; t<=100; t++){
                daysPos = min(daysPos, lastPos[t]);
            }
            if(daysPos==INT_MAX)
                a[i] = 0;
            else 
                a[i] = daysPos - i;
    
            lastPos[temp] = i;
        }
        return a;
    }
};

// Optimisation: Instead of checking for every number, we can just 
// Use the days_distance stored, to reach a temperature warmer than it
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& a) {
        int n = a.size();
        vi out(n);

        for(int i=n-2; i>=0; i--){
            int j=i+1;
            while(j<n && a[j]<=a[i]){
                if(out[j]==0) j=n;
                else j+=out[j];
            }
            out[i] = j==n ? 0 : j-i;
        }
    
        return out;
    }
};

// for a temp, what matters is the latest pos of more warm temperature
// ex: 30....80....65.. 45.....30...60...70
// So here for 45 only 60 matters and for 65 only 70 matters
// when we get 80, it is the most warm temp, so all temps less than it could be 
// discarded
// Stack
class Solution2 {
public:
    vector<int> dailyTemperatures(vector<int>& a) {
        int n = a.size();
        vi ans(n);
        stack<int> stk; // stores idx

        for(int i=n-1; i>=0; i--){
            int temp = a[i];
            while(stk.size() && temp>=a[stk.top()]){
                stk.pop();
            }
            if(stk.empty())
                ans[i] = 0;
            else
                ans[i] = stk.top() - i;
            
            stk.push(i);
        
        }
        return ans;        
    }
};

// @lc code=end

int main(){
    Solution sol; vi a;
    a = {73, 74, 75, 71, 69, 72, 76, 73};
    // a = {0,0,0,0,0,0,30};
    a = {34,80,80,34,34,80,80,80,80,34};
    a = sol.dailyTemperatures(a); print(a);

    return 0;
}
