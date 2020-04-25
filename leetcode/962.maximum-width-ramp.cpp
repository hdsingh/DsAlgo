/*
 * @lc app=leetcode id=962 lang=cpp
 *
 * [962] Maximum Width Ramp
 *
 * https://leetcode.com/problems/maximum-width-ramp/description/
 *
 * algorithms
 * Medium (43.78%)
 * Likes:    427
 * Dislikes: 10
 * Total Accepted:    14.6K
 * Total Submissions: 33.2K
 * Testcase Example:  '[6,0,8,2,1,5]'
 *
 * Given an array A of integers, a ramp is a tuple (i, j) for which i < j and
 * A[i] <= A[j].  The width of such a ramp is j - i.
 * 
 * Find the maximum width of a ramp in A.  If one doesn't exist, return 0.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [6,0,8,2,1,5]
 * Output: 4
 * Explanation: 
 * The maximum width ramp is achieved at (i, j) = (1, 5): A[1] = 0 and A[5] =
 * 5.
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [9,8,1,0,1,9,4,0,4,1]
 * Output: 7
 * Explanation: 
 * The maximum width ramp is achieved at (i, j) = (2, 9): A[2] = 1 and A[9] =
 * 1.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 2 <= A.length <= 50000
 * 0 <= A[i] <= 50000
 * 
 * 
 * 
 * 
 * 
 * 
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

// ref : https://leetcode.com/problems/maximum-width-ramp/discuss/265765/Detailed-Explaination-of-all-the-three-approaches
class Solution {
public:
    int maxWidthRamp(vector<int>& a) {
        int n = a.size();
        int res = 0;
        vi stk;
        for(int i=0; i<n; i++)
            if(stk.empty() || a[stk.back()]>a[i])
                stk.push_back(i);

        for(int j=n-1; j>=0; --j){
            while(!stk.empty() && a[stk.back()]<=a[j]){
                res = max(res, j - stk.back());
                stk.pop_back();
            }
        }

        return res;       

    }
};
// @lc code=end

int main(){
    Solution sol; vvi as; int out;
    as = {
        // {6,0},
        {6,0,8,2,1,5},
        {9,8,1,0,1,9,4,0,4,1},
    };
    for(auto &a: as){
        out = sol.maxWidthRamp(a); deb(out);
    }
    return 0;
}
