/*
 * @lc app=leetcode id=1343 lang=cpp
 *
 * [1343] Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold
 *
 * https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/description/
 *
 * algorithms
 * Medium (64.56%)
 * Likes:    52
 * Dislikes: 9
 * Total Accepted:    4.8K
 * Total Submissions: 7.4K
 * Testcase Example:  '[2,2,2,2,5,5,5,8]\n3\n4'
 *
 * Given an array of integers arr and two integers k and threshold.
 * 
 * Return the number of sub-arrays of size k and average greater than or equal
 * to threshold.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: arr = [2,2,2,2,5,5,5,8], k = 3, threshold = 4
 * Output: 3
 * Explanation: Sub-arrays [2,5,5],[5,5,5] and [5,5,8] have averages 4, 5 and 6
 * respectively. All other sub-arrays of size 3 have averages less than 4 (the
 * threshold).
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: arr = [1,1,1,1,1], k = 1, threshold = 0
 * Output: 5
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: arr = [11,13,17,23,29,31,7,5,2,3], k = 3, threshold = 5
 * Output: 6
 * Explanation: The first 6 sub-arrays of size 3 have averages greater than 5.
 * Note that averages are not integers.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: arr = [7,7,7,7,7,7,7], k = 7, threshold = 7
 * Output: 1
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: arr = [4,4,4,4], k = 4, threshold = 1
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= arr.length <= 10^5
 * 1 <= arr[i] <= 10^4
 * 1 <= k <= arr.length
 * 0 <= threshold <= 10^4
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

class Solution {
public:
    int numOfSubarrays(vector<int>& a, int k, int th) {
        int n = a.size();

        vi sum(n);
        sum[0] = a[0];
        for(int i=1; i<n; i++)  
            sum[i] = sum[i-1] + a[i];

        int cnt = 0;
        for(int i=0; i+k-1<n; i++){
            int avg = sum[i+k-1] - (i-1>0 ? sum[i-1] : 0);
            avg/=k;
            if(avg>=th)
                cnt++;
        }

        return cnt;

    }
};
// @lc code=end

int main(){
    Solution sol; vi arr; int cnt, k, threshold;
    arr = {2,2,2,2,5,5,5,8}, k = 3, threshold = 4;
    cnt = sol.numOfSubarrays(arr, k, threshold); deb(cnt);

    arr = {1,1,1,1,1}, k = 1, threshold = 0;
    cnt = sol.numOfSubarrays(arr, k, threshold); deb(cnt);
    arr = {11,13,17,23,29,31,7,5,2,3}, k = 3, threshold = 5;
    cnt = sol.numOfSubarrays(arr, k, threshold); deb(cnt);
    arr = {7,7,7,7,7,7,7}, k = 7, threshold = 7;
    cnt = sol.numOfSubarrays(arr, k, threshold); deb(cnt);
    arr = {4,4,4,4}, k = 4, threshold = 1;
    cnt = sol.numOfSubarrays(arr, k, threshold); deb(cnt);
    
    
    return 0;
}