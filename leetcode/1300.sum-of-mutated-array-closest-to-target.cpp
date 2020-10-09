/*
 * @lc app=leetcode id=1300 lang=cpp
 *
 * [1300] Sum of Mutated Array Closest to Target
 *
 * https://leetcode.com/problems/sum-of-mutated-array-closest-to-target/description/
 *
 * algorithms
 * Medium (45.68%)
 * Likes:    135
 * Dislikes: 21
 * Total Accepted:    5.7K
 * Total Submissions: 12.4K
 * Testcase Example:  '[4,9,3]\n10'
 *
 * Given an integer array arr and a target value target, return the integer
 * value such that when we change all the integers larger than value in the
 * given array to be equal to value, the sum of the array gets as close as
 * possible (in absolute difference) to target.
 * 
 * In case of a tie, return the minimum such integer.
 * 
 * Notice that the answer is not neccesarilly a number from arr.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: arr = [4,9,3], target = 10
 * Output: 3
 * Explanation: When using 3 arr converts to [3, 3, 3] which sums 9 and that's
 * the optimal answer.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: arr = [2,3,5], target = 10
 * Output: 5
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: arr = [60864,25176,27249,21296,20204], target = 56803
 * Output: 11361
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= arr.length <= 10^4
 * 1 <= arr[i], target <= 10^5
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

class Solution {
public:
    int findBestValue(vector<int>& a, int T) {
        int n = a.size();
        int l = 0;
        int r = T;

        auto sum = [&](int mid){
            int s = 0;
            for(auto x: a)
                s+= (x<mid ? x : mid);
            return s;
        };

        while(l<=r){
            int mid = l + (r-l)/2;
            int s = sum(mid);
            if(s==T) return mid;
            
            if(s<T)
                l = mid + 1;
            else 
                r = mid - 1;
        }

        int f = sum(l); int s = sum(l-1);
        if(abs(f-T)<abs(s-T)) return l;
        return l-1;
    }
};

class Solution {
public:
    int findBestValue(vector<int>& a, int X) {
        int n = a.size();
        int lt = 0, rt = *max_element(a.begin(),a.end())+1;

        auto sum = [&](int val){
            int tot = 0;
            for(auto x: a)
                tot+=min(x,val);
            return tot;
        };

        while(1+lt<rt){
            int mid = lt + (rt-lt)/2;
            if(sum(mid)>=X)
                rt = mid;
            else 
                lt = mid;
        }
    
        if(abs(X-sum(rt-1))<=abs(X-sum(rt)))return rt-1;

        return rt;
    }
};
// @lc code=end

int main(){
    Solution sol; vi arr; int target, out;
    arr = { 4,9,3 }, target = 10;
    out = sol.findBestValue(arr, target); deb(out);
    arr = { 2,3,5 }, target = 10;
    out = sol.findBestValue(arr, target); deb(out);
    arr = { 60864,25176,27249,21296,20204 }, target = 56803;
    out = sol.findBestValue(arr, target); deb(out);

    return 0;
}