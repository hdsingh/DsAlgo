/*
 * @lc app=leetcode id=1344 lang=cpp
 *
 * [1344] Angle Between Hands of a Clock
 *
 * https://leetcode.com/problems/angle-between-hands-of-a-clock/description/
 *
 * algorithms
 * Medium (60.48%)
 * Likes:    76
 * Dislikes: 18
 * Total Accepted:    6K
 * Total Submissions: 10K
 * Testcase Example:  '12\n30'
 *
 * Given two numbers, hour and minutes. Return the smaller angle (in
 * sexagesimal units) formed between the hour and the minute hand.
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: hour = 12, minutes = 30
 * Output: 165
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input: hour = 3, minutes = 30
 * Output: 75
 * 
 * 
 * Example 3:
 * 
 * 
 * 
 * 
 * Input: hour = 3, minutes = 15
 * Output: 7.5
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: hour = 4, minutes = 50
 * Output: 155
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: hour = 12, minutes = 0
 * Output: 0
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= hour <= 12
 * 0 <= minutes <= 59
 * Answers within 10^-5 of the actual value will be accepted as correct.
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

class Solution0 {
public:
    double angleClock(double H, double M) {
        double hdeg = H*30 + M/2;
        double mdeg = 6*M;
        double dif = abs(hdeg-mdeg);
        double tot = 360;
        return min(dif, tot-dif);
    }
};

class Solution {
public:
    double angleClock(double H, double M) {
        double ang = 360*abs(H/12 + (M/12)/60 - M/60);
        return min(ang,360-ang);
    }
};
// @lc code=end

int main(){
    Solution0 sol; int hour, minutes; double out;
    hour = 12, minutes = 30;
    out = sol.angleClock(hour, minutes); deb(out);
    hour = 3, minutes = 30;
    out = sol.angleClock(hour, minutes); deb(out);
    hour = 3, minutes = 15;
    out = sol.angleClock(hour, minutes); deb(out);
    hour = 4, minutes = 50;
    out = sol.angleClock(hour, minutes); deb(out);
    hour = 12, minutes = 0;
    out = sol.angleClock(hour, minutes); deb(out);
    return 0;
}
