/*
 * @lc app=leetcode id=456 lang=cpp
 *
 * [456] 132 Pattern
 *
 * https://leetcode.com/problems/132-pattern/description/
 *
 * algorithms
 * Medium (28.62%)
 * Likes:    1057
 * Dislikes: 72
 * Total Accepted:    45.7K
 * Total Submissions: 159.5K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 
 * Given a sequence of n integers a1, a2, ..., an, a 132 pattern is a
 * subsequence ai, aj, ak such
 * that i < j < k and ai < ak < aj. Design an algorithm that takes a list of n
 * numbers as input and checks whether there is a 132 pattern in the list.
 * 
 * Note: n will be less than 15,000.
 * 
 * Example 1:
 * 
 * Input: [1, 2, 3, 4]
 * 
 * Output: False
 * 
 * Explanation: There is no 132 pattern in the sequence.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [3, 1, 4, 2]
 * 
 * Output: True
 * 
 * Explanation: There is a 132 pattern in the sequence: [1, 4, 2].
 * 
 * 
 * 
 * Example 3:
 * 
 * Input: [-1, 3, 2, 0]
 * 
 * Output: True
 * 
 * Explanation: There are three 132 patterns in the sequence: [-1, 3, 2], [-1,
 * 3, 0] and [-1, 2, 0].
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

// Brute Force
class Solution0 {
public:
    bool find132pattern(vector<int>& a) {
        int n = a.size();
        fore(i,0, n){
            fore(j, i+1, n){
                fore(k, j+1, n){
                    if(a[i]<a[k] && a[k]<a[j]){
                        // deb3(i,j,k);
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

// Better Brute Force
class Solution2 {
public:
    bool find132pattern(vector<int>& a) {
        int n = a.size();
        int mn =  a[0];
        for(int j=1; j<n; j++){
            mn = min(a[j], mn);
            for(int k=j+1; k<n; k++){
                if(mn<a[j] && a[k]<a[j] && mn<a[k])
                    return true;
            }
        }
        return false;
    }
};
// @lc code=end

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        vector<int> mins(n);
        mins[0] = nums[0];
        for(int i=1; i<n; ++i)
            mins[i] = min(mins[i-1], nums[i]);
        stack<int> stk;
        for(int i=0; i<n; ++i){
            while(stk.size() && nums[stk.top()]<=nums[i])
                stk.pop();
            
            int prev_gr = stk.size() ? stk.top() : -1;
            
            if(prev_gr>0 && mins[prev_gr-1]<nums[i]){
                return true;
            }
            
            stk.push(i);
        }
        
        return false;
    }
};

int main(){
    Solution0 sol0;
    Solution sol; 
    vvi as; bool out;
    as = {
        { 3,5,0,3,4 },
        {1, 2, 3, 4},
        {3, 1, 4, 2},
        {-1, 3, 2, 0},
        {1,2,3,4,},
        {1,4,5,3,10},
        {1,-4,2,-1,3,-3,-4,0,-3,-1}
    };
    for(auto &a: as){
        out = sol0.find132pattern(a); deb(out);
        out = sol.find132pattern(a); deb(out);
    }
    return 0;
}
