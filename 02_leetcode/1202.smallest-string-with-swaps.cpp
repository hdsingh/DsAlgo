/*
 * @lc app=leetcode id=1202 lang=cpp
 *
 * [1202] Smallest String With Swaps
 *
 * https://leetcode.com/problems/smallest-string-with-swaps/description/
 *
 * algorithms
 * Medium (44.13%)
 * Likes:    349
 * Dislikes: 11
 * Total Accepted:    9.9K
 * Total Submissions: 22.4K
 * Testcase Example:  '"dcab"\n[[0,3],[1,2]]'
 *
 * You are given a string s, and an array of pairs of indices in the string
 * pairs where pairs[i] = [a, b] indicates 2 indices(0-indexed) of the string.
 * 
 * You can swap the characters at any pair of indices in the given pairs any
 * number of times.
 * 
 * Return the lexicographically smallest string that s can be changed to after
 * using the swaps.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "dcab", pairs = [[0,3],[1,2]]
 * Output: "bacd"
 * Explaination: 
 * Swap s[0] and s[3], s = "bcad"
 * Swap s[1] and s[2], s = "bacd"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "dcab", pairs = [[0,3],[1,2],[0,2]]
 * Output: "abcd"
 * Explaination: 
 * Swap s[0] and s[3], s = "bcad"
 * Swap s[0] and s[2], s = "acbd"
 * Swap s[1] and s[2], s = "abcd"
 * 
 * Example 3:
 * 
 * 
 * Input: s = "cba", pairs = [[0,1],[1,2]]
 * Output: "abc"
 * Explaination: 
 * Swap s[0] and s[1], s = "bca"
 * Swap s[1] and s[2], s = "bac"
 * Swap s[0] and s[1], s = "abc"
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 10^5
 * 0 <= pairs.length <= 10^5
 * 0 <= pairs[i][0], pairs[i][1] < s.length
 * s only contains lower case English letters.
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

// Union Find
class Solution0 {
    int n;
    vi par, rank;
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        n = s.size();
        par.clear(); par.resize(n); 
        rank.clear(); rank.resize(n);

        // make set
        iota(all(par),0);

        // unite
        for(auto &p: pairs)
            unite(p[0], p[1]);

        unordered_map<int,vector<int>> unions;
        unordered_map<int, string> outs;
        for(int i=0; i<n; ++i){
            int p = find_par(i);
            unions[p].push_back(i);
            outs[p].push_back(s[i]);
        }

        for(auto &up : unions){
            // up: union pair
            int p = up.first;
            sort(all(up.second)); // sort all the united indexes
            sort(all(outs[p])); // sort the string formed
            
            for(int i=0; i<(int)up.second.size(); ++i){
                s[up.second[i]] = outs[p][i];
            }
        }     

        return s;
    }

    void unite(int a, int b){
        a = find_par(a);
        b = find_par(b);
        if(a!=b){
            if(rank[a]<rank[b])
                swap(a,b);
            if(rank[a]==rank[b])
                ++rank[a];
            par[b] = a;
        }
    }

    int find_par(int a){
        if(a==par[a]) return a;
        return par[a] = find_par(par[a]);
    }
};

// Connected Components
class Solution {
    int n; vvi adj; vi idxs; vector<bool> visited;
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        n = s.size();
        adj.clear(); adj.resize(n);
        visited.clear(); visited.resize(n);

        for(auto &p: pairs)
            adj[p[0]].push_back(p[1]), adj[p[1]].push_back(p[0]);
        
        for(int i=0; i<n; ++i){
            if(!visited[i]){
                visited[i] = true;
                idxs.clear();
                dfs(i);
                string cur;
                for(auto &idx: idxs)
                    cur.push_back(s[idx]);

                sort(all(idxs));
                sort(all(cur));

                for(int j=0; j<(int)idxs.size(); ++j)
                    s[idxs[j]] = cur[j];
            }
        }

        return s;
    }

    void dfs(int a){
        idxs.push_back(a);
        for(auto ad: adj[a]){
            if(!visited[ad]){
                visited[ad] = true;
                dfs(ad);
            }
        }
    }
};
// @lc code=end


int main(){
    Solution sol; string s; vvi pairs;
    s = "dcab", pairs = {{0,3},{1,2}};
    s = sol.smallestStringWithSwaps(s, pairs); deb(s);

    s = "dcab", pairs = {{0,3},{1,2},{0,2}};
    s = sol.smallestStringWithSwaps(s, pairs); deb(s);

    s = "cba", pairs = {{0,1},{1,2}};
    s = sol.smallestStringWithSwaps(s, pairs); deb(s);

    return 0;
}