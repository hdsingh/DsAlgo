/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 *
 * https://leetcode.com/problems/subarray-sum-equals-k/description/
 *
 * algorithms
 * Medium (42.87%)
 * Likes:    2427
 * Dislikes: 67
 * Total Accepted:    136.2K
 * Total Submissions: 317.6K
 * Testcase Example:  '[1,1,1]\n2'
 *
 * Given an array of integers and an integer k, you need to find the total
 * number of continuous subarrays whose sum equals to k.
 * 
 * Example 1:
 * 
 * Input:nums = [1,1,1], k = 2
 * Output: 2
 * 
 * 
 * 
 * Note:
 * 
 * The length of the array is in range [1, 20,000].
 * The range of numbers in the array is [-1000, 1000] and the range of the
 * integer k is [-1e7, 1e7].
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

// Brute Force
class Solution2 {
public:
    int subarraySum(vector<int>& a, int k) {
        int n = a.size();
        vi pre(n); pre[0] = a[0];
        for(int i=1; i<n; i++)
            pre[i] = pre[i-1] + a[i];
        
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=i; j>=0; j--){
                int sum = pre[i] - (j-1>=0 ? pre[j-1] : 0);
                if(sum==k) ++cnt;
            }
        }
        return cnt;
    }
};

// Space optimised Brute Force, fix a start point
// and start a sum from it
class Solution3 {
public:
    int subarraySum(vector<int>& a, int k) {
        int n = a.size();
        int cnt = 0;

        for(int i=0; i<n; ++i){
            int sum = 0;
            for(int j=i; j<n; ++j){
                sum+=a[j];
                if(sum==k) ++cnt;
            }
        }
        return cnt;
    }
};

// if in presum, values at 2 pos is same, it means the elements in bw has a
// sum of 0. similarly if difference bw two positions is k, the sum of elements 
// in bw is k. So we will keep track of this diff.
class Solution {
public:
    int subarraySum(vector<int>& a, int k) {
        int n = a.size();
        int cnt(0), sum(0);
        unordered_map<int, int> difCnt;
        difCnt[0] = 1;
        
        for(int i=0; i<n; i++){
            sum+=a[i];
            if(difCnt.find(sum-k)!=difCnt.end()){
                cnt+=difCnt[sum-k];
            }
            difCnt[sum]++;
        }
        
        return cnt;
    }
};

int main(){
    Solution sol; vi a; int k, out;
    a = {1,5,6,}; k = 6;
    a = {0,0,0,0,0,0,0,0,0,0}, k = 0;
    // a= { 28,54,7,-70,22,65,-6 },k=100;
    out = sol.subarraySum(a, k); deb(out);
    Solution3 sol1;       
    out = sol1.subarraySum(a, k); deb(out);
    return 0;
}
