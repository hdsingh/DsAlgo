/*
 * @lc app=leetcode id=1306 lang=cpp
 *
 * [1306] Jump Game III
 *
 * https://leetcode.com/problems/jump-game-iii/description/
 *
 * algorithms
 * Medium (61.20%)
 * Likes:    179
 * Dislikes: 4
 * Total Accepted:    12.4K
 * Total Submissions: 20.3K
 * Testcase Example:  '[4,2,3,0,3,1,2]\n5'
 *
 * Given an array of non-negative integers arr, you are initially positioned at
 * start index of the array. When you are at index i, you can jump to i +
 * arr[i] or i - arr[i], check if you can reach to any index with value 0.
 * 
 * Notice that you can not jump outside of the array at any time.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: arr = [4,2,3,0,3,1,2], start = 5
 * Output: true
 * Explanation: 
 * All possible ways to reach at index 3 with value 0 are: 
 * index 5 -> index 4 -> index 1 -> index 3 
 * index 5 -> index 6 -> index 4 -> index 1 -> index 3 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: arr = [4,2,3,0,3,1,2], start = 0
 * Output: true 
 * Explanation: 
 * One possible way to reach at index 3 with value 0 is: 
 * index 0 -> index 4 -> index 1 -> index 3
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: arr = [3,0,2,1,2], start = 2
 * Output: false
 * Explanation: There is no way to reach at index 1 with value 0.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= arr.length <= 5 * 10^4
 * 0 <= arr[i] < arr.length
 * 0 <= start < arr.length
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

class Solution0 {
    int n;
    unordered_map<int,int> visited;
public:
    bool canReach(vector<int>& a, int start) {
        n = a.size();
        visited.clear();
        return dfs(start, a);
    }

    bool dfs(int x, const vi &a){
        if(a[x]==0) return true;
        if(visited[x]) return false;

        visited[x] = 1;
        bool left = false, right = false;

        int pos = x - a[x];
        if(pos>=0 && pos<n)
            left =  dfs(pos,a);
        pos = x + a[x];
        if(pos>=0 && pos<n)
            right = dfs(pos,a);

        return left||right;        
    }
};

class Solution {
public:
    bool canReach(vector<int>& a, int start) {
        int n = a.size();
        unordered_map<int, int> visited;
        queue<int> q; // indexes
        q.push(start);

        while(!q.empty()){
            int x = q.front(); q.pop();
            if(a[x]==0) return true;
            visited[x] = true;
            int pos = x + a[x];
            if(pos>=0 && pos<n && !visited[pos])
                q.push(pos);
            pos = x - a[x];
            if(pos>=0 && pos<n && !visited[pos])
                q.push(pos);
        }

        return false;
    }
};

// @lc code=end

int main(){
    Solution sol; vi arr; int start; bool out;
    arr = {4,2,3,0,3,1,2}, start = 5;
    out = sol.canReach(arr,start); deb(out);

    arr = {4,2,3,0,3,1,2}, start = 0;
    out = sol.canReach(arr,start); deb(out);

    arr = {3,0,2,1,2}, start = 2;
    out = sol.canReach(arr,start); deb(out);
    return 0;
}
