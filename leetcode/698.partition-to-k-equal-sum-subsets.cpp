/*
 * @lc app=leetcode id=698 lang=cpp
 *
 * [698] Partition to K Equal Sum Subsets
 *
 * https://leetcode.com/problems/partition-to-k-equal-sum-subsets/description/
 *
 * algorithms
 * Medium (43.98%)
 * Likes:    1125
 * Dislikes: 64
 * Total Accepted:    59.2K
 * Total Submissions: 134.6K
 * Testcase Example:  '[4,3,2,3,5,2,1]\n4'
 *
 * Given an array of integers nums and a positive integer k, find whether it's
 * possible to divide this array into k non-empty subsets whose sums are all
 * equal.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [4, 3, 2, 3, 5, 2, 1], k = 4
 * Output: True
 * Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3),
 * (2,3) with equal sums.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= k <= len(nums) <= 16.
 * 0 < nums[i] < 10000.
 * 
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
template <typename T>void print_vv(T v){if(v.size()==0) {cout<<"Empty"<<endl; return;} int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}
template <class T, class U> void print_m(map<T,U> m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}


// https://github.com/bephrem1/backtobackswe/blob/master/Dynamic%20Programming%2C%20Recursion%2C%20%26%20Backtracking/PartitionIntoKEqualSumSubsets/PartitionIntoKEqualSumSubsets.java
// @lc code=start
class Solution0 {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        if(n<k) return false;
        int sum = accumulate(all(nums),0);
        if(sum%k || k<=0) return false;
        vector<bool> visited(n, false);

        return canPartition(0, nums, visited, k, 0, sum/k);      
    }

    bool canPartition(int start, vi &nums, vector<bool> &visited, int k, int curBucketSum, int target){
        if(k==1) return true;

        if(curBucketSum == target)
            return canPartition(0,nums, visited, k-1, 0, target);
        
        for(int i=start; i<nums.size(); i++){
            if(!visited[i] && curBucketSum + nums[i] <=target){
                visited[i] = true;
                if(canPartition(i+1, nums, visited,k,curBucketSum+nums[i],target))
                    return true;
                visited[i] = false;
            }
        }
        return false;
    }
};

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& a, int k) {
        int n = a.size();
        sort(all(a));
        int sum = accumulate(all(a), 0);
        int target = sum/k;
        if(sum%k || a.back()>target) return false;

        bool possible[1<<n];
        memset(possible, 0, sizeof possible);
        // if it is possible to partition ith state bits(included numbers)
        // into subsets having sum = target
        possible[0] = true; // it is possible for an empty subset
        int total[1<<n];
        memset(total, 0, sizeof(total));
        // memset(total, sizeof total, 0);
        // total of numbers present in ith state

        // Traverse over all states
        for(int state=0; state<(1<<n); ++state){
            if(!possible[state]) continue;
            
            // else try adding each element that has not been included
            for(int i=0; i<n; ++i){
                int future = state | (1<<i);
                
                // if we haven't already included that element and
                // and adding number to total of this state will not exceed limit(target)
                if(state!=future){
                    if((total[state]%target) + a[i]<= target){
                        possible[future] = true;
                        total[future] = total[state] + a[i];
                    }else // pruning since the elements are sorted
                        break;
                }
            }
        }
        // if it is possible for last state (all 1s i.e all nums included)
        return possible[(1<<n) - 1]; 
    }
};
// @lc code=end
int main(){
    Solution sol;
    vi nums = {4, 3, 2, 3, 5, 2, 1};
    int k = 4;
    cout<<sol.canPartitionKSubsets(nums,k)<<endl;

    nums = {10,10,10,7,7,7,7,7,7,6,6,6};
    cout<<sol.canPartitionKSubsets(nums,3)<<endl;

    nums = { 2,2,2,2,3,4,5 }; k=4;
    cout<<sol.canPartitionKSubsets(nums,k)<<endl;

}

