/*
 * @lc app=leetcode id=523 lang=cpp
 *
 * [523] Continuous Subarray Sum
 *
 * https://leetcode.com/problems/continuous-subarray-sum/description/
 *
 * algorithms
 * Medium (24.25%)
 * Likes:    789
 * Dislikes: 1066
 * Total Accepted:    77.3K
 * Total Submissions: 319.1K
 * Testcase Example:  '[23,2,4,6,7]\n6'
 *
 * Given a list of non-negative numbers and a target integer k, write a
 * function to check if the array has a continuous subarray of size at least 2
 * that sums up to a multiple of k, that is, sums up to n*k where n is also an
 * integer.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [23, 2, 4, 6, 7],  k=6
 * Output: True
 * Explanation: Because [2, 4] is a continuous subarray of size 2 and sums up
 * to 6.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [23, 2, 6, 4, 7],  k=6
 * Output: True
 * Explanation: Because [23, 2, 6, 4, 7] is an continuous subarray of size 5
 * and sums up to 42.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The length of the array won't exceed 10,000.
 * You may assume the sum of all the numbers is in the range of a signed 32-bit
 * integer.
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

// Brute force
class Solution1 {
public:
    bool checkSubarraySum(vector<int>& a, int k) {
        int n = a.size();
        if(n<=1) return false;
        if(k==1){
            if(n==1) return false;
            int sum = accumulate(all(a),0);
            return sum>0;
        }
        else if(k==0){
            for(int i=0; i<n-1; ++i)
                if(!a[i] && !a[i+1])
                    return true;
        }
    
        vi pre(n); pre[0] = a[0];
        for(int i=1; i<n; ++i)
            pre[i] = pre[i-1] + a[i];
        
        // print(pre);
    
        for(int i=0; i<n; ++i){
            for(int j=i+1; j<n; ++j){
                int sum = pre[j] - (i-1>=0 ? pre[i-1] : 0);
                if(k==0){
                    if(sum==0)
                        return true;
                }else if(sum%k==0) 
                    return true;  
            }
        }

        return false;
    }
};

// Mod Property: 
// In the running sum(pre) with mod, if two positions have a repeated x,
// then between these two occurances, the sum is multiple of mod, i.e.
// the pre[j] - pre[i-1] = n*k
class Solution {
public:
    bool checkSubarraySum(vector<int>& a, int k) {
        int n = a.size();

        unordered_map<int,int> m;
        m[0] = -1; // start with initial value 0 
        int runningSum = 0;
        for(int i=0; i<n; ++i){
            runningSum+=a[i];
            if(k) runningSum%=k;
            if(m.find(runningSum)!=m.end()){
                if(i - m[runningSum] > 1)
                    return true;
            }else 
                m[runningSum] = i;
        }

        return false;
    }
};
// @lc code=end

int main(){
    Solution sol; int k; vi a; int out;
    a = {23, 2, 4, 6, 7},  k=6;
    out = sol.checkSubarraySum(a, k); deb(out);
    a = {23, 2, 6, 4, 7},  k=6;
    out = sol.checkSubarraySum(a, k); deb(out);
    a = {1,3,5,6},  k=6;
    out = sol.checkSubarraySum(a, k); deb(out);
    a = {0,0}; k = 0;
    out = sol.checkSubarraySum(a, k); deb(out);
    a = {1}, k=1;
    out = sol.checkSubarraySum(a, k); deb(out);
    a = {1,1}, k=1;
    out = sol.checkSubarraySum(a, k); deb(out);

    return 0;
}
