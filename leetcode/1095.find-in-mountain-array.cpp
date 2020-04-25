/*
 * @lc app=leetcode id=1095 lang=cpp
 *
 * [1095] Find in Mountain Array
 *
 * https://leetcode.com/problems/find-in-mountain-array/description/
 *
 * algorithms
 * Hard (35.43%)
 * Likes:    158
 * Dislikes: 21
 * Total Accepted:    7.4K
 * Total Submissions: 20.8K
 * Testcase Example:  '[1,2,3,4,5,3,1]\n3'
 *
 * (This problem is an interactive problem.)
 * 
 * You may recall that an array A is a mountain array if and only if:
 * 
 * 
 * A.length >= 3
 * There exists some i with 0 < i < A.length - 1 such that:
 * 
 * A[0] < A[1] < ... A[i-1] < A[i]
 * A[i] > A[i+1] > ... > A[A.length - 1]
 * 
 * 
 * 
 * 
 * Given a mountain array mountainArr, return the minimum index such that
 * mountainArr.get(index) == target.  If such an index doesn't exist, return
 * -1.
 * 
 * You can't access the mountain array directly.  You may only access the array
 * using a MountainArray interface:
 * 
 * 
 * MountainArray.get(k) returns the element of the array at index k
 * (0-indexed).
 * MountainArray.length() returns the length of the array.
 * 
 * 
 * Submissions making more than 100 calls to MountainArray.get will be judged
 * Wrong Answer.  Also, any solutions that attempt to circumvent the judge will
 * result in disqualification.
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: array = [1,2,3,4,5,3,1], target = 3
 * Output: 2
 * Explanation: 3 exists in the array, at index=2 and index=5. Return the
 * minimum index, which is 2.
 * 
 * Example 2:
 * 
 * 
 * Input: array = [0,1,2,4,2,1], target = 3
 * Output: -1
 * Explanation: 3 does not exist in the array, so we return -1.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 3 <= mountain_arr.length() <= 10000
 * 0 <= target <= 10^9
 * 0 <= mountain_arr.get(index) <= 10^9
 * 
 * 
 */

// @lc code=start
/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */
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

class MountainArray {
public:
    vi a;
    int cnt;
    MountainArray(vi &arr){
        cnt = 0;
        a.resize(arr.size());
        a = arr;
    }

    int get(int index){
        cnt++;
        return a[index];
    }

    int length(){
        return a.size();
    }
};

class Solution {
    vector<int> arr;
public:
    int findInMountainArray(int x, MountainArray &ma) {
        arr.resize(10001,-1);

        int n = ma.length();
        int l =0; int r = n-1; int peak;
        while(l<=r){
            int mid = l +  (r-l)/2;
            int a_mid, a_mid_prev;
            if(mid==0 || (a_mid=get(mid,ma))>(a_mid_prev=get(mid-1, ma)) ){
                peak = mid;
                l = mid+1;
            }else 
                r = mid-1;
        }
        if(get(peak, ma)==x)
            return peak;
        // found peak
        // search left of peak in increasing arr
        l = 0; r=peak-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            int a_mid = get(mid, ma);
            if(a_mid==x)
                return mid;
            else if(a_mid<x)
                l = mid + 1;
            else
                r = mid - 1;
        }
        
        // search in decreasing array
        l = peak+1; r = n-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            int a_mid = get(mid, ma);
            if(a_mid==x)
                return mid;
            else if(a_mid<x)
                r = mid - 1;
            else 
                l = mid + 1;
        }
        
        return -1;
    }
    
    int get(int mid, MountainArray &ma){
        if(arr[mid]!=-1) 
            return arr[mid];
        return arr[mid] = ma.get(mid);
    }
};
// @lc code=end

int main(){
    Solution sol; vi array; int target, out;

    array = { 1,3,4,5,6,3,1 }, target = 0;
    MountainArray ma(array);

    // out =  sol.findInMountainArray(target, ma); deb(out);
    // deb(ma.cnt);

    array = { 1,3,5,7,9,8,6,4,3}, target = 8; 
    array = { 1,5,2}, target = 0; 
    array = { 0,1,2,4,2,1}, target = 3; 
    MountainArray ma2(array);
    out =  sol.findInMountainArray(target, ma2); deb(out);
    deb(ma2.cnt);
    return 0;
}