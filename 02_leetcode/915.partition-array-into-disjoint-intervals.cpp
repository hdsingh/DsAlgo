/*
 * @lc app=leetcode id=915 lang=cpp
 *
 * [915] Partition Array into Disjoint Intervals
 *
 * https://leetcode.com/problems/partition-array-into-disjoint-intervals/description/
 *
 * algorithms
 * Medium (44.63%)
 * Likes:    281
 * Dislikes: 21
 * Total Accepted:    16.4K
 * Total Submissions: 36.8K
 * Testcase Example:  '[5,0,3,8,6]'
 *
 * Given an array A, partition it into two (contiguous) subarrays left and
 * right so that:
 * 
 * 
 * Every element in left is less than or equal to every element in right.
 * left and right are non-empty.
 * left has the smallest possible size.
 * 
 * 
 * Return the length of left after such a partitioning.  It is guaranteed that
 * such a partitioning exists.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [5,0,3,8,6]
 * Output: 3
 * Explanation: left = [5,0,3], right = [8,6]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1,1,1,0,6,12]
 * Output: 4
 * Explanation: left = [1,1,1,0], right = [6,12]
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 2 <= A.length <= 30000
 * 0 <= A[i] <= 10^6
 * It is guaranteed there is at least one way to partition A as
 * described.
 * 
 * 
 * 
 * 
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

class Solution {
public:
    int partitionDisjoint(vector<int>& a) {
        int n = a.size();

        vi maxPre(n); maxPre[0]=a[0];
        for(int i=1; i<n; i++)
            maxPre[i] = max(maxPre[i-1], a[i]);
        
        vi minPre(n); minPre[n-1] = a[n-1];
        for(int i=n-2; i>=0; i--)
            minPre[i] = min(minPre[i+1], a[i]);
        
        // print(a,1);
        // print(maxPre);
        // print(minPre);

        int i=0;
        for(i=0; i<n-1; i++){
            if(maxPre[i]<=minPre[i+1])
                break;
        }

        return i+1;
    }
};
// @lc code=end


int main(){
    Solution sol;
    vi a; int out;
    a = {5,0,3,8,6};
    out = sol.partitionDisjoint(a); deb(out);
    a = {1,1,1,0,6,12};
    a = {1,1,0,1};
    out = sol.partitionDisjoint(a); deb(out);
    return 0;
}