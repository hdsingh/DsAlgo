/*
 * @lc app=leetcode id=1124 lang=cpp
 *
 * [1124] Longest Well-Performing Interval
 *
 * https://leetcode.com/problems/longest-well-performing-interval/description/
 *
 * algorithms
 * Medium (32.17%)
 * Likes:    287
 * Dislikes: 47
 * Total Accepted:    8.5K
 * Total Submissions: 26.4K
 * Testcase Example:  '[9,9,6,0,6,6,9]'
 *
 * We are given hours, a list of the number of hours worked per day for a given
 * employee.
 * 
 * A day is considered to be a tiring day if and only if the number of hours
 * worked is (strictly) greater than 8.
 * 
 * A well-performing interval is an interval of days for which the number of
 * tiring days is strictly larger than the number of non-tiring days.
 * 
 * Return the length of the longest well-performing interval.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: hours = [9,9,6,0,6,6,9]
 * Output: 3
 * Explanation: The longest well-performing interval is [9,9,6].
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= hours.length <= 10000
 * 0 <= hours[i] <= 16
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

// For prefix sums, (of +1, -1)
// if pre[i] == pre[j], len = j-i+1 = j - seen[sum] + 1;
// there are equal number of 1s and 0s,
// here we want 1s = 0s + 1;
// so len = j - seen[sum-1], (a[i+1]..j); 
class Solution {
public:
    int longestWPI(vector<int>& a) {
        int n = a.size();
        int mxlen = 0;
        unordered_map<int,int> seen; // sum, index
        // the first time a sum is seen at some index
        int sum = 0;

        for(int i=0; i<n; i++){
            int x = a[i];
            sum += x>8 ? 1 : -1;
            if(seen.find(sum)==seen.end()) 
                seen[sum] = i;
            if(sum>0){
                mxlen = i+1; // 1s more than 0s
            }else{
                if(seen.find(sum-1)!=seen.end())
                    mxlen = max(mxlen, i - seen[sum-1]);
            }
        }
        
        return mxlen;
    }
};
// @lc code=end

int main(){
    Solution sol; vvi as; int out;
    as = {
        {8,10,6,16,5},
        // {9,9,6,0,6,6,9},
        // {1,1,10,10,2,9,2,1},
        // {6,9,9},
        // {9,6,9},
        // {6,6,9,9,9,9,6,6},
        // {6,6,6,6,6,9,},
        // {9,9,9,6,6,6,6,6},
    };

    for(auto a: as){
        out = sol.longestWPI(a); deb(out);
    }
    return 0;
}
