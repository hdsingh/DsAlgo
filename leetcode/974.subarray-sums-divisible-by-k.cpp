/*
 * @lc app=leetcode id=974 lang=cpp
 *
 * [974] Subarray Sums Divisible by K
 *
 * https://leetcode.com/problems/subarray-sums-divisible-by-k/description/
 *
 * algorithms
 * Medium (47.54%)
 * Likes:    592
 * Dislikes: 54
 * Total Accepted:    24.4K
 * Total Submissions: 51.3K
 * Testcase Example:  '[4,5,0,-2,-3,1]\n5'
 *
 * Given an array A of integers, return the number of (contiguous, non-empty)
 * subarrays that have a sum divisible by K.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: A = [4,5,0,-2,-3,1], K = 5
 * Output: 7
 * Explanation: There are 7 subarrays with a sum divisible by K = 5:
 * [4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2,
 * -3]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= A.length <= 30000
 * -10000 <= A[i] <= 10000
 * 2 <= K <= 10000
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
template <typename T>void print_vv(T v){int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}
template <class T, class U> void print_m(map<T,U> m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}

// TLE
class Solution1 {
public:
    int subarraysDivByK(vector<int>& a, int K) {
        int n = a.size();
        vi pre(n); pre[0] = a[0];
        for(int i=1; i<n; i++){
            pre[i] = pre[i-1] + a[i];
        }
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=i; j>=0; j--){
                int sum = pre[i] - (j-1>=0 ? pre[j-1] : 0);
                if(sum%K==0) cnt++;
            }
        }
        return cnt;
    }
};

// Ref: https://leetcode.com/problems/subarray-sums-divisible-by-k/solution/
// Put initialpre sum = 0;
// use mod of presum to count the k's possible
// If Pre[i]%K - Pre[j]%K = 0 , then p[i] to p[j] is a
// valid pair. so store all pre mod k and use P&C to count.
class Solution2 {
public:
    int subarraysDivByK(vector<int>& a, int K) {
        int n = a.size();
        vi pre(n); pre[0] = a[0];
        for(int i=1; i<n; i++)
            pre[i] = pre[i-1] + a[i];
        
        vi cnt(K);
        cnt[0] = 1; // for the 0 element at beg
        for(auto x : pre)
            cnt[(x%K + K)%K]++;
        
        print(cnt,1);

        int out = 0;
        for(auto x: cnt){
            // out+= C(x,2)
            if(x>=2) out+= (x * (x-1))/2;
        }
        return out;   
    }
};

// Same idea better implentation
class Solution {
public:
    int subarraysDivByK(vector<int>& a, int K) {
        vi cnt(K);
        cnt[0] = 1;
        int sum = 0;

        for(auto &x: a){
            sum+=x;
            cnt[(sum%K + K)%K]++;
        }

        int out = 0;
        for(auto &x: cnt)
            if(x>=2) out+=(x*(x-1))/2;

        return out;   
    }
};

class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        vector<int> cnt(K);
        cnt[0] = 1;
        int sum = 0, ans = 0;
        
        for(auto x: A){
            sum+=x;
            int rem = (sum%K + K)%K;
            if(cnt[rem])
                ans+=cnt[rem];
            cnt[rem]++;
        }
        
        return ans;
    }
};
// @lc code=end

int main(){
    Solution2 sol; vi a; int out, K;
    a = { 4,5,0,-2,-3,1 }, K = 5;
    a = {-4};
    // out = sol.subarraysDivByK(a, K); deb(out);
    a = {2,-2,2,-4};K = 6;
    out = sol.subarraysDivByK(a, K); deb(out);

    return 0;
}