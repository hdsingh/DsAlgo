/*
 * @lc app=leetcode id=907 lang=cpp
 *
 * [907] Sum of Subarray Minimums
 *
 * https://leetcode.com/problems/sum-of-subarray-minimums/description/
 *
 * algorithms
 * Medium (30.53%)
 * Likes:    821
 * Dislikes: 58
 * Total Accepted:    19.1K
 * Total Submissions: 62.5K
 * Testcase Example:  '[3,1,2,4]'
 *
 * Given an array of integers A, find the sum of min(B), where B ranges over
 * every (contiguous) subarray of A.
 * 
 * Since the answer may be large, return the answer modulo 10^9 + 7.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [3,1,2,4]
 * Output: 17
 * Explanation: Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2],
 * [1,2,4], [3,1,2,4]. 
 * Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.  Sum is 17.
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= A.length <= 30000
 * 1 <= A[i] <= 30000
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

template <typename T>void print(T v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<v.size(); i++)cout<<setw(w)<<i<<" ";cout<<endl;}for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(w)<<*i<<" ";cout<<endl;}
template <typename T>void print_vv(T v){if(v.size()==0) {cout<<"Empty"<<endl; return;} int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}
template <class T, class U> void print_m(map<T,U> m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}

class Solution1 {
    const int mod = 1e9 + 7;
public:
    int sumSubarrayMins(vector<int>& a) {
        int n = a.size();
        int tot = 0;
        for(int i=0; i<n; i++){
            int mn = INT_MAX;
            for(int j=i; j>=0; j--){
                mn = min(mn, a[j]);
                tot = (tot + mn + mod)%mod;
            }
        }
        return tot;
    }
};

// TLE due to recounting of elements in stack
class Solution0 {
    const int mod = 1e9 + 7;
public:
    int sumSubarrayMins(vector<int>& a) {
        int n = a.size();
        long long tot = 0;
        vector<pair<int,int>> stk; // value,count
        
        for(int i=0; i<n; i++){
            int cnt = 1;
            while(!stk.empty() && stk.back().first >= a[i]){
                cnt+=stk.back().second;
                stk.pop_back();
            }
            stk.push_back({a[i], cnt});


            for(int j=0; j<(int)stk.size(); ++j){
                long val = stk[j].first;
                long count = stk[j].second;
                tot = (tot + val*count + mod)%mod;
            }
        }
        

        return tot;
    }
};

// Better implementation of above idea
//https://leetcode.com/problems/sum-of-subarray-minimums/solution/ 
class Solution2 {
    const int mod = 1e9 + 7;
public:
    int sumSubarrayMins(vector<int>& a) {
        int n = a.size();
        long long tot = 0;
        vector<pair<int,int>> stk; // value,count
        int dot = 0;
        
        for(int i=0; i<n; i++){
            int cnt = 1;
            while(!stk.empty() && stk.back().first >= a[i]){
                cnt+=stk.back().second;
                dot-=stk.back().first * stk.back().second;
                stk.pop_back();
            }
            stk.push_back({a[i], cnt});
            dot+=a[i]*cnt;
            tot+=dot;
            tot%=mod;
        }        

        return tot;
    }
};

// Ref: https://leetcode.com/problems/sum-of-subarray-minimums/discuss/178876/stack-solution-with-very-detailed-explanation-step-by-step
// Using concept of next less element, previous less element 
// and using the distance to calcuate the result
// Since we can form subarrays, bw prev_less and next_less,
// ans[i] = a[i] * (next_less[i] - i ) * (i - prev_less[i])
// 1 9 3 8 2
// for 3 =>  2 * 2 subarrays
// 93, 938, 3, 38
class Solution {
    const int mod = 1e9+7;
public:
    int sumSubarrayMins(vector<int>& a) {
        int n = a.size();
        stack<int> stk_p, stk_n;
        vi prev_less(n), next_less(n);
        
        for(int i=0; i<n; ++i){
            while(stk_p.size() && a[stk_p.top()]>=a[i])
                stk_p.pop();
            prev_less[i] = stk_p.size() ? stk_p.top() : -1; // limit -1 if not found
            stk_p.push(i);
        }

        for(int i=n-1; i>=0; --i){
            while(stk_n.size() && a[stk_n.top()]>a[i])
                stk_n.pop();
            next_less[i] = stk_n.size() ? stk_n.top() : n; // limit should be n here if not found
            stk_n.push(i);
        }

        long long ans = 0;
        for(int i=0; i<n; i++){
            ans += (i - prev_less[i]) * (next_less[i] - i )%mod * a[i]% mod;
            ans%=mod;
        }
        return (int)ans;
    }
};

// @lc code=end

int main(){
    Solution sol; Solution1 sol1;
    vvi as; int out; 
    as = {
        {5,5,4,20,3},
        {3,1,2,6,5,4},
        {11,11,11},
        {5,4,3,6,7,10},
        {10,11,5,4,3,2,1,20,30,40},
    };
    for(auto &a: as){
        out = sol.sumSubarrayMins(a); deb(out); 
        out = sol1.sumSubarrayMins(a); deb(out); 
    }
    return 0;
}
