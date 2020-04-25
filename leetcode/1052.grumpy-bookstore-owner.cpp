/*
 * @lc app=leetcode id=1052 lang=cpp
 *
 * [1052] Grumpy Bookstore Owner
 *
 * https://leetcode.com/problems/grumpy-bookstore-owner/description/
 *
 * algorithms
 * Medium (54.21%)
 * Likes:    273
 * Dislikes: 23
 * Total Accepted:    16.9K
 * Total Submissions: 31.2K
 * Testcase Example:  '[1,0,1,2,1,1,7,5]\n[0,1,0,1,0,1,0,1]\n3'
 *
 * Today, the bookstore owner has a store open for customers.length minutes.
 * Every minute, some number of customers (customers[i]) enter the store, and
 * all those customers leave after the end of that minute.
 * 
 * On some minutes, the bookstore owner is grumpy.  If the bookstore owner is
 * grumpy on the i-th minute, grumpy[i] = 1, otherwise grumpy[i] = 0.  When the
 * bookstore owner is grumpy, the customers of that minute are not satisfied,
 * otherwise they are satisfied.
 * 
 * The bookstore owner knows a secret technique to keep themselves not grumpy
 * for X minutes straight, but can only use it once.
 * 
 * Return the maximum number of customers that can be satisfied throughout the
 * day.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: customers = [1,0,1,2,1,1,7,5], grumpy = [0,1,0,1,0,1,0,1], X = 3
 * Output: 16
 * Explanation: The bookstore owner keeps themselves not grumpy for the last 3
 * minutes. 
 * The maximum number of customers that can be satisfied = 1 + 1 + 1 + 1 + 7 +
 * 5 = 16.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= X <= customers.length == grumpy.length <= 20000
 * 0 <= customers[i] <= 1000
 * 0 <= grumpy[i] <= 1
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
template <class T, class U> void print_m(map<T,U> m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}

// Choose a strip of len X, where diff bw with and without gr is max
// total = gr_l + no_grX + gr_r
class Solution1 {
public:
    int maxSatisfied(vector<int>& a, vector<int>& grumpy, int X) {
        int n = a.size();
        vi gr(n), nogr(n); // pre with grump, no grump
        nogr[0] = a[0];
        gr[0] = a[0]*(grumpy[0]==1 ? 0 : 1);

        for(int i=1; i<n; i++){
            nogr[i] = nogr[i-1] + a[i];
            gr[i] = gr[i-1] + a[i] * (grumpy[i]==1 ? 0 : 1);
        }

        int loc = 0; // find the location of max diff
        int mdiff = 0;
        for(int i=0; i+X<=n; i++){
            int withoutGr = nogr[i+X-1] - (i-1>=0 ? nogr[i-1] : 0);
            int withGr = gr[i+X -1] - (i-1>=0 ? gr[i-1] : 0);
            int diff = withoutGr - withGr;
            if(diff>mdiff){
                mdiff = diff;
                loc = i;
            }
        }

        int ans = (loc-1>=0 ? gr[loc-1] : 0) + 
                  nogr[loc+X-1] - (loc-1>=0 ? nogr[loc-1] : 0) + 
                  gr[n-1] - gr[loc+X-1];
        return ans;        
    }
};

// Better implementation + Sliding Window
class Solution {
public:
    int maxSatisfied(vector<int>& cs, vector<int>& gr, int X) {
        int n = cs.size();
        int satisfied = 0; int add_satisfied = 0; int mx_add_satisfied = 0;

        for(int i=0; i<n; i++){
            if(gr[i]==0){
                satisfied+=cs[i];
            }else{
                add_satisfied+=cs[i];
            }

            if(i>=X)
                add_satisfied-= gr[i-X] * cs[i-X];
            mx_add_satisfied = max(mx_add_satisfied, add_satisfied);
        }
        return mx_add_satisfied + satisfied;
    }
};
// @lc code=end

int main(){
    Solution sol; vi customers, grumpy; int X, out;
    customers = { 1,0,1,2,1,1,7,5 }, 
    grumpy =    { 0,1,0,1,0,1,0,1 }, X = 3;
    out = sol.maxSatisfied(customers, grumpy, X); deb(out);
    customers = { 5,8 }, 
    grumpy =    { 0,1}, X = 1;
    out = sol.maxSatisfied(customers, grumpy, X); deb(out);
    grumpy =    {0,1,0,0,0,0,0,1};
    customers = {0,1,2,3,4,5,6,7};
    X  = 3;
    out = sol.maxSatisfied(customers, grumpy, X); deb(out);
    return 0;
}
