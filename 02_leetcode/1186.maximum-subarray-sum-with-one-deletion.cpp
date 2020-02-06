/*
 * @lc app=leetcode id=1186 lang=cpp
 *
 * [1186] Maximum Subarray Sum with One Deletion
 *
 * https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/description/
 *
 * algorithms
 * Medium (35.25%)
 * Likes:    313
 * Dislikes: 12
 * Total Accepted:    9.9K
 * Total Submissions: 28.1K
 * Testcase Example:  '[1,-2,0,3]'
 *
 * Given an array of integers, return the maximum sum for a non-empty subarray
 * (contiguous elements) with at most one element deletion. In other words, you
 * want to choose a subarray and optionally delete one element from it so that
 * there is still at least one element left and the sum of the remaining
 * elements is maximum possible.
 * 
 * Note that the subarray needs to be non-empty after deleting one element.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: arr = [1,-2,0,3]
 * Output: 4
 * Explanation: Because we can choose [1, -2, 0, 3] and drop -2, thus the
 * subarray [1, 0, 3] becomes the maximum value.
 * 
 * Example 2:
 * 
 * 
 * Input: arr = [1,-2,-2,3]
 * Output: 3
 * Explanation: We just choose [3] and it's the maximum sum.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: arr = [-1,-1,-1,-1]
 * Output: -1
 * Explanation: The final subarray needs to be non-empty. You can't choose [-1]
 * and delete -1 from it, then get an empty subarray to make the sum equals to
 * 0.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= arr.length <= 10^5
 * -10^4 <= arr[i] <= 10^4
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

// Refer: https://www.youtube.com/watch?v=AxkYOnS-hjs 
class Solution1 {
public:
    int maximumSum(vector<int>& a) {
        // equal to max subarray from left + max sub from right
        const int n = a.size();
        vi left(n); vi right(n);

        int high = *max_element(all(a));
        if(high<0) return high;

        int ans = 0;
        int cur_max = 0;
        left[0] = cur_max;
        for(int i=0; i<n; i++){
            cur_max = max(cur_max + a[i], a[i]);
            left[i] = cur_max;
            ans = max(ans, cur_max);
        }

        cur_max = 0;
        for(int i=n-1; i>=0; i--){
            cur_max = max(cur_max + a[i], a[i]);
            right[i] = cur_max;
            ans = max(ans, cur_max);
        }

        // print(a);
        // print(left);
        // print(right);

        for(int i=1; i<n-1; i++){
            ans = max(ans, left[i-1] + right[i+1]);
        }

        return ans;
    }
};

class Solution{
public:
    int maximumSum(vi &a){
        const int n = a.size();
        int ans = a[0];
        int pre_del = 0;
        int pre_no_del = a[0];
        for(int i=1; i<n; i++){
            pre_del = max(pre_no_del, pre_del + a[i]);
            pre_no_del = max(pre_no_del + a[i], a[i]); //simple kadane
            ans = max({ans, pre_del, pre_no_del});
        }
        return ans;
    }
};
// @lc code=end

int main(){
    Solution sol;
    vi arr; int out;
    arr = {1,-4,-5,-2,5,0,-1,2};
    out = sol.maximumSum(arr); deb(out);
    arr = {1,-2,0,3};
    out = sol.maximumSum(arr); deb(out);
    arr = {1,-2,-2,3};
    out = sol.maximumSum(arr); deb(out);
    arr = {-1,-1,-1,-1};
    out = sol.maximumSum(arr); deb(out);
    return 0;
}
