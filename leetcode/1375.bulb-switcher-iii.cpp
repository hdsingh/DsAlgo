/*
 * @lc app=leetcode id=1375 lang=cpp
 *
 * [1375] Bulb Switcher III
 *
 * https://leetcode.com/problems/bulb-switcher-iii/description/
 *
 * algorithms
 * Medium (58.73%)
 * Likes:    73
 * Dislikes: 9
 * Total Accepted:    7.4K
 * Total Submissions: 12.7K
 * Testcase Example:  '[2,1,3,5,4]'
 *
 * There is a room with n bulbs, numbered from 1 to n, arranged in a row from
 * left to right. Initially, all the bulbs are turned off.
 * 
 * At moment k (for k from 0 to n - 1), we turn on the light[k] bulb. A bulb
 * change color to blue only if it is on and all the previous bulbs (to the
 * left) are turned on too.
 * 
 * Return the number of moments in which all turned on bulbs are blue.
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: light = [2,1,3,5,4]
 * Output: 3
 * Explanation: All bulbs turned on, are blue at the moment 1, 2 and 4.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: light = [3,2,4,1,5]
 * Output: 2
 * Explanation: All bulbs turned on, are blue at the moment 3, and 4
 * (index-0).
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: light = [4,1,2,3]
 * Output: 1
 * Explanation: All bulbs turned on, are blue at the moment 3 (index-0).
 * Bulb 4th changes to blue at the moment 3.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: light = [2,1,4,3,6,5]
 * Output: 3
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: light = [1,2,3,4,5,6]
 * Output: 6
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == light.length
 * 1 <= n <= 5 * 10^4
 * light is a permutation of  [1, 2, ..., n]
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
    int numTimesAllBlue(vector<int>& seq) {
        int n = seq.size();
        vi a(n+1);
        iota(all(a),0);

        int lastOn = 0; int lastBlue = 0;
        int cnt = 0;
        for(auto &x: seq){
            a[x] = 0;
            lastOn = max(lastOn, x);

            while(lastBlue+1<=n && a[lastBlue+1]==0)
                ++lastBlue;

            if(lastBlue==lastOn)
                ++cnt;            
        }

        return cnt;
    }
};
// @lc code=end

// Good Observation: a rightmost on bulb at ith position can get all blue,
// only in the ith turn (because we need i turns to switch on the bulb including and previous it)
class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        int n = light.size(); int cnt = 0;
        int rightOn = 0;

        for(int i=0; i<n; ++i){
            rightOn = max(rightOn,light[i]);
            if(rightOn==i+1) ++cnt;
        }
        return cnt;
    }
};

int main(){
    Solution sol; int out;
    vvi lights = {
        {2,1,3,5,4},
        {3,2,4,1,5},
        {4,1,2,3},
        {2,1,4,3,6,5},
        {1,2,3,4,5,6}
    };

    for(auto light: lights){
        out = sol.numTimesAllBlue(light); deb(out);
    }

    return 0;
}
