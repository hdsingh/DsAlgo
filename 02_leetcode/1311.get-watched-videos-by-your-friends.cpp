/*
 * @lc app=leetcode id=1311 lang=cpp
 *
 * [1311] Get Watched Videos by Your Friends
 *
 * https://leetcode.com/problems/get-watched-videos-by-your-friends/description/
 *
 * algorithms
 * Medium (42.35%)
 * Likes:    68
 * Dislikes: 113
 * Total Accepted:    6.6K
 * Total Submissions: 15.5K
 * Testcase Example:  '[["A","B"],["C"],["B","C"],["D"]]\n[[1,2],[0,3],[0,3],[1,2]]\n0\n1'
 *
 * There are n people, each person has a unique id between 0 and n-1. Given the
 * arrays watchedVideos and friends, where watchedVideos[i] and friends[i]
 * contain the list of watched videos and the list of friends respectively for
 * the person with id = i.
 * 
 * Level 1 of videos are all watched videos by your friends, level 2 of videos
 * are all watched videos by the friends of your friends and so on. In general,
 * the level k of videos are all watched videos by people with the shortest
 * path exactly equal to k with you. Given your id and the level of videos,
 * return the list of videos ordered by their frequencies (increasing). For
 * videos with the same frequency order them alphabetically from least to
 * greatest. 
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: watchedVideos = [["A","B"],["C"],["B","C"],["D"]], friends =
 * [[1,2],[0,3],[0,3],[1,2]], id = 0, level = 1
 * Output: ["B","C"] 
 * Explanation: 
 * You have id = 0 (green color in the figure) and your friends are (yellow
 * color in the figure):
 * Person with id = 1 -> watchedVideos = ["C"] 
 * Person with id = 2 -> watchedVideos = ["B","C"] 
 * The frequencies of watchedVideos by your friends are: 
 * B -> 1 
 * C -> 2
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input: watchedVideos = [["A","B"],["C"],["B","C"],["D"]], friends =
 * [[1,2],[0,3],[0,3],[1,2]], id = 0, level = 2
 * Output: ["D"]
 * Explanation: 
 * You have id = 0 (green color in the figure) and the only friend of your
 * friends is the person with id = 3 (yellow color in the figure).
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == watchedVideos.length == friends.length
 * 2 <= n <= 100
 * 1 <= watchedVideos[i].length <= 100
 * 1 <= watchedVideos[i][j].length <= 8
 * 0 <= friends[i].length < n
 * 0 <= friends[i][j] < n
 * 0 <= id < n
 * 1 <= level < n
 * if friends[i] contains j, then friends[j] contains i
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
template <class M, class T, class U> void print_m(unordered_map<T,U> m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}

class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vs>& wVids, vvi& friends, int id, int level) {
        unordered_map<int,int> visited;
        unordered_map<string, int> watchedCnt;
        queue<int> q;
        visited[id] = true;
        q.push(id);

        int depth = -1;
        while(q.size() && depth<=level){
            ++depth;
            int breadth = q.size();
            for(int i=0; i<breadth; ++i){
                id = q.front(); q.pop();
                for(auto f: friends[id])
                    if(!visited[f]){
                        visited[f] = true;
                        q.push(f);
                    }
        
                if(depth==level){
                    for(auto vid: wVids[id])
                        watchedCnt[vid]++;
                }
            }
        }

        // print_m(watchedCnt);
        
        vector<pair<string,int>> watched;
        for(auto p: watchedCnt)
            watched.push_back({p.first, p.second});
        
        sort(all(watched),[](pair<string,int> &p1, pair<string,int> &p2){
            if(p1.second==p2.second)
                return p1.first<p2.first;
            return p1.second<p2.second;
        });


        vs out;
        for(auto p: watched)
            out.push_back(p.first);
        
        return out;

    }
};

// @lc code=end

int main(){
    Solution sol;
    vector<vs> watchedVideos; vvi friends; int id,level; vs out;
    watchedVideos = {{"A","B"},{"C"},{"B","C"},{"D"}}, friends = {{1,2},{0,3},{0,3},{1,2}}, id = 0, level = 1;
    out = sol.watchedVideosByFriends(watchedVideos,friends,id,level); print(out);

    watchedVideos = {{"A","B"},{"C"},{"B","C"},{"D"}}, friends = {{1,2},{0,3},{0,3},{1,2}}, id = 0, level = 2;
    out = sol.watchedVideosByFriends(watchedVideos,friends,id,level); print(out);

    return 0;
}
