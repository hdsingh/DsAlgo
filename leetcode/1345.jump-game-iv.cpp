/*
 * @lc app=leetcode id=1345 lang=cpp
 *
 * [1345] Jump Game IV
 *
 * https://leetcode.com/problems/jump-game-iv/description/
 *
 * algorithms
 * Hard (34.37%)
 * Likes:    108
 * Dislikes: 7
 * Total Accepted:    4.7K
 * Total Submissions: 13.7K
 * Testcase Example:  '[100,-23,-23,404,100,23,23,23,3,404]'
 *
 * Given an array of integers arr, you are initially positioned at the first
 * index of the array.
 * 
 * In one step you can jump from index i to index:
 * 
 * 
 * i + 1 where: i + 1 < arr.length.
 * i - 1 where: i - 1 >= 0.
 * j where: arr[i] == arr[j] and i != j.
 * 
 * 
 * Return the minimum number of steps to reach the last index of the array.
 * 
 * Notice that you can not jump outside of the array at any time.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: arr = [100,-23,-23,404,100,23,23,23,3,404]
 * Output: 3
 * Explanation: You need three jumps from index 0 --> 4 --> 3 --> 9. Note that
 * index 9 is the last index of the array.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: arr = [7]
 * Output: 0
 * Explanation: Start index is the last index. You don't need to jump.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: arr = [7,6,9,6,9,6,9,7]
 * Output: 1
 * Explanation: You can jump directly from index 0 to index 7 which is last
 * index of the array.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: arr = [6,1,9]
 * Output: 2
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: arr = [11,22,7,7,7,7,7,7,7,22,13]
 * Output: 3
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= arr.length <= 5 * 10^4
 * -10^8 <= arr[i] <= 10^8
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
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if(n==1) return 0;
        unordered_map<int,vector<int>> locs;
        for(int i=0; i<n; ++i){
            int j = i;
            while(j+1<n && arr[j+1]==arr[i]){
                ++j;
            }
            locs[arr[i]].push_back(i);
            if(i!=j) locs[arr[i]].push_back(j);
            i = j;
        }
    
        queue<int> q;
        q.push(0);
        vector<bool> vis(n);
        vis[0] = 1;
        int jumps = 0;
    
        while(q.size()){
            queue<int> nq;
            while(q.size()){
                int pos =  q.front(); q.pop();
                if(pos==n-1) return jumps;
               
                for(auto ad: locs[arr[pos]]){
                    if(!vis[ad]){
                        nq.push(ad);
                        vis[ad] = 1;
                    }
                }
                locs[arr[pos]].clear();
            
                for(auto ad: {pos-1, pos+1}){
                    if(ad<0 || ad>=n || vis[ad]) continue;
                    nq.push(ad);
                    vis[ad] = 1;
                }
    
            }
            q = nq;
            ++jumps;
        }
        
        return jumps;
    }
};

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vi> indices_of_val;
        for(int i=0; i<n; ++i)
            indices_of_val[arr[i]].push_back(i);
        
        vector<bool> vis(n);
        queue<int> q;
        vis[0] = true;
        q.push(0);

        int dist = -1;
        while(q.size()){
            dist++;
            int sz = q.size();
            for(int i=0; i<sz; ++i){
                int top = q.front(); q.pop();
                if(top==n-1) return dist;
            
                vi &next = indices_of_val[arr[top]];
                if(top-1>=0) next.push_back(top-1);
                if(top+1<n) next.push_back(top+1);

                for(auto j: next){
                    if(!vis[j]){
                        vis[j] = true;
                        q.push(j);
                    }
                }
    
                // to end TLE, delete the next indices of val
                next.clear();
            }
        }

        return dist;
    }
};
// @lc code=end

int main(){
    Solution sol; int out;
    vvi as = {
        {100,-23,-23,404,100,23,23,23,3,404},
        {7},
        {7,6,9,6,9,6,9,7},
        {6,1,9},
        {11,22,7,7,7,7,7,7,7,22,13},
    };
    for(auto a: as)
        out = sol.minJumps(a), deb(out);
    return 0;
}
