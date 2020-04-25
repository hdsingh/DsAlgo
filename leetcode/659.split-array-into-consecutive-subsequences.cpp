/*
 * @lc app=leetcode id=659 lang=cpp
 *
 * [659] Split Array into Consecutive Subsequences
 *
 * https://leetcode.com/problems/split-array-into-consecutive-subsequences/description/
 *
 * algorithms
 * Medium (42.74%)
 * Likes:    835
 * Dislikes: 320
 * Total Accepted:    34.1K
 * Total Submissions: 79.7K
 * Testcase Example:  '[1,2,3,3,4,5]'
 *
 * Given an array nums sorted in ascending order, return true if and only if
 * you can split it into 1 or more subsequences such that each subsequence
 * consists of consecutive integers and has length at least 3.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3,3,4,5]
 * Output: True
 * Explanation:
 * You can split them into two consecutive subsequences : 
 * 1, 2, 3
 * 3, 4, 5
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1,2,3,3,4,4,5,5]
 * Output: True
 * Explanation:
 * You can split them into two consecutive subsequences : 
 * 1, 2, 3, 4, 5
 * 3, 4, 5
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [1,2,3,4,4,5]
 * Output: False
 * 
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10000
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
    bool isPossible(vector<int>& a) {
        int n = a.size();
        unordered_map<int,int> cnt; // count
        unordered_map<int,int> req; // required by how may
        for(auto &x: a)
            cnt[x]++;

        // In short cnt[x]--, means x has been appended to a seq
        for(auto &x: a){
            if(cnt[x]==0) continue; // if count 0, then it has already been used
            // if its reqirement is there and it is available, use it, and set
            // requirement for next number, ex: 3's count is 2 and is req, so it will be used(cnt[3]--, )
            // reqirement will be satisfied(req[3]--), and there would be demand for 4 to extend the seq
            if(cnt[x]>0 && req[x]>0){ 
                cnt[x]--;
                req[x]--;
                req[x+1]++;
            }else if(cnt[x]>0 && cnt[x+1]>0 && cnt[x+2]>0){
            // if 0,1,2 all are available, use them and set requirement for 3
                cnt[x]--;
                cnt[x+1]--;
                cnt[x+2]--;
                req[x+3]++;
            }else // other conditions are invalid, don't belong to any consequtive seq
                return false;
        }

        return true;
           
    }
};
// @lc code=end

int main(){
    Solution sol; vvi aa; bool out;
    aa = {
        {1,2,3,3,4,5},
        {1,2,3,3,4,4,5,5},
        {1,2,3,4,4,5},
    };
    for(auto a: aa){
        out = sol.isPossible(a); deb(out);
    }
    return 0;
}
