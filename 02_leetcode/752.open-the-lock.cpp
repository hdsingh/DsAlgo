/*
 * @lc app=leetcode id=752 lang=cpp
 *
 * [752] Open the Lock
 *
 * https://leetcode.com/problems/open-the-lock/description/
 *
 * algorithms
 * Medium (49.51%)
 * Likes:    674
 * Dislikes: 37
 * Total Accepted:    41.3K
 * Total Submissions: 83.4K
 * Testcase Example:  '["0201","0101","0102","1212","2002"]\n"0202"'
 *
 * 
 * You have a lock in front of you with 4 circular wheels.  Each wheel has 10
 * slots: '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'.  The wheels can
 * rotate freely and wrap around: for example we can turn '9' to be '0', or '0'
 * to be '9'.  Each move consists of turning one wheel one slot.
 * 
 * The lock initially starts at '0000', a string representing the state of the
 * 4 wheels.
 * 
 * You are given a list of deadends dead ends, meaning if the lock displays any
 * of these codes, the wheels of the lock will stop turning and you will be
 * unable to open it.
 * 
 * Given a target representing the value of the wheels that will unlock the
 * lock, return the minimum total number of turns required to open the lock, or
 * -1 if it is impossible.
 * 
 * 
 * Example 1:
 * 
 * Input: deadends = ["0201","0101","0102","1212","2002"], target = "0202"
 * Output: 6
 * Explanation:
 * A sequence of valid moves would be "0000" -> "1000" -> "1100" -> "1200" ->
 * "1201" -> "1202" -> "0202".
 * Note that a sequence like "0000" -> "0001" -> "0002" -> "0102" -> "0202"
 * would be invalid,
 * because the wheels of the lock become stuck after the display becomes the
 * dead end "0102".
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: deadends = ["8888"], target = "0009"
 * Output: 1
 * Explanation:
 * We can turn the last wheel in reverse to move from "0000" -> "0009".
 * 
 * 
 * 
 * Example 3:
 * 
 * Input: deadends = ["8887","8889","8878","8898","8788","8988","7888","9888"],
 * target = "8888"
 * Output: -1
 * Explanation:
 * We can't reach the target without getting stuck.
 * 
 * 
 * 
 * Example 4:
 * 
 * Input: deadends = ["0000"], target = "8888"
 * Output: -1
 * 
 * 
 * 
 * Note:
 * 
 * The length of deadends will be in the range [1, 500].
 * target will not be in the list deadends.
 * Every string in deadends and the string target will be a string of 4 digits
 * from the 10,000 possibilities '0000' to '9999'.
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
    int openLock(vector<string>& deadends, string target) {
        unordered_map<string, bool> visited;
        unordered_map<string,bool> dead;
        for(auto d: deadends)
            dead[d] = true;
        queue<string> q;
        string cur = "0000";
        visited[cur] = true;
        if(dead[cur]) return -1;
        q.push(cur);
        
        int moves = 0;
        while(q.size()){
            ++moves;
            int breadth = q.size();
            for(int i=0; i<breadth; ++i){
                cur = q.front(); q.pop();
                visited[cur] = true;

                // try out all possibilities and push it in string if valid and unvisited
                for(int j=0; j<4; ++j){
                    string s = cur;
                    char c = s[j] + 1;
                    s[j] = '1'<=c && c<='9' ? c : '0';
                    if(s==target) return moves;
                    if(!dead[s] && !visited[s]){
                        visited[s] = true;
                        q.push(s);
                        // deb2(cur, s);
                    }

                    s = cur;
                    c = s[j] - 1;
                    s[j] = '1'<=c && c<='9' ? c : '9';

                    if(s==target) return moves;
                    if(!dead[s] && !visited[s]){
                        visited[s] = true;
                        q.push(s);
                        // deb2(cur, s);
                    }
                }
            }
        }

        return -1;        
    }
};

// @lc code=end

int main(){
    Solution sol; vs deadends; string target; int out;
    deadends = { "0201","0101","0102","1212","2002" }, target = "0202";
    out = sol.openLock(deadends,target); deb(out);

    deadends = { "8888" }, target = "0009";
    out = sol.openLock(deadends,target); deb(out);

    deadends = { "8887","8889","8878","8898","8788","8988","7888","9888" }, target = "8888";
    out = sol.openLock(deadends,target); deb(out);

    deadends = { "0000" }, target = "8888";
    out = sol.openLock(deadends,target); deb(out);

    return 0;
}
