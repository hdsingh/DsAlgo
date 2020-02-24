/*
 * @lc app=leetcode id=945 lang=cpp
 *
 * [945] Minimum Increment to Make Array Unique
 *
 * https://leetcode.com/problems/minimum-increment-to-make-array-unique/description/
 *
 * algorithms
 * Medium (44.99%)
 * Likes:    298
 * Dislikes: 14
 * Total Accepted:    19.4K
 * Total Submissions: 43.2K
 * Testcase Example:  '[1,2,2]'
 *
 * Given an array of integers A, a move consists of choosing any A[i], and
 * incrementing it by 1.
 * 
 * Return the least number of moves to make every value in A unique.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,2]
 * Output: 1
 * Explanation:  After 1 move, the array could be [1, 2, 3].
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,2,1,2,1,7]
 * Output: 6
 * Explanation:  After 6 moves, the array could be [3, 4, 1, 2, 5, 7].
 * It can be shown with 5 or less moves that it is impossible for the array to
 * have all unique values.
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 0 <= A.length <= 40000
 * 0 <= A[i] < 40000
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

// Brute Force
class Solution1 {
public:
    int minIncrementForUnique(vector<int>& a) {
        int n = a.size();
        // sort(all(a));

        int moves = 0;
        unordered_map<int,int> seen;
        for(int x: a){
            while(seen[x]){
                ++x;
                ++moves;
            }
            seen[x] = 1;            
        }

        return moves;
    }
};

class Solution2 {
public:
    int minIncrementForUnique(vector<int>& a) {
        int n = a.size();
        
        map<int,int> m;
        for(auto &x: a)
            m[x]++;
        
        // print_m(m);

        auto it = m.begin();
        int moves = 0; //m.begin()->second -1;
        int lim = -1; //m.begin()->first + moves;    
        // ++it;
        while(it!=m.end()){
            int x = it->first;
            int freq = it->second;
            if(x>lim){
                lim = x + freq - 1;
                moves+= (tsum(lim) - tsum(x)) - x * (freq-1);
            }else{
                int old_lim = lim;
                lim+=freq; // new lim
                moves+= (tsum(lim) - tsum(old_lim)) - x*freq;
            }
            ++it;
        }

        return moves;
    }

    int tsum(int n){
        return (n*(n+1))/2;
    }
};

// Increase moves only if lim is more than x
// reset lim for each element to its next position
class Solution {
public:
    int minIncrementForUnique(vector<int>& a) {
        sort(all(a));
        
        int res=0; int lim = 0;
        for(int &x: a){
            res += max(lim-x, 0);
            lim = max(lim, x)+1;
        }

        return res;
    }
};
// @lc code=end


int main(){
    Solution sol; vi a; int out;
    a = {1,2,2};
    out = sol.minIncrementForUnique(a); deb(out);
    a = {3,2,1,2,1,7};
    // a = {1,1,1,1,1,1,1,1,1,1,2,2,2,2};
    out = sol.minIncrementForUnique(a); deb(out);
    return 0;
}