/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (25.70%)
 * Likes:    5623
 * Dislikes: 684
 * Total Accepted:    779.6K
 * Total Submissions: 3M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array nums of n integers, are there elements a, b, c in nums such
 * that a + b + c = 0? Find all unique triplets in the array which gives the
 * sum of zero.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate triplets.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 0, 1, 2, -1, -4],
 * 
 * A solution set is:
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
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
    vector<vector<int>> threeSum(vector<int>& a) {
        int n = a.size();
        if(n<3) return {};
        sort(all(a));
        unordered_map<int,int> m;
        for(auto &x: a)
            m[x]++;

        set<vi> out;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int x = a[i]; int y =a[j]; int z = -(x+y);
                if(m.find(x)!=m.end() && m[x] && m.find(y)!=m.end() && m[y] && m.find(z)!=m.end() && m[z]){
                    if(x==y && y==z && m[x]<3) continue;
                    if(x==y && m[x]<2) continue;
                    if(x==z && m[x]<2) continue;
                    if(y==z && m[y]<2) continue;
                    vi uniq = {x,y,z};
                    if(m[x]>1 && m[y]>1 && m[z]>1) 
                        m[x]--,m[y]--,m[z]--;
                    sort(all(uniq));
                    out.insert(uniq);
                }
            }
        }

        return {all(out)};
    }
};

// Two Pointers
// Fix value of x, and find y,z
// Ref: https://leetcode.com/problems/3sum/discuss/7438/C%2B%2B-two-pointes-solution-(easy-way-to-handle-duplicaiton).
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        int n = a.size();
        sort(all(a));

        vvi out;
        for(int i=0; i<n; i++){
            if(i && a[i]==a[i-1]) continue;
            int l = i+1; int r = n-1;
            while(l<r){
                int sum = a[i] + a[l] + a[r];
                if(sum<0) ++l;
                else if(sum>0) --r;
                else{
                    out.push_back({a[i],a[l], a[r]});
                    // handle duplicates
                    while(l+1<n &&  a[l]==a[l+1]) ++l;
                    while(r-1>=0 && a[r]==a[r-1]) --r;    

                    ++l; --r;
                }
            }
        }
        return out;
    }
};
// @lc code=end

int main(){
    Solution sol; vi a; vvi out; 
    a = { -1, 0, 1, 2, -1, -4 };
    // a = {-4, -1, 2,  };
    // a = {0,0,0,0};
    // a = {1,2,-3,4,-5};
    // a = {-4,2,1};
    // a = {-2,-1,1,2};
    // a = { -4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6 };
    a = {1,2,-3};
    out = sol.threeSum(a); print_vv(out);
    return 0;
}
