/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (33.16%)
 * Likes:    2918
 * Dislikes: 358
 * Total Accepted:    476.7K
 * Total Submissions: 1.4M
 * Testcase Example:  '[4,5,6,7,0,1,2]\n0'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 * 
 * (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
 * 
 * You are given a target value to search. If found in the array return its
 * index, otherwise return -1.
 * 
 * You may assume no duplicate exists in the array.
 * 
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [4,5,6,7,0,1,2], target = 0
 * Output: 4
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [4,5,6,7,0,1,2], target = 3
 * Output: -1
 * 
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

// @lc code=start
class Solution1 {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(!n) return -1;
        // if(n==1) return nums[0];
        int low = 0;
        int high = n - 1;
        
        // Find the min element index
        while(low<high){
            int mid = low + (high-low)/2;

            if(nums[mid]>nums[high])
                low = mid + 1;
            else if(nums[mid] < nums[high])
                high = mid;
            else
                high--;
        }

        int min_val_index = low;
        low = 0;
        high = n-1;
        
        // Account for rotation
        while(low<=high){
            int mid = low + (high-low)/2;
            int realmid = (mid+min_val_index)%n;

            if(nums[realmid]==target) return realmid;
            else if(nums[realmid]<target)
                low = mid + 1;
            else
                high = mid - 1;
        }     

        return -1;
    }
};

// Find the piviot element : by comparing with lat element
// ex 1: 
//   3, 4, 5, 6, 7, 1, 2
//   T  T  T  T  T  F  F 
// if we find a_mid > a_last, there is a possibility of even bigger element on right
//   1 2 3 4 5 6 7 8   and    10, 30, 3 , 4, 5, 8
//   F F F F F F F F          T   T   F   F  F  F
// else move left
class Solution2 {
public:
    int search(vector<int>& a, int x) {
        // print(a, 1);
        int n = a.size();
        if(!n) return -1;
        int pv = 0; //pivot

        int l(0), r(n-1), mid;
        while(l<=r){
            mid = l + (r-l)/2;
            // deb3(l, r, mid);
            if(a[mid]>a[n-1]){
                pv = mid;
                l = mid + 1;
            }else 
                r = mid - 1;
            // deb(pv);
        }
        deb(pv);
        deb(a[pv]);
        
        if(a[pv]==x) return pv;
        // do serch on both sides of pv
        l = 0; r = pv;
        while(l<=r){
            mid = l + (r-l)/2;
            if(a[mid]==x)
                return mid;
            else if(a[mid]<x)
                l = mid + 1;
            else 
                r = mid - 1;
        }

        l = pv + 1; r = n-1;
        while(l<=r){
            mid = l + (r-l)/2;
            if(a[mid]==x)
                return mid;
            else if(a[mid]<x)
                l = mid + 1;
            else 
                r = mid - 1;
        }
        return -1;
    }
};

class Solution3 {
public:
    int search(vector<int>& a, int X) {
        // find the beg((rot)ation point) by looking for first false
        // check if the mid is less than back

        int n = a.size();
        int rot = 0, l = 0, r = n-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(a[mid]>a.back())
                l = mid+1;
            else 
                rot = mid, r = mid-1;
        }
        // deb(rot);

        // now search as if in normal array by normailising the idx wrt to mod
        l = 0, r = n-1;
        while(l<=r){
            int mid = (l+r)/2;
            // deb(mid);
            int rmid = (mid+rot)%n;
            if(a[rmid]==X) return rmid;
            else if(a[rmid]<X)
                l = mid + 1;
            else 
                r = mid - 1;
        }

        return -1;
    }
};


class Solution {
public:
    int search(vector<int>& a, int X) {
        int n = a.size();
        int l = 0, r = n-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(a[mid]==X) return mid;
            // not rotated (a[mid] to a[r] are in inc order)
            if(a[mid]<=a[r]){
                if(a[mid]<X && X<=a[r])
                    l = mid + 1;
                else 
                    r = mid - 1;
            }else{ // is rotated
                // (a[l] to a[mid] will be in increasing order)
                if(a[l]<=X && X<a[mid])
                    r = mid - 1;
                else 
                    l = mid + 1;
            }
        }

        return -1;
    }
};

// @lc code=end
int main(){
    Solution sol;
    vi nums; int target;

    nums = {4,5,6,7,0,1,2};
    target = 0;
    cout<<sol.search(nums,target)<<endl;

    nums = {4,5,6,7,0,1,2};
    target = 3;
    cout<<sol.search(nums,target)<<endl;

    nums = {500,100,200,};
    target = 200;
    cout<<sol.search(nums,target)<<endl;


}