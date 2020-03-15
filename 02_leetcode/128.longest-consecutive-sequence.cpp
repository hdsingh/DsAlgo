/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 *
 * https://leetcode.com/problems/longest-consecutive-sequence/description/
 *
 * algorithms
 * Hard (43.91%)
 * Likes:    2679
 * Dislikes: 153
 * Total Accepted:    266.8K
 * Total Submissions: 607.1K
 * Testcase Example:  '[100,4,200,1,3,2]'
 *
 * Given an unsorted array of integers, find the length of the longest
 * consecutive elements sequence.
 * 
 * Your algorithm should run in O(n) complexity.
 * 
 * Example:
 * 
 * 
 * Input: [100, 4, 200, 1, 3, 2]
 * Output: 4
 * Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
 * Therefore its length is 4.
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


// size based DSU
class Solution {
    int max_size;
    map<int,int> par, size;
public:
    int longestConsecutive(vector<int>& nums) {
        if(!(int)nums.size()) return 0;
        max_size = 1;
        par.clear(); size.clear();
        
        // make set
        for(auto &x: nums){
            par[x] = x;
            size[x] = 1;
        }
        
        for(auto &x: nums){
            if(par.count(x+1))
                union_sets(x, x+1);
            
            if(par.count(x-1))
                union_sets(x,x-1);
        }

        return max_size;
    }

    void union_sets(int x, int y){
        x = find_par(x); 
        y = find_par(y);
        if(x==y) return;
        if(size[x]<size[y])
            swap(x,y);
        par[y] = x;
        size[x]+=size[y];
        max_size = max(max_size, size[x]);
    }

    int find_par(int x){
        if(par[x]==x) return x;
        return par[x] = find_par(par[x]);
    }
};


// @lc code=end

int main(){
    Solution sol; vvi aa; int out;
    aa = {
        {100,4,200,1,3,2,5,},
        {0},
        // {}
    };

    for(auto &a: aa){
      out = sol.longestConsecutive(a); deb(out);  
    }
    return 0;
}
