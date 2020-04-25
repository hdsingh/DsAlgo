/*
 * @lc app=leetcode id=768 lang=cpp
 *
 * [768] Max Chunks To Make Sorted II
 *
 * https://leetcode.com/problems/max-chunks-to-make-sorted-ii/description/
 *
 * algorithms
 * Hard (47.75%)
 * Likes:    347
 * Dislikes: 14
 * Total Accepted:    17.4K
 * Total Submissions: 36.5K
 * Testcase Example:  '[5,4,3,2,1]'
 *
 * This question is the same as "Max Chunks to Make Sorted" except the integers
 * of the given array are not necessarily distinct, the input array could be up
 * to length 2000, and the elements could be up to 10**8.
 * 
 * 
 * 
 * Given an array arr of integers (not necessarily distinct), we split the
 * array into some number of "chunks" (partitions), and individually sort each
 * chunk.  After concatenating them, the result equals the sorted array.
 * 
 * What is the most number of chunks we could have made?
 * 
 * Example 1:
 * 
 * 
 * Input: arr = [5,4,3,2,1]
 * Output: 1
 * Explanation:
 * Splitting into two or more chunks will not return the required result.
 * For example, splitting into [5, 4], [3, 2, 1] will result in [4, 5, 1, 2,
 * 3], which isn't sorted.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: arr = [2,1,3,4,4]
 * Output: 4
 * Explanation:
 * We can split into two chunks, such as [2, 1], [3, 4, 4].
 * However, splitting into [2, 1], [3], [4], [4] is the highest number of
 * chunks possible.
 * 
 * 
 * Note:
 * 
 * 
 * arr will have length in range [1, 2000].
 * arr[i] will be an integer in range [0, 10**8].
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
template <typename T>void print_vv(T v){int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}
template <class T, class U> void print_m(multimap<T,U> m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}

// Create distint elements and then apply same logic
class Solution1 {
public:
    int maxChunksToSorted(vector<int>& a) {
        int n = a.size();
        vi b = a;
        sort(all(b));
        multimap<int, int> m;
        for(int i=0; i<n; i++){
            m.insert({b[i], i});
        }

        for(auto &x :a){
            auto it = m.equal_range(x);
            x = it.first->second;
            m.erase(it.first);
        }
        // print(a);
        int mx = -1; int cnt = 0;
        for(int i=0; i<n; i++){
            mx = max(mx, a[i]);
            if(mx==i) ++cnt;
        }
        return cnt;
    }
};

// Ref: Since arr[i]...arr[j] is permutation, its sum will be equal to sorted array,
// if it can form a sorted chunk
class Solution {
public:
    int maxChunksToSorted(vector<int>& a) {
        vi a_sorted = a;
        sort(all(a_sorted));
        ll a_sum = 0;
        ll sorted_sum = 0;

        int cnt = 0;
        for(int i=0; i<a.size(); i++){
            a_sum+=a[i];
            sorted_sum+=a_sorted[i];
            if(a_sum==sorted_sum) ++cnt;
        }
        return cnt;
    }
};
// @lc code=end

int main(){
    Solution sol; vi arr; int out;
    arr = { 4,3,2,1,0 }; 
    out = sol.maxChunksToSorted(arr); deb(out);
    arr = { 20,10,30,40,40 };
    out = sol.maxChunksToSorted(arr); deb(out);
    return 0;
}