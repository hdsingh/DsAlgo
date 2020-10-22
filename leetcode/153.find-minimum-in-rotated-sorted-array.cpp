/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 *
 * https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (43.83%)
 * Likes:    1355
 * Dislikes: 187
 * Total Accepted:    343.1K
 * Total Submissions: 782.2K
 * Testcase Example:  '[3,4,5,1,2]'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 * 
 * (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
 * 
 * Find the minimum element.
 * 
 * You may assume no duplicate exists in the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,4,5,1,2] 
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [4,5,6,7,0,1,2]
 * Output: 0
 * 
 * 
 */
#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(a) int((a).size())
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

#define _deb(x) cout<<x;
void _print() {cerr << "]\n";} template <typename T, typename... V>void _print(T t, V... v) {_deb(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#define deb(x...) cerr << "[" << #x << "] = ["; _print(x)
template <class T, class U> void print_m(const map<T,U> &m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}
template<class T, class U>void debp(const pair<T, U> &pr, bool end_line=1){cout<<"{"<<pr.first<<" "<<pr.second<<"}"; cout<<(end_line ? "\n" : ", ");}
template <class T> void print_vp(const T &vp, int sep_line=0){if(vp.empty()){cout<<"Empty"<<endl; return;}if(!sep_line) cout<<"{ ";for(auto x: vp) debp(x,sep_line);if(!sep_line) cout<<"}\n";cout<<endl;}
template <typename T>void print(const T &v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<sz(v); i++)cout<<setw(w)<<i<<" ";cout<<endl;}for(auto &el: v) cout<<setw(w)<<el<<" ";cout<<endl;}
template <typename T>void print_vv(const T &vv){if(sz(vv)==0) {cout<<"Empty"<<endl; return;} int w = 3;cout<<setw(w)<<" ";for(int j=0; j<sz(*vv.begin()); j++)cout<<setw(w)<<j<<" ";cout<<endl;int i = 0;for(auto &v: vv){cout<<i++<<" {";for(auto &el: v) cout<<setw(w)<<el<<" ";cout<<"},\n";}cout<<endl;}

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        // find first element <=a[n-1];
        int lt = -1, rt = n;
        while(1+lt<rt){
            int mid = lt + (rt-lt)/2;
            if(nums[mid]<=nums[n-1])
                rt = mid;
            else 
                lt = mid;
        }
        return nums[rt];        
    }
};

// Is the mid element greater than a[last];
// here we are looking for first false;
// ex:  4 5 6 7 1 2 3 
//      T T T T F F F
// or
//      1 2 3 4 5 6 7
//      F F F F F F F 
class Solution {
public:
    int findMin(vector<int>& a) {
        int n = a.size();
        int l = 0, r = n-1;
        int ans = 0;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(a[mid]>a.back()){
                l = mid + 1;
            }else{
                ans = a[mid];
                r = mid - 1;
            }
        }

        return ans;
    }
};

// @lc code=end
int main(){
    Solution sol;
    vi nums = {3,4,5,1,2};
    cout<<sol.findMin(nums)<<endl;

    nums = {4,5,6,7,0,1,2};
    cout<<sol.findMin(nums)<<endl;

    nums = {4,5,6,7,7,0,1,1,2,2,3,};
    cout<<sol.findMin(nums)<<endl;
    
    nums = {-1};
    cout<<sol.findMin(nums)<<endl;

}
