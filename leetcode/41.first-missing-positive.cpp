/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 *
 * https://leetcode.com/problems/first-missing-positive/description/
 *
 * algorithms
 * Hard (30.84%)
 * Likes:    2726
 * Dislikes: 729
 * Total Accepted:    291.2K
 * Total Submissions: 943.5K
 * Testcase Example:  '[1,2,0]'
 *
 * Given an unsorted integer array, find the smallest missing positive
 * integer.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,0]
 * Output: 3
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,4,-1,1]
 * Output: 2
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [7,8,9,11,12]
 * Output: 1
 * 
 * 
 * Note:
 * 
 * Your algorithm should run in O(n) time and uses constant extra space.
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

// the answer has to be in range [1..n], if a number is acutally missing
// else it would be n+1
// 1. Pass 1: set all the out of range values to n+10
// 2. Pass 2. mark the a[(abs(x))-1] as -ve
// The first +ve number is answer
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // 1. remove out of range
        int n = nums.size();
        for(int i=0; i<n; ++i)
            if(nums[i]<=0 || nums[i]>n)
                nums[i] = n+10;
    
        // print(nums);
        // mark preset numbers's pos with -ve
        for(int i=0; i<n; ++i){
            int pos = abs(nums[i]) - 1;
            if(pos>=0 && pos<n)
                nums[pos] = -(abs(nums[pos]));
        }

        // print(nums);

        // the 1st pos where nums[i], is not -ve is the answer
        int i;
        for(i=0; i<n; ++i){
            if(nums[i]>=0)
                break;
        }
        return i+1; // due to 0 based
    }
};

class Solution {
public:
    int firstMissingPositive(vector<int>& a) {
        int n = a.size();
        for(int i=0; i<n; ++i){
            while(a[i]>0 && a[i]<=n && a[a[i]-1]!=a[i]){
                swap(a[i], a[a[i]-1]);
            }
        }
        
        for(int i=0; i<n; ++i){
            if(a[i]!=i+1)
                return i+1;
        }
        
        return n+1;
    }
};

class Solution1 {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; ++i){
            if(nums[i]<=0 || n<nums[i]){
                nums[i] = n+10;
            }
        }
        
        for(int i=0; i<n; ++i){
            int pos = abs(nums[i])-1;
            if(pos>=n) continue;
            nums[pos] = -abs(nums[pos]);
        }
        
        for(int i=0; i<n; ++i){
            if(nums[i]>0) 
                return i+1;
        }
        return n+1;
    }
};

class Solution0 {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        vector<bool> present(n+1);
        for(int i=0; i<n; ++i){
            if(0<nums[i] && nums[i]<=n){
                present[nums[i]] = 1;
            }
        }
        
        for(int i=1; i<=n; ++i)
            if(!present[i])
                return i;
        return n+1;
    }
};
// @lc code=end

int main(){
    Solution sol; int out;
    vvi aa = {
        {0,1,2},
        {1,2,0},
        {3,4,-1,1},
        {7,8,9,11,12}
    };
    for(auto a: aa){
        out = sol.firstMissingPositive(a), deb(out);
    }
    return 0;
}
