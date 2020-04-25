/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 *
 * https://leetcode.com/problems/4sum/description/
 *
 * algorithms
 * Medium (32.49%)
 * Likes:    1524
 * Dislikes: 288
 * Total Accepted:    296.3K
 * Total Submissions: 911.8K
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * Given an array nums of n integers and an integer target, are there elements
 * a, b, c, and d in nums such that a + b + c + d = target? Find all unique
 * quadruplets in the array which gives the sum of target.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate quadruplets.
 * 
 * Example:
 * 
 * 
 * Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
 * 
 * A solution set is:
 * [
 * ⁠ [-1,  0, 0, 1],
 * ⁠ [-2, -1, 1, 2],
 * ⁠ [-2,  0, 0, 2]
 * ]
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

// i and j will vary, for each i,j form ab = arr[i]  + arr[j]
// so now will find answer for ab, c,d reducing it to 3Sum
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int t) {
        int n = arr.size();
        sort(all(arr));

        vvi out;
        for(int i=0; i<n; i++){
            // dulpicate
            if(i && arr[i]==arr[i-1]) continue;
            for(int j=i+1; j<n; j++){
                // duplicate, with gap of 1 bw i and j
                if(j>i+1 && arr[j]==arr[j-1]) continue;
                int ab = arr[i] + arr[j];
                
                int l = j+1; int r = n-1;
                while(l<r){
                    int sum = ab + arr[l] + arr[r];
                    if(sum<t) ++l;
                    else if(sum>t) --r;
                    else{
                        out.push_back({arr[i], arr[j], arr[l], arr[r]});
                        while(l+1<n && arr[l]==arr[l+1] && l<r) ++l;
                        while(r-1>=0 && arr[r]==arr[r-1] && l<r) --r;
                        ++l; --r;
                    } 
                }
            }            
        }

        return out;
    }
};
// @lc code=end

int main(){
    Solution sol; vi nums; int t; vvi out;
    // nums = {1, 1,1,1,1,1,1,1}; t=4;
    nums = {1, 0, -1, 0, -2, 2}; t = 0;
    // nums = {}; t = 0;
    out = sol.fourSum(nums,t); print_vv(out);
    return 0;
}
