/*
 * @lc app=leetcode id=689 lang=cpp
 *
 * [689] Maximum Sum of 3 Non-Overlapping Subarrays
 *
 * https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/description/
 *
 * algorithms
 * Hard (45.15%)
 * Likes:    777
 * Dislikes: 42
 * Total Accepted:    34.5K
 * Total Submissions: 76.4K
 * Testcase Example:  '[1,2,1,2,6,7,5,1]\n2'
 *
 * In a given array nums of positive integers, find three non-overlapping
 * subarrays with maximum sum.
 * 
 * Each subarray will be of size k, and we want to maximize the sum of all 3*k
 * entries.
 * 
 * Return the result as a list of indices representing the starting position of
 * each interval (0-indexed). If there are multiple answers, return the
 * lexicographically smallest one.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,1,2,6,7,5,1], 2
 * Output: [0, 3, 5]
 * Explanation: Subarrays [1, 2], [2, 6], [7, 5] correspond to the starting
 * indices [0, 3, 5].
 * We could have also taken [2, 1], but an answer of [1, 3, 5] would be
 * lexicographically larger.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * nums.length will be between 1 and 20000.
 * nums[i] will be between 1 and 65535.
 * k will be between 1 and floor(nums.length / 3).
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

// find 3 idx i,j,k such that sum_k[a] + sum_k[j] + sum_k[k] is max
// and i+K<=j  && j+K<=k,
// also instead of storing the values store the index
class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& a, int K) {
        int n = a.size();
        vi w(n-K + 1); // window sum

        int sum = 0;
        for(int i=0; i<n; ++i){
            sum+=a[i];
            if(i-K>=0) sum-=a[i-K]; 
            if(i-K+1>=0) w[i-K+1] = sum;
        }

        vi left(n), right(n);
        int best = 0;
        for(int i=0; i<(int)w.size(); ++i){
            if(w[i]>w[best]) best = i; // no equal here since we want the first less
            left[i] = best;
        }

        best = w.size()-1;
        for(int i=w.size()-1; i>=0; --i){
            if(w[i]>=w[best]) best = i; // notice the equal here, which  ensures the lexicography
            right[i] = best;
        }

        // print(w);
        // print(left);
        // print(right);

        vi res = {-1,-1,-1};
        for(int j=K; j<(int)w.size()-K; ++j){
            int i = left[j-K]; int k = right[j+K];
            if(res[0]==-1 || w[i]+w[j]+w[k]>w[res[0]] + w[res[1]] + w[res[2]]){
                res[0] = i;
                res[1] = j;
                res[2] = k;
            }
        }
            
        return res;
    }
};
// @lc code=end

int main(){
    Solution sol; vi a, out; int k;
    a = {1,2,1,2,6,7,5,1}; k = 2;
    out = sol.maxSumOfThreeSubarrays(a,k); print(out);
    cout<<endl;

    a = { 1,2,1,2,1,2,1,2,1 } ,k = 2;
    out = sol.maxSumOfThreeSubarrays(a,k); print(out);

    
    return 0;
}
