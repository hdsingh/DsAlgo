/*
 * @lc app=leetcode id=918 lang=cpp
 *
 * [918] Maximum Sum Circular Subarray
 *
 * https://leetcode.com/problems/maximum-sum-circular-subarray/description/
 *
 * algorithms
 * Medium (33.93%)
 * Likes:    497
 * Dislikes: 25
 * Total Accepted:    16.7K
 * Total Submissions: 49.3K
 * Testcase Example:  '[1,-2,3,-2]'
 *
 * Given a circular array C of integers represented by A, find the maximum
 * possible sum of a non-empty subarray of C.
 * 
 * Here, a circular array means the end of the array connects to the beginning
 * of the array.  (Formally, C[i] = A[i] when 0 <= i < A.length, and
 * C[i+A.length] = C[i] when i >= 0.)
 * 
 * Also, a subarray may only include each element of the fixed buffer A at most
 * once.  (Formally, for a subarray C[i], C[i+1], ..., C[j], there does not
 * exist i <= k1, k2 <= j with k1 % A.length = k2 % A.length.)
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [1,-2,3,-2]
 * Output: 3
 * Explanation: Subarray [3] has maximum sum 3
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [5,-3,5]
 * Output: 10
 * Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [3,-1,2,-1]
 * Output: 4
 * Explanation: Subarray [2,-1,3] has maximum sum 2 + (-1) + 3 = 4
 * 
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: [3,-2,2,-3]
 * Output: 3
 * Explanation: Subarray [3] and [3,-2,2] both have maximum sum 3
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: [-2,-3,-1]
 * Output: -1
 * Explanation: Subarray [-1] has maximum sum -1
 * 
 * 
 * 
 * 
 * Note: 
 * 
 * 
 * -30000 <= A[i] <= 30000
 * 1 <= A.length <= 30000
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

// If subarray is in middle, use kadane
// If on two separate sides, find sum, revSum
// find preMax of revSum, so that max possible sum
// from both ends is added
class Solution1 {
public:
    int maxSubarraySumCircular(vector<int>& a) {
        int n = a.size();
        vi maxSum(n); // l to r
        maxSum[0] = a[0];
        int curSum = a[0];

        for(int i=1; i<n; i++){
            curSum = max(a[i], curSum+a[i]);
            maxSum[i] = max(maxSum[i-1], curSum);
        }

        vi sum(n);
        sum[0] = a[0];
        for(int i=1; i<n; i++) 
            sum[i] = sum[i-1] + a[i];

        vi sumRev(n);
        sumRev[n-1] = a[n-1];
        for(int i=n-2; i>=0; i--){
            sumRev[i] = sumRev[i+1] + a[i];
        }

        for(int i=n-2; i>=0; i--){
            sumRev[i] = max(sumRev[i], sumRev[i+1]);
        }

        int mx = maxSum[n-1];
        for(int i=0; i<n-1; i++){
            mx = max(mx, sum[i] + sumRev[i+1]);
        }

        return mx;
    }
};

// Ref: https://leetcode.com/problems/maximum-sum-circular-subarray/discuss/178422/One-Pass
class Solution{
public:
    int maxSubarraySumCircular(vi  &a){
        int n = a.size();
        int maxSum = a[0], curMax=a[0], minSum = a[0], curMin = a[0], total = a[0];

        for(int i=1; i<n; i++){
            curMax = max(curMax + a[i], a[i]);
            maxSum = max(maxSum, curMax);
            curMin = min(curMin + a[i], a[i]);
            minSum = min(minSum, curMin);     
            total+=a[i];
        }

        return maxSum > 0 ? max(maxSum, total - minSum) : maxSum;
    }
};
// @lc code=end

int main(){
    Solution sol; vi a; int out;
    vvi as = { 
        {1,-2,3,-2},
        {5,-3,5},
        {3,-1,2,-1},
        {3,-2,2,-3},
        {-2,-3,-1},
        {-2,2,-2,9},
    };
    for(auto &a: as){
        out = sol.maxSubarraySumCircular(a); deb(out);
    }
    return 0;
}
