/*
 * @lc app=leetcode id=886 lang=cpp
 *
 * [886] Possible Bipartition
 *
 * https://leetcode.com/problems/possible-bipartition/description/
 *
 * algorithms
 * Medium (42.56%)
 * Likes:    419
 * Dislikes: 17
 * Total Accepted:    20.3K
 * Total Submissions: 47.6K
 * Testcase Example:  '4\n[[1,2],[1,3],[2,4]]'
 *
 * Given a set of N people (numbered 1, 2, ..., N), we would like to split
 * everyone into two groups of any size.
 * 
 * Each person may dislike some other people, and they should not go into the
 * same group. 
 * 
 * Formally, if dislikes[i] = [a, b], it means it is not allowed to put the
 * people numbered a and b into the same group.
 * 
 * Return true if and only if it is possible to split everyone into two groups
 * in this way.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: N = 4, dislikes = [[1,2],[1,3],[2,4]]
 * Output: true
 * Explanation: group1 [1,4], group2 [2,3]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: N = 3, dislikes = [[1,2],[1,3],[2,3]]
 * Output: false
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: N = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
 * Output: false
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= N <= 2000
 * 0 <= dislikes.length <= 10000
 * 1 <= dislikes[i][j] <= N
 * dislikes[i][0] < dislikes[i][1]
 * There does not exist i != j for which dislikes[i] == dislikes[j].
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

class Solution0 {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dis) {
        vvi adj(n+1);
        for(auto d: dis)
            adj[d[0]].push_back(d[1]), adj[d[1]].push_back(d[0]);
        
        vi color(n+1, -1);
        queue<int> q;
        bool is_bipartite = true;
        for(int i=1; i<=n; ++i){
            if(color[i]!=-1) continue;
            color[i] = 0;
            q.push(i);

            while(!q.empty()){
                int cur = q.front(); q.pop();
                for(auto ad: adj[cur]){
                    if(color[ad]==-1){
                        color[ad] = color[cur]^1;
                        q.push(ad);
                    }else{
                        is_bipartite &= color[cur]!=color[ad];
                    }
                }
            }
        }

        return is_bipartite;
    }
};

class Solution {
    vvi adj;
    vi colors;
    int n;
public:
    bool possibleBipartition(int N, vector<vector<int>>& dis) {
        n = N;
        adj.clear(); adj.resize(n+1);
        colors.clear(); colors.resize(n+1,-1);
        for(auto &d: dis)
            adj[d[0]].push_back(d[1]), adj[d[1]].push_back(d[0]);
        
        for(int i=1; i<=n; ++i){
            if(colors[i]==-1 && !dfs(i,0))
                return false;
        }
        return true;
    }

    bool dfs(int x, int c){
        if(colors[x]!=-1) return colors[x]==c;
        colors[x] = c;

        for(auto ad: adj[x]){
            if(!dfs(ad, 1^c))
                return false;
        }
      
        return true;
    }
};

// @lc code=end


int main(){
    
    return 0;
}