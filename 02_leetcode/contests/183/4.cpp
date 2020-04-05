/*
 * @lc app=leetcode id=1406 lang=cpp
 *
 * [1406] Stone Game III
 *
 * https://leetcode.com/problems/stone-game-iii/description/
 *
 * algorithms
 * Hard (44.47%)
 * Likes:    35
 * Dislikes: 0
 * Total Accepted:    1.6K
 * Total Submissions: 3.5K
 * Testcase Example:  '[1,2,3,7]'
 *
 * Alice and Bob continue their games with piles of stones. There are several
 * stones arranged in a row, and each stone has an associated value which is an
 * integer given in the array stoneValue.
 * 
 * Alice and Bob take turns, with Alice starting first. On each player's turn,
 * that player can take 1, 2 or 3 stones from the first remaining stones in the
 * row.
 * 
 * The score of each player is the sum of values of the stones taken. The score
 * of each player is 0 initially.
 * 
 * The objective of the game is to end with the highest score, and the winner
 * is the player with the highest score and there could be a tie. The game
 * continues until all the stones have been taken.
 * 
 * Assume Alice and Bob play optimally.
 * 
 * Return "Alice" if Alice will win, "Bob" if Bob will win or "Tie" if they end
 * the game with the same score.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: values = [1,2,3,7]
 * Output: "Bob"
 * Explanation: Alice will always lose. Her best move will be to take three
 * piles and the score become 6. Now the score of Bob is 7 and Bob wins.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: values = [1,2,3,-9]
 * Output: "Alice"
 * Explanation: Alice must choose all the three piles at the first move to win
 * and leave Bob with negative score.
 * If Alice chooses one pile her score will be 1 and the next move Bob's score
 * becomes 5. The next move Alice will take the pile with value = -9 and lose.
 * If Alice chooses two piles her score will be 3 and the next move Bob's score
 * becomes 3. The next move Alice will take the pile with value = -9 and also
 * lose.
 * Remember that both play optimally so here Alice will choose the scenario
 * that makes her win.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: values = [1,2,3,6]
 * Output: "Tie"
 * Explanation: Alice cannot win this game. She can end the game in a draw if
 * she decided to choose all the first three piles, otherwise she will lose.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: values = [1,2,3,-1,-2,-3,7]
 * Output: "Alice"
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: values = [-1,-2,-3]
 * Output: "Tie"
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= values.length <= 50000
 * -1000 <= values[i] <= 1000
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

class Solution1 {
    const int inf = 1e9;
public:
    string stoneGameIII(vector<int>& a) {
        int n = a.size();
        vi dp(n+3);
        vi suf(n+1+3);
        for(int i=n-1; i>=0; --i)
            suf[i] = suf[i+1] + a[i];
        
        for(int i=n-1; i>=0; --i){
            dp[i] = -inf;
            for(int j=1; j<=3; j++){
                max_self(dp[i], suf[i] - dp[i+j]);
            }
        }

        int alice = dp[0];
        int bob = min({dp[1], dp[2], dp[3]});
    
        string out = alice == bob ? "Tie" : alice > bob ? "Alice" : "Bob";
        return out;
    }
};

// We will go from right to left,
// dp[i] represents the max value that can be gained at pos i by me
// if at pos i, I select next k stones, then the opponent can gain from 
// the max starting at pos[i+k], ie dp[i+k]; 
class Solution {
public:
    string stoneGameIII(vector<int>& a) {
        int n = a.size();
        vi dp(n+3);

        int suf = 0;
        for(int i=n-1; i>=0; --i){
            dp[i] = -1e9;
            suf+=a[i];

            // 1. Simple method
            // for(int j=1; j<=3; j++){
                // max_self(dp[i], suf - dp[i+j]);
            // }

            // 2. better implementation since k<=3
            // max_self(dp[i], max({suf - dp[i+1], suf - dp[i+2], suf - dp[i+3]}) );

            // 3.more better implementation
            max_self(dp[i], suf - min({dp[i+1], dp[i+2], dp[i+3]}) );
            
        }

        int alice = dp[0];
        int bob = min({dp[1], dp[2], dp[3]});

        string out = alice == bob ? "Tie" : alice > bob ? "Alice" : "Bob";
        return out;
    }
};
// @lc code=end

int main(){
    Solution sol; string out;
    vvi aa = { 
        {1,2,3,7},
        {1,2,3,-9},
        {1,2,3,6},
        {1,2,3,-1,-2,-3,7},
        {-1,-2,-3},   
    };
    for(auto a: aa){
        out = sol.stoneGameIII(a); deb(out);
    }
    return 0;
}
