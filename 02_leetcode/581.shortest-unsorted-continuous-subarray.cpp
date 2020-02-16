/*
 * @lc app=leetcode id=581 lang=cpp
 *
 * [581] Shortest Unsorted Continuous Subarray
 *
 * https://leetcode.com/problems/shortest-unsorted-continuous-subarray/description/
 *
 * algorithms
 * Easy (30.67%)
 * Likes:    2080
 * Dislikes: 106
 * Total Accepted:    98.3K
 * Total Submissions: 320.6K
 * Testcase Example:  '[2,6,4,8,10,9,15]'
 *
 * Given an integer array, you need to find one continuous subarray that if you
 * only sort this subarray in ascending order, then the whole array will be
 * sorted in ascending order, too.  
 * 
 * You need to find the shortest such subarray and output its length.
 * 
 * Example 1:
 * 
 * Input: [2, 6, 4, 8, 10, 9, 15]
 * Output: 5
 * Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make
 * the whole array sorted in ascending order.
 * 
 * 
 * 
 * Note:
 * 
 * Then length of the input array is in range [1, 10,000].
 * The input array may contain duplicates, so ascending order here means . 
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

class Solution1 {
public:
    int findUnsortedSubarray(vector<int>& a) {
        int n = a.size();
        vector<int> b = a;
        sort(b.begin(), b.end());

        int start = n, end = 0;
        for(int i=0; i<n; i++){
            if(a[i]!=b[i]){
                start = min(start, i);
                end = max(end, i);
            }
        }

        if(end==0) return 0;
        return end-start+1;
    }
};

// find the pos of correct posotion of min and max elements to 
// determine boundaries of unsorted array
class Solution2 {
public:
    int findUnsortedSubarray(vector<int>& a) {
        int n = a.size();
        vector<int> stk;
        int l=n, r=0;
        // Find l
        for(int i=0; i<n; i++){
            while(stk.size() && a[stk.back()]>a[i]){
                l = min(l, stk.back()); stk.pop_back();
            }
            stk.push_back(i);
        }

        stk.clear();
        // find r
        for(int i=n-1; i>=0; i--){
            while(stk.size() && a[stk.back()]<a[i]){
                r = max(r, stk.back()); stk.pop_back();
            }
            stk.push_back(i);
        }

        // deb2(l, r);
        return r-l>0 ? r-l+1 : 0;
    }
};

class Solution {
public:
    int findUnsortedSubarray(vector<int>& a) {
        int n=a.size();
        int min_val = INT_MAX; // min val in a dec slope
        int max_val = INT_MIN; // max val in increasing slope
        int l=n; int r = 0; // boundaries  of unsorted array

        for(int i=1;i<n; i++)
            if(a[i-1]>a[i])
                min_val = min(min_val, a[i]);
        
        // find just greater than min_val
        for(int i=0; i<n; i++)
            if(a[i]>min_val){
                l = i; break;
            }
        
        for(int i=n-1; i>0; i--)
            if(a[i-1]>a[i]){
                max_val = max(max_val, a[i-1]);
            }
        
        // find just smaller than max_val
        for(int i=n-1; i>0; i--)
            if(a[i]<max_val){
                r = i; break;
            }
        
        return r-l>0 ? r-l + 1 : 0;            
    }
};
// @lc code=end


int main(){
    Solution sol; int out; vi a;
    a = {2,1,6,4,5,7,8,9};
    // a = {1,2,3,4, 0};
    // a = {2, 6, 4, 8, 10, 9, 15};
    out = sol.findUnsortedSubarray(a); deb(out);
    return 0;
}