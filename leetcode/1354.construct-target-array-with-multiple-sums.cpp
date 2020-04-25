/*
 * @lc app=leetcode id=1354 lang=cpp
 *
 * [1354] Construct Target Array With Multiple Sums
 *
 * https://leetcode.com/problems/construct-target-array-with-multiple-sums/description/
 *
 * algorithms
 * Hard (34.41%)
 * Likes:    125
 * Dislikes: 20
 * Total Accepted:    5.1K
 * Total Submissions: 14.7K
 * Testcase Example:  '[9,3,5]'
 *
 * Given an array of integers target. From a starting array, A consisting of
 * all 1's, you may perform the following procedure :
 * 
 * 
 * let x be the sum of all elements currently in your array.
 * choose index i, such that 0 <= i < target.size and set the value of A at
 * index i to x.
 * You may repeat this procedure as many times as needed.
 * 
 * 
 * Return True if it is possible to construct the target array from A otherwise
 * return False.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: target = [9,3,5]
 * Output: true
 * Explanation: Start with [1, 1, 1] 
 * [1, 1, 1], sum = 3 choose index 1
 * [1, 3, 1], sum = 5 choose index 2
 * [1, 3, 5], sum = 9 choose index 0
 * [9, 3, 5] Done
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: target = [1,1,1,2]
 * Output: false
 * Explanation: Impossible to create target array from [1,1,1,1].
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: target = [8,5]
 * Output: true
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * N == target.length
 * 1 <= target.length <= 5 * 10^4
 * 1 <= target[i] <= 10^9
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

// We know the prev_val =  cur - (sum-cur)
// also prev_val>0 
// prev_val = 2*cur-sum > 0
// ->  2*cur >sum or cur > sum/2

// Reffered:
// Let's say [mx, a1,a2,..,an]
// other=a1+a2+...+an
// sm=other+mx
// if mx-other>other, there must be multiple(mx//other) times operations, and previous value of mx is mx%other
// for instance, [10,3], mx=10, other=3, prev=1(10%3)
// [1,3] => [4,3] => [7,3] => [10,3]
// you keep adding other to the element whose index is mx's, 3(10//3) times, and then 1 becomes 10
// So instead of decreasing each time in less amount, just directly add the final answer by mod
class Solution {
public:
    bool isPossible(vector<int>& arr) {
        int n = arr.size();
        if(n==1)
            return arr[0]==1;
        
        priority_queue<int> pq;
        ll sum = 0;
        for(auto &x: arr){
            sum+=x;
            pq.push(x);
        }

        // deb(sum);
        while(sum>1 && pq.top() > sum/2){
            int cur = pq.top(); pq.pop();
            sum-=cur;
            // deb2(cur,sum);
            if(sum<=1)
                return sum;
            pq.push(cur%sum);
            sum+= cur%sum;
            // pq.push(cur-sum);
            // sum += cur-sum;
        }

        return sum==n;
    }
};
// @lc code=end

int main(){
    Solution sol; bool out;
    vvi arrs = {
        {1,10},
        // {9,9,9},
        {9,3,5},
        {1,1,1,2},
        {8,5},
        // {2,10},
        // {1,1000000000},
        // {2,1000000001},

    };
    for(auto a: arrs){
        out = sol.isPossible(a); deb(out);
    }
    return 0;
}
